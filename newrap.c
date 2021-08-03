#include <stdio.h>
//function whose root needs to be calculated
#define f(x) x*x*x - 5
//derivative of that function
#define f1(x) 3*x*x
int main() {
    float ini_guess;
    printf("make initial guess: ");
    scanf("%f", &ini_guess);
    float x1, x0 = ini_guess;
    printf("enter the number of iteration you want to do: ");
    int n;
    scanf("%d", &n);
    printf("%5s\t%5s\t%5s\n", "iteno", "x0", "x1");
    for (int i = 0; i < n; i++) {
        //newton's formula to calculate root
        x1 = (x0 - ((f(x0)) / (f1(x0))));
        printf("%5d\t%3.2f\t%3.2f\n", i, x0, x1);
        //giving x0 the new closer to root value that we just calculated
        x0 = x1;
    }
    //x1 would be approximate root after iteration
    printf("root: %3.2f\n", x1);
    return 0;
}