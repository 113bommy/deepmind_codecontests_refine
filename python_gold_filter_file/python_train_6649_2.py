import sys
b=0
a=[{},{}]
for e in sys.stdin:
 if'\n'==e:b=1
 else:c,_=e.split(',');c=int(c);a[b].setdefault(c,0);a[b][c]+=1
for k in sorted({*a[0]}&{*a[1]}):print(k,a[0][k]+a[1][k])
