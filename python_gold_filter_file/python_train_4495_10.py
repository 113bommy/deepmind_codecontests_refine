var= input().lower();
match= ['a','e','i','o','u','y'];
str=""
for x in match:
	var=var.replace(x,"")
for x in var:
	str+="."+x
print (str)		