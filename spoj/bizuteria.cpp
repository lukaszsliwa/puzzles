#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> v;
string line;

bool foo(const string& a, const string& b) {
	return a.size() < b.size() || a .size() == b.size() && a < b;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> line;
		v.push_back(line);
	}
	sort(v.begin(), v.end(), foo);
	for(vector<string>::iterator it = v.begin();
		it != v.end(); ++it)
		cout << *it << endl;
}
