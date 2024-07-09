def main():
    n,m=map(int,input().split())
    a=list(map(int,input().split()))
    xy=[list(map(int,input().split())) for _ in [0]*m]
    class unionfind():
        #size:要素数,tree：unionfind木
        def __init__(self,size):#self,要素数
            self.size=size
            self.tree=[[i,1] for i in range(self.size)]#root,depth
        
        #rootを探す
        def root(self,index):
            if self.tree[index][0]==index:
                return index
            else:
                self.tree[index][0]=self.root(self.tree[index][0])
                return self.tree[index][0]
    
        #結合
        def unite(self,index1,index2):
            r1=self.root(index1)
            r2=self.root(index2)
            if r1!=r2:
                d1,d2=self.tree[r1][1],self.tree[r2][1]
                if d1<=d2:
                    self.tree[r1][0]=r2
                    self.tree[r2][1]=max(d1+1,d2)
                else:
                    self.tree[r2][0]=r1
                    self.tree[r1][1]=max(d2+1,d1)
    
        #同じか判定
        def same(self,index1,index2):
            r1=self.root(index1)
            r2=self.root(index2)
            return r1==r2
    
        #連結成分の個数
        def component(self):
            return len({self.root(i) for i in range(self.size)})
    
    u=unionfind(n)
    for x,y in xy:
        u.unite(x,y)
    for i in range(n):
        u.tree[i][0]=u.root(i)
    ut=u.tree
    d=dict()
    for i in range(n):
        if ut[i][0] in d.keys():
            d[ut[i][0]].append(a[i])
        else:
            d[ut[i][0]]=[a[i]]
    list1=[]
    list2=[]
    for s in d.values():
        s2=sorted(s)
        list1.append(s2[0])
        list2+=s2[1:]
    if len(list1)==1:
        print(0)
    elif len(list1)>len(list2)+2:
        print("Impossible")
    else:
        list2.sort()
        print(sum(list1)+sum(list2[:len(list1)-2]))
main()