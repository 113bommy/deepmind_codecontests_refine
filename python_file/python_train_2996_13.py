class Node:
    def __init__(self):
        self.child = [None] * 26
        self.counts = [0] * 26

    # def add(self, s, bucket, idx_s):
    #     c = s[idx_s]
    #     if self.child[c] is None:
    #         self.child[c] = Node()
    #     for i, cnt in enumerate(bucket):
    #         if cnt:
    #             self.counts[i] += 1
    #     bucket[c] -= 1
    #     if idx_s >= 1:
    #         self.child[c].add(s, bucket, idx_s - 1)
    #     else:
    #         Leaves.append(self.counts)

    def add(self, s, bucket):
        node = self
        for idx_s, c in zip(range(len(s)-1, -1, -1), s[::-1]):
            if node.child[c] is None:
                node.child[c] = Node()
            for i, cnt in enumerate(bucket):
                if cnt:
                    node.counts[i] += 1
            bucket[c] -= 1
            if idx_s > 0:
                node = node.child[c]
        Leaves.append(node.counts)

    # def get(self, s, idx_s):
    #     c = s[idx_s]
    #     if idx_s > 0:
    #         return self.child[c].get(s, idx_s-1)
    #     else:
    #         return self.counts[c]

Leaves = []
trie = Node()
N = int(input())
S = [[ord(c)-97 for c in input()] for _ in range(N)]
for s in S:
    b = [0] * 26
    for c in s:
        b[c] += 1
    trie.add(s, b)
ans = -N
# for s in S:
#     ans += trie.get(s, len(s)-1)
for s, l in zip(S, Leaves):
    ans += l[s[0]]
print(ans)
