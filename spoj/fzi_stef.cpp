#include <cstdio>
using namespace std;

int main() {
  long long int n, a, current = 0, result = 0;
  scanf("%lld", &n);
  while(n--) {
    scanf("%lld", &a);
    if(current > 0) {
      current += a;
    } else {
      current = a;
    }
    if(current > result) {
      result = current;
    }
  }
  printf("%lld\n", result);
}
