#include <stdio.h>
using namespace std;

main() {
	printf("1\n10000\n");
	for(int i = 1; i <= 10000; ++i)
		printf("%d %d\n", i, i);
}
