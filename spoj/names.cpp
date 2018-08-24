#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

map<string, int> names;

inline string name(const string& n) {
	size_t len = n.size() - 1;
	while(n[len] != ' ' && len--);
	string ret;
	for(size_t i = len + 1; i < n.size(); ++i)
		ret += toupper(n[i]);
	return ret;
}

typedef map<string, int>::iterator map_iter;

struct r {
	string name;
	int val;
	r() {}
	r(string n, int v) : name(n), val(v) {}
};

bool operator < (const r& a, const r& b) {
	return a.val < b.val || 
		(a.val == b.val && a.name > b.name);
}

vector<r> vec;

int main() {
	string line;
	while(getline(cin, line))
		names[name(line)]++;
	for(map_iter it = names.begin();
		it != names.end(); ++it)
		vec.push_back(r(it->first, it->second));
	sort(vec.begin(), vec.end());
	while(!vec.empty()) {
		cout << vec.back().name << " " << vec.back().val << endl;
		vec.pop_back();
	}
}
