#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

struct towar {
	string nazwa;
	int zloty, groszy;
	towar(string naz, int z, int g) {
		nazwa = naz;
		zloty = z;
		groszy = g;
	}
};

bool operator < (const towar& a, const towar& b) {
	return a.zloty > b.zloty || 
		(a.zloty == b.zloty && a.groszy > b.groszy);
}

vector<towar> t;

int main() {
	string nazwa;
	int l, x, y, n;
	cin >> l;
	while(l--) {
		cin >> n;
		while(n--) {
			cin >> nazwa >> x >> y;
			t.push_back(towar(nazwa, x, y));
		}
		sort(t.begin(), t.end());
		while(!t.empty()) {
			cout << t.back().nazwa << " " <<
			t.back().zloty << " " << t.back().groszy << endl;
			t.pop_back();
		}
	}
}
