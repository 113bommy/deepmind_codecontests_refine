s=input()
print(sum(s[i]!=s[~i] for i in range(len(s)//2)))