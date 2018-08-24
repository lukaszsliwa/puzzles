#include <stdio.h>

int i, j, a, b, c;

int nwd(int a, int b) {
	if(b == 0)
		return a;
	return nwd(b, a % b);
}

int main() {
	int r = 0;
	scanf("%d%d%d", &a, &b, &c);
	for(i = 0; i <= a; i += c)
		for(j = 0; j <= b; j += c)
			if(nwd(i, j) == c) {
				printf("%d %d\n", i, j);
				r++;
			}
	printf("[%d]\n", r - 2);
	return 0;
}
