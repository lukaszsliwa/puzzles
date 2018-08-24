#include <cstdio>
#include <cmath>
using namespace std;

bool bin(int l, int bb) {
	int len = 0, tab[13];
	while(l > 0) {
		tab[len++] = l % 2;
		l /= 2;
	}
	if(len <= bb) {
		for(int i = 0; i < bb - len; ++i)
			printf("0");
		for(int i = len - 1; i >= 0; --i)
			printf("%d", tab[i]);
	} else
		return false;
	printf("\n");
	return true;
}

int main() {
	int t, b;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &b);
		for(int i = 0; i < b; ++i)
			printf("0");
		printf("\n");
		for(int liczba = 1; bin(liczba ^ (liczba >> 1), b); liczba++);

		printf("\n");
	}
}
