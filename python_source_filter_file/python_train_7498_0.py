class SegmentTree():
	def __init__(self,n):
		self.dat = [0 for _ in range(n*2-1)]
		#index n???????????????????????¢?????????:
		#???????????? : (n-1)//2
		#???????????? : (2n+1) , (2n+2)
		self.n = n

	def update (self,node_index,value):
		""" index?????????value????????´?????? """
		index = node_index + (self.n-1) #node_index????????????dot???index?????????
		self.dat[index] += value

		#?????°????????????????????????????????´????????????
		while index > 0 :
			index = (index - 1) // 2				 #???????????????????????£???
			self.dat[index] = self.dat[index*2+1] + self.dat[index*2+2] #??????????????????????????????

	def querry (self,left,right,nowNode,nowLeft,nowRight):
		"""[left,right):??¢?´¢??????,noeNode:?????¨????????????,[nowLeft,nowRight):?????¨?????????????????????"""

		# ??????????????¶??£????????????
		if nowRight < left or nowLeft > right:
			return 0

		# ?????¨?????¢?´¢???????????¨????????????????????????????????????
		if left <= nowLeft and nowRight <= right:
			return self.dat[nowNode]

		# ???????????????????????????????????¨???????????????
		else:
			value_left = self.querry(left,right,2*nowNode+1,nowLeft,(nowLeft+nowRight)//2)
			value_right = self.querry(left,right,2*nowNode+2,(nowLeft+nowRight)//2+1,nowRight)
			return (value_left + value_right)

	def DEBUG_dat(self):
		print(self.dat)


if __name__ == "__main__":
	n ,q  = map(int,input().split(" "))
	result = []

	for i in range(1,20):
		if 2 ** i >= n:
			min_pow2 = 2 **  i
			break

	tree = SegmentTree(min_pow2)

	for i in range(q):
		com,x,y = map(int,input().split(" "))
		if com == 0:
			tree.update(x-1,y)
		else:
			result.append(tree.querry(x-1,y,0,0,min_pow2-1))


	for ans in result:
		print(ans)