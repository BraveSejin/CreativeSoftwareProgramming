#include <stdio.h>

// global 변수들(따라서 static 변수들)에 대한 선언
const char *spaces = "                                        ";
int depth = 0;

// n 번째 피보나치 수를 계산하여 return합니다.
int fib(int n)
{
	// local 변수 선언(정의) --> automatic 변수
	int result;

	// 사용하는 각 이름들에 대한 위치 값 출력 --> (S)는 static, (A)는 automatic
	// %.*s나 %p는 지금은 몰라도 돼용. 궁금하면 물어봐 주세요
	printf("%.*s|Calc-ing fib[%d]...\n",	depth * 4, spaces, n);
	printf("%.*s|(S)   &fib: %p\n",			depth * 4, spaces, &fib);
	printf("%.*s|(S) &depth: %p\n",			depth * 4, spaces, &depth);
	printf("%.*s|(A)     &n: %p\n",			depth * 4, spaces, &n);
	printf("%.*s|(A)&result: %p\n",			depth * 4, spaces, &result);
	
	// 피보나치 수열의 규칙에 따라 결과 계산
	if ( n < 3 )
	{
		result = 1;
	}
	else
	{
		depth = depth + 1;

		result = fib(n - 2) + fib(n - 1);

		depth = depth - 1;
	}

	// 어쨋든 원래 목표였던 피보나치 수 출력
	printf("%.*s|Done. fib[%d] is %d\n\n", depth * 4, spaces, n, result);

	return result;
}

int main()
{
	fib(5);
	return 0;
}