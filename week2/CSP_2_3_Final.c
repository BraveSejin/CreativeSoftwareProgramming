#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Data 파트를 변수들만 가지고 구성한 버전입니다.
void PrintThatNumbers_Mk1()
{
    int number_0;
    int number_1;
    int number_2;
    int number_3;
    int number_4;
    int number_5;

    while ( 1 )
    {
        number_0 = rand() % 45 + 1;
        number_1 = rand() % 45 + 1;
        number_2 = rand() % 45 + 1;
        number_3 = rand() % 45 + 1;
        number_4 = rand() % 45 + 1;
        number_5 = rand() % 45 + 1;

        if ( number_0 != number_1 &&
            number_0 != number_2 &&
            number_0 != number_3 &&
            number_0 != number_4 &&
            number_0 != number_5 &&

            number_1 != number_2 &&
            number_1 != number_3 &&
            number_1 != number_4 &&
            number_1 != number_5 &&

            number_2 != number_3 &&
            number_2 != number_4 &&
            number_2 != number_5 &&

            number_3 != number_4 &&
            number_3 != number_5 &&

            number_4 != number_5 )
        {
            printf("Mk1: [");
            printf("%.2d, ", number_0);
            printf("%.2d, ", number_1);
            printf("%.2d, ", number_2);
            printf("%.2d, ", number_3);
            printf("%.2d, ", number_4);
            printf("%.2d, ", number_5);
            printf("\b\b]\n");

            // 위 조건식 계산 결과값이 nonzero라면 무조건 함수 내용물(while문을 포함한) 실행이 끝남
            return;
        }

        // 함수 내용물 실행이 끝나지 않은 채 여기까지 Code 흐름이 내려온다면,
        // 위 조건식 계산 결과값이 0이었음을 의미함 --> 겹치는 숫자가 있음 --> '다시' 뽑기 위해 Code 흐름을 while문 꼭대기로 올림
    }
}

// Data 파트를 6칸짜리 배열을 가운데에 놓고 구성했지만 여전히 실행 흐름은 순차맛 가득인 버전입니다.
void PrintThatNumbers_Mk2()
{
    int numbers[6];

    while ( 1 )
    {
        numbers[0] = rand() % 45 + 1;
        numbers[1] = rand() % 45 + 1;
        numbers[2] = rand() % 45 + 1;
        numbers[3] = rand() % 45 + 1;
        numbers[4] = rand() % 45 + 1;
        numbers[5] = rand() % 45 + 1;

        if ( numbers[0] != numbers[1] &&
            numbers[0] != numbers[2] &&
            numbers[0] != numbers[3] &&
            numbers[0] != numbers[4] &&
            numbers[0] != numbers[5] &&

            numbers[1] != numbers[2] &&
            numbers[1] != numbers[3] &&
            numbers[1] != numbers[4] &&
            numbers[1] != numbers[5] &&

            numbers[2] != numbers[3] &&
            numbers[2] != numbers[4] &&
            numbers[2] != numbers[5] &&

            numbers[3] != numbers[4] &&
            numbers[3] != numbers[5] &&

            numbers[4] != numbers[5] )
        {
            printf("Mk2: [");
            printf("%.2d, ", numbers[0]);
            printf("%.2d, ", numbers[1]);
            printf("%.2d, ", numbers[2]);
            printf("%.2d, ", numbers[3]);
            printf("%.2d, ", numbers[4]);
            printf("%.2d, ", numbers[5]);
            printf("\b\b]\n");

            // 위 조건식 계산 결과값이 nonzero라면 무조건 함수 내용물(while문을 포함한) 실행이 끝남
            return;
        }

        // 함수 내용물 실행이 끝나지 않은 채 여기까지 Code 흐름이 내려온다면,
        // 위 조건식 계산 결과값이 0이었음을 의미함 --> 겹치는 숫자가 있음 --> '다시' 뽑기 위해 Code 흐름을 while문 꼭대기로 올림
    }
}

// Data 파트를 6칸짜리 배열을 가운데에 놓고 구성했고, [ ] 연산자가 이항 연산자임을 활용하여 반복 구조를 도입, 총 문장 수를 줄인 버전입니다.
void PrintThatNumbers_Mk3()
{
    int numbers[6];
    int index;

    int isSameNumberFound;
    int idx_from;
    int idx_to;

    while ( 1 )
    {
        // 원본 코드:
        //numbers[0] = rand() % 45 + 1;
        //numbers[1] = rand() % 45 + 1;
        //numbers[2] = rand() % 45 + 1;
        //numbers[3] = rand() % 45 + 1;
        //numbers[4] = rand() % 45 + 1;
        //numbers[5] = rand() % 45 + 1;

        // C의 for문이에요.
        // Python의 for문과는 조금 달라요. 반복 흐름의 그 세 부분을 한 곳에(조건식 주변에) 몰아 적을 수 있게 해 줘요.
        for (
            // 1. 첫 반복을 준비하는 수식 (첫 조건식 계산 직전에 계산됨)
            index = 0 ;
            
            // 2. 언제 반복을 끝낼 것인지 정하는 수식(조건식)
            index < 6 ;
            
            // 3. 다음 반복을 준비하는 수식 (내용물 문장 실행 직후, 다음 조건식 계산 직전에 계산됨)
            index = index + 1 )
        {
            // 아무튼 이 중괄호 안에서 index 값은 [0, 6) 범위 안에서 매 반복마다 1씩 증가해요.

            // 두 수식 numbers와 index를 [ ] 연산자로 조합하여 이번에 뽑은 새 숫자를 담을 int '한' 칸을 특정하고 있어요.
            numbers[index] = rand() % 45 + 1;
        }



        // 원본 코드:
        //if ( numbers[0] != numbers[1] &&
        //    numbers[0] != numbers[2] &&
        //    numbers[0] != numbers[3] &&
        //    numbers[0] != numbers[4] &&
        //    numbers[0] != numbers[5] &&

        //    numbers[1] != numbers[2] &&
        //    numbers[1] != numbers[3] &&
        //    numbers[1] != numbers[4] &&
        //    numbers[1] != numbers[5] &&

        //    numbers[2] != numbers[3] &&
        //    numbers[2] != numbers[4] &&
        //    numbers[2] != numbers[5] &&

        //    numbers[3] != numbers[4] &&
        //    numbers[3] != numbers[5] &&

        //    numbers[4] != numbers[5] )

        // 반복 흐름을 도입할 예정이기 때문에, 더 이상 '겹침' 여부를 단일 수식으로 표현할 수 없게 되었어요.
        // 그래서 여기서는 '겹침을 발견했는지 여부'를 담을 새 변수 iSNF를 도입해서 활용하고 있어요.

        // 아직 아무 검사도 안 한 지금 시점에는 겹침을 발견 못 한 것이 맞으니 이를 담아 둠
        isSameNumberFound = 0;

        for ( idx_from = 0; idx_from < 6 && isSameNumberFound == 0; idx_from += 1 )       // int 형식을 다룰 때, 수식 idx_from += 1은 수식 idx_from = idx_from + 1과 동치예요
            for ( idx_to = idx_from + 1; idx_to < 6 && isSameNumberFound == 0; ++idx_to ) // int 형식을 다룰 때, 수식 ++idx_to는 수식 idx_to = idx_to + 1과 동치예요
                if ( numbers[idx_from] == numbers[idx_to] )
                    isSameNumberFound = 1;

        /*
            !연산자는 단항 연산자예요.
            대상 수식을 계산한 결과값이 0에 준하면 nonzero, nonzero에 준하면 0이 계산 결과값으로 나와요.
            '! 수식'의 형식은 대상 수식의 형식과 동등해요.
        */
        if ( !isSameNumberFound ) 
        {
            printf("Mk3: [");

            for ( index = 0; index < 6; ++index )
                printf("%.2d, ", numbers[index]);

            printf("\b\b]\n");

            // 위 조건식 계산 결과값이 nonzero라면 무조건 함수 내용물(while문을 포함한) 실행이 끝남
            return;
        }

        // 함수 내용물 실행이 끝나지 않은 채 여기까지 Code 흐름이 내려온다면,
        // 위 조건식 계산 결과값이 0이었음을 의미함 --> 겹치는 숫자가 있음 --> '다시' 뽑기 위해 Code 흐름을 while문 꼭대기로 올림
    }
}

// Data 파트를 45칸짜리 배열을 가운데에 놓고 구성한 버전입니다. 숫자를 하나씩 담고 열심히 섞은 다음, 배열의 앞 여섯 칸에 담긴 숫자들을 출력하고 있어요.
void PrintThatNumbers_Mk4()
{
    int numbers[45];
    int index;
    int count_shuffle;

    // '덱' 만들기
    for ( index = 0; index < 45; ++index )
        numbers[index] = index + 1;

    // 섞기
    for ( count_shuffle = 1000000; count_shuffle > 0; --count_shuffle )
    {
        int idx_from;
        int idx_to;
        int temp;

        idx_from = rand() % 45; // index를 다루는 때와 프로그래밍 목표에서 언급한 숫자 자체를 다루는 때를 잘 구분해야 해요. 여기선 +1 하면 안 돼요.
        idx_to = rand() % 45;

        temp = numbers[idx_from];
        numbers[idx_from] = numbers[idx_to];
        numbers[idx_to] = temp;
    }

    // 섞은 다음 바로 출력
    printf("Mk4: [");

    for ( index = 0; index < 6; ++index )
        printf("%.2d, ", numbers[index]);

    printf("\b\b]\n");
}


int main()
{
    int sample_name_for_demonstration;

    srand(time(0));

    // VS의 이름 자동 완성 기능
    // 대충 이 아래에서 PTN 이나 snfd 를 쳐 봐요.
    // 왜 다른 프로그래머 분들이 새 이름 정할 때 대문자를 섞거나 _(underscore)를 중간에 끼워 두는지 알 수 있을 거예요.

    PrintThatNumbers_Mk1();
    PrintThatNumbers_Mk2();
    PrintThatNumbers_Mk3();
    PrintThatNumbers_Mk4();

    return 0;
}
