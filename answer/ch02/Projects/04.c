#include <stdio.h>

int main(void)
{
  printf("Enter an amount: ");
  double amount;
  scanf("%lf", &amount);

  double with_tax = amount * 1.05;

  printf("With tax added : $%lf", with_tax);
  return 0;
}
