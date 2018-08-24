#include <iostream>
#include <string>
using namespace std;

int t;
string text;

int main() {
	cin >> t;
	while(t--) {
		cin >> text;
		for(int i = 0; i < text.length() / 2; ++i)
			cout << text[i];
		cout << endl;
	}
}
