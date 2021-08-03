//program to construct discrete freq table find mean and sd
#include <stdio.h>
#include <math.h>
int main() {
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
    float fxdiffxsq[100];
    float sumfxdiffxsq = 0;
    for (int i = 0; i < no_of_ele; i++) {
        fxdiffxsq[i] = freq[i] * pow((data[i] - mean), 2);
        sumfxdiffxsq += fxdiffxsq[i];
    }
    printf("mean: %f\n", mean);
    printf("%5s\t%5s\t%5s\n", "data", "freq", "fxdiffmean");
    for (int i = 0; i < no_of_ele; i++) {
        printf("%3.2f\t%3.2f\t%3.2f\n", data[i], freq[i], fxdiffxsq[i]);
    }
    float varience = sumfxdiffxsq / N;
    float std_div = sqrt(varience);
    printf("varience = %f\t standard deviation : %f\n", varience, std_div);
    return 0;
}