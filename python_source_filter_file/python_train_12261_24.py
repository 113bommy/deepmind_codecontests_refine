s=input()
for i in range(1,4)[::-1]:
    if "R"*i in s:
        print(i)
        break
