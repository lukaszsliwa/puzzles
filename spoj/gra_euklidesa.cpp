#include <iostream>
using namespace std;

inline long long int e(long long int a, long long int b) {
	long long int t;
	while(b > 0) {
		t = a;
		a = b;
		b = t % b;
	}
	return 2 * a;
}

int main() {
	long long int a, b;
	int t;
	cin >> t;
	while(t--) {
		cin >> a >> b;
		cout << e(a, b) << endl;
	}
}
