#include <locale.h>
#include <stdio.h>

int main(void)
{
  setlocale(LC_ALL, "");
  struct lconv *lconv = localeconv();
  printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n"
          "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
          lconv->decimal_point,
          lconv->thousands_sep,
          lconv->grouping,
          lconv->int_curr_symbol,
          lconv->currency_symbol,
          lconv->mon_decimal_point,
          lconv->mon_thousands_sep,
          lconv->mon_grouping,
          lconv->positive_sign,
          lconv->negative_sign,
          lconv->int_frac_digits,
          lconv->frac_digits,
          lconv->p_cs_precedes,
          lconv->p_sep_by_space,
          lconv->n_cs_precedes,
          lconv->n_sep_by_space,
          lconv->p_sign_posn,
          lconv->n_sign_posn
  );
  return 0;
}
