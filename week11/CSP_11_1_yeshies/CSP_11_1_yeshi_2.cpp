#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

/*
	유리수 값 하나를 다루기 위한 형식입니다.

	오늘은 덧셈 버전만 담아왔어요.
*/
struct RationalNumber
{

/*
	☆
	지난 시간에 본 내용을 이렇게 #if - #endif로 둘러 싸 두었어요.
	VS나 VS Code에서 '닫아 둘' 수 있을 거예요.
*/
#if 1
	inline static int count_normal_constructor_called = 0;
	inline static int count_copy_constructor_called = 0;
	inline static int count_move_constructor_called = 0;
	inline static int count_destructor_called_normal = 0;
	inline static int count_destructor_called_alreadyMoved = 0;

	bool isMoved = false;

	static void PrintCounts()
	{
		std::cout
			<< "     생성됨: " << count_normal_constructor_called << std::endl
			<< "복사 생성됨: " << count_copy_constructor_called << std::endl
			<< "이동 생성됨: " << count_move_constructor_called << std::endl
			<< "     파괴됨: " << count_destructor_called_normal << std::endl
			<< "이동-파괴됨: " << count_destructor_called_alreadyMoved << std::endl;
	}

	static void ClearCounts()
	{
		count_normal_constructor_called = 0;
		count_copy_constructor_called = 0;
		count_move_constructor_called = 0;
		count_destructor_called_normal = 0;
		count_destructor_called_alreadyMoved = 0;
	}

	/*
		Data 멤버 선언 부분
	*/

	// 유리수의 분자 값입니다.
	int boonja;

	// 유리수의 분모 값입니다.
	int boonmo;

	/*
		생성자, 파괴자 정의 부분
	*/

	// (추가됨) (0/1)을 의미하는 새로운 유리수 object를 initialize합니다.
	RationalNumber() : boonja{ 0 }, boonmo{ 1 }
	{
		// 여기선 약분 불필요

		std::cout << "유리수> RN()을 통해 생성되고 있어요! - this: " << this << std::endl;

		++count_normal_constructor_called;
	}

	// (추가됨) 지정된 값을 분자로써 갖는, 분모는 1인 새로운 유리수 object를 initialize합니다.
	RationalNumber(int number) : boonja{ number }, boonmo{ 1 }
	{
		// 여기선 약분 불필요

		std::cout << "유리수> RN(int)를 통해 생성되고 있어요! - this: " << this << ", n: " << number << std::endl;

		++count_normal_constructor_called;
	}

	// 지정된 분자, 분모 값을 갖는 새로운 유리수 object를 initialize합니다.
	RationalNumber(int boonja, int boonmo) : boonja{ boonja }, boonmo{ boonmo }
	{
		Yakboon();

		std::cout << "유리수> RN(int, int)를 통해 생성되고 있어요! - this: " << this << ", boonja: " << boonja << ", boonmo: " << boonmo << std::endl;

		++count_normal_constructor_called;
	}

	// '복사 생성자'입니다.
	RationalNumber(const RationalNumber &other) : boonja{ other.boonja }, boonmo{ other.boonmo }
	{
		std::cout << "유리수> RN(const RN &)를 통해 생성되고 있어요! - this: " << this << ", &other:" << &other << ", boonja: " << boonja << ", boonmo: " << boonmo << std::endl;

		++count_copy_constructor_called;
	}

	// '이동 생성자'입니다.
	RationalNumber(RationalNumber &&other) : boonja{ other.boonja }, boonmo{ other.boonmo }
	{
		other.isMoved = true;

		std::cout << "유리수> RN(RN &&)를 통해 생성되고 있어요! - this: " << this << ", &other:" << &other << ", boonja: " << boonja << ", boonmo: " << boonmo << std::endl;

		++count_move_constructor_called;
	}

	// 아무 일도 안 하는 파괴자입니다.
	~RationalNumber()
	{
		// '이동당한' object인지 여부에 따라 서로 다르게 카운트하고 있어요.
		if ( isMoved )
		{
			std::cout << "유리수> ~RN()을 통해 파괴되고 있어요. 근데 이미 뜯긴 몸이라 괜찮아요. - this: " << this << ", boonja: " << boonja << ", boonmo: " << boonmo << std::endl;

			++count_destructor_called_alreadyMoved;
		}
		else
		{
			std::cout << "유리수> ~RN()을 통해 파괴되고 있어요... - this: " << this << ", boonja: " << boonja << ", boonmo: " << boonmo << std::endl;

			++count_destructor_called_normal;
		}
	}

	/*
		Code 멤버 정의 부분
	*/

	// 이 유리수 object에 대한 std::string 형식 값을 얻습니다.
	operator std::string()
	{
		std::ostringstream os;

		// 분모가 1인 경우 분자 값만 적음
		if ( boonmo == 1 )
			os << '(' << boonja << ')';
		// 그렇지 않은 경우 분수 형태로 적음
		else
			os << '(' << boonja << '/' << boonmo << ')';

		return os.str();
	}

	// 이 유리수 object를 약분합니다.
	void Yakboon()
	{
		// 분자가 0이라면 분모를 1로 만들고 끝
		if ( boonja == 0 )
		{
			boonmo = 1;
			return;
		}

		// 분자, 분모의 최대공약수 구하기
		int numbers[2]{ boonja, boonmo };
		bool idx_greater = boonja < boonmo;

		static_assert(!0 == 1, "!0 != 1");

		while ( numbers[!idx_greater] != 0 )
		{
			numbers[idx_greater] %= numbers[!idx_greater];
			idx_greater = !idx_greater;
		}

		// 최대공약수는 numbers[idx_greater]에 있음 -> 분자, 분모를 최대공약수로 나눔
		boonja /= numbers[idx_greater];
		boonmo /= numbers[idx_greater];

		// 마지막으로, 분모가 음수라면 (-1/-1)을 곱함
		if ( boonmo < 0 )
		{
			boonja = -boonja;
			boonmo = -boonmo;
		}
	}

	/*
		출력용 친구 << 연산자 정의 부분
	*/
	friend std::ostream &operator <<(std::ostream &os, const RationalNumber &rhs)
	{
		if ( rhs.boonmo == 1 )
			os << '(' << rhs.boonja << ')';
		else
			os << '(' << rhs.boonja << '/' << rhs.boonmo << ')';

		return os;
	}


	/*
		object를 생성하기 위해 반자동 방식으로 칸을 형성하려 할 때 사용할 연산자들 정의 부분
		(이 아래에 정의된 네 연산자는 인수 형식 및 return값의 형식을 항상 이렇게 적게 돼요)
	*/
	void *operator new(size_t size)
	{
		void *result = std::malloc(size);

		std::cout << "시스템> 새 유리수 object를 위한 칸을 만들고 있어요! - size: " << size << ", result: " << result << std::endl;

		return result;
	}

	void operator delete(void *ptr)
	{
		std::cout << "시스템> 유리수 object의 마지막 숨통을 끊고 있어요... - ptr: " << ptr << std::endl;

		free(ptr);
	}

	void *operator new[](size_t size)
	{
		void *result = malloc(size);

		std::cout << "시스템> 새 유리수 object " << ((size - sizeof(size_t)) / sizeof(RationalNumber)) << "개를 위한 칸을 만들고 있어요! - size: " << size << ", result: " << result << std::endl;

		return result;
	}

	void operator delete[](void *ptr)
	{
		std::cout << "시스템> 유리수 object " << *(size_t *)ptr << "개의 마지막 숨통을 끊고 있어요... - ptr: " << ptr << std::endl;

		free(ptr);
	}
#endif
	/*
		+= 연산자는 기존 좌항 object를 그대로 return object로 삼을 수 있어요.
	*/
	RationalNumber &operator +=(const RationalNumber &rhs)
	{
		// 통분 불필요
		if ( boonmo == rhs.boonmo )
		{
			boonja += rhs.boonja;
		}
		// 통분 필요
		else
		{
			boonja = boonja * rhs.boonmo + rhs.boonja * boonmo;
			boonmo *= rhs.boonmo;
		}

		Yakboon();

		return *this;
	}

	RationalNumber &operator +=(RationalNumber &&rhs)
	{
		// rhs object는 이 중괄호 내용물을 실행하는 동안은 내 소유가 맞아요.
		// 따라서 아래 += 수식은 이 위에 정의된 버전의 += 연산자를 사용한 셈이 돼요.
		return *this += rhs;
	}

/*
	☆
	'선택적 컴파일' 기능을 적용해 두었어요.
	아래 #define directive를 주석으로 만들어버리면
	멤버 버전 연산자들을 대신 사용할 수 있게 돼요.
*/
#define USE_NONMEMBER_OPERATORS

#ifdef USE_NONMEMBER_OPERATORS
	/*
		비멤버 연산자 버전이에요.
	*/

	/*
		+ 연산자 정의를 += 연산자 호출식을 사용해서 구성해야 했어요.

		좌/우항 모두 내 소유가 아닌 경우 난 덧셈 결과를 담을 사본 object를 만들어야 해요.
	*/
	friend RationalNumber operator +(const RationalNumber &lhs, const RationalNumber &rhs)
	{
		return std::move(RationalNumber{ lhs } += rhs);
	}

	/*
		좌항 object는 내 소유일 때 호출돼요.
		
		좌항 object는 '이번 호출을 야기한 덧셈식을 포함한 전체 수식'의 계산이 끝날 때까지는 재활용할 수 있어요.
		따라서 나도 이 다음에 호출될 다른 Code를 위해 그 object를 재양도하고 있어요.
	*/
	friend RationalNumber &&operator +(RationalNumber &&lhs, const RationalNumber &rhs)
	{
		return std::move(lhs += rhs);
	}

	/*
		우항 object는 내 소유일 때 호출돼요.

		유리수 덧셈은 교환법칙이 성립하므로, 여기선 우항에 좌항을 더해 담은 다음 우항 object를 재양도하고 있어요.
	*/
	friend RationalNumber &&operator +(const RationalNumber &lhs, RationalNumber &&rhs)
	{
		return std::move(rhs += lhs);
	}

	/*
		둘 다 내 소유일 때 호출돼요. 좌항 object를 재양도해요.
	*/
	friend RationalNumber &&operator +(RationalNumber &&lhs, RationalNumber &&rhs)
	{
		return std::move(lhs += rhs);
	}
#else
	/*
		위와 동등한 느낌의, 이번에는 멤버 연산자 버전이에요.
	*/

	RationalNumber operator +(const RationalNumber &rhs) const &
	{
		return std::move(RationalNumber{ *this } += rhs);
	}

	RationalNumber &&operator +(const RationalNumber &rhs) &&
	{
		return std::move(*this += rhs);
	}

	RationalNumber &&operator +(RationalNumber &&rhs) const &
	{
		return std::move(rhs += *this);
	}

	RationalNumber &&operator +(RationalNumber &&rhs) &&
	{
		return std::move(*this += rhs);
	}
#endif
};


int main()
{
	RationalNumber n = 3;

	std::cout <<
		(
			(n + n) + (n + n)
		)
		<< std::endl;

	RationalNumber::PrintCounts();

	return 0;
}
