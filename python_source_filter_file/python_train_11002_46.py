t= int(input())

d_100 = t // 100
d_20 = (t % 100) // 20
d_10 = (t % 100 % 20) // 10
d_5 = (t % 100 % 20 % 10) // 5
d_1 = t % 100 % 20 % 10 % 5

print(d_100 + d_20 + d_5 + d_1)