/*
	TODO 목표#1: '내 캐릭터' 설정
	
	진행 방법:

	1. '내 캐릭터'의 이름을 정해 주세요.

	2. 이 파일의 이름을, 방금 정한 내 캐릭터의 이름이 들어 있도록 변경해 주세요.
	   (솔루션 탐색기에서 변경해도 돼요)

	3. Internal 배열 name 선언의 initializer 부분을, 방금 정한 내 캐릭터 이름이 반영되도록 변경해 주세요.

	4. Internal 배열 stat 선언의 initializer 부분을, 내 캐릭터의 성격에 걸맞는 능력치 숫자들이 배열에 담길 수 있도록 변경해 주세요.
*/


static const char name[] = "[Enter Your Name]";

// 능력치는 맨 앞부터 각각 STR, DEX, CON, INT, WIS, CHA를 의미해요.
// 능력치의 총합은 100이어야 해요.
static int stat[] = { 0, 0, 0, 0, 0, 100 };


const char *GetNameOf_YourName()
{
	return name;
}


const int *GetStatOf_YourName()
{
	return stat;
}

