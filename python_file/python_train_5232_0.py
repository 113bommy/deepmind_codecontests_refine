
import sys,math,cmath,time,bisect
from collections import deque 
start_time = time.time()
tt = 0
#---------------------- USER DEFINED INPUT FUNCTIONS ----------------------#
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    return(input().strip())
def invr():
    return(map(int,input().split()))
##########################################################################
################# ---- THE ACTUAL CODE STARTS BELOW ---- #################
 
def solve():
    n = inp()
    arr= inlt()
    M={}
    brr=[]
    for i in range(n):
        brr.append([arr[i],i])
    brr.sort()
    for i in range(n):
        arr[brr[i][1]]= i+1
    # print(arr)
    ans =[0]*(n+1)
    mx=0
    for i in range(n):
        ans[arr[i]]= ans[arr[i]-1]+1
        mx= max(ans[arr[i]] , mx)
    return n-mx
 
################## ---- THE ACTUAL CODE ENDS ABOVE ---- ##################
##########################################################################
def main():
    # if not ONLINE_JUDGE:
    # sys.stdin = open("/home/aman/Documents/compwtitive_coding/Competitive-coding-codes/in.txt","r")
    # sys.stdout = open("/home/aman/Documents/compwtitive_coding/Competitive-coding-codes/out.txt","w")
    t = 1
    t = inp()
    for tt in range(t):
        print(solve())
    # if not ONLINE_JUDGE:
    # print("Time Elapsed :",time.time() - start_time,"seconds")
    # sys.stdout.close()
#------------------ USER DEFINED PROGRAMMING FUNCTIONS ------------------#
def counter(a):
    q = [0] * max(a)
    for i in range(len(a)):
        q[a[i] - 1] = q[a[i] - 1] + 1
    return(q)
 
def string_counter(a):
    q = [0] * 26
    for i in range(len(a)):
        q[ord(a[i]) - 97] = q[ord(a[i]) - 97] + 1
    return(q)
# ONLINE_JUDGE = __debug__
# if ONLINE_JUDGE:
#     input = sys.stdin.readline
    
if __name__ == '__main__':
    main()