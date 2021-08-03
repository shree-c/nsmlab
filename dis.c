//program to construct discrete freq table find mean and sd
//formula for calculating standard deviation
// sd = sqrt(sumof1_to_n(x - mean) / N) 
//where
// N = sum of frequencies
// x is data
#include <stdio.h>
#include <math.h>
int main() {
    //fx is array for freq * data
    //sumfx for holding fx sum for calculating mean
    float data[100], freq[100], fx[100], sumfx = 0, N = 0;
    printf("enter the total number of elements: ");
    int no_of_ele;
    scanf("%d", &no_of_ele);
    printf("enter the number of values of data and their freq--->\n");
    for (int i = 0; i < no_of_ele; i++) {
        printf("data %dth element: ", i);
        scanf("%f", &data[i]);
        printf("frequency of %dth data: ", i);
        scanf("%f", &freq[i]);
        //calculating data * freq
        fx[i] = data[i] * freq[i];
        //calculating sumf*x by summing f*x;
        sumfx += fx[i];
        //summing frequency N
        N += freq[i];
    }
    float mean = sumfx / N;
    //calculating f*(x - x1)^2
    float f_x_diff_x_sq[100];
    float sumfxdiffxsq = 0;
    for (int i = 0; i < no_of_ele; i++) {
        f_x_diff_x_sq[i] = freq[i] * pow((data[i] - mean), 2);
        sumfxdiffxsq += f_x_diff_x_sq[i];
    }
    printf("mean: %f\n", mean);
    printf("%5s\t%5s\t%5s\n", "data", "freq", "fxdiffmean");
    for (int i = 0; i < no_of_ele; i++) {
        printf("%3.2f\t%3.2f\t%3.2f\n", data[i], freq[i], f_x_diff_x_sq[i]);
    }
    float varience = sumfxdiffxsq / N;
    float std_div = sqrt(varience);
    printf("varience = %f\t standard deviation : %f\n", varience, std_div);
    return 0;
}