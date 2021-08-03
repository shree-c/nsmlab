#include <stdio.h>
#include <math.h>
float f(float x) {
	return sin(x * x) - tan(x) + 4;
}
int main() {
	//finding initial roots
	int i = 0;
	float fa = f(i);
	float fb = f(i + 1);
	float a, b, c;
	for ( ;fa * fb > 0; i++) {
		a = i, b = i + 1;
		fa = f(a);
		fb = f(b);
		printf("fa = %f, fb = %f, a = %f,b = %f \n", fa, fb, a, b);
	}
	i--;
	a = i - 1, b = i + 1, c = (a + b) / 2.0;
	if (f(a) == 0) {
		printf("root: %f\n", a);
		return 0;
	}
	else if (f(b) == 0) {
		printf("root: %f\n", b);
		return 0;
	}

	float fc = f(c);
	printf("initial roots a = %f, b = %f, c = %f, fa = %f, fb = %f, fc = %f\n", a, b, c, f(a), f(b), f(c));
	while ((int) fc) {
		if ((fa * fc < 0))
			b = c;
		if ((fb * fc < 0))
			a = c;
		c = (a + b) / 2.0;
		fc = f(c);
		printf("a = %f, b = %f, c = %f, fa = %f, fb = %f, fc = %f\n", a, b, c, f(a), f(b), f(c));
		getchar();
	}
	printf("root : %f\n", c);
	//printf("%d", f(22));
	return 0;
}
