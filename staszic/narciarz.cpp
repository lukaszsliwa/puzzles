#include <iostream>
using namespace std;

const int n_max = 101;

class nar {
	int t, droga[n_max];
	bool krawedzie[n_max][n_max];
	int tab[n_max][n_max];
public:
	nar() {
		int i, y, x;
		cin >> t;
		for(i = 1; i <= t; ++i)
			for(y = 1; y <= t; ++y)
				cin >> krawedzie[i][y];
		for(i = 1; i <= t; ++i)
			droga[i] = 0;
		for(i = 1; i <= t; ++i) {
			for(y = i + 1; y <= t; ++y)
				if(krawedzie[i][y]) droga[y] = 1;
			for(y = i + 1; y <= t; ++y)
				for(x = y + 1; x <= t; ++x)
					if(krawedzie[y][x])
						droga[x] = (droga[x] + droga[y]) % 123456789;
			for(y = 1; y <= t; ++y) {
				tab[i][y] = droga[y];
				droga[y] = 0;
			}
		}
	}
	~nar() {
		int i, y;
		for(i = 1; i <= t; ++i) {
			for(y = 1; y <= t; ++y)
				cout << tab[i][y] << ' ';
			cout << endl;
		}
	}
};

main() {
	nar n;
}
