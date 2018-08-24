#include <stdio.h>

struct drzewo {
	int x, y, l, p;
	drzewo *lewy, *prawy;
	drzewo() {
		x = y = l = p = 0;
		lewy = prawy = 0;
	}
	drzewo(int xx, int yy) {
		x = xx; y = yy;
	}
} *root;

int n;

int getint() {
	int t; scanf("%d", &t);
	return t;
}

void utworz_drzewo(drzewo*& r, int a, int b) {
	r = new drzewo(a, b);
	if(b - a > 0) {
		utworz_drzewo(r->lewy, a, (a + b) / 2);
		utworz_drzewo(r->prawy, (a + b) / 2 + 1, b);
	}
}

void ustaw(int& a, int& b, int aa, int bb) {
	a = aa; b = bb;
}

void wstaw(drzewo* r, int p, int l) {
	if(r != 0) {
		int x = r->x, y = r->y;
		if(x == p && p == y) {
			if(l < 0) /* ) */
				ustaw(r->l, r->p, 0, 1);
			else	/* ( */
				ustaw(r->l, r->p, 1, 0);
		} else if(p <= (x + y) / 2)
			wstaw(r->lewy, p, l);
		else
			wstaw(r->prawy, p, l);
		if(r->lewy != 0 && r->prawy != 0) {
			if(r->lewy->l <= r->prawy->p) {
				r->l = r->prawy->l;
				r->p = r->lewy->p + r->prawy->p - r->lewy->l;
			} else {
				r->p = r->lewy->p;
				r->l = r->lewy->l + r->prawy->l - r->prawy->p;
			}
		}
	}
}

void swap(int& a, int& b) {
	int t = b;
	b = a;
	a = t;
}

void zamien(drzewo* r, int l) {
	if(r != 0) {
		int x = r->x, y = r->y;
		if(x == l && l == y) {
			swap(r->l, r->p);
		} else if(l <= (x + y) / 2)
			zamien(r->lewy, l);
		else
			zamien(r->prawy, l);
		if(r->lewy != 0 && r->prawy != 0) {
			if(r->lewy->l <= r->prawy->p) {
				r->l = r->prawy->l;
				r->p = r->lewy->p + r->prawy->p - r->lewy->l;
			} else {
				r->p = r->lewy->p;
				r->l = r->lewy->l + r->prawy->l - r->prawy->p;
			}
		}
	}

}

char* poprawny() {
	if(root->l == 0 && 
		root->p == 0)
		return "TAK";
	else
		return "NIE";
}

main() {
	int l;
	n = getint();
	utworz_drzewo(root, 1, n);
	for(int i = 1; i <= n; ++i)
		wstaw(root, i, getint());
	while((l = getint()) != -1)
		if(l == 0)
			puts(poprawny());
		else
			zamien(root, l);
}
