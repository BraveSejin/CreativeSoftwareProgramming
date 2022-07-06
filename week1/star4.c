#include<stdio.h>

int main(int argc, char const *argv[])
{
    printf("마름모의 넓이를 입력하세요!\n");
    int area;
    scanf("%d", &area);
    
    // 구현 전략 : 1 ~ 넓이 라인 (커지는 삼각형)과 (넓이+1) ~ 넓이*2 -1 라인을 따로 생각하여 구현
    // 예시 : 넓이가 5일때 1 ~ 5번째 줄과 6 ~ 9번째 줄을 따로 생각해서 구현한다. 
    
    // 마름모의 1 ~ area번 라인을 출력
    int num_line = area;
    int num_space;
    int num_star;
    int loop;

    int cur_line = 1; // 이번에 몇번째 반복인지
    while (cur_line <= num_line){

        num_space = num_line - cur_line; // 이번 라인에 스페이스 몇개?
        num_star = cur_line * 2 - 1; // 이번 라인에 star 몇개? 
        loop = 1; // 이번이 몇번 반복인지

        while (loop <= num_space){
            printf("@");
            loop++;
        }
        
        loop = 1;
        while (loop <= num_star){
            printf("*");
            loop++;
        }
        printf("\n");
        cur_line += 1;
    }

    cur_line = 1;
    while (cur_line <= num_line){
        num_space = cur_line;
        num_star = (num_line - cur_line) * 2 + 1;
        loop = 1; // 이번이 몇번 반복인지

        while (loop <= num_space){
            printf("@");
            loop++;
        }
        
        loop = 1;
        while (loop <= num_star){
            printf("*");
            loop++;
        }
        printf("\n");
        cur_line += 1;
    }

    return 0;
}
