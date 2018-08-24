#include <iostream.h>

char tab[101];

#define small_letter(X) \
	(X >= 'a' && X <= 'z')
#define big_letter(X) \
	(X >= 'A' && X <= 'Z')

void putstring(char t[], int& l) {
	int i;
	for(i = 0; i < l; ++i)
		putchar_unlocked(t[i]);
	putchar_unlocked('\n');
}

void translate_on_java(char t[], int& l) {
	int i;
	bool space = false;
	for(i = 0; i < l; ++i) 
		if(t[i] == '_')
			space = true;
		else if(space) {
			putchar_unlocked(t[i] - 32);
			space = false;
		} else
			putchar_unlocked(t[i]);
	putchar_unlocked('\n');
}

void translate_on_c(char t[], int& l) {
	int i;
	for(i = 0; i < l; ++i)
		if(big_letter(t[i])) {
			putchar_unlocked('_');
			putchar_unlocked(t[i] + 32);
		} else
			putchar_unlocked(t[i]);
	putchar_unlocked('\n');
}

void check(char t[], bool& c, bool& j, int& l) {
	int i;
	c = j = false;
	if(big_letter(t[0]) || t[0] == '_' || t[l - 1] == '_') {
		c = j = true;
		return ;
	}
	for(i = 1; i < l; ++i)
		if(t[i] == '_' && t[i - 1] == '_')
			c = j = true;
		else if(t[i] == '_')
			c = true;
		else if(big_letter(t[i]))
			j = true;
}

main() {
	int len;
	bool c, java;
	while(cin >> tab) {
		len = strlen(tab);
		printf("%s: ", tab);
		check(tab, c, java, len);
		if(c && java)
			printf("Error!\n");
		else if(!c && !java)
			printf("%s\n", tab);
		else if(c)
			translate_on_java(tab, len);
		else
			translate_on_c(tab, len);
	}
}
