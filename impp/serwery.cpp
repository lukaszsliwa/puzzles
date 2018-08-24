#include <cstdio>
using namespace std;

const int M = 101;

int main() {
	unsigned int index = 0, n, t, tab[M];
	scanf("%d", &n);
	while(n--) {
		long long int suma = 0;
		scanf("%d", &t);
		index = 0;
		for(int i = 0; i < t; ++i) {
			scanf("%d", &tab[i]);
			if(tab[index] < tab[i])
				index = i;
		}
		for(int i = 0; i < t; ++i)
			if(i != index)
				suma += tab[i];
		printf("%lld\n", suma);
	}
}
