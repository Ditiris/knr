/* Rewrite the temperature conversion program of Section 1.2 to use a function
 * for conversion. 
 */

#include <stdio.h>

#define FIVE_NINTHS 0.555555555555556
// C = (5/9)(F-32)
float f2c(float aFahrenheit) {
	return (FIVE_NINTHS * (aFahrenheit - 32.0));
}

float c2f(float aCelsius) {
	return (1.8 * aCelsius + 32.0);
}

int main() {
	float theCelsius;
	int theLower = -100;
	int theStep = 20;
	int theUpper = 100;

	theCelsius = theLower;
	printf("Celsius Fahrenheit\n");
	while (theCelsius <= theUpper) {
		printf("%6.1f\t%6.1f\n", theCelsius, c2f(theCelsius));
		theCelsius += theStep;
	}
	return 0;
}
