#include <stdio.h>
#include <math.h>

main() {
	int c, n, l;
	double R = 0.0;
	bool zero;
	scanf("%d", &c);
	while(c--) {
		scanf("%d", &n);
		R = 0.0;
		zero = false;
		while(n--) {
			scanf("%d", &l);
			if(l == 0)
				zero = true;
			R += (double)log10((double)l);
		}
		if(zero)
			printf("1\n");
		else
			printf("%d\n", (int)floor(R + 1.0));
	}
}
