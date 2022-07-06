#include <stdio.h>

int main(int argc, char const *argv[])
{
    int number[3];
    int *p_number;
    int a_number[3];
    int f_number();

    int arr[2];
    int (*p_arr)[2];
    int a_arr[3][2];
    int f_arr()[2];

    int func();
    int (*p_func) ();
    int a_func[3]();
    int f_func()();
    
    
    return 0;
}
