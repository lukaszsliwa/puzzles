#include <iostream>
#include <string>
using namespace std;

string a, b;

string string_merge(string& x, string& y) {
	int x_len = 0, y_len = 0;
	int len = min(x.length(), y.length());
	bool next = true;
	string s = "";
	for(int i = 0; i < 2 * len; ++i) {
		if(next)
			s += x[x_len++];
		else
			s += y[y_len++];
		next = !next;
	}
	return s;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		cin >> a >> b;
		cout << string_merge(a, b) << endl;
	}
}
