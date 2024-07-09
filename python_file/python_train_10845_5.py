import sys
input = sys.stdin.readline

def getInt(): return int(input())
def getVars(): return map(int, input().split())
def getArr(): return list(map(int, input().split()))
def getStr(): return input().strip()
## -------------------------------


def ObrabotkaPlus():
    global PLUS, res, R
    keys = list(PLUS.keys())
    keys.sort()
    for k in keys:
        if k <= R:
            R += sum(PLUS[k])
        else:
            res = 'NO'
            break

def ObrabotkaNull():
    global m0, res, R
    if m0 > R:
        res = 'NO'


    
def ObrabotkaMinus2():
    global R, res, MINUS
    keys = list(MINUS.keys())
    keys.sort(reverse = True)
    for k in keys:
        for x in MINUS[k]:
            if R < x[0]:
                res = 'NO'
                break
            else:
                R += x[1]
                if R < 0:
                    res = 'NO'
                    break
        if res == 'NO':
            break


        
res = 'YES'
N, R = getVars()
m0 = 0
PLUS = {}
MINUS = {}
MINUS3 = []
for i in range(N):
    a, b = getVars()
    if b > 0:
        if a <= R:
            R += b
        else:
            if a not in PLUS:
                PLUS[a] = []
            PLUS[a].append(b)
    elif b == 0:
        m0 = max(m0, a)
    else:
        key = max(a, -b) + b
        if key not in MINUS:
            MINUS[key] = []
        MINUS[key].append([a, b])



ObrabotkaPlus()
if res == 'YES':
    ObrabotkaNull()
if res == 'YES':
    ObrabotkaMinus2()

print(res)
        
