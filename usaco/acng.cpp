// PROG: acng
// LANG: C++

#include <cstdio>

using namespace std;

int n, next_value, score = 0;

void wczytaj() {
	FILE *f;
	f = fopen("acng.in", "r");
	fscanf(f, "%d", &n);
	fclose(f);
}

void wypisz(int e) {
	FILE *f;
	f = fopen("acng.out", "w");
	fprintf(f, "%d\n", e);
	fclose(f);
}

int main() {
	wczytaj();
	//scanf("%d", &n);
	if(n % 2 != 0)
		next_value = n * 3 + 1;
	else
		next_value = n / 2;
	score++;
	while(next_value > 1) {
		n = next_value;
		if(n % 2 != 0)
			next_value = n * 3 + 1;
		else
			next_value /= 2;
		score++;
	}
	//printf("%d", score);
	wypisz(score);
	return 0;
}
