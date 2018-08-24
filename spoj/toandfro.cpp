#include <stdio.h>
#include <string.h>

const int M = 201;
char text[M];

void swap(char& a, char& b) {
	char t = a;
	a = b; b = t;
}

main() {
	int n, i, j, k, w, len;
	while(scanf("%d", &n) && n != 0) {
		scanf("%s", text);
		len = strlen(text);
		for(i = 0, w = 0; i < len; i += n, ++w)
			for(j = i, k = 1; k <= n / 2 && (w % 2) != 0; ++j, ++k)
				swap(text[j], text[i + n - k]);
		for(i = 0; i < n; ++i)
			for(j = i; j < len; j += n)
				printf("%c", text[j]);
		printf("\n");
	}
}
