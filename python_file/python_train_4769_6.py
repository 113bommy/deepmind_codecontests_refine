import heapq
#printn = lambda x: sys.stdout.write(x)
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
#inm   = lambda:      map(int, input().split())
DBG = True  and False
#def ddprint(x):
#  if DBG:
#    print(x)

q = inn()
x = inl()
root = x[1]
b = x[2]
tl = []
tr = []
nl = nr = suml = sumr = 0
#ddprint("q " + str(q))
for i in range(1,q):
    #ddprint("i " + str(i))
    x = inl()
    if len(x)==1:
        z = sumr - suml - (root if nr>nl else 0) + b
        print("{} {}".format(root,z))
    else:
        a = x[1]
        b += x[2]
        if nl == nr:
            aa = -heapq.heappushpop(tl,-a)
            suml += a - aa
            if aa<root:
                aa,root = root,aa
            heapq.heappush(tr,aa)
            sumr += aa
            nr += 1
        else:
            aa = heapq.heappushpop(tr,a)
            sumr += a - aa
            if aa>root:
                aa,root = root,aa
            heapq.heappush(tl,-aa)
            suml += aa
            nl += 1
        #ddprint("b {} root {} nl {} nr {} suml {} sumr {}".format(b,root,nl,nr,suml,sumr))
        #ddprint(tl)
        #ddprint(tr)
