#include <iostream>
using namespace std;

int nwd(int a, int b) {
	int t;
	while(b > 0) {
		t = a;
		a = b;
		b = t % b;
	}
	return a;
}

int nww(int a, int b) {
	return a * b / nwd(a, b);
}

int main() {
	int t, a, b;
	cin >> t;
	while(t--) {
		cin >> a >> b;
		cout << nww(a, b) << endl;
	}
}
