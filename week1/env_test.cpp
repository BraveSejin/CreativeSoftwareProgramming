/*
	우리 수업용 환경 구축이 잘 되었는지 확인하기 위한 예시 코드 파일입니다.

	- 아직 아무 것도 안 배운 상태니 내용은 구경 안 해도 돼요(나중에 다시 나옴)

	- 자신의 환경에 이 코드를 복붙해 간 다음 컴파일->실행했을 때
	  콘솔 창에 3이 출력되면 성공이에요

	- 컴파일 오류가 나거나, 실행은 되는데 3이 아닌 0이 출력되고 있는 경우
	  강사 또는 NPC의 도움을 요청해 주세요
*/

#include <iostream>
#include <vector>
#include <algorithm>

consteval int Three()
{
	// return std::vector<int>{ 3 }[0];
    
    return std::vector<int>{ 3 }[0];
}

int main()
{
	constexpr int three = Three();

	std::cout << three << std::endl;

	return 0;
}
