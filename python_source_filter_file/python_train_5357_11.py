"""
time limit per test: 1 second
memory limit per test: 256 megabytes
inputstandard input
outputstandard output

Little X and Little Z are good friends. They always chat online. But both of them 
have schedules.

Little Z has fixed schedule. He always online at any moment of time between 
a 1 and b 1, between a 2 and b 2, ..., between a p and b p (all borders inclusive). 
But the schedule of Little X is quite strange, it depends on the time when he gets up.
If he gets up at time 0, he will be online at any moment of time between c 1 and d 1,
between c 2 and d 2, ..., between c q and d q (all borders inclusive).
But if he gets up at time t, these segments will be shifted by t.
They become [c i + t, d i + t] (for all i).

If at a moment of time, both Little X and Little Z are online simultaneosly,
they can chat online happily. You know that Little X can get up at an integer moment of
time between l and r (both borders inclusive). Also you know that Little X wants to get up
at the moment of time, that is suitable for chatting with Little Z (they must have at least
one common moment of time in schedules).
How many integer moments of time from the segment [l, r] suit for that?

Input
The first line contains four space-separated
integers p, q, l, r (1 ≤  p, q ≤ 50; 0 ≤ l ≤ r ≤ 1000).

Each of the next p lines contains two space-separated
integers a i, b i (0 ≤ a i < b i ≤ 1000).
Each of the next q lines contains two space-separated integers c j, d j (0 ≤ c j < d j ≤ 1000).

It's guaranteed that b i < a i + 1 and d j < c j + 1 for all valid i and j.

Output
Output a single integer — the number of moments of time
from the segment [l, r] which suit for online conversation.
"""

"""
EJEMPLO 1
1 1 0 4
2 3
0 1

Little Z
2,3

Little X
0,1


EJEMPLO 2
p, q, l, r
2 3 0 20
15 17
23 26
1 4
7 11
15 17

little Z (p)
15 17
23 26

little X (q)
1 4
7 11
15 17

Usar panadas?? usar diferencias? entre segnmentos
"""

import pdb
import sys

def get_input_file():
    f = open("demo469.txt", "r")
    var = f.read()
    return var


def solve():
    inp = sys.stdin.read()
    #inp = get_input_file()
    mylist = inp.splitlines()
    (p, q, l, r) = [ int(elem) for elem in mylist[0].split(' ')]
    times = list()
    z_times = list()
    x_times = list()
    count = 0
    for elem in mylist[1:]:
        (first, last) = elem.split(' ')
        times.append(list(range(int(first), int(last)+1)))
    for elem in times[0:p]:
        z_times = z_times + elem
    for elem in times[p:]:
        x_times = x_times + elem
    for i in range(l,r+1):
        x_new = [x + i for x in x_times]
        print(x_new)
        for j in x_new:
            if j in z_times:
                count += 1
                break
    print(count)


def main():
    solve()

if __name__ == "__main__":
    main()
