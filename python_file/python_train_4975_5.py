# 久々の幅優先探索……

import queue

n = int(input())
edges = [list(map(int, input().split())) for _ in range(n-1)]
num_0_mod_3 = n // 3
num_2_mod_3 = (n+1) // 3
num_1_mod_3 = (n+2) // 3


def add_edge(u, v ):
    G[u].append(v)
    G[v].append(u)

G = [[] for _ in range(n)] #グラフの隣接リスト表現
for edge in edges:
    add_edge(edge[0]-1, edge[1]-1)

num_distance_even = 0
num_distance_odd = 0

q = queue.Queue()
q.put(0)

distance = [-1] * n
distance[0] = 0
num_distance_even += 1

for v in G[0]:
    q.put(v)

while(q.qsize() > 0):
    now = q.get()
    for v in G[now]:
        if distance[v] >= 0:
            pass
        else:
            q.put(v)
            distance[v] = distance[now] + 1
            if (distance[v] & 1):
                num_distance_odd += 1
            else:
                num_distance_even += 1

# print(distance)
# print(num_distance_even, num_distance_odd)

ans = [-1] * n

index_one = 1
index_two = 2
index_zero = 3

if num_distance_even >= num_1_mod_3 + num_2_mod_3:
    # evenに120 oddに0

    for i in range(n):
        if (distance[i] & 1) == 1:
            ans[i] = index_zero
            index_zero += 3
        else:
            if (index_one <= n):
                ans[i] = index_one
                index_one += 3
            elif (index_two <= n):
                ans[i] = index_two
                index_two += 3
            else:
                ans[i] = index_zero
                index_zero += 3


elif num_distance_odd >= num_1_mod_3 + num_2_mod_3:
    # evenに0 oddに012
    for i in range(n):
        if (distance[i] & 1) == 0:
            ans[i] = index_zero
            index_zero += 3
        else:
            if (index_one <= n):
                ans[i] = index_one
                index_one += 3
            elif (index_two <= n):
                ans[i] = index_two
                index_two += 3
            else:
                ans[i] = index_zero
                index_zero += 3


else:
#     num_distance_even <= num_distance_odd * 2 and num_distance_odd <= num_distance_even * 2:
    # evenを2、oddを1、適宜0
    for i in range(n):
        if (distance[i] & 1) == 1:
            if (index_one <= n):
                ans[i] = index_one
                index_one += 3
            else:
                ans[i] = index_zero
                index_zero += 3
        else:
            if (index_two <= n):
                ans[i] = index_two
                index_two += 3
            else:
                ans[i] = index_zero
                index_zero += 3


print(' '.join(list(map(str, ans))))
