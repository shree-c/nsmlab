#include <stdio.h>
#define f(x) x * x - 3
#define f1(x) 2*x
int main() {
    int ini_guess;
    printf("enter initial guess: ");
    scanf("%d", &ini_guess);
    printf("enter the number of iterations you want to do: ");
    int ite;
    scanf("%d", &ite);
    float x0 = ini_guess, x1;
    printf("%15s\t%15s\t%15s\t%15s\n", "x0", "x1", "f(x0)", "f1(x0)");
    printf("%12.3f\t%12.3f\t%12.3f\t%12.3f\n", x0, 0.00, f(x0), f1(x0));
    for (int i = 0; i < ite; i++) {
        x1 = x0 - ((f(x0)) / (f1(x0)));
        printf("%12.3f\t%12.3f\t%12.3f\t%12.3f\n", x0, x1, f(x0), f1(x0));
        x0 = x1;
    }
    printf("--->%f\n",x1);
    return 0;
}
