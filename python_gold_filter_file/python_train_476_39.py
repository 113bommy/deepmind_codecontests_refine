s,v1,v2,t1,t2=list(map(int,input().split()))
first=v1*s+2*t1 
second=v2*s+2*t2
if first<second:
    print('First')
elif first>second:
    print('Second')
else:
    print('Friendship')