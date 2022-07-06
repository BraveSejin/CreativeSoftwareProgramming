#include <stdio.h>

// global ������(���� static ������)�� ���� ����
const char *spaces = "                                        ";
int depth = 0;

// n ��° �Ǻ���ġ ���� ����Ͽ� return�մϴ�.
int fib(int n)
{
	// local ���� ����(����) --> automatic ����
	int result;

	// ����ϴ� �� �̸��鿡 ���� ��ġ �� ��� --> (S)�� static, (A)�� automatic
	// %.*s�� %p�� ������ ���� �ſ�. �ñ��ϸ� ����� �ּ���
	printf("%.*s|Calc-ing fib[%d]...\n",	depth * 4, spaces, n);
	printf("%.*s|(S)   &fib: %p\n",			depth * 4, spaces, &fib);
	printf("%.*s|(S) &depth: %p\n",			depth * 4, spaces, &depth);
	printf("%.*s|(A)     &n: %p\n",			depth * 4, spaces, &n);
	printf("%.*s|(A)&result: %p\n",			depth * 4, spaces, &result);
	
	// �Ǻ���ġ ������ ��Ģ�� ���� ��� ���
	if ( n < 3 )
	{
		result = 1;
	}
	else
	{
		depth = depth + 1;

		result = fib(n - 2) + fib(n - 1);

		depth = depth - 1;
	}

	// ��¶�� ���� ��ǥ���� �Ǻ���ġ �� ���
	printf("%.*s|Done. fib[%d] is %d\n\n", depth * 4, spaces, n, result);

	return result;
}

int main()
{
	fib(5);
	return 0;
}