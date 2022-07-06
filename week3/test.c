#include <stdio.h>

void fill_with_three(int* pos)
{
    *pos = 3;
}

int main(int argc, char const *argv[])
{
    int numbers[2];
    
    // scanf("%d", &numbers[0]);
    fill_with_three(numbers);
    numbers[1] = 5;
    printf("%d", numbers[0]);
    return 0;
}
