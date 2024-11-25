#include <stdio.h>
#include <math.h>

int main(void) {

int radius = 0;
    printf("Enter the radius of the analog clock:");
    scanf("%d", &radius);

    for (int i = 0; i <= 12; i++) {
        float pi = M_PI;
        float angle = (pi/2) - (i * pi / 6);
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        printf("The x-coordinate and y-coordinate of %d o'clock are x:%f y:%f\n", i, x, y);
    }

    return 0;
}
