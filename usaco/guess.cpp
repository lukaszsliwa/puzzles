// PROG: guess
// LANG: C++

#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int m, lewy = 0, prawy;
	char odpowiedz[3];
	bool stop = false;
	setbuf(stdout, 0);
	scanf("%d", &prawy);
	while(!stop) {
		m = (lewy + prawy + 1) / 2;
		printf("%d\n", m);
		scanf("%s", odpowiedz);
		if(strlen(odpowiedz) > 1)
			stop = true;
		else if(odpowiedz[0] == 'L')
			lewy = m;
		else
			prawy = m;
	}
	return 0;
}
