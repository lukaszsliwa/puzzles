#include <iostream>
#include <string>
#include <iterator>
#include <vector>
using namespace std;

vector<string> w;

void clean(string& t) {
	string p;
	for(int i = 0 ; i < t.length(); ++i)
		if(t[i] != '-')
			p += tolower(t[i]);
	t = p;
}
main() {
	string nazwa;
	int n;
	cin >> n;
	while(n--) {
		cin >> nazwa;
		clean(nazwa);
		w.push_back(nazwa);
	}
	sort(w.begin(), w.end());
	cout << distance(w.begin(), unique(w.begin(), w.end()));
	
}
