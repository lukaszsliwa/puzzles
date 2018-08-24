#include <iostream>
using namespace std;

int n, a, b, c, d;

string result(int a, int b, int c, int d) {
  if (a > c && b > d || a > d && b > c) { // brakuje warunku dla przekreconego prostokata na przekatnej
    return "TAK";
  }
  return "NIE";
}

int main() {
   cin >> n;
   while (n--) {
     cin >> a >> b >> c >> d;
     cout << result(a, b, c, d) << endl;
   }
}
