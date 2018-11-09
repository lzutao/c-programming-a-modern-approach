#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define IS_NULL(x) ((x) == NULL)
#define IS_NOT_NULL(x) ((x) != NULL)

int main(int argc, char const *argv[])
{
  const struct lconv *user_lconv;
  const char *temp;
  if (argc != 2) {
    return 1;
  }

  temp = setlocale(LC_ALL, argv[1]);
  if (IS_NULL(temp)) {
    printf("Locale information not available\n");
    exit(EXIT_FAILURE);
  }

  user_lconv = localeconv();
  printf("decimal_point       = \"%s\"\n", user_lconv->decimal_point);
  printf("thousands_sep       = \"%s\"\n", user_lconv->thousands_sep);
  printf("grouping            = %d\n",     (int)*user_lconv->grouping);
  printf("int_curr_symbol     = \"%s\"\n", user_lconv->int_curr_symbol);
  printf("currency_symbol     = \"%s\"\n", user_lconv->currency_symbol);
  printf("mon_decimal_point   = \"%s\"\n", user_lconv->mon_decimal_point);
  printf("mon_thousands_sep   = \"%s\"\n", user_lconv->mon_thousands_sep);
  printf("mon_grouping        = %d\n",     (int)*user_lconv->mon_grouping);
  printf("positive_sign       = \"%s\"\n", user_lconv->positive_sign);
  printf("negative_sign       = \"%s\"\n", user_lconv->negative_sign);
  printf("int_frac_digits     = %d\n",     user_lconv->int_frac_digits);
  printf("frac_digits         = %d\n",     user_lconv->frac_digits);
  printf("p_cs_precedes       = %d\n",     user_lconv->p_cs_precedes);
  printf("p_sep_by_space      = %d\n",     user_lconv->p_sep_by_space);
  printf("n_cs_precedes       = %d\n",     user_lconv->n_cs_precedes);
  printf("n_sep_by_space      = %d\n",     user_lconv->n_sep_by_space);
  printf("p_sign_posn         = %d\n",     user_lconv->p_sign_posn);
  printf("n_sign_posn         = %d\n",     user_lconv->n_sign_posn);
  printf("int_p_cs_precedes   = %d\n",     user_lconv->int_p_cs_precedes);
  printf("int_n_cs_precedes   = %d\n",     user_lconv->int_n_cs_precedes);
  printf("int_p_sep_by_space  = %d\n",     user_lconv->int_p_sep_by_space);
  printf("int_n_sep_by_space  = %d\n",     user_lconv->int_n_sep_by_space);
  printf("int_p_sign_posn     = %d\n",     user_lconv->int_p_sign_posn);
  printf("int_n_sign_posn     = %d\n",     user_lconv->int_n_sign_posn);

  return 0;
}
