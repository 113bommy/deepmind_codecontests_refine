n=int(input())

print('DENIED' if any([x%2==0 and (x%3 and x%5) for x in map(int,input().split())]) else 'APPLOVED')