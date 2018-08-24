#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	long long int liczba;
	short int len = 0, index = 0;
	bool ciekawa[30];
	scanf("%lld", &liczba);
	liczba++;
	len = (short int)log2((double)(liczba));
	while(len--) {
		ciekawa[index++] = liczba % 2;
		liczba /= 2;
	}
	while(index--)
		printf(ciekawa[index] ? "6" : "5");
	printf("\n");
}
