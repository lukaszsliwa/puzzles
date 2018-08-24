#include <stdio.h>
main() {
	int l;
	while(scanf("%d", &l) && l != 42)
		printf("%d\n", l);
}
