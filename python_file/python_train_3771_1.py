import math

L = int(input())

s = input()

color = [-1] * L

counts = {}

for l in s:
	if l in counts:
		counts[l] += 1
	else:
		counts[l] = 1

c = 'a'

indexs = {}
prefixsum = 0
while c <= 'z':
	# print(c)
	if c in counts:
		indexs[c + "start"] = prefixsum
		prefixsum += counts[c] - 1
		indexs[c + "end"] = prefixsum
		prefixsum += 1
	c = chr(ord(c) + 1)

# print(indexs)

def f():
	global L, s, color, counts, indexs
	for i in range(len(s)):
		c = s[i]
		# print(color)
		if i >= indexs[c + "start"] and i <= indexs[c + "end"]:
			# print(c, end=" ")
			# print("at correct ")
			# print(i)
			pass
		elif i < indexs[c + "start"]:
			# move forward to position
			currC = color[i]
			if currC == -1:
				if color[i + 1] == -1 or color[i + 1] == 0:
					currC = 1
				else:
					currC = 0
			targetC = 1
			if currC == 1:
				targetC = 0
			color[i] = currC
			targetIndex = indexs[c + "start"]
			j = i + 1
			while j < targetIndex + 1:
				nextChar = s[j]
				nextCol = color[j]
				# print(c)
				# print(currC)
				# print(nextChar)
				# print(nextCol)
				if nextChar < c:
					if nextCol == currC:
						print("NO")
						return
					else:
						color[j] = targetC
				elif nextChar == c:
					if nextCol == currC:
						targetIndex += 1
					elif nextCol == -1:
						color[j] = currC
						targetIndex += 1
					else:
						print("NO")
						return
				else:
					color[j] == currC
				j += 1
		elif i > indexs[c + "end"]:
			currC = color[i]
			if currC == -1:
				if color[i - 1] == -1 or color[i - 1] == 0:
					currC = 1
				else:
					currC = 0
			targetC = 0
			if currC == 0:
				targetC = 1
			color[i] = currC
			targetIndex = indexs[c + "end"]
			j = i - 1
			while j > targetIndex - 1:
				# same letter
				nextL = s[j]
				nextC = color[j]
				if nextL > c:
					if nextC == currC:
						print("NO")
						return
					elif nextC == -1:
						nextC = targetC
					else:
						pass
				elif nextL == c:
					# nextC is not -1
					assert nextC != -1
					if nextC == currC:
						targetIndex -= 1
					else:
						print("NO")
						return
				else:
					if nextC != currC:
						print("NO")
						return
				j -= 1
	print("YES")
	for i in color:
		if i == -1:
			print(0, end="")
		else:
			print(i, end="")



f()







