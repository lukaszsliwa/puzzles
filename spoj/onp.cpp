#include <stdio.h>
#include <string.h>

int l = 0, len;
char expr[404];

void onp() {
	char znak = expr[l++], op;
	if(l < len) {
		if(znak == '(') {
			onp();
			op = expr[l++];
			onp();
			l++;
			putchar(op);
		} else
			putchar(znak);
	}
}

main() {
	int t = 0;
	scanf("%d", &t);
	while(t--) {
		scanf("%s", expr);
		len = strlen(expr);
		l = 0;
		onp();
		putchar('\n');
	}
}
