#include <iostream>


// TODO#1 일단 바로 녹색 화살표 눌러볼 예정이에요.
void func(int arg) { std::cout << "func(int) 호출됨!" << std::endl; }
void func(const int arg) { std::cout << "func(const int) 호출됨?!" << std::endl; }

void func(int &arg) { std::cout << "func(int &) 호출됨!" << std::endl; }
void func(const int &arg) { std::cout << "func(const int &) 호출됨!" << std::endl; }

void func(int &&arg) { std::cout << "func(int &&) 호출됨!" << std::endl; }
void func(const int &&arg) { std::cout << "func(const int &&) 호출됨!" << std::endl; }

int main()
{
	int origin{ 3 };
	const int corigin{ 3 };

	// TODO#2 아래 세 선언의 initializer 자리를 고쳐 적어 보면서 언제 오류가 나고 언제 안 나는지 확인해 봐요.
	int number{ origin };
	int &ref{ origin };
	int &&rref{ 3 };

	// TODO#3 아래 세 선언의 initializer 자리를 고쳐 적어 보면서 언제 오류가 나고 언제 안 나는지 확인해 봐요.
	const int cnumber{ corigin };
	const int &cref{ corigin };
	const int &&crref{ 3 };


	// TODO#4 여기에 func() 호출식을 적어볼 예정이에요!


	return 0;
}