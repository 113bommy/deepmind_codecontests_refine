i=input
t=int(i())
while t:
 t-=1
 i();a=[*map(ord,i())]
 print("YNEOS"[1-all((x-y)%26in{0,2,24}for x,y in zip(a,a[::-1]))::2])