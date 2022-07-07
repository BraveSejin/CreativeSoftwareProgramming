#include <stdio.h>

// 사용할 총 Data의 크기에 따라 여기를 살짝 고쳐 주세요.
#define SIZE_DATA 4096

// 나중에 칸을 마련하기 위해 큰 공간을 미리 정의해 두기 위한 선언이에요.
int data[SIZE_DATA];

int main()
{
	/*
		칸 사용 계획
			data[0]: 입력받은 수
			data[1]: 현재까지 받은 수들의 합
	*/

	// 반복 준비: 첫 입력받기가 가능하도록 이상한 값을 넣어 둠
	data[0] = -1;

	// 반복 준비: 아직 입력받은 게 없으니 합을 0으로 둠
	data[1] = 0;

	// 반복 종료 조건: 방금 0을 입력받았다면 종료
	while ( data[0] != 0 )
	{
		// 숫자 하나 받기
		data[0] = 0;
		printf("Enter a number>");
		scanf("%d", &data[0]);

		// 다음 반복 준비: 방금 하나를 입력받았으므로 그 수를 더함
		data[1] += data[0];
	}

	printf("Sum: %d\n", data[1]);

	return 0;
}