#include <iostream>
using namespace std;

char znak;
int a, b, reg[10];

int main() {
	while(cin >> znak >> a >> b) {
		if(znak == 'z')
			reg[a] = b;
		else if(znak == '+')
			cout << (reg[a] + reg[b]) << endl;
		else if(znak == '-')
			cout << (reg[a] - reg[b]) << endl;
		else if(znak == '*')
			cout << (reg[a] * reg[b]) << endl;
		else if(znak == '/')
			cout << (reg[a] / reg[b]) << endl;
		else
			cout << (reg[a] % reg[b]) << endl;
	}
}
