N, Q = map(int, input().split())
tree_data = [tuple(map(int, input().split())) for i in range(N - 1)]
operation = [tuple(map(int, input().split())) for i in range(Q)]

tree_data = sorted(tree_data)

node = dict(zip(range(1, N + 1), [0] * N))
for o in operation:
    node[o[0]] += o[1]

for n in tree_data:
    node[n[1]] += node[n[0]]

print(' '.join(map(str, node.values())))
