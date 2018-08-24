#include <iostream>
using namespace std;

int main() {
    int find, n, value;
    while(cin >> find >> n) {
        int count = 0;
	while(n--) {
	    cin >> value;
	    if(value == find) count++;
	}
	cout << count << endl;
    }
}
