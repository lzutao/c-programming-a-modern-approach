#include <stdio.h>

int main(void)
{
  struct isbn
  {
    int gs1_prefix;
    int group_id;
    int publisher_code;
    int item_number;
    int check_digit;
  };
  struct isbn isbn;

  printf("Enter ISBN: ");
  scanf("%d -%d -%d -%d -%d",
        &isbn.gs1_prefix, &isbn.group_id, &isbn.publisher_code,
        &isbn.item_number, &isbn.check_digit
  );

  printf("GS1 prefix: %d\n"
         "Group identifier: %d\n"
         "Publisher code: %d\n"
         "Item number: %d\n"
         "Check digit: %d\n",
         isbn.gs1_prefix, isbn.group_id, isbn.publisher_code,
         isbn.item_number, isbn.check_digit);

  return 0;
}
