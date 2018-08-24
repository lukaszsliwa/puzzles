#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Line {
	string name, attrs;
	Line(string nn, string aa) : name(nn), attrs(aa) {}
};

vector<Line> text;

int main() {
	string line;
	cin >> line;
	text.push_back(line);
	while(cin >> line) {
		string name;
		istringstream p(line);
		vector<string> linev;
		p >> name;
		name.erase(0, 1);
		while(p >> tmp)
			linev.push_back(tmp);
		sort(linev.begin(), linev.end());
		tmp = "";
		for(int i = 0; i < linev.size(); ++i)
			tmp += linev[i];
		text.push_back(Line(name, ));
	}
}
