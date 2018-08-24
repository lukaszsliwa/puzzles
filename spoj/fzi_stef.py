n, result, current = int(input()), 0, 0
for i in range(0, n):
   cash = int(input())
   if current > 0:
      current += cash
   else:
      current = cash
   if current > result:
      result = current
print(result)

