/*
	'수식으로써 적은' 포인터 변수, 배열, 함수 이름이
	C 컴파일러에 의해 어떻게 deduce될 수 있는지 확인하기 위한 예시들이에요.

	이 파일에서는 '배열의 배열' 형식을 다룰 때의 deduce 양상을 예상해 봐요.
	(세부 설명은 다음 파일에서 ㄱㄱ할 듯)

	실행 결과를 관찰한 다음 각 함수들의 내용을 잘 보고,
	파일 맨 아래에 있는 질문에 답해 보세요.
*/
 
#include <stdio.h>

void Init_Matrix(int[3][4]);

void Print_Matrix(int[][4]);

int main()
{
	/*
		선언 읽는 법:
		1. 이름을 중심에 두고 안에서 밖으로
		2. 괄호 먼저
		3. 오른쪽 먼저

		따라서 matrix는...
			- 3칸짜리인데, 각 칸이...
				- 4칸짜리인데, 각 칸이...
					- int 값 하나 담을 만한 크기
				...인 배열
			...인 배열
		...이 됩니다!
	*/
	int matrix[3][4];

	Init_Matrix(matrix);
	Print_Matrix(matrix);

	return 0;
}

// 3x4 배열을 받아서 안에 숫자를 적당히 담아 주는 함수입니다?
void Init_Matrix(int m[3][4])
{
	int row;
	int column;

	for ( row = 0; row < 3; row++ )
		for ( column = 0; column < 4; column++ )
			m[row][column] = row + column + 1;
}

// ?x4 배열의 내용을, 위치 값을 포함하여 까만 창에 출력해 주는 함수입니다?
void Print_Matrix(int m[][4])
{
	int row;
	int column;

	for ( row = 0; row < 3; row++ )
	{
		for ( column = 0; column < 4; column++ )
		{
			printf("%d(at %p) ", m[row][column], &m[row][column]);
		}
		printf("\n");
	}
}


/*
	Q. 위에 있는 함수들은 그 선언/정의를 보면

	void Init_Matrix(int[3][4])
	void Print_Matrix(int[][4])

	...와 같이 적혀 있습니다.

	여기서 인수의 형식을 int[][]와 같이 적어버리면 즉시 오류가 나는 것을 볼 수 있습니다.
	-> 심지어 함수 정의가 아니라 함수 선언을 이렇게 적어도 오류가 납니다.

	왜 이런 걸까요?

	Hint: 현재 m[0][0]과 m[1][0]의 위치 값은 서로 int 기준 '4'칸 만큼 차이나는 것을 구경할 수 있어요.
*/