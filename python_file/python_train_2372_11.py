N = int(input())
S = input()

cnt = 0
for i in range(N):
    for j in range(N):
        k = i*2 - j
        if j < k < N and S[i] != S[j] and S[j] !=S[k] and S[i] != S[k]:
            cnt += 1

print(S.count("R")*S.count("G")*S.count("B")-cnt)