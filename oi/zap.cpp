#include <stdio.h>

const int n_max = 50005;
const int k_max = 2000;
int n, zap_tab[n_max], zap_ktab[k_max][k_max];

int min(int& x, int& y) {
	return x < y ? x : y;
}

int max(int& x, int& y) {
	return x < y ? y : x;
}

int zap2(int i) {
	int j, r;
	if(zap_tab[i] != 0)
		return zap_tab[i];
	for(r = 0, j = 2; j <= i; ++j)
		r += (zap_tab[i / j] = zap2(i / j));
	return (zap_tab[i] = i * i - r);
}

void set(int i, int j, int v) {
	if(i < k_max && j < k_max)
		zap_ktab[i][j] = v;
}

int zap(int i, int j) {
	int k, r, w;
	if(i == j) {
		w = zap2(i);
		set(i, i, w);
		return w;
	} else if(i == 1 || j == 1)
		return max(i, j);
	else if(i < k_max && j < k_max && zap_ktab[i][j] != 0)
			return zap_ktab[i][j];
	else if(i == j)
		return zap2(i);
	for(r = 0, k = 2; k <= min(i, j); ++k) {
		w = zap(min(i, j) / k, max(i, j) / k);
		set(min(i, j) / k, max(i, j) / k, w);
		r += w;
	}
	set(i, j, i * j - r);
	return i * j - r;
}

int main() {
	int a, b, c;
	scanf("%d", &n);
	zap_tab[1] = 1;
	while(n--) {
		scanf("%d%d%d", &a, &b, &c);
		printf("%d\n", zap(min(a, b) / c, max(a, b) / c));
	}
	return 0;
}
