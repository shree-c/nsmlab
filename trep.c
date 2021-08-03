#include <stdio.h>
#define f(x) 1 / (1 + (x * x)) 
//fromula to calculate area
//area = h/2(f(lower_bound) + f(upper_bound) + 2 (f(1) + f(2) + .... + f(upper_bound - 1))
//where h = (upper_bound + lower_bound)/(number of parts we want to divide the area)
int main() {
    printf("enter the lower bound and upper bound: ");
    //a and b for lower bound and upper bound
    float a, b;
    scanf("%f%f", &a, &b);
    printf("enter the number of times you want to divide the area under curve between bounds: ");
    int n;
    scanf("%d", &n);
    //calculating the value of x each parts
    //the first value would be a and last b
    //array for holding x values
    float x_val[100];
    x_val[0] = a;
    //width of each part
    float width = (b - a) / n;
    int i;
    for(i = 0; x_val[i] < b; i++) {
        x_val[i + 1] = x_val[i] + width;
    }
    //calculating the values of function at different x values
    //s for holding sum of f(x)s from i index 1 to i index n - 1
    float fun_vals[100], s = 0;
    //pretty print
    printf("%5s\t%5s\n", "x_vals", "f(x_vals)");
    printf("--------------\n");
    printf("%3.2f\t%3.2f\n", x_val[0], f(x_val[0]));
    for (int i = 1; i < n; i++) {
        fun_vals[i] = (f(x_val[i]));
        s += fun_vals[i];
        printf("%3.2f\t%3.2f\n", x_val[i], fun_vals[i]);
    }
    printf("s-->%f\n", s);
    printf("%3.2f\t%3.2f\n", x_val[n], f(x_val[n]));
    float area_under_curve = (width / 2.0)*((f(x_val[0])) + (f(x_val[n])) + (2 * s));
    printf("area under curve/integral: %f\n", area_under_curve);
    return 0;
}