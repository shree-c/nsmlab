// program to find mean and std deviation of continuous distribution table
//formula
//sd = 1/N * sqrt((N * sumof_1_to_n(f * x^2)) - (sumof_1_to_n(f * x))^2)
//N = sum of frequencies
//x = midpoint
//f = frequency for that class
#include <stdio.h>
#include <math.h>
int main() {
    //taking input range and width of each class
    int upper_lim, lower_lim, width;
    printf("enter upper limit, lower limit and width of each class: ");
    scanf("%d%d%d", &upper_lim, &lower_lim, &width);
    //diclaring various variables for holding things
    //f array for holding frequencies
    //class for holding class ranges 
    //N for freq sum
    //x for midpoints
    float class[100], f[100], x[100], N = 0;
    class[0] = lower_lim;
    for (int i = 0; class[i] < upper_lim; i++) {
        class[i + 1] = class[i] + width;
        x[i] = (class[i] + class[i+1]) / 2.0;
        printf("enter freq: ");
        scanf("%f", &f[i]);
        N += f[i];
    }
    //arrays for f*x^2 and f * x
    float f_prod_x[100], f_prod_x2[100];
    //variables for holding sums
    float sum_f_prod_x = 0, sum_f_prod_x2 = 0;
    //pretty print
    printf("\n%8s\t%5s\t%5s\t%5s\t%5s\t\n", "clasrang", "freq", "midpt", "f*x", "f*x2");
    for (int i = 0; class[i] < upper_lim; i++) {
        f_prod_x[i] = x[i] * f[i];
        f_prod_x2[i] = x[i] * x[i] * f[i];
        sum_f_prod_x += f_prod_x[i];
        sum_f_prod_x2 += f_prod_x2[i];
        printf("%4.2f-%3.2f\t%3.2f\t%3.2f\t%3.2f\t%3.2f\n", class[i], class[i+1], x[i], f[i], f_prod_x[i], f_prod_x2[i]);
    }
    //calculating standard deviation and mean
    float mean = sum_f_prod_x / N;
    float sd = (1/N) * sqrt((N * sum_f_prod_x2) - (sum_f_prod_x* sum_f_prod_x));
    printf("mean: %f standard deviation : %f\n", mean, sd);
    return 0;
}