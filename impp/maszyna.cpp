#include <stdio.h>
#include <string.h>
main() {
	char b[256]; int R = 0, i, c;
	scanf("%d", &c);
	while(c--) {
		scanf("%s", b);
		for(R = 0, i = strlen(b) - 1; i >= 0; --i)
			if(b[i] == '1')
				R += i % 2 == 0 ? 1 : 2;
		printf("%d\n", R % 3 == 0 ? 0 : 1);
	}
}
