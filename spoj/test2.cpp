#include <stdio.h>

int l, p = -1;

int main() {
	while(true) {
		scanf("%d", &l);
		printf("%d\n", l);
		if(p == 42 && l == 42)
			break;
		p = l;
	}
}
