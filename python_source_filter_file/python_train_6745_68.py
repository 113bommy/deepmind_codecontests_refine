S = str(input())
s = [i for i in range(int(len(S) / 2)) if S[i] != S[-i]]
print(len(s))