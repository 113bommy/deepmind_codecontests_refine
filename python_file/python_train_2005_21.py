def invert_func(a, i):
    b = [0]*i
    for j in range(i):
        b[j]=['1','0'][int(a[i-j-1])]
    if i<=len(a):
        b = b+a[i:]
    return b

def main():
    for _ in range(int(input())):
        n = int(input())
        arr1 = list(input().strip())
        arr2 = input().strip()
        count=0
        ans = []
        j = n-1
        while(j>=0):
            if arr1[j]=='0':
                j-=1
            else:
                if arr1[0]=='0':
                    count+=1
                    ans.append('1')
                    arr1[0] = '1'
                count+=1
                ans.append(str(j+1))
                arr1 = invert_func(arr1,j+1)
                j-=1
        j=n-1
        flag = '0'
        while(j>=0):
            if(arr2[j]==flag):
                j-=1
            else:
                count+=1
                ans.append(str(j+1))
                flag=['1','0'][int(flag)]
                j-=1
        print(count," ".join(ans))

main()
