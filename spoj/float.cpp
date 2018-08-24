#include <cstdio>
using namespace std;

int n;
float v;

int main() {
	scanf("%d", &n);
	while(n--) {
		scanf("%f", &v);
		for(int i = sizeof v - 1; i >= 0; --i)
			printf("%x ", ((const unsigned char*)&v)[i]);
		printf("\n");
	}
}
