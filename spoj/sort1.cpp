#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

struct punkt {
	string nazwa;
	int x, y;
	double odleglosc;
	punkt(string& naz, int xx, int yy, double odl) {
		nazwa = naz;
		x = xx;
		y = yy;
		odleglosc = odl;
	}

	/*bool operator < (punkt& P) const {
		return odleglosc > P.odleglosc;
	}*/
};

bool operator < (const punkt& a, const punkt& b) {
	return a.odleglosc > b.odleglosc;
}

vector<punkt> p;

int main() {
	string nazwa;
	int t, n, x, y;
	cin >> t;
	while(t--) {
		cin >> n;
		while(n--) {
			cin >> nazwa >> x >> y;
			p.push_back(punkt(nazwa, x, y, (double)sqrt(x*x + y*y)));
		}
		sort(p.begin(), p.end());
		while(!p.empty()) {
			cout << p.back().nazwa << " " 
				<< p.back().x << " " 
				<< p.back().y << endl;
			p.pop_back();
		}
		cout << endl;
	}
}
