X=[int(input()) for i in range(5)]
Y=[]
for x in X:
  Y.append(-(-x//10)*10-x)
print(sum(Y)+sum(Y)-(max(Y)))