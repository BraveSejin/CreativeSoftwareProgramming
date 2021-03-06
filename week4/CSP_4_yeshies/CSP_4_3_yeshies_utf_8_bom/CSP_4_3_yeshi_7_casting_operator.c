/*
	'수식으로서 적은' 포인터 변수, 배열, 함수 이름이
	C 컴파일러에 의해 어떻게 deduce될 수 있는지 확인하기 위한 예시들이에요.

	이 파일에서는
	어떤 수식에 대한 casting 연산자를 직접 붙여 봄으로써
	앞에서 등장했던 다양한 deduction 규칙들이 실제로 적용되어 있는 것을 확인해 봐요.

	주의:
		이 파일의 코드는 정상적으로 실행되지 않을 거예요.
		각 문장들에 달아 둔 주석 설명들을 읽으며 deduction 양상을 확인해 보세요.
		다 읽은 다음에는 주석으로 막아 둔 문장들을 풀고 VS가 어떤 오류 메시지를 내뱉고 있는지 확인해 보세요.
*/
 
// number는 변수 이름이에요.
double number = 3;

// arr은 배열 이름이에요.
int arr[] = { 3, 3, 3 };

// Three는 함수 이름이에요.
int Three()
{
	return 3;
}

int main()
{
	// 우항은 적힌 그대로 컴파일돼요.
	number = (int)number;

	// 우항은 (int)(int *)arr로 컴파일돼요. 어차피 아마 eax 등에 담게 될 테니 그냥 컴파일해 주고 있어요.
	number = (int)arr;

	// 우항은 (int)(int (*)())Three로 컴파일돼요. 어차피 아마 eax 등에 담게 될 테니 그냥 컴파일해 주고 있어요.
	number = (int)Three;



	// 우항은 적힌 그대로 컴파일돼요
	number = (double)number;

	// 우항은 (double)(int *)arr로 컴파일돼요. '위치 값에 대한 double 값'을 VS에서는 허용하지 않으므로 오류가 나요.
	//number = (double)arr;

	// 우항은 (double)(int (*)())Three로 컴파일돼요. '위치 값에 대한 double 값'을 VS에서는 허용하지 않으므로 오류가 나요.
	//number = (double)Three;



	// 우항은 적힌 그대로 컴파일돼요. 'double 값에 대한 위치 값'을 VS에서는 허용하지 않으므로 오류가 나요.
	//number = *(int *)number;

	// 우항은 적힌 그대로 컴파일돼요.
	number = *(int *)arr;

	// 우항은 *(int *)(int (*)())Three와 같은 느낌으로 컴파일돼요.
	// int * 형식이나 int (*)() 형식이나 아무튼 위치 값 나오는 건 맞으니 그냥 컴파일해 주고 있어요.
	number = *(int *)Three;



	// '배열 값'의 개념은 C에 존재하지 않으므로 오류가 나요.
	//number = *(int[3])number;

	// '배열 값'의 개념은 C에 존재하지 않으므로 오류가 나요.
	//number = *(int[3])arr;

	// '배열 값'의 개념은 C에 존재하지 않으므로 오류가 나요.
	//number = *(int[3])Three;



	// 우항은 적힌 그대로 컴파일돼요.
	// int (*)[3] 형식이나 double * 형식이나 아무튼 위치 값 나오는 건 맞으니 그냥 컴파일해 주고 있어요.
	number = **(int(*)[3])&number;

	// 우항은 적힌 그대로 컴파일돼요.
	number = **(int(*)[3])&arr;

	// 우항은 적힌 그대로 컴파일돼요.
	// int (*)[3] 형식이나 double * 형식이나 아무튼 위치 값 나오는 건 맞으니 그냥 컴파일해 주고 있어요.
	number = **(int(*)[3])&Three;



	// '함수 값'의 개념은 C에 존재하지 않으므로 오류가 나요.
	//number = ((int())number)();

	// '함수 값'의 개념은 C에 존재하지 않으므로 오류가 나요.
	//number = ((int())arr)();

	// '함수 값'의 개념은 C에 존재하지 않으므로 오류가 나요.
	//number = ((int())Three)();



	// 우항은 적힌 그대로 컴파일돼요.
	// int (*)() 형식이나 double * 형식이나 아무튼 위치 값 나오는 건 맞으니 그냥 컴파일해 주고 있어요.
	number = ((int(*)())&number)();

	// 우항은 적힌 그대로 컴파일돼요.
	// int (*)() 형식이나 int (*)[3] 형식이나 아무튼 위치 값 나오는 건 맞으니 그냥 컴파일해 주고 있어요.
	number = ((int(*)())&arr)();

	// 우항은 적힌 그대로 컴파일돼요.
	number = ((int(*)())&Three)();






	/*
		대충 보면 느낌이 오듯, casting 연산자는 생각보다 다양한 가능성을 가지고 있어요.
		일단 지금은 아래 두 내용 정도만 마지막으로 짚어 두면 좋을 듯 해요:
	*/

	/*
		1. Casting 연산자의 가장 큰 의미는,
		   context, 달리 말하면 '주변 수식'에 무관하게 deduction 방안을 프로그래머가 직접 정할 수 있다는 것이에요.
		   - 애초에 절대 컴파일러가 deduce하지 않을 배열/함수 형식으로 casting하는 것은 프로그래머도 못 하도록 막아 놨어요
		   - 반대로 말하면, 주변 수식을 읽은 컴파일러가 위와 같은 요상한 deduction을 수행해 줄 수도 있다는 게 돼요

		2. 보편적인 프로그래밍 시나리오에서는 void * 형식을 쓰지 않는 한 내가 직접 casting 연산자를 적을 일은 많지 않아요.
		   따라서 청정한 지금 시점에서는 casting 연산자를 '안 돌아가는 코드를 돌게 하는' 목표로 사용하지 않는 것이 더 좋을 거예요.
		   - 선언을 적절히 잘 적고, 적어 둔 대로 그 이름을 수식으로서 사용한다면 여간해서는 굳이 casting 연산자를 쓰지 않아도 돼요
		   - 단, deduce 과정에 선언이 개입하기 어려운 시나리오에서는 casting 연산자가 필요할 수 있기는 해요.
		     > C에서는 printf("%f", number) 대신 printf("%f", (double)number)와 같이 적는 게 필요할 때가 있을 수 있어요
			 > 나중에 C++를 다룰 때는 이와는 살짝 다른 느낌으로 casting 연산자'들'을 적절히 골라 써야 할 수 있어요
	*/

	return 0;
}