N = int(input())

for i in range(1,11,1):
    if (N%i==0 and N/i<10):
        print("Yes")
        exit()
    
print("No")