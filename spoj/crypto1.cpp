#include <stdio.h>
#include <time.h>
#include <math.h>

time_t input;
tm* timeinfo;

main() {
	long long int n;
	scanf("%ld", &n);
	n = (int)sqrt((double)(n * 4000000007));
	input = (int)n;
	timeinfo = localtime(&input);
	printf("%s\n", asctime(timeinfo));
}
