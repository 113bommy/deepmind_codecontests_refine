for y in range(int(input())):
    n,k=map(int,input().split())
    lst=[]
    ans=[]
    for i in range(n):
        lst.append(list(input()))
    for i in range(n):
        for j in range(k):
            if i==n-1:
                if j==k-1:
                    if lst[i][j]=='0':
                        pass
                    else:
                        ans.append([i,j,i-1,j,i-1,j-1])
                        ans.append([i,j,i-1,j,i,j-1])
                        ans.append([i,j,i-1,j-1,i,j-1])
                    
                else:
                    if lst[i][j]=='0':
                        pass
                    else:
                        ans.append([i,j,i-1,j,i-1,j+1])
                        ans.append([i,j+1,i-1,j,i-1,j+1])
                        lst[i][j]='0'
                            
                        if lst[i][j+1]=='1':
                            lst[i][j+1]='0'
                        else:
                            lst[i][j+1]='1'
                            
                        
            else:
                if j==k-1:
                    if lst[i][j]=='0':
                        pass
                    else:
                        if lst[i][j-1]=='0':
                            ans.append([i,j,i+1,j,i+1,j-1])
                            lst[i][j]='0'
                            if lst[i+1][j]=='1':
                                lst[i+1][j]='0'
                            else:
                                lst[i+1][j]='1'
                            if lst[i+1][j-1]=='1':
                                lst[i+1][j-1]='0'
                            else:
                                lst[i+1][j-1]='1'
                        
                else:
                    if lst[i][j]=='0':
                        pass
                    else:
                        if lst[i][j+1]=='0':
                            ans.append([i,j,i+1,j,i+1,j+1])
                            lst[i][j]='0'
                            if lst[i+1][j]=='1':
                                lst[i+1][j]='0'
                            else:
                                lst[i+1][j]='1'
                            if lst[i+1][j+1]=='1':
                                lst[i+1][j+1]='0'
                            else:
                                lst[i+1][j+1]='1'
                        else:
                            ans.append([i,j,i,j+1,i+1,j+1])
                            
                            lst[i][j]='0'
                            if lst[i][j+1]=='1':
                                lst[i][j+1]='0'
                            else:
                                lst[i][j+1]='1'
                            if lst[i+1][j+1]=='1':
                                lst[i+1][j+1]='0'
                            else:
                                lst[i+1][j+1]='1'
    print(len(ans))
    for i in ans:
        for j in i:
            print(j+1,end=" ")
        print()