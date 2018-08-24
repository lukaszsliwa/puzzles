#include <stdio.h>

using namespace std;

struct stack {
	int index, tab[1001];
	stack() { index = -1; }
	void push(int& e) {
		tab[++index] = e;
	}
	void pop() {
		index--;
	}
	int top() {
		return tab[index];
	}
	bool empty() {
		return index < 0;
	}
	void clear() {
		index = -1;
	}
} s;

int getint() {
	int t;
	char znak;
	while((znak = getchar_unlocked()) 
		&& (znak < '0' || znak > '9'));
	t = znak - '0';
	while((znak = getchar_unlocked()) 
		&& znak <= '9' && znak >= '0')
		t = t * 10 + znak - '0';
	return t;
}

main() {
	int t, index, l;
	while((t = getint()) && t != 0) {
		index = 1;
		while(t--) {
			l = getint();
			if(l != index)
				s.push(l);
			else
				index++;
			while(!s.empty() && index == s.top()) {
				s.pop();
				index++;
			}
		}
		puts(s.empty() ? "yes" : "no");
		s.clear();
	}
}
