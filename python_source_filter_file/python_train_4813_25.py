import sys
input = sys.stdin.readline

#import time

def main():
    #start = time.time()
    pos = []
    for a in range(1, 10001, 1):
        for b in range(a, 10001, a):
            for c in range(b, 10001, b):
                pos.append([a, b, c])
    #print(time.time() - start)
        
    for _ in range(int(input())):
        a, b, c = map(int,input().split())
        
        move = 100000000
        ans = []
        for el in pos:
            tmove = (abs(a - el[0]) + abs(b - el[1]) + abs(c - el[2]))
            if tmove < move:
                move = tmove
                ans = el
                
        print(move)
        print(*ans)
            
        


main()






