#include <iostream>
using namespace std;

float a, b, c;

int main() {
	cin >> a >> b >> c;
	if(a == 0.0 && c == b)
		cout << "NWR" << endl;
	else if(a == 0.0 && c != b)
		cout << "BR" << endl;
	else
		printf("%.2f\n", (c - b) / a);
}
