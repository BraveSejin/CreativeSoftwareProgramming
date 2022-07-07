#include <stdio.h>

// 사용할 Data의 크기에 따라 여기를 살짝 고쳐 주세요.
#define SIZE_DATA 16384

// 나중에 칸을 마련하기 위해 큰 공간을 미리 정의해 두기 위한 선언이에요.
char data[SIZE_DATA];


struct Stat
{
	int str;
	int dex;
	int con;
};

int main()
{
	double *p_rate;
	struct Stat *p_stat;

	// p_rate를 통해 사용 가능한 double 한 칸 잡기


	// p_stat을 통해 사용 가능한 struct Stat 한 칸 잡기




	*p_rate = 3.0;

	// Note. 수식 p_stat->str은 수식 (*p_stat).str과 동일해요
	p_stat->str = 30;
	p_stat->dex = 50;
	p_stat->con = 20;


	printf("p_rate: %p | *p_rate: %f\n", p_rate, *p_rate);
	printf("p_stat: %p | *p_stat: (%d, %d, %d)\n", p_stat, p_stat->str, p_stat->dex, p_stat->con);

	return 0;
}