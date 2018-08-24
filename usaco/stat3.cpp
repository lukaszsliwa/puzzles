// PROG: stat3
// LANG: C++
// ID: crh
#include <fstream>
#include <cmath>
using namespace std;

main() {
	int n, v, s = 0;
	ifstream f("stat3.in");
	f >> n;
	while(f >> v) {
		s += v;
		if(v == 0)
			n--;
	}
	ofstream p("stat3.out");
	s = (int)(((float)s / (float)n) * 10);
	p << s << endl;
}
