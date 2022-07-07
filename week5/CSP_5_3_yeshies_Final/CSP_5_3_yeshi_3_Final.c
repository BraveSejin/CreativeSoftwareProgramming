#include <stdio.h>

// 사용할 Data의 크기에 따라 여기를 살짝 고쳐 주세요.
#define SIZE_DATA 16384

// 나중에 칸을 마련하기 위해 큰 공간을 미리 정의해 두기 위한 선언이에요.
char data[SIZE_DATA];

// 각 공간이 현재 사용중인지 여부를 표시해 두기 위한 배열 선언이에요.
// 0: 사용 가능
// 그 외: 사용중(Object 크기 값을 적어요)
int flags[SIZE_DATA];



// size만큼의 크기를 갖는 새 공간을 할당하고 그 시작(기준) 위치 값을 return해요.
void *Alloc(int size)
{
	// data 안을 좌우로 돌아다니기 위한 변수
	int idx;

	// 찾은 빈 공간 수를 카운트하기 위한 변수
	int count = 0;



	// 사용 가능한 size만큼의 공간 찾기 -> 찾았다면 바로 표시 후 return
	for ( idx = 0; idx < SIZE_DATA - size; ++idx )
	{
		if ( flags[idx] == 0 )
		{
			++count;

			if ( count == size )
			{
				while ( count )
				{
					flags[idx] = size;
					--idx;
					--count;
				}

				++idx;

				printf("Alloc(): %dB allocated at %p ( &data[%d] )\n", size, &data[idx], idx);
				return &data[idx];
			}
		}
		else
		{
			count = 0;
		}
	}

	// 찾기에 실패했다면 오류 메시지 출력 후 0 return
	printf("Error: Out of memory.\n");

	return 0;
}

// 사용이 끝난 공간을 반납받아요.
void Free(void *ptr)
{
	// data 안 좌우로 돌아다니기 위한 변수
	int idx;

	// 반납받은 칸의 크기(flags에 담아 둔 값을 통해 유추)
	int size;

	// flag 초기화에 사용할 변수
	int count = 0;



	// ptr 값을 토대로 idx, size 확인하기
	idx = (char *)ptr - data;
	size = flags[idx];

	// 해당 공간에 대한 flag들 초기화하기(0으로 만듦)
	for ( count = 0; count < size; ++count )
	{
		flags[idx] = 0;
		++idx;
	}

	printf("Free(): %dB freed at %p ( &data[%d] )\n", size, ptr, idx - size);
}


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
		p_rate = Alloc(sizeof(double));

		// p_stat을 통해 사용 가능한 struct Stat 한 칸 잡기
		p_stat = Alloc(sizeof(struct Stat));


		*p_rate = 3.0;

		// Note. 수식 p_stat->str은 수식 (*p_stat).str과 동일해요
		p_stat->str = 30;
		p_stat->dex = 50;
		p_stat->con = 20;


		printf("p_rate: %p | *p_rate: %f\n", p_rate, *p_rate);
		printf("p_stat: %p | *p_stat: (%d, %d, %d)\n", p_stat, p_stat->str, p_stat->dex, p_stat->con);

		//Free(p_rate);
		//Free(p_stat);

		printf("Press enter to continue>");
		scanf("%*c");
	}

	return 0;
}