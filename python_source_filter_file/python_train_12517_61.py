string = input()

new_string = list(filter(lambda x: x in "HQ+9", string))

if len(new_string):
    print("YES")
else:
    print("NO")