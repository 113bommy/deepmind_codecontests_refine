#! /usr/bin/env python
# -*- coding: utf-8 -*-

'''
753

A. Santa Claus and Candies
time limit per test
1 second
memory limit per test
256 megabytes
input
standard input
output
standard output


Santa Claus has n candies, he dreams to give them as gifts to children.

What is the maximal number of children for whose he can give candies if Santa Claus want each kid should get distinct positive integer number of candies. Santa Class wants to give all n candies he has.
Input

The only line contains positive integer number n (1 <= n <= 1000) — number of candies Santa Claus has.
Output

Print to the first line integer number k — maximal number of kids which can get candies.

Print to the second line k distinct integer numbers: number of candies for each of k kid. The sum of k printed numbers should be exactly n.

If there are many solutions, print any of them.
'''

if __name__ == '__main__':
    n = int(input())

    t = 1
    ans = [t]
    k = 0
    while True:
        t += 1
        s = sum(ans)
        d = n - s
        if s == n:
            k = len(ans)
            break
        elif t > d:
            k = len(ans)
            ans[-1] += d
            break
        else:
            ans.append(t)

    print(k)
    print(*ans)
