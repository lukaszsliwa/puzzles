#include <iostream>
using namespace std;

int main() {
	int a, b;
	char znak;
	while(cin >> znak >> a >> b) {
		if(znak == '+')
			cout << (a + b) << endl;
		else if(znak == '-')
			cout << (a - b) << endl;
		else if(znak == '*')
			cout << (a * b) << endl;
		else if(znak == '/')
			cout << (a / b) << endl;
		else if(znak == '%')
			cout << (a % b) << endl;
	}
}
