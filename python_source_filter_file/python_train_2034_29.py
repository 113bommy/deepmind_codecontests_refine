n =int(input ()) 
if n<= 127:
    print ("byte") 
elif n<=32768: 
    print ("short") 
elif n<=2147483648:
    print ("int") 
elif n<=9223372036854775807:
    print ("long")
else:
    print ("Biginteger")




 


