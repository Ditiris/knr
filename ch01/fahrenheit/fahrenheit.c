#include <stdio.h>

// C = (5/9)(F-32)
int main() 
{
	float fahrenheit, celsius;
	int lower, upper, step;

	lower = 0; 		/* lower limit of temperature scale */
	upper = 300;  /* upper limit */
	step = 20;		/* step size */

	fahrenheit = lower;
	printf("Celsius Fahrenheit\n");
	while (fahrenheit <= upper) {
		celsius = 5 * (fahrenheit - 32) / 9;
		printf("%6.1f\t%6.1f\n", fahrenheit, celsius);
		fahrenheit = fahrenheit + step;
	}
}
