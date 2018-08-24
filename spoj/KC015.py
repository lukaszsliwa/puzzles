import sys
for line in sys.stdin.readlines():
   if eval(line):
      print("1")
   else:
      print("0")

