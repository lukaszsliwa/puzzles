import sys
result = 0
for line in sys.stdin.readlines():
   s = sum(map(int, line.split()))
   result += s
   print(s)
print(result)
