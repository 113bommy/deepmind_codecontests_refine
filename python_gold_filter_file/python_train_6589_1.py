n = int(input())
num = input()
lucky = set(num)
luck_num = ''.join(lucky)
luck_list = ['7', '4', '74', '47']
out = 'YES'

if len(lucky) > 2 :
    out = 'NO'
elif len(lucky) <= 2 and luck_num not in luck_list  :
        out = 'NO'
else :
    fir_half = [ int(i) for i in num[:n//2] ]
    sec_half = [ int(i) for i in num[n//2:] ]

    if sum(fir_half) != sum(sec_half) :
        out = 'NO'

print(out)


    
