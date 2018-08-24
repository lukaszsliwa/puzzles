#include <deque>
#include <iostream>
using namespace std;

deque<int> K;

int main() {
	int val;
	while(cin >> val) {
		if(K.size() == 6)
			K.pop_front();

		K.push_back(val);
		cout << val << endl;
		if((K[1] == 42 && K[3] == 42 && K[5] == 42) ||
			(K[1] == 42 && K[2] == 42 && K[3] == 42))
			break;
	}
}
