n = int(input())
m1, M1 = map(int, input().split())
m2, M2 = map(int, input().split())
m3, M3 = map(int, input().split())
first = min(n-m2-m3, M1)
n -= first
second = min(n-m3, M2)
n -= second
third = n
print(first, second, third)