#include <stdio.h>

/*
	TODO 목표#2: main.c에서 사용할 이름 수정

	여기 보이는 함수 선언의 함수 이름, 함수 포인터 변수의 initializer 자리에 적힌 함수 이름을
	
	방금 여러분의 .c 파일에서 새로 정한 그 함수들의 이름과 같도록 고쳐 주세요. (복붙해 와요)
*/
const char *GetNameOf_YourName();
const int *GetStatOf_YourName();

const char *(*const GetNameOf_Me)() = GetNameOf_YourName;
const int *(*const GetStatOf_Me)() = GetStatOf_YourName;



/*
	두 캐릭터의 대결(능력치 비교)을 통해 승자를 결정하는 함수입니다.

	Return값:
		- 음수: 왼쪽 캐릭터가 이김
		- 0: 비김
		- 양수: 오른쪽 캐릭터가 이김
*/
int Duel(const int *stat_left, const int *stat_right)
{
	/*
		TODO 목표#3: '항상' 여러분의 캐릭터가 이기도록 Duel() 정의 내용물 구성

		- 여러분의 캐릭터는 왼쪽에 있을 수도, 오른쪽에 있을 수도 있습니다.
		
		- 양 쪽 모두 여러분의 캐릭터가 아닐 수도 있습니다.
		  > 두 캐릭터의 능력치가 다르다면 어느 한 쪽이 이겨야 해요.
		    이 때 왼쪽 캐릭터가 이겼다면, 좌/우를 바꾸어 다시 대결했을 땐 오른쪽 캐릭터가 이겨야 해요

		- 양 쪽 캐릭터의 능력치가 동일한 경우 비겨야 해요.
	*/

	return 0;
}




const char *GetNameOf_MasterLee();
const int *GetStatOf_MasterLee();

const char *GetNameOf_Enemy();
const int *GetStatOf_Enemy();
void Reroll();

void Mk1();
void Mk2();
void Mk3();

int main()
{
	/*
		TODO 목표#4: 테스트 Mk. 1, 2, 3
		
		우선 '마스터 이' 캐릭터와 대결을 수행하여 결과를 출력하는 Mk1()을 호출하면서
		항상 여러분의 캐릭터가 이기는지 여부를 확인해 보세요.

		그 다음, 임의의 캐릭터를 만들어 가며 내 캐릭터와의 대결을 수행하고 그 결과를 출력하는 Mk2()를 호출하면서
		역시나 항상 여러분의 캐릭터가 이기는지 여부를 확인해 보세요.

		마지막으로, 임의의 캐릭터를 두 개씩 만들어 가며 대결을 수행하고 그 결과를 출력하는 Mk3()를 호출하면서
		여러분의 Duel()이 일관적으로 대결을 수행하고 있는지 여부를 확인해 보세요.
	*/

	Mk1();
	//Mk2();
	//Mk3();
	
	return 0;
}

void Mk1()
{
	int result;

	printf("테스트 Mk. 1\n");

	// 나 vs 마스터 이
	printf("\n%s vs %s\n", GetNameOf_Me(), GetNameOf_MasterLee());
	result = Duel(GetStatOf_Me(), GetStatOf_MasterLee());

	if ( result < 0 )
		printf("%s의 승리!\n", GetNameOf_Me());
	else if ( result == 0 )
		printf("비김...\n");
	else
		printf("%s의 패배...\n", GetNameOf_Me());

	// 마스터 이 vs 나
	printf("\n%s vs %s\n", GetNameOf_MasterLee(), GetNameOf_Me());
	result = Duel(GetStatOf_MasterLee(), GetStatOf_Me());

	if ( result < 0 )
		printf("%s의 패배...\n", GetNameOf_Me());
	else if ( result == 0 )
		printf("비김...\n");
	else
		printf("%s의 승리!\n", GetNameOf_Me());

	// 나 vs 나
	printf("\n%s vs %s\n", GetNameOf_Me(), GetNameOf_Me());
	result = Duel(GetStatOf_Me(), GetStatOf_Me());

	if ( result < 0 )
		printf("왼쪽 %s이(가) 이겨버림...\n", GetNameOf_Me());
	else if ( result == 0 )
		printf("비김!\n");
	else
		printf("오른쪽 %s이(가) 이겨버림...\n", GetNameOf_Me());
}


void Mk2()
{
	int count;
	int result;

	for ( count = 0; count < 10; ++count )
	{
		Reroll();

		printf("\n\n%d번째 상대: [%d, %d, %d, %d, %d, %d]\n",
			count,
			GetStatOf_Enemy()[0],
			GetStatOf_Enemy()[1],
			GetStatOf_Enemy()[2],
			GetStatOf_Enemy()[3],
			GetStatOf_Enemy()[4],
			GetStatOf_Enemy()[5]);


		// 나 vs 적절한 상대
		printf("\n%s vs %s\n", GetNameOf_Me(), GetNameOf_Enemy());
		result = Duel(GetStatOf_Me(), GetNameOf_Enemy());

		if ( result < 0 )
			printf("%s의 승리!\n", GetNameOf_Me());
		else if ( result == 0 )
		{
			printf("비김... 테스트 실패.\n");
			return;
		}
		else
		{
			printf("%s의 패배... 테스트 실패.\n", GetNameOf_Me());
			return;
		}


		// 적절한 상대 vs 나
		printf("\n%s vs %s\n", GetNameOf_Enemy(), GetNameOf_Me());
		result = Duel(GetNameOf_Enemy(), GetStatOf_Me());

		if ( result < 0 )
		{
			printf("%s의 패배...\n", GetNameOf_Me());
			return;
		}
		else if ( result == 0 )
		{
			printf("비김...\n");
			return;
		}
		else
			printf("%s의 승리!\n", GetNameOf_Me());
	}

	printf("테스트 성공!\n");
}


void Mk3()
{
	int stat_left[6];
	int stat_right[6];

	int count;
	int idx;
	int result0, result1;

	for ( count = 0; count < 100; ++count )
	{
		// 왼쪽 캐릭터 능력치 뽑아 복사
		Reroll();
		for ( idx = 0; idx < 6; ++idx )
			stat_left[idx] = GetStatOf_Enemy()[idx];

		// 오른쪽 캐릭터 능력치 뽑아 복사
		Reroll();
		for ( idx = 0; idx < 6; ++idx )
			stat_right[idx] = GetStatOf_Enemy()[idx];



		printf("%d번째 대결: [%d, %d, %d, %d, %d, %d] vs [%d, %d, %d, %d, %d, %d] -> ",
			count,
			stat_left[0],
			stat_left[1],
			stat_left[2],
			stat_left[3],
			stat_left[4],
			stat_left[5],
			stat_right[0],
			stat_right[1],
			stat_right[2],
			stat_right[3],
			stat_right[4],
			stat_right[5]);


		result0 = Duel(stat_left, stat_right);
		result1 = Duel(stat_right, stat_left);

		if ( result0 < 0 && result1 > 0 )
			printf("왼쪽 캐릭터 승!\n");
		else if ( result0 > 0 && result1 < 0 )
			printf("오른쪽 캐릭터 승!\n");
		else if ( result0 == 0 && result1 == 0 )
		{
			if ( stat_left[0] == stat_right[0] && 
				stat_left[1] == stat_right[1] && 
				stat_left[2] == stat_right[2] && 
				stat_left[3] == stat_right[3] && 
				stat_left[4] == stat_right[4] && 
				stat_left[5] == stat_right[5] )
				printf("비김!\n");
			else
			{
				printf("능력치가 다른데 비겨버림...\n");
				return;
			}
		}
		else
		{
			printf("결과가 일관적이지 않음...\n");
			return;
		}
	}

	printf("테스트 성공!\n");
}