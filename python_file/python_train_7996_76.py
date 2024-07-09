a = input()[:int(input())]
j = set(sorted(set(a), key=a.index)[:2])
j.discard("1")
print(list(j)[0] if j else 1)