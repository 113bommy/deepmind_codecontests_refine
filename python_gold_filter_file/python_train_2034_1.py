n=int(input())
 
if n>=-128 and n<=127:
   print('byte')
elif n>=-32768 and n<=32767:
   print('short')
elif n>=-2147483648 and n<=2147483647:
   print('int')
elif n>=-9223372036854775808 and n<=9223372036854775807:
   print('long')
else:
   print('BigInteger')
