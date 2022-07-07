/*
	이 예시 코드의 내용은 직접 실행하지 않아도 좋아요.
	수업자료에 있는 정도만 구경해 봐도 될 듯 해요.

	주의: Release 말고 Debug 모드로 되어 있나 확인해 주세요.
		  Release 모드일 때는 아무 명령어도 안 남는 게 정상임!
*/

int main()
{
	// static 위치를 갖는 int 변수
	static int static_number;

	// automatic 위치를 갖는 int 변수
	int automatic_number;

	// 함수(C에서는 항상 static 위치를 가짐)
	int func();

	// static 위치에 상수 0을 담음
	static_number = 0;

	// automatic 위치에 상수 0을 담음
	automatic_number = 0;

	// 함수 호출(F11을 누르면 노란 화살표가 함수 안으로 이동하는 것을 따라갈 수 있음)
	func();

	return 0;
}

int func()
{
	// automatic 위치를 갖는 int 변수
	int number;

	// automatic 위치에 상수 0을 담음
	number = 0;

	return number;
}
