import re


find = re.compile('(ogo(go)*)+')
s = input()
print(find.sub('***', s))
