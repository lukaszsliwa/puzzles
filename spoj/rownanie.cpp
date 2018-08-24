#include <iostream>
using namespace std;

float a, b, c, delta;

int main() {
	while(cin >> a >> b >> c) {
		delta = b * b - 4 * a * c;
		if(delta == 0)
			cout << 1 << endl;
		else if(delta < 0)
			cout << 0 << endl;
		else
			cout << 2 << endl;
	}
}
