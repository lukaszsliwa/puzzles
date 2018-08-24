/*
ID: crh
LANG: C++
TASK: gift1
*/
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<string, int> s;
vector<string> w;

main() {
	string giver;
	int h, m, n, i, d;
	ifstream in("gift1.in");
	ofstream out("gift1.out");
	in >> n;
	for(i = 1; i <= n; ++i) {
		in >> giver;
		w.push_back(giver);
	}
	while(n--) {
		in >> giver;
		in >> h >> m;
		if(m != 0)
			d = (h % m == 0) ? h / m : (h - (h % m)) / m;
		s[giver] -= (d * m);
		while(m--) {
			in >> giver;
			s[giver] += d;
		}
	}
	for(vector<string>::iterator y = w.begin();
		y != w.end(); ++y)
		out << *y << " " << s[*y] << endl;
}
