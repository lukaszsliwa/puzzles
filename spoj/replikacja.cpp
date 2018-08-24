#include <iostream>
#include <string>
using namespace std;

int t, v;
string text;

int main() {
	cin >> t;
	while(t--) {
		cin >> v >> text;
		while(v--)
			cout << text;
		cout << endl;
	}
}
