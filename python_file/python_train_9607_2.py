#https://codeforces.com/contest/1439/problem/A1

def concat(mat):
    l=[]
    for i in range(len(mat)):
        l+=mat[i]
    return l

        
def trnwt3_1(arr3_1, poss): #concated array
    ind3=[[]]
    t=(arr3_1)
    for i in range(len(t)):
        if t[i]==1: t[i]=0; ind3[0]+=poss[i]
    return ind3
        
def trnwt2_1(arr2_1, poss):
    ind2=[[]]
    t=(arr2_1)
    for k in range(len(t)):
        if t[k]==1: t[k]=0; ind2[0]+=poss[k]; break
    for i in range(len(t)):
        if i!=k and t[i]==0: t[i]=1; ind2[0]+=poss[i]
    
    ind2+=trnwt3_1(t, poss)
  
    return (ind2)
    
def trnwt1_1(arr1_1, poss):
    ind1=[[]]
    count=0
    t=(arr1_1)
    for i in range(len(t)):
        if t[i]==0: 
            count+=1; 
            if count<=2:
                t[i]=1; ind1[0]+=poss[i]
        else: t[i]=0; ind1[0]+=poss[i]
    
    ind1+=trnwt2_1(t, poss)
  
    return (ind1)
    
def trnwt4_1(arr4_1, poss):
    ind4=[[]]
    t=(arr4_1)
    for i in range(3):
        if t[i]==1: t[i]=0; ind4[0]+=poss[i]
    
    ind4+=trnwt1_1(t, poss)
    
    return (ind4)
    
T=int(input())

for t in range(T):
    n, m= map(int, input().split())
    prob=[]
    for p in range(n):
        s=input()
        prob.append(list(map(int, s)))

    # print(prob)

    ans=[]    
    i=0
    while(i<n-1):
        # print(i)
        j=0
        while(j<m-1):

            postn=[[i, j], [i, j+1], [i+1, j], [i+1, j+1]] 
            to_arr=[prob[i][j], prob[i][j+1], prob[i+1][j], prob[i+1][j+1]]
            
            if to_arr.count(1)==3: ans+=trnwt3_1(to_arr, postn); prob[i][j]=0; prob[i][j+1]=0; prob[i+1][j]=0; prob[i+1][j+1]=0
            if to_arr.count(1)==2: ans+=trnwt2_1(to_arr, postn); prob[i][j]=0; prob[i][j+1]=0; prob[i+1][j]=0; prob[i+1][j+1]=0
            if to_arr.count(1)==1: ans+=trnwt1_1(to_arr, postn); prob[i][j]=0; prob[i][j+1]=0; prob[i+1][j]=0; prob[i+1][j+1]=0
            if to_arr.count(1)==4: ans+=trnwt4_1(to_arr, postn); prob[i][j]=0; prob[i][j+1]=0; prob[i+1][j]=0; prob[i+1][j+1]=0
            
            j+=2 
            if m%2==1 and j==m-1: j-=1; 
        i+=2
        if n%2==1 and i==n-1: i-=1;
       
    print(len(ans))    
    for u in range(len(ans)):
        for v in ans[u]:
            print(v+1, end=" ")
        print()


        
    # print(ans)

# arr=[[0, 1], [0, 0]]
# poss=[[1, 1], [1, 2], [2, 1], [2,2]]
# print(trnwt1_1(concat(arr), poss))


