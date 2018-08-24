try:
   while True:
      l = map(int, raw_input().split(' '))
      x = l[0]
      del l[0]
      l.sort()
      l.reverse()
      last = l[-1]
      for i in range(len(l)-2, -1, -1):
         if last == l[i]:
            del l[i]
         else: 
            last = l[i]
      if len(l) >= x:
         print(l[x-1])
      else:
         print('-')
except EOFError:
   pass
