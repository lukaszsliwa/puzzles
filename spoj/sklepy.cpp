#include <cstdio>
#include <map>
#include <vector>
using namespace std;

map<unsigned int, unsigned int> suma;
vector<unsigned int> lista;

int main() {
	int t;
	unsigned int a, b;
	scanf("%d", &t);
	while(t--) {
		scanf("%u %u", &a, &b);
		if(suma[a] == 0)
			lista.push_back(a);
		suma[a] += b;
	}
	printf("%u\n", lista.size());
	for(int i = 0; i != lista.size(); ++i)
		printf("%u %u\n", lista[i], suma[lista[i]]);
}
