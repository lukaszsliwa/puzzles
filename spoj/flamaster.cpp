#include <iostream>
using namespace std;

int t, i;
string line;

int main() {
	cin >> t;
	while(t--) {
		cin >> line;
		i = 0;
		while(i < line.size()) {
			if(line[i] == line[i + 1] &&
				line[i + 1] == line[i + 2]) {
				int ile = 1;
				while(i < line.size() && 
					line[i] == line[i + 1]) {
					ile++;
					i++;
				}
				cout << line[i++] << ile;
			} else {
				cout << line[i];
				i++;
			}
		}
		cout << endl;
	}
}
