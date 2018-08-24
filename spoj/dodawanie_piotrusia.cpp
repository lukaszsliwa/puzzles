#include <iostream>
using namespace std;

int obroc(int v) {
	int t = 0;
	while(v > 0) {
		int cyfra = v % 10;
		t = t * 10 + cyfra;
		v = (v - cyfra) / 10;
	}
	return t;
}

int main() {
	int a, b, t, R = 0;
	cin >> t;
	while(t--) {
		cin >> a;
		R = 0;
		while((b = obroc(a)) != a) {
			a += b;
			R++;
		}
		cout << a << " " << R << endl;
	}
}
