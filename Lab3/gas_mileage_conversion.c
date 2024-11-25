#include <stdio.h>

main() { // starts with what we start our chart at, where it ends, and the step between in mpg
int start = 10;
int end = 50;
int step = 5;
double lpk = 0;
  printf("MPG \t L/100km\n");
for (int mpg = start; mpg <= end; mpg += step) {
  lpk = (235.215 / mpg); // turns mgp to L/100km
  printf("%3d %12.2f\n", mpg, lpk);
}

}