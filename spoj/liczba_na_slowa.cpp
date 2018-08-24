#include <iostream>
#include <string>
using namespace std;

string jednosci[] = { "zero", "jeden", "dwa", "trzy", "cztery",
		"piec", "szesc", "siedem", "osiem", "dziewiec" };

string nastki[] = { "dziesiec", "jedenascie", "dwanascie", "trzynascie",
		"czternascie", "pietnascie", "czesnascie", "siedemnascie",
		"osiemnascie", "dziewietnascie" };

string dziesiatki[] = { "", "dziesiec", "dwadziescia", "trzydziesci", 
		"czterdziesci", "piecdziesiat", "szescdziesiat", 
		"siedemdziesiat", "osiemdziesiat", "dziewiecdziesiat" };

string setki = { "", "sto", "dwiescie", "trzysta", "czterysta", "piecset",
		"szescset", "siedemset", "osiemset", "dziewiecset" };
		
string slownie(int liczba) {
	
}

int main() {
	cin >> t;
	while(t--) {
		cin >> var;
		cout << slowanie(var) << endl;
	}
}
