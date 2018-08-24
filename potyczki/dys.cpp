#include <stdio.h>

const int m = 100001;

int main() {
	int n, r = 0;
	char a[m], b[m];
	scanf("%d%s%s", &n, a, b);
	for(int i = 0; i < n; ++i)
		if(a[i] != b[i]) r++;
	printf("%d", r);
}
