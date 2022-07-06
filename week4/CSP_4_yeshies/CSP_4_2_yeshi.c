#include <stdio.h>

// 언제나 int 값 3을 return하는 함수예요.
int func()
{
	return 3;
}

int main()
{
	// number는 int 한 칸에 대한 이름이에요.
	int number = 3;

	// arr은 int 세 칸에 대한 이름이에요. 여기 적힌 이름 arr에 마우스 포인터 갖다 대 봐요.
	// (배열 선언의 initializer 부분을 이런 식으로 적을 수 있어요. 얘는 수식은 아님!)
	int arr[] = { 3, 3, 3 };

	// func는 뭐 이건 그냥 함수 이름이에요.
	int func();

	// 상수 값 3 자리에 5 담기
	3 = 5;

	// number 자리에 5 담기
	number = 5;

	// arr 자리에 5 담기
	arr = 5;

	// 'arr에 대한 여러 칸들 중 0번째 칸' 자리에 5 담기
	arr[0] = 5;

	// 함수 func 자리에 5 담기
	func = 5;

	// 함수 func의 return값 자리에 5 담기
	func() = 5;

	return 0;
}