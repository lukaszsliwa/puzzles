import sys
for line in sys.stdin.readlines():
   words, numbers = 0, 0
   for chars in line.split(' '):
      try:
         int(chars)
         numbers += 1
      except:
         words += 1
   print(numbers, words)
