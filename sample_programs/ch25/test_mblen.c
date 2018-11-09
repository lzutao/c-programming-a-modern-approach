#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>

// the number of characters in a multibyte string is the sum of mblen()'s
// note: the simpler approach is mbsrtowcs(NULL, str, sz, NULL)
size_t strlen_mb(const char* ptr)
{
  size_t result = 0;
  const char* end = ptr + strlen(ptr);
  mblen(NULL, 0); // reset the conversion state
  while(ptr < end) {
    int next = mblen(ptr, end - ptr);
    if(next == -1) {
       perror("strlen_mb");
       break;
    }
    ptr += next;
    ++result;
  }
  return result;
}

int main(void)
{
  setlocale(LC_ALL, "en_US.utf8");
  const char* str = "z\u00df\u6c34\U0001f34c";
  size_t len_s = strlen(str);
  size_t mb_len_s = mbstowcs(NULL, str, len_s);
  printf("The string %s consists of %zu bytes, but only %zu characters\n",
      str, len_s, mb_len_s);
}
