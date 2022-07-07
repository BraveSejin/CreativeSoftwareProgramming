#include <stdio.h>

// 사용할 총 Data의 크기에 따라 여기를 살짝 고쳐 주세요.
#define SIZE_DATA 4096

// 나중에 칸을 마련하기 위해 큰 공간을 미리 정의해 두기 위한 선언이에요.
int data[SIZE_DATA];

void Fib(void)
{
	// x == 1 또는 x == 2면 Fib(x) = 1
	if ( data[data[1]] == 1 || data[data[1]] == 2 )
	{
		printf("Fib(%d): 1\n", data[data[1]]);
		data[data[1]] = 1;
		return;
	}

	// Fib(x - 1) 구하기 - base + 1이 다음 호출의 base가 되어야 하므로 base 값을 1만큼 조정
	data[data[1] + 1] = data[data[1]] - 1;
	++data[1];
	Fib();
	--data[1];

	// Fib(x - 2) 구하기 - base + 2가 다음 호출의 base가 되어야 하므로 base 값을 2만큼 조정
	data[data[1] + 2] = data[data[1]] - 2;
	data[1] += 2;
	Fib();
	data[1] -= 2;

	// Fib(x) = Fib(x + 1) + Fib(x + 2)
	printf("Fib(%d): %d\n", data[data[1]], data[data[1] + 1] + data[data[1] + 2]);
	data[data[1]] = data[data[1] + 1] + data[data[1] + 2];

	return;
}

int main()
{
	/*
		칸 사용 계획
			data[0]: n
			data[1]: base
			data[base]: x -> Fib(x)
			data[base + 1]: x - 1 -> Fib(x - 1)
			data[base + 2]: x - 2 -> Fib(x - 2)
	*/

	// 첫 호출의 base는 2
	data[1] = 2;

	printf("Enter a number>");
	scanf("%d", &data[0]);

	data[data[1]] = data[0];
	Fib();
	printf("Fib(%d): %d\n", data[0], data[data[1]]);

	return 0;
}