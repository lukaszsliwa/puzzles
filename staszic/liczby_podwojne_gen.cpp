#include <iostream>
using namespace std;

bool sprawdz(long long int e) {
	long long int c, last = e % 10;;
	bool zmiana = false;
	while(e > 0) {
		c = e % 10;
		if(last != c && zmiana)
			return false;
		else if(last != c)
			zmiana = true;
		e = (e - e % 10) / 10;
		last = c;
	}
	return zmiana;
}

main() {
	long long int i, w, t;
	//cin >> t;
	for(w = 1; w <= 100000; ++w) {
		//cin >> w;
		for(i = 2; sprawdz(w * i) == false; ++i);
		cout << w << ' ' << w * i << endl; //<< " = " << w << " * " << i << endl;
	}
}
