def fib(n, m):
  pass 

n = int(input())
for i in range(0,n):
   line = input().split(' ')
   n, m = line[0], line[1]
   print(fib(n, m))

