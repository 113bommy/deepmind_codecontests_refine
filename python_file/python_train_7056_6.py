s  = input()
q  = int(input())
inv = 1
sfb = [0,"",""]
for i in range(q):
    ls = list(input().split())
    if ls[0] == "1":
        inv *=-1
    else:
        f,c = ls[1:]
        if f == "1":
            sfb[inv] +=c
        else:
            sfb[-inv] +=c

ans = sfb[1][::-1] + s + sfb[-1]
print(ans[::inv])
