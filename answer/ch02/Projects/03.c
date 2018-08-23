#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

#define PI 3.14159
#define SPHERE_SCALE (4.0 / 3.0)

void fatal(const char *msg);
double intput_double(const char *str);

int main(int argc, char *argv[])
{
  if (argc < 2) {
    printf("usage: %s <radius of the sphere>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  double radius = intput_double(argv[1]);

  if (radius < 0) {
    fatal("Radius is less than zero.");
  }

  double volume = SPHERE_SCALE * PI * (radius * radius * radius);

  printf("Volume of the sphere with radius %lf: %lf\n", radius, volume);
  exit(EXIT_SUCCESS);
}

void fatal(const char *msg)
{
  fprintf(stderr, "error: %s\n", msg);
  exit(EXIT_FAILURE);
}

double intput_double(const char *str)
{
  char *endptr;

  errno = 0;  /* To distinguish success/failure after call */
  double value = strtod(str, &endptr);

  /* Check for various possible errors */

  if ((errno == ERANGE && value == HUGE_VAL)
      || (errno != 0 && value == 0)) {
    perror("strtod");
    exit(EXIT_FAILURE);
  }

  if (endptr == str) {
    fatal("No digits were found.");
  }

  /* If we got here, strtod function successfully parsed a number */

  if (isinf(value) || isnan(value)) {
    fatal("Invalid input number.");
  }

  return value;
}
