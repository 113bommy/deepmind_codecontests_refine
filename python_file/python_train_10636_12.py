def f(a, step, mod):
    i = 1;
    answer = 0;
    while a > 9:
        c = a % 10
        a //= 10
        answer += (step[i] + step[i - 1]) * c % mod
        i += 2
    answer += (step[i] + step[i - 1]) * a % mod
    return answer
    
def main():
    answer = 0
    mod = 998244353
    n = int(input())
    step = []
    c = 1
    for i in range(20):
        step.append(c)
        c *= 10
    
    for c in list(map(int, input().split())):
        answer += f(c, step, mod) * n % mod 
    answer %= mod
    print(answer)
    
if __name__ == "__main__":
    main();