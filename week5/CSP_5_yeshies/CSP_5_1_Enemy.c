#include <stdlib.h>
#include <time.h>

static char name[] = "적절한 상대";

static int stat[] = { 100, 0, 0, 0, 0, 0 };

static int isFirstRoll = 1;

// 능력치를 새로 뽑습니다.
void Reroll()
{
	int idx;
	int stat_toDistribute;

	if ( isFirstRoll )
	{
		srand(time(0));
		isFirstRoll = 0;
	}

	// 능력치 분배 방법들 중 그럭저럭 간단한 것을 적용했어요.
	stat_toDistribute = 100;

	for ( idx = 0; idx < 6; ++idx )
	{
		stat[idx] = rand() % (stat_toDistribute + 1);
		stat_toDistribute -= stat[idx];
	}

	/*
		TODO 목표#5: 능력치 분배 '우선 순위' 커스터마이즈 방법 모색해 보기

		현재 적용되어 있는 분배 방법은 힘 능력치가 높게 나올 확률이 상대적으로 높습니다.
		이 대신 '여러분이 좋아하는 능력치'가 높게 나올 확률을 높이는 방안을 한 번 생각해 보세요.
	*/
}

const char *GetNameOf_Enemy()
{
	return name;
}

const int *GetStatOf_Enemy()
{
	return stat;
}

