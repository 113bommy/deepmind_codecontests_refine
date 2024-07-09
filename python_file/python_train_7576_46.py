#!/usr/bin/env python
# -*- coding: utf-8 -*-
n=int(input())
a=[int(x) for x in input().split()]
mod=10**9+7
lcm=1
from fractions import gcd
for ai in a:
    lcm=ai*lcm//gcd(ai,lcm)
ans=0
for ai in a:
    ans+=lcm//ai
print(ans%mod)