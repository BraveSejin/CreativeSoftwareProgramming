#include <stdio.h>

int main()
{
    /*
        C에서는 이런 느낌으로 주석을 적는 것도 가능해요. (원래 이게 근본)

        Data 준비

        width: 마름모의 너비(변의 길이)

        row: 지금까지 몇 줄을 출력했는지(이번에 몇 번째 줄을 출력해야 하는지)
        
        count_symbols_toPrint: 이번에 글자를 몇 개 출력해야 하는지

        count_symbols_printed: 지금까지 글자를 몇 개 출력했는지
    */

    int width;
    int row;
    int count_symbols_toPrint;
    int count_symbols_printed;

    printf("마름모의 너비를 입력하세요>");
    scanf("%d", &width);

    // 1.1
    row = 0;

    // 1.2
    while ( row < width )
    {
        // 띄어쓰기 출력
        count_symbols_toPrint = width - row - 1;

        // 1-1.1
        count_symbols_printed = 0;

        // 1-1.2
        while ( count_symbols_printed < count_symbols_toPrint )
        {
            printf(" ");

            // 1-1.3
            count_symbols_printed = count_symbols_printed + 1;
        }

        // * 출력
        count_symbols_toPrint = row * 2 + 1;

        // 1-2.1
        count_symbols_printed = 0;

        // 1-2.2
        while ( count_symbols_printed < count_symbols_toPrint )
        {
            printf("*");

            // 1-2.3
            count_symbols_printed = count_symbols_printed + 1;
        }

        // 엔터 키 글자 출력
        printf("\n");

        // 1.3
        row = row + 1;
    }


    /*
        마름모의 아래 절반을 출력하기 위해 위 코드를 복붙해 와서 살짝 고침

        width 값은 매 줄 출력 도중 변경되지 않으므로,
        아래 절반의 각 줄을 출력하기 위해
        매 반복마다 row 자리에 적당한 값을 담아 둠으로써 목표 달성 시도
    */

    // 2.1
    row = width - 2;

    // 2.2
    while ( row >= 0 )
    {
        // 이 아래 내용물은 동일 (2.3 부분은 물론 고쳐 둠)

        // 띄어쓰기 출력
        count_symbols_toPrint = width - row - 1;

        // 2-1.1
        count_symbols_printed = 0;

        // 2-1.2
        while ( count_symbols_printed < count_symbols_toPrint )
        {
            printf(" ");

            // 2-1.3
            count_symbols_printed = count_symbols_printed + 1;
        }

        // * 출력
        count_symbols_toPrint = row * 2 + 1;

        // 2-2.1
        count_symbols_printed = 0;

        // 2-2.2
        while ( count_symbols_printed < count_symbols_toPrint )
        {
            printf("*");

            // 2-2.3
            count_symbols_printed = count_symbols_printed + 1;
        }

        // 엔터 키 글자 출력
        printf("\n");

        // 2.3
        row = row - 1;
    }


    // 적절한 종료 메시지
    printf("짠!");

    return 0;
}
