#include <stdio.h>

void increment(int& t) {
	t++;
}

main() {
	int i, j, q = 0;
	const int n = 3000;
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= n; ++j)
			increment(q);//printf("[%d][%d]\n", i, j);
	for(i = 1; i <= n; ++i)
		printf("%d ", i);
}
