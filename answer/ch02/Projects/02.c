#include <stdio.h>

#define PI 3.14159
#define SPHERE_SCALE (4.0 / 3.0)

int main(void)
{
  int radius = 10;
  double vol = SPHERE_SCALE * PI * (radius * radius * radius);

  printf("%.2f\n", vol);
  return 0;
}
