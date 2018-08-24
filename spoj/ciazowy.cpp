#include <iostream>
#include <cmath>
using namespace std;

inline int r(int x, int y, int z) {
	int n = abs(x + y - z * y) * 12;
	int d = abs(z - 1);
	int r = n / d;
	if(n % d && n % d >= (d + 1) / 2)
		r++;
	return r;
	
}

int main() {
	int t, x, y, z;
	cin >> t;
	while(t--) {
		cin >> x >> y >> z;
		cout << r(x, y, z) << endl;
	}
}
