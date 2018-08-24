#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

double tab[1000];

int main() {
	int t, n;
	double srednia;
	cin >> t;
	while(t--) {
		cin >> n;
		srednia = 0.0;
		for(int i = 0; i < n; ++i) {
			cin >> tab[i];
			srednia += tab[i];
		}
		srednia /= n;
		double roznica = fabs(srednia - tab[0]);
		int val = (int)tab[0];
		for(int i = 0; i < n; ++i)
			if(roznica > fabs(srednia - tab[i])) {
				roznica = fabs(srednia - tab[i]);
				val = (int)tab[i];
			}
		cout << val << endl;

	}
}
