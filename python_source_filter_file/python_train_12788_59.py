a,b,c,d,e,f=map(int,input().split())
a100=a*100
b100=b*100
ok=[]
for ai in range(31):
  for bi in range(31):
    for ci in range(31):
      for di in range(31):
        ab= ai*a100+bi*b100
        cd= ci*c+di*d
        if ab + cd >f:
          break
        else:
          if (ab/100)*e>=cd:
            ok.append([ab+cd,cd])
print(*sorted(ok, key=lambda x: (100*x[1] / x[0] if x[0] else 0))[-1])


