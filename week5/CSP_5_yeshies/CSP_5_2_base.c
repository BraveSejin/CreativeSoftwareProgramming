#include <stdio.h>

// 각 캐릭터별 힘 능력치를 나열하는 배열이에요.
int strs[4] = { 20, 30, 50, 60 };

// 각 캐릭터별 민첩성 능력치를 나열하는 배열이에요.
int dexs[4] = { 50, 20, 10, 30 };

// 각 캐릭터별 체력 능력치를 나열하는 배열이에요.
int cons[4] = { 30, 50, 40, 10 };

// 0등이 몇 번 캐릭터인지 등을 담기 위한 배열이에요.
// idxs_sorted[0]에는 0등 캐릭터의 번호를 담아야 해요.
int idxs_sorted[4] = { 0, 1, 2, 3 };


// 대결 자체를 의미하는 함수예요. 이번에는 능력치 배열이 아닌 캐릭터 번호(index)를 인수로 받고 있어요.
// left번 캐릭터가 이기면 음수, right번 캐릭터가 이기면 양수를 return하면 돼요(무승부는 고려 안 해도 돼요)
int Duel(int idx_left, int idx_right)
{
	// 지금은 무조건 left번 캐릭터가 이긴다고 적어 두었는데
	// 위의 배열 이름들을 써서 능력치 비교를 수행하도록 다시 적어 주세요
	return -1;
}


int main()
{
	/*
		위에 정의해 둔 Duel()을 재차 호출함으로써
		배열 idx_sorted의 각 자리에 적절한 캐릭터 번호들을 담아요.
	*/
	int idx_current;
	int idx_challenger;
	int result;

	/*
		목표: 0등, 1등, 2등, 3등이 누군지 순서대로 다 찾기
	*/

	// 일단 처음엔 0등을 찾으려는 중
	idx_current = 0;

	// 3등짜지 다 찾았을 때(4등을 찾으려 하고 있을 때)까지 진행
	while ( idx_current < 4 )
	{
		/*
			목표: 이번 등수(이하 n등)에 해당하는 캐릭터 찾기
				- 만약 누군가가 0등이라면 그 캐릭터는 1등 찾을 때는 전혀 고려하지 않아도 됨
				- n등 자리에 적혀 있는 번호의 캐릭터가 n등이 맞다고 가정해 두고, 이게 맞나 꾸준히 검증
					> 고려해야 할 캐릭터들끼리 대결을 진행하여, 가정이 깨질 때마다 n등 자리 캐릭터 번호를 교체
		*/

		// 일단 처음엔 바로 옆 자리에 적힌 캐릭터와 대결할 예정
		idx_challenger = idx_current + 1;

		// 모든 캐릭터들과 대결을 수행할 때까지 진행
		while ( idx_challenger < 4 )
		{
			// 이번 대결 진행
			result = Duel(idxs_sorted[idx_current], idxs_sorted[idx_challenger]);

			// 대결 결과 가정에 모순이 생기면 캐릭터 번호 교체
			if ( result > 0 )
			{
				// 초기 상태를 A | B 로 표기했을 때

				//         A ^ B | B
				idxs_sorted[idx_current] = idxs_sorted[idx_current] ^ idxs_sorted[idx_challenger];

				//         A ^ B | ( A ^ B ) ^ B --> A ^ B | A
				idxs_sorted[idx_challenger] = idxs_sorted[idx_current] ^ idxs_sorted[idx_challenger];

				// ( A ^ B ) ^ A | A             -->     B | A
				idxs_sorted[idx_current] = idxs_sorted[idx_current] ^ idxs_sorted[idx_challenger];
			}

			++idx_challenger;
		}

		// 검증이 끝나면 n등이 누군지 확실히 알게 됨!
		printf("%d등: %d번 캐릭터\n", idx_current, idxs_sorted[idx_current]);

		++idx_current;
	}


	return 0;
}

