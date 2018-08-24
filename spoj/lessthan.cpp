#include <algorithm>
#include <vector>
#include <cstdio>

int t, k;

const int MAX = 31;

struct bignum {
	char cyfra[MAX];
	int size;
	bignum() : size(0) {}
	bignum(const bignum& a) {
		for(int i = 0; i < a.size; ++i)
			cyfra[i] = a.cyfra[i];
		size = a.size;
	}
};

bool operator < (const bignum& A, const bignum& B) {
	if(A.size != B.size)
		return A.size < B.size;

	int p = 0;
	while(p < A.size) {
		if(A.cyfra[p] < B.cyfra[p])
			return true;
		else if(A.cyfra[p] > B.cyfra[p])
			return false;
		p++;
	}

	return false;
}

std::vector<bignum> A;

void print(const char*, int);

bool foo(const bignum& A, const bignum& B) {

	return A < B;
}

int pos(bignum& v) {
	int s = 1, e = A.size();
	while(s <= e) {
		int mid = (s + e) / 2;
		
		/*print(A[mid - 1].cyfra, A[mid - 1].size);
		print(v.cyfra, v.size);
		printf(" %d\n", A[mid - 1] < v);*/

		if(A[mid - 1] < v)
			s = mid + 1;
		else
			e = mid - 1;
	}
	return s - 1;
}

void get_string(bignum& e) {
	scanf("%s", e.cyfra);
	e.size = strlen(e.cyfra);
}

void print(const char* tab, int s) {
	for(int i = 0; i < s; ++i)
		printf("%c", tab[i]);
	printf(" ");
}

typedef std::vector<bignum>::iterator vec_iter;

int main() {
	bignum var;

	std::scanf("%d", &t);
	while(t--) {
		get_string(var);
		
		//print(var.cyfra, var.size);

		A.push_back(bignum(var));
	}
	sort(A.begin(), A.end(), foo);

	//for(vec_iter it = A.begin(); it != A.end(); ++it)
	//	print(it->cyfra, it->size);
	//for(int i = 0; i < A.size(); ++i)
	//	print(A[i].cyfra, A[i].size);

	std::scanf("%d", &k);
	while(k--) {
		get_string(var);
		std::printf("%d\n", pos(var));
	}
}
