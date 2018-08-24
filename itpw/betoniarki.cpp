#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

const int N_MAX = 11;
const int puste = 0, moj_zawodnik = 1, przeciwnik = 2, beton = 3;

struct log {
	int x1, y1, x2, y2, xs, ys;
	log() { }
	log(int a, int b, int c, int d, int e, int f) {
		x1 = a; y1 = b;
		x2 = c; y2 = d;
		xs = e; ys = f;
	}
};

struct sam {
	int x, y;
	bool zablokowana;
	sam() { }
	sam(int xx, int yy, bool t = false) : x(xx), y(yy), zablokowana(t) { }
} samochod[5];

struct wsp_xy {
	int x, y;
	wsp_xy(int xx, int yy) : x(xx), y(yy) { }
};

queue<int> q_sam;
vector<log> ruchy_przeciwnika;

class betoniarki {
	/* 1 - niebieski, 2 - czerwony */
	int nr, czas;
	/* 0 - puste pole, 1 - moj zawodnik, 2 - przeciwnik, 3 - beton */
	int plansza[N_MAX][N_MAX];
	bool kogo_ruch;
public:
	betoniarki() : nr(-1), czas(0), kogo_ruch(false) { 
		int _l = 4;
		while(_l--)
			q_sam.push(_l);
	}
	void odbierz_numer() {
		scanf("%d", &nr);
		kogo_ruch = (nr == 1);
	}
	int odbierz_czas() {
		scanf("%d", &czas);
		return czas;
	}
	bool kto_rusza() {
		return kogo_ruch;
	}
	void wykonano() {
		kogo_ruch = !kogo_ruch;
	}
	void ustaw(int x, int y, int c) {
		plansza[x][y] = c;
	}
	void odbierz_ruch() {
		int a, b, c, d, e, f;
		scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
		ruchy_przeciwnika.push_back(log(a, b, c, d, e, f));
		ustaw(a, b, 0);
		ustaw(c, d, 2);
		ustaw(e, f, 3);
	}
	void przygotuj_plansze() {
		int A, B;
		if(nr == 1) {
			A = 1; B = 2;
		} else {
			A = 2; B = 1;
		}
		/* ustawienie niebieskich */
		ustaw(1, 7, A); ustaw(4, 10, A);
		ustaw(7, 10, A); ustaw(10, 7, A);
		/* ustawienie czerwonych */
		ustaw(1, 4, B); ustaw(4, 1, B);	
		ustaw(7, 1, B); ustaw(10, 4, B);
	}
	int stan(int a, int b) {
		if(a >= 1 && a <= 10 && b >= 1 && b <= 10)
			return plansza[a][b];
	}
	 znajdz_betoniarke() {
		while(!q_sam.empty() && zablokowana(q_sam.front()))
			q_sam.pop();
		if(!q_sam.empty()) {
			int v = q_sam.front();
			q_sam.push(v);
			q_sam.pop();
			return v;
		}
	}
	void wykonaj_ruch() {
		
	}
} interfejs;

int main() {
	interfejs.odbierz_numer();
	while(true) {
		if(!interfejs.kto_rusza())
			interfejs.odbierz_ruch();
		else {
			interfejs.odbierz_czas();
			interfejs.wykonaj_ruch();
		}
		interfejs.wykonano();
	}
	return 0;	
}
