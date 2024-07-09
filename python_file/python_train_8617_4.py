from collections import defaultdict
import bisect

alphabet="abcdefghijklmnopqrstuvwxyz"

bS = int(input())
S= input()
nQ = int(input())

S = [i for i in S]

query = []
for i in range(nQ):
  query.append(input().split())

locs =defaultdict(list)

for i,char in enumerate(S):
    locs[char].append(i)
    
def countChars(iter,ss,ee):
  nChar = 0
  for i in alphabet:
    if len(locs[i]) == 0:
      pass
    else:
      sptr = bisect.bisect_right(locs[i],ss)
      eptr = bisect.bisect_left(locs[i],ee)
      if sptr == eptr:
        if sptr < 1 or sptr > len(locs[i]):
          continue
        else:
          if locs[i][sptr-1] == ss:
            nChar+=1
      else:
        nChar += 1
  return nChar
    
  
res = []
for iter,iQ in enumerate(query):
  if int(iQ[0]) == 2:
    res.append(str( countChars(iter,int(iQ[1])-1,int(iQ[2])) ))
  if int(iQ[0]) == 1:
    location = int(iQ[1])-1
    curChar  = S[location]
    if curChar != iQ[2]:
      locs[curChar].remove(location) #remove from old
      bisect.insort(locs[iQ[2]],location)
      S[location] = iQ[2]
      
print(" ".join(res))

  