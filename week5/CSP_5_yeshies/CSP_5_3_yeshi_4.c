#include <stdio.h>

// stdlib.h에 선언되어 있는 malloc()과 free()를 쓸 예정이에요.
#include <stdlib.h>


struct Stat
{
	int str;
	int dex;
	int con;
};

int main()
{
	while ( 1 )
	{
		double *p_rate;
		struct Stat *p_stat;

		// p_rate를 통해 사용 가능한 double 한 칸 잡기
		p_rate = malloc(sizeof(double));

		// p_stat을 통해 사용 가능한 struct Stat 한 칸 잡기
		p_stat = malloc(sizeof(struct Stat));


		*p_rate = 3.0;

		// Note. 수식 p_stat->str은 수식 (*p_stat).str과 동일해요
		p_stat->str = 30;
		p_stat->dex = 50;
		p_stat->con = 20;


		printf("p_rate: %p | *p_rate: %f\n", p_rate, *p_rate);
		printf("p_stat: %p | *p_stat: (%d, %d, %d)\n", p_stat, p_stat->str, p_stat->dex, p_stat->con);

		free(p_rate);
		free(p_stat);

		getchar();
	}

	return 0;
}