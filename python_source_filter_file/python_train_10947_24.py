t = int(input())

for _ in range(t):
    n = int(input())
    answer = 0
    while n > 1:
        if n%2==0:
            n = n/2
            answer += 1
        elif n%3==0:
            n = (2*n)/3
            answer +=1
        elif n%5 == 0:
            n = (4*n)/5
            answer += 1
        else:
            answer = -1
            break

    print(answer)
