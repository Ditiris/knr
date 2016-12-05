#include <stdio.h>

// C = (5/9)(F-32)
// F = (9/5)C + 32

int main() {
	float f;
	float c;

	float lower = 0.0;
	float upper = 100.0;
	float step = 5.0;

	c = upper;
	printf("Celsius Fahrenheit\n");
	while (c > lower) {
		f = (9.0/5.0)*c + 32.0;
		printf("%6.1f\t%6.1f\n", c, f);
		c = c - step;
	}
}
