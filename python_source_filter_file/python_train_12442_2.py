#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2016 missingdays <missingdays@missingdays>
#
# Distributed under terms of the MIT license.

"""

"""

n, m = [int(i) for i in input().split()]

city = []

for i in range(n):
    city.append([int(i) for i in input().split()])

ma = 0

for i in range(m):
    ml = 1e10 # bigger than any

    for j in range(n):
        ml = min(ml, city[j][i])

    ma = max(ma, ml)

print(ma)    
