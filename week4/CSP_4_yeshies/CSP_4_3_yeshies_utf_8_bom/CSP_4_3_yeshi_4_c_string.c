/*
	'수식으로써 적은' 포인터 변수, 배열, 함수 이름이
	C 컴파일러에 의해 어떻게 deduce될 수 있는지 확인하기 위한 예시들이에요.

	이 파일에서는
	C에서 큰 따옴표로 둘러 싼 문자열 literal을 어떻게 다루는지 살펴 봐요.
	- const specifier, 그리고 declarator를 꾸미기 위한 C의 마지막 기호인 *const에 대해서도 살펴 봐요
*/
 
#include <stdio.h>

/*
	주목: 아래에 있는 help1 ~ help5는 현재 모두 initializer 자리에 "HELP"를 적어 두었습니다.
*/

// help1: 일반적으로 문자열 literal을 사용할 때 쓰는 선언
const char *help1 = "HELP";

// help2: help1 선언에서 * 말고 *const를 사용한 선언
const char *const help2 = "HELP";

// help3: help1 선언에서 const를 없앤 선언
char *help3 = "HELP";

// help4: help3 선언에서 * 말고 []를 사용한 선언
char help4[] = "HELP";

// help5: help4 선언에 const가 붙은 선언
const char help5[] = "HELP";





void func1(), func2(), func3(), func4(), func5();




int main()
{
	// TODO: 이번 예제도 아래 있는 주석을 적당히 풀어서 함수들을 하나씩 호출해 봅시다.
	func1();
	//func2();

	// 주의: func3(), func4()는 일단 주석 푼 다음 그 함수 정의로 가서 설명을 먼저 읽어 보도록 합시다.
	//func3();
	//func4();

	// 마지막 func5()에서는 *const에 대해 살짝 요약해 두었어요.
	//func5();

	return 0;
}


void func1()
{
	// %s는 주어진 포인터 값을 따라가면 나오는 문자열을 출력할 때 사용합니다.
	printf("%%s로 출력하기:\n");
	printf("help1: %s\n", help1);
	printf("help2: %s\n", help2);
	printf("help3: %s\n", help3);
	printf("help4: %s\n", help4);
	printf("help5: %s\n", help5);
	printf("--> 주어진 포인터 값을 따라가면 나오는 문자열을 출력\n\n");

	// %c는 주어진 값을 char 형식 값으로 간주하고, 그 숫자에 대한 문자 표현을 출력할 때 사용합니다.
	printf("%%c로 출력하기:\n");
	printf("help1[3]: %c\n", help1[3]);
	printf("help2[3]: %c\n", help2[3]);
	printf("help3[3]: %c\n", help3[3]);
	printf("help4[3]: %c\n", help4[3]);
	printf("help5[3]: %c\n", help5[3]);
	printf("--> 주어진 값을 char 형식 값으로 간주하여, 그 숫자에 대한 문자 표현을 출력\n\n");
}


void func2()
{
	// %p는 주어진 값 자체를 위치 값으로 간주하여 좀 더 보기 쉽게 출력할 때 사용합니다.
	printf("%%p로 출력하기:\n");
	printf("help1: %p\n", help1);
	printf("help2: %p\n", help2);
	printf("help3: %p\n", help3);
	printf("help4: %p\n", help4);
	printf("help5: %p\n", help5);
	printf("\n");

	printf("&help1: %p\n", &help1);
	printf("&help2: %p\n", &help2);
	printf("&help3: %p\n", &help3);
	printf("&help4: %p\n", &help4);
	printf("&help5: %p\n", &help5);
	printf("--> ( func2()에 있는 주석 참조 )\n");

	/*
		Python에서 변경 가능성 이야기할 때 구경해 보았듯,
		어차피 동일한 내용을 갖는 문자열들을 메모리에 하나만 올려 놓고 공유해서 쓰게 하는 것은 나름의 이점이 있습니다.
		C 컴파일러 및 운영체제들도 보통은 이런 이점을 챙겨 놓는 편이에요.

		그 때 그랬듯 C에서도,
		문자 5개짜리 문자열인 "HELP"(마지막에 달리는 \0 포함)를 미리 메모리 어딘가에 살짝 따로 담아 놓고
		수식 "HELP" 자체는 '몰래 담아 둔 그 위치'를 의미하는 포인터 상수 값이 나오록 만들어버립니다.
		그래서 우리 표준 환경 기준으로는 포인터 변수 help1, help2, help3에 모두 동일한 포인터 값이 담긴 것으로 보이지요.
		(GCC나 구버전 VS는 안 그럴지도 몰라용)

		뭐, 그 셋 모두 동일한 위치에 있는 char 5칸짜리 배열 { 'H', 'E', 'L', 'P', '\0' }을 가리키고 있지만,
		어쨋든 모두 서로 다른 이름의 서로 다른 포인터 변수기 때문에 &help1, &help2, &help3의 계산 결과는 모두 다르게 나오고 있습니다.

		반면, 포인터 변수와 달리 배열은 명백히 '이 이름에 대해 사용 가능한 여러 칸 확보하기'가 목표입니다.
		따라서 help4, help5의 경우 initializer 자리에 "HELP"를 적었다 하더라도 C 컴파일러는 이를 그냥 { 'H', 'E', 'L', 'P', '\0' }와 같은 느낌으로 간주해 버립니다.
		( help4, help5를 char 5칸짜리 배열로 간주 + 각 칸을 해당 숫자들로 initialize )
	*/
}


void func3()
{
	/*
		현재,
		help1의 형식은 const char *
		help2의 형식은 const char *const
		help3의 형식은       char *
		help4의 형식은       char [5]
		help5의 형식은 const char [5]
		...로 선언되어 있습니다.

		이 상태에서 아래 다섯 줄의 주석을 하나씩 풀어서
		'이 포인터가 가리키는 위치 기준 오른쪽 3번째 칸'의 값을 바꾸려 시도해 보면,
		help1, help2, help5는 거의 즉시 빨간 줄이 그어지고,
		help3는 일단 실행은 되지만 중간에 터질 것이고,
		help4만 그런거 없이 잘 실행되는 것을 구경할 수 있습니다.

		선언을 잘 읽어 보면, 왜 이런 차이가 발생하는지 감을 잡을 수 있을 것입니다.

		hint: "HELP"를 몰래 적어 둔 위치는 '변경 불가능'을 상정하는 위치고,
			  const specifier는 C 코드 상에서 이 이름을 가지고 specifier에 명시된 형식 값(여기서는 char 값)을 변경할 수 없게 만드는 친구입니다.
	*/

	//help1[3] = 'L';
	//help2[3] = 'L';
	//help3[3] = 'L';
	//help4[3] = 'L';
	//help5[3] = 'L';

	printf("help1: %s\n", help1);
	printf("help2: %s\n", help2);
	printf("help3: %s\n", help3);
	printf("help4: %s\n", help4);
	printf("help5: %s\n", help5);
}


void func4()
{
	/*
		현재,
		help1의 형식은 const char *
		help2의 형식은 const char *const
		help3의 형식은       char *
		help4의 형식은       char [5]
		help5의 형식은 const char [5]
		...로 선언되어 있습니다.

		이 상태에서 아래 다섯 줄의 주석을 하나씩 풀어서
		'이 이름 자체에 대해 정의된 칸'의 값을 바꾸려 시도해 보면,
		...이번에는 아까랑 빨간 줄의 위치가 조금 다른 것을 구경할 수 있습니다.

		help4와 help5는... = 연산자가 무엇인지 되짚어 보면 이해할 수 있을 것이고,
		help1과 help2의 차이점을 눈여겨 본다면, help2처럼 포인터 변수를 선언했을 때의 효과를 유추할 수 있을 것입니다!
	*/

	help4[3] = 'L';

	//help1 = help4;
	//help2 = help4;
	//help3 = help4;
	//help4 = help4;
	//help5 = help4;

	printf("help1: %s\n", help1);
	printf("help2: %s\n", help2);
	printf("help3: %s\n", help3);
	printf("help4: %s\n", help4);
	printf("help5: %s\n", help5);
}


void func5()
{
	int number = 3;
	
	// 일부러 띄어쓰기나 specifier 나열 순서를 요상하게 적어 놨어요. 미안해요.
	int       *       m_mptr = &number;
	int       * const m_cptr = &number;
	int const *       c_mptr = &number;
	int const * const c_cptr = &number;


	int *const* m_mcptr = &m_mptr;
	int **const m_cmptr = &m_mptr;


	// func3()의 결과에 따르면 아래와 같이 오류 여부가 결정될 거예요:
	*m_mptr = 3;
	*m_cptr = 3;
	//*c_mptr = 3;
	//*c_cptr = 3;

	// -> const specifier는, specifier 자리에 적어 둔 그 형식 값을 이 이름으로 변경할 수 없게 만들어요.



	// func4()의 결과에 따르면 아래와 같이 오류 여부가 결정될 거예요:
	m_mptr = &number;
	//m_cptr = &number;
	c_mptr = &number;
	//c_cptr = &number;

	// -> 비슷한 느낌으로, 이 선언에 의하면 이 이름으로 *const 값을 변경할 수 없어요.



	// 물론, 선언의 declarator에 여러 *, *const들이 혼재되어 있을 때도 위 규칙은 그 순간순간에 대해서만 적용돼요.
	m_mcptr = m_mcptr;     // 수식 m_mcptr의 형식은 int *const * 이라 '가장 먼저 읽을 요소에 const가 없어서' 가능
	//m_cmptr = m_cmptr;   // 수식 m_mcptr의 형식은 int * *const   라 '가장 먼저 읽을 요소에 const가 있어서' 불가능

	//*m_mcptr = *m_mcptr; // 수식 *m_mcptr의 형식은 int *const   라 '가장 먼저 읽을 요소에 const가 있어서' 불가능
	*m_cmptr = *m_cmptr;   // 수식 *m_cmptr의 형식은 int *      이라 '가장 먼저 읽을 요소에 const가 없어서' 가능


	/*
		당연하지만, '가장 먼저 읽을 요소'가 [ ]이거나 ( )일 때도
		결과적으로 '그 값'이 특정되지 않으므로 = 연산자 좌항 자리에 적을 수 없어요.

		그래서 의미 관점에서는 int [3] 형식은 int *이 아닌 int *const 형식으로 deduce된다고 여겨도 틀린 말이 아니게 돼요.
		그래서 의미 관점에서는 int () 형식은 int (*)()이 아닌 int (*const)() 형식으로 deduce된다고 여겨도 틀린 말이 아니게 돼요.
		- 물론 이 두 deduction이 진짜로 일어나는 것은 아니에요. '어차피 변경 불가능'한 무언가에 굳이 const를 더 붙이진 않도록 설계되어 있어요.
	*/
}

