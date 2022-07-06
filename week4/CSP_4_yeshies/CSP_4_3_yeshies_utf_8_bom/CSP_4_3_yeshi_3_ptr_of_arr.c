/*
	'수식으로써 적은' 포인터 변수, 배열, 함수 이름이
	C 컴파일러에 의해 어떻게 deduce될 수 있는지 확인하기 위한 예시들이에요.

	이 파일에서는
	'4칸짜리 배열' 하나의 위치를 나타내는 포인터 형식을 다루는 양상을 확인하면서
	배열 형식과 포인터 형식 사이의 유착 관계를 다시 한 번 정리해 봐요
*/
 
#include <stdio.h>

void Init_Matrix(int[][4]);

void Print_Matrix(int(*)[4]);

int main()
{
	// main()의 내용은 이전 예제와 동일해요.
	int matrix[3][4];

	Init_Matrix(matrix);
	Print_Matrix(matrix);

	return 0;
}

// 'int 배열'의 배열을 받아서 안에 숫자를 적당히 담아 주는 함수입니다?
void Init_Matrix(int m[][4])
{
	void Init_Matrix_Row(int[]);

	Init_Matrix_Row(m[0]);
	Init_Matrix_Row(m[1]);
	Init_Matrix_Row(m[2]);
}

// int 배열을 받아서 안에 숫자를 적당히 담아 주는 함수입니다?
void Init_Matrix_Row(int row[])
{
	row[0] = 0;
	row[1] = 1;
	row[2] = 2;
	row[3] = 3;
}

// 'int 배열'의 배열의 내용을, 위치 값을 포함하여 까만 창에 출력해 주는 함수입니다?
void Print_Matrix(int (*m)[4])
{
	void Print_Matrix_Row(int[]);

	Print_Matrix_Row(*m);
	Print_Matrix_Row(*(m + 1));
	Print_Matrix_Row(*(m + 2));
}

// int 배열의 각 칸의 숫자들을 화면에 출력해 주는 함수입니다?
void Print_Matrix_Row(int row[])
{
	printf("%d(at %p) %d(at %p) %d(at %p) %d(at %p) \n", row[0], row, row[1], row + 1, row[2], row + 2, row[3], row + 3);
}

/*
	1. 포인터 값은 단순한 '위치 값'이 아니라 '특정 한 칸에 대한 위치 값'입니다.
	   따라서 포인터 변수를 실제로 선언 및 사용하려 할 때는 '무슨 형식 한 칸'인지 정확히 짚어 줄 필요가 있습니다.


	2. 배열을 선언/정의할 때 우리가 정할 수 있는 것은...
		- 몇 칸 짜리인지
		- 그 칸 하나에 무엇을 담을 수 있는지
	   ...입니다.

	   이 때, int 4칸짜리 배열과 int 5칸짜리 배열은 서로 다른 형식으로 취급됩니다.
	   ( '배열들의 나열'에서 '다음 배열'의 위치가 int 기준 4칸 뒤가 될 지 5칸 뒤가 될 지가 서로 달라요 )


	3. 따라서, 배열 하나에 대한 포인터 변수/인수를 선언할 때는
	   그 포인터 따라가면 얼마나 큰, 각 칸에 무슨 형식 들어가는 배열이 나올 것인지를 정확하게 적어 주어야만 합니다.


	4. 마지막으로, 선언 읽는 규칙에 따르면,
	   int *m[4]; 으로 적어 버리면 'int를 가리키는 포인터 4칸'짜리 배열이 되어 버립니다.
	   그래서 여기선 반드시 괄호를 써서 int (*m)[4];로 적어서 'int 4칸짜리 배열' 하나를 가리키는 포인터 변수로 만들어야 합니다!
	   (이런 규칙이 불편하기 때문에 인수 선언 자리에 int m[][4]와 같이 적어도 알아서 int (*m)[4]로 간주하도록 배려해 두었다고 생각해도 될 듯)
*/