//program to calculate variance and sd of continous distribution table
#include <stdio.h>
#include <math.h>
int main() {
    int upper_lim, lower_lim, width;
    printf("enter upper limit, lower limit and width: ");
    scanf("%d%d%d", &upper_lim, &lower_lim, &width);
    int class_hold[100];
    class_hold[0] = lower_lim;
    float midpoint[100], mid_mul_freq[100];
    float freq[100], freq_sum = 0, mid_mul_freq_sum = 0;
    for (int i = 0; class_hold[i] < upper_lim; i++) {
        class_hold[i + 1] = class_hold[i] + width;
        //calculating midpoint
        midpoint[i] = (class_hold[i] + class_hold[i + 1]) / 2;
        printf("enter frequency: ");
        scanf("%f", &freq[i]);
        freq_sum += freq[i];
        mid_mul_freq[i] = freq[i] * midpoint[i];
        mid_mul_freq_sum += mid_mul_freq[i];
    }
    float mean = mid_mul_freq_sum / freq_sum;
    float freq_mul_dif_mid_mean[100], sum_freq_mul_dif_mid_mean = 0;
    for (int i = 0; class_hold[i] < upper_lim; i++) {
        freq_mul_dif_mid_mean[i] = freq[i] * (pow((midpoint[i]- mean), 2));
        sum_freq_mul_dif_mid_mean += freq_mul_dif_mid_mean[i];
    }
    printf("\nclassrange---midpoint---frequency---mid*freq---freq * (mid - mean)\n");
    for (int i = 0; class_hold[i] < upper_lim; i++) {
        printf("%d----%d---%f---%f---%f---%f\n", class_hold[i], class_hold[i + 1], midpoint[i], freq[i], mid_mul_freq[i], freq_mul_dif_mid_mean[i]);
    }
    float variance = sum_freq_mul_dif_mid_mean / freq_sum;
    float std_div = sqrt(variance);
    printf("varience = %f\t sd = %f, mean = %f\n", variance, std_div, mean);
}