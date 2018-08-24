#include <cstdio>
#include <vector>
#include <algorithm>

struct ulamek {
	int licznik, mianownik;
	ulamek(int ll, int mm) {
		licznik = ll;
		mianownik = mm;
	}
	bool operator < (const ulamek& U) const {
		int w = abs(mianownik * U.mianownik);
		int a = licznik * (w / mianownik);
		int b = U.licznik * (w / U.mianownik);
		return a > b || (a == b && mianownik > U.mianownik);
	}
};

std::vector<ulamek> w;

int main() {
	int a, b, t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d/%d", &a, &b);
		w.push_back(ulamek(a, b));
	}
	std::sort(w.begin(), w.end());
	while(!w.empty()) {
		printf("%d/%d\n", w.back().licznik, w.back().mianownik);
		w.pop_back();
	}
}
