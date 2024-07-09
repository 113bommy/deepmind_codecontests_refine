# -*- coding: utf-8 -*-
x, y, z, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))

bc = [i + j for i in b for j in c]
bc.sort(reverse=True)

abc = [i + j for i in a for j in bc[:min(k, len(bc))]]
abc.sort(reverse=True)

for i in range(k):
    print(abc[i])
