#include <cstdio>
using namespace std;

bool pierwsza[10003];

void pierwsze(int n) {
	for(int i = 1; i <= n; ++i)
		pierwsza[i] = true;
	pierwsza[1] = false;
	for(int i = 2; i <= n; ++i) {
		if(pierwsza[i] == true) {
			int k = 2 * i;
			while(k <= n) {
				pierwsza[k] = false;
				k += i;
			}
		}
	}
}

int main() {
	int t, v;
	scanf("%d", &t);
	pierwsze(10001);
	while(t--) {
		scanf("%d", &v);
		printf(pierwsza[v] ? "TAK\n" : "NIE\n");
	}
}
