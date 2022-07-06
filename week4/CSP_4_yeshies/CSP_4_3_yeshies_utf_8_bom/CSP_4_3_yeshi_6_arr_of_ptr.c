/*
	'수식으로써 적은' 포인터 변수, 배열, 함수 이름이
	C 컴파일러에 의해 어떻게 deduce될 수 있는지 확인하기 위한 예시들이에요.

	이번에는 세 가지 요소, *, [], ()를 한데 섞은 이름을 선언해 둔 다음 활용하는 예시가 적혀 있습니다.

	오늘 보았던 여러 예시들을 돌이켜 생각해 보면,
	아래에 있는 funcs가 정확히 무엇인지,
	main()에서 하는 일이 정확히 무엇인지,
	그리고 이 프로그램이 대충 어떻게 실행되고 있는건지 얼추 파악할 수 있을 것입니다.
*/
 
#include <stdio.h>

int func0(), func1(), func2(), func3();

// [] -> * -> () -> int 순으로 읽혀요!
int(*funcs[])() = { func0, func1, func2, func3 };

int state = 0;


// 이 아래에 있는 이름들은 프로그램 내부에서 쓰여요
int weight = 50;
char buffer[64];

int main()
{
	while ( state != -1 )
		state = funcs[state]();

	return 0;
}

int func0()
{
	printf("--- 메뉴 ---\n"
		   "1. 먹기\n"
		   "2. 그만 두기\n"
		   "선택하세요>");

	scanf("%s", buffer);

	if ( buffer[0] == '1' )
		return 1;

	if ( buffer[0] == '2' )
		return 2;

	return 3;
}

int func1()
{
	printf("먹었습니다.\n");

	weight += 10;

	if ( weight > 200 )
	{
		printf("당신은 너무 많이 먹어서 배가 터져 죽었습니다.\n");
		return -1;
	}

	printf("현재 체중은 %dkg입니다.\n"
		   "1. 더 먹기\n"
		   "2. 그만 두기\n"
		   "선택하세요>", weight);

	scanf("%s", buffer);

	if ( buffer[0] == '1' )
		return 1;

	if ( buffer[0] == '2' )
		return 2;

	return 3;
}

int func2()
{
	if ( weight == 50 )
		printf("당신은 현명하게도 아무 것도 먹지 않는 것을 선택했습니다.\n");
	else
		printf("당신은 현명하게도 더 이상 먹지 않는 것을 선택했습니다.\n");

	return -1;
}

int func3()
{
	printf("잘못 누르셨습니다.\n");

	return 0;
}