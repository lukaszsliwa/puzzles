#include <cstdio>
#include <cstring>
using namespace std;

char* nazwa(const short unsigned int& t, int index) {
	if(index == 0) {
		if(t == 1) return "jeden ";
		if(t == 2) return "dwa ";
		if(t == 3) return "trzy ";
		if(t == 4) return "cztery ";
		if(t == 5) return "piec ";
		if(t == 6) return "szesc ";
		if(t == 7) return "siedem ";
		if(t == 8) return "osiem ";
		if(t == 9) return "dziewiec ";
		if(t == 10) return "dziesiec ";
		if(t == 11) return "jedenascie ";
		if(t == 12) return "dwanascie ";
		if(t == 13) return "trzynascie ";
		if(t == 14) return "czternascie ";
		if(t == 15) return "pietnascie ";
		if(t == 16) return "szesnascie ";
		if(t == 17) return "siedemnascie ";
		if(t == 18) return "osiemnascie ";
		if(t == 19) return "dziewietnascie ";
	} else if(index == 1) {
		if(t == 1) return "dziesiec ";
		if(t == 2) return "dwadziescia ";
		if(t == 3) return "trzydziesci ";
		if(t == 4) return "czterdziesci ";
		if(t == 5) return "piecdziesiat ";
		if(t == 6) return "szescdziesiat ";
		if(t == 7) return "siedemdziesiat ";
		if(t == 8) return "osiemdziesiat ";
		if(t == 9) return "dziewiecdziesiat ";
	} else if(index == 2) {
		if(t == 1) return "sto ";
		if(t == 2) return "dwiescie ";
		if(t == 3) return "trzysta ";
		if(t == 4) return "czterysta ";
		if(t == 5) return "piecset ";
		if(t == 6) return "szescset ";
		if(t == 7) return "siedemset ";
		if(t == 8) return "osiemset ";
		if(t == 9) return "dziewiecset ";
	}
	return "";
}

int main() {
	unsigned int n, liczba;
	short unsigned int tab[15];
	char li[15];
	scanf("%u", &n);
	while(n--) {
		scanf("%s", li);
		int len = strlen(li), index;
		for(int i = 0; i < len; ++i)
			tab[len - i - 1] = li[i] - '0';
		bool zero = true;
		for(index = len - 1; index >= 0; index--) {
			if(index % 3 == 1 && tab[index] == 1 && index >= 1) {
				if(zero && (tab[index] != 0 || tab[index - 1] != 0))
					zero = false;
				printf("%s", nazwa(10 + tab[--index], 0));
			} else {
				if(zero && tab[index] != 0)
					zero = false;
				printf("%s", nazwa(tab[index], index % 3));
			}
			if(index == 3 && !zero) {
				printf("tys. ");
				zero = true;
			} else if(index == 6 && !zero) {
				printf("mln. ");
				zero = true;
			} else if(index == 9 && !zero) {
				printf("mld. ");
				zero = true;
			} else if(index == 12 && !zero) {
				printf("bln. ");
				zero = true;
			}
		}
		printf("\n");
	}
}
