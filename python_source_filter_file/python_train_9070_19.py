w1,h1,w2,h2=map(int,input().split())

w=max(w1,w2)+2
h=max(h1,h2)+2

print(2*(w+h)-4)