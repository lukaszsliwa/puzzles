#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int t;
const int MAX = 10001;

struct bignum {
	int cyfry[MAX];
	size_t size;
	bignum() : size(0) {}
	bignum(char tab[], size_t t) {
		for(int i = 0; i < t; ++i)
			cyfry[i] = tab[i];
		size = t;
	}
	bignum operator = (const bignum& v) {
		return bignum(v.cyfry, v.size);
	}
};

bignum operator * (const bignum& a, const bignum& b) {
	bignum liczba1, liczba2;
	if(a.size < b.size) {
		liczba1 = b;
		liczba2 = a;
	} else {
		liczba1 = a;
		liczba2 = b;
	}


}

void get(bignum& v) {
	char znak;
	int len = 0;
	while((znak = getchar_unlocked()) &&
		(znak < '0' || znak > '9'));
	v.cyfry[len++] = znak - '0';
	while((znak = getchar_unlocked()) &&
		(znak >= '0' && znak <= '9'))
		v.cyfry[len++] = znak - '0';
	v.size = len;
}

#define input(A, B) get(A); get(B);

void output(const bignum& v) {
	for(int i = 0; i < v.size; ++i)
		putchar(v.cyfry[i] + '0');
	putchar('\n');
}

int main() {
	bignum a, b;

	scanf("%d", &t);
	while(t--) {
		input(a, b);
		output(a * b);
	}
}
