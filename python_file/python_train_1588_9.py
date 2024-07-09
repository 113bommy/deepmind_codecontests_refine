import math
def funk(n):
    #polygon with n ecken, kleiner als kreis immer hmm
    #die eine flache ecke auf den boden dann die höhe der hälfte der winkel.
    #höchster punkt ist n//2 und der ist wie hoch? naja die höhe aller kanten im winkel in dem sie kommen
    #also erster ist im winkel 0 also null, zweiter ist im winkel letzeter winkel +
    sum = 0
    for i in range(1, int(n//2) +1):
        sum += math.sin(math.radians(i*360/n))
    return sum


count = int(input())
input_l = []
for i in range(count):
    tmp = input()
    input_l.append(int(tmp))

for i in input_l:
    print(funk(2*i))
