from decimal import *
getcontext().prec = 700

x, y, z = map(Decimal, input().split())
a = []

a.append((y**z * x.ln(), -1, 'x^y^z'))
a.append((z**y * x.ln(), -2, 'x^z^y'))
a.append((y *z * x.ln(), -3, '(x^y)^z'))

a.append((x**z * y.ln(), -5, 'y^x^z'))
a.append((z**x * y.ln(), -6, 'y^z^x'))
a.append((x *z * y.ln(), -7, '(y^x)^z'))


a.append((x**y * z.ln(), -9, 'z^x^y'))
a.append((y**x * z.ln(), -10, 'z^y^x'))
a.append((x *y * z.ln(), -11, '(z^x)^y'))

print(max(a)[2])
