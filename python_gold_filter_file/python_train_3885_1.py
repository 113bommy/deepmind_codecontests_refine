
def translateinput(i):
	return bitbraichar[input().replace(' ','')]

bitbraichar = {
	'10010':'a',
	'11020':'b',
	'20011':'c',
	'21012':'d',
	'11011':'e',
	'21021':'f',
	'22022':'g',
	'12021':'h',
	'12012':'j',
	'10120':'k',
	'11130':'l',
	'20121':'m',
	'21122':'n',
	'11121':'o',
	'21131':'p',
	'22132':'q',
	'12131':'r',
	'12122':'t',
	'10221':'u',
	'11231':'v',
	'12113':'w',
	'20222':'x',
	'21223':'y',
	'11222':'z'
}

n = int(input())

for i in map(translateinput,range(n)):
	print(i,end='')
