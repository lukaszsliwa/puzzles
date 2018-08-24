#include <cstdio>
using namespace std;

struct bignum {
	size_t size;
	int tab[1001];
	bignum() : size(0) {}
	bignum(const bignum& v) : size(v.size) {
		for(int i = 0; i < v.size; ++i)
			tab[i] = v.tab[i];
	}
};

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

int foo(const int* T, int s) {
	return (s >= 0 ? T[s] : 0);
}

void operator + (const bignum& a, const bignum& b) {
	int wynik[1001], i = 0, reszta = 0;
	int a_len = a.size, b_len = b.size;
	while(a_len > 0 || b_len > 0) {
		wynik[i] = foo(a.tab, a_len - 1) + foo(b.tab, b_len - 1) + reszta;
		reszta = 0;
		if(wynik[i] > 9) {
			wynik[i] %= 10;
			reszta = 1;
		}
		a_len--; b_len--; i++;
	}
	if(reszta == 1)
		wynik[i++] = reszta;
	for(int p = 0; p < i / 2; ++p)
		swap(wynik[p], wynik[i - p - 1]);
	for(int p = 0; p < i; ++p)
		printf("%d", wynik[p]);
	printf("\n");

}

inline void get(bignum& v) {
	char znak; int l = 0;
	while((znak = getchar_unlocked()) && (znak < '0' || znak > '9'));
	v.tab[l++] = znak - '0';
	while((znak = getchar_unlocked()) && znak >= '0' && znak <= '9')
		v.tab[l++] = znak - '0';
	v.size = l;
}

int main() {
	int t;
	bignum a, b;
	scanf("%d", &t);
	while(t--) {
		get(a); get(b);
		a + b;
	}
}
