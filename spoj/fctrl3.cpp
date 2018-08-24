#include <cstdio>
using namespace std;

int silnia(int n) {
	int i, s = 0;
	if(n > 9)
		return 0;
	for(i = s = 1; i <= n && n <= 9; ++i)
		s *= i;
	return s;

}

int main() {
	int d, n;
	scanf("%d", &d);
	while(d--) {
		scanf("%d", &n);
		printf("%d %d\n", ((silnia(n) - silnia(n) % 10) / 10) % 10, silnia(n) % 10);
	}
}
