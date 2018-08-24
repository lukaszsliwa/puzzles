#include <iostream>
#include <vector>
#include <string>
using namespace std;

class towar {
public:
	string kod;
	int a, b;
	towar(string k, int x, int y) {
		kod = k;
		a = x;
		b = y;
	}
	bool operator < (const towar& T) const {
		return kod > T.kod;
	}
};

vector<towar> w;

int main() {
	int l, t, a, b;
	string kod;
	cin >> t;
	while(t--) {
		cin >> l;
		while(l--) {
			cin >> kod >> a >> b;
			w.push_back(towar(kod, a, b));
		}
		sort(w.begin(), w.end());
		while(!w.empty()) {
			cout << w.back().kod << " " << w.back().a << " " << w.back().b << endl;
			w.pop_back();
		}
	}
}
