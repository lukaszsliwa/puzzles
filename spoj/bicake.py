import math
try:
   while True:
      n = int(raw_input())
      if n == 1:
         print 0
      else:
         r = 2*n-4
         m = int(math.sqrt(r))
         if m*(m+1) <= r:
            print m+1
         else:
            print m
except:
   pass
