#include <stdio.h>

int main(void)
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int absolute_num = (num < 0) ? -num: num;

    if (absolute_num <= 9)
        printf("1 digit");
    else if (absolute_num <= 99)
        printf("2 digits");
    else if (absolute_num <= 999)
        printf("3 digits");
    else if (absolute_num <= 9999)
        printf("4 digits");
    else if (absolute_num <= 32767)
        printf("5 digits");
    else
        printf("Integer overflow on 16 bit int");

    return 0;
}
