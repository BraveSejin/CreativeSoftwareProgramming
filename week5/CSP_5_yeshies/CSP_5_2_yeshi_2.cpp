/*
	주의: 이 파일은 .cpp 파일이에요!
		  경우에 따라 컴파일러 설정을 C++용으로 바꾸어야 할 수 있어요.
		  (VS를 쓴다면 그냥 ㄱㄱ하면 돼요)

	혼동을 막기 위해 대부분의 코드는 C에서 썼던 그대로 사용했어요.
*/

#include <stdio.h>

struct StatType
{
	int str;
	int dex;
	int con;
};

// 마치 배열을 initialize하듯 구조체 변수 / 배열도 initialize할 수 있어요.
// (구조체 정의에 적어 둔 순서대로 각 멤버 자리에 들어가요)
struct StatType mystat = { 20, 50, 30 };

int main()
{
	// ':: 연산자'를 쓰기 위해 .cpp 파일로 만들어 두었어요.
	// 지금은 이 연산자 자체의 의미는 몰라도 돼요.
	// 아무튼 아래의 printf() 호출식은 각 멤버 이름에 대해 정의된 offset 값과 구조체 한 칸의 크기 값을 출력해요.
	// 출력 결과 및 멤버 선언을 토대로 각 멤버들이 구조체 한 칸 안에서 어느 부분에 위치하는지 파악할 수 있어요!
	printf("&str: %p\n"
		"&dex: %p\n"
		"&con: %p\n"
		"size: %p\n", &StatType::str, &StatType::dex, &StatType::con, sizeof mystat);

	printf("&mystat    : %p\n"
		"&mystat.str: %p\n"
		"&mystat.dex: %p\n"
		"&mystat.con: %p\n", &mystat, &mystat.str, &mystat.dex, &mystat.con);

	/*
		대충 확인해 보았다면,
		각 멤버 선언의 specifier를 조금씩 바꾸어 가며 offset 값이 어떻게 다르게 나오는지 확인해 보세요.

		초기 설정이 int - int - int였다면...

		int - int - double
		int - double - int
		int - char - int
		int - char - char

		...와 같이 바꾼 다음 다시 한 번 실행해 봐요.


		뭔가 오묘한 결과가 나온다면 정상이에요.
		컴파일러가 뭔가 힘을 써서 int 한 칸은 0, 4, 8, C 자리에 오도록, double 한 칸은 0, 8 자리에 오도록 노력하고 있을 거예요.
		(VS 설정에 따라 이런 노력을 덜 하거나 안 할 수도 있긴 해요)

		지난 수업 예시 구경할 때 항상 int 한 칸에 대한 위치 값 끝자리가 0, 4, 8, C(12) 중 하나였다는 점을 생각해 보면
		'이렇게 해 두는 게 더 편한가?' 하며 그러려니 할 수 있을 거예요.
		--> 실제로 이렇게 해 두는 게 (빈 공간이 생겨 조금 손해보긴 하지만) 더 빨라요!
	*/


	/*
		또 하나,

		방금 우리는 . 연산자(이항 연산자)와 & 연산자를 함께 사용해 보았어요.
		이 둘 중 어떤 연산자가 더 먼저 붙는지를 위 코드 및 실행 결과를 토대로 유추해 보고, (정답을 바로 알고 싶다면 수식에 괄호를 첨가해 봐요)
		수업 내용을 토대로 왜 그 연산자가 먼저 붙는 게 말이 되는지도 한 번 생각해 봐요.
	*/

	return 0;
}