#include <queue>
#include <iostream>
using namespace std;

struct pat {
	int d;
	pat(int dd) : d(dd) {}
	bool operator < (const pat& P) const {
		return d == P.d;
	}
};

priority_queue<pat> q;

main() {
	int n, a, b, l;
	cin >> n;
	while(n--) {
		cin >> l;
		q.push(pat(l));
	}
	while(!q.empty()) {
		a = q.top().d;
		q.pop();
		cout << a << ' ';
		if(!q.empty()) {
			b = q.top().d;
			cout << b;
			q.pop();
			if(a == b)
				q.push(pat(a + b));
			else {
				q.push(pat(b));
				q.push(pat(a));
				break;
			}
		} else {
			q.push(pat(a));
			break;
		}
		cout << endl;
	}
	cout << endl << q.size() << endl;
}
