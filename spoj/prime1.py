import math

def prime(n):
   for i in range(2, int(math.sqrt(n)) + 1):
      if n % i == 0:
         return False
   return True

number = 2
stop = 1000000000
while number <= stop:
   if prime(number):
      print number,
   number += 1
