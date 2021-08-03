#include <stdio.h>
#define f(x) x *x - 3
int main()
{
    //variable for calculating initial guess
    int i = 0;
    //variables for calculating f(a), f(b), f(c);
    float fa, fb, fc;
    //loop to calculate reasonable range
    do
    {
        fa = f(i);
        fb = f(i + 1);
        i++;
    } while (fa * fb > 0);
    //taking average of bounds a and b
    float a = i - 1, b = i, c = (a + b) / 2.0;
    printf("initial guesses a = %f, b = %f\n", a, b);
    //asking for number of iterations needed to be done
    printf("enter the number of iterations: ");
    int n, j = 1;
    scanf("%d", &n);
    printf("%5s\t%5s\t%5s\t%5s%5s\t%5s\t%5s\t\n", "iteno",
           "f(a)",
           "f(b)", "f(c)", "a", "b", "c");
    printf("%3.2d\t%3.2f\t%3.2f\t%3.2f\t%3.2f\t%3.2f\t%3.2f\t\n", j++, f(a), f(b), f(c), a, b, c);
    //adjusting the values of a and b depending on the product of functions at different values
    for (; j <= n; i++)
    {
        if ((f(a)) * (f(c)) > 0)
            a = c;
        else
            b = c;
        c = (a + b) / 2;
        printf("%3.2d\t%3.2f\t%3.2f\t%3.2f\t%3.2f\t%3.2f\t%3.2f\t\n", j++, f(a), f(b), f(c), a, b, c);
    }
    //printing roots
    printf("root: %f\n", c);
    return 0;
}