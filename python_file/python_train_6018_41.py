S = input()
N = 10**9 + 7
d = {str(i):[int(i == k) for k in range(10)] for i in range(10) }
d["?"] = [1] * 10 
l = d[S[0]] + [0]*3
#print(l)
for i in range(1, len(S)):
  if S[i] == "?":
    l = [(sum([l[((k - j) * 4)%13] for j in range(10)]))%N for k in range(13)]
  else:
    l = [l[((k - int(S[i])) * 4)%13] for k in range(13)]
  #print(l)
print(l[5])         