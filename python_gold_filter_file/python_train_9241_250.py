K = int(input())
S = input()
print(S if (len(S) <= K) else (S[:K] + "..."))