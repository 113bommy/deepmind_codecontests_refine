import sys
input = sys.stdin.readline

class RollingHash:
  def __init__(self, s):
    self.base1 = 1009
    self.base2 = 1007
    self.mod1 = pow(10,9)+7
    self.mod2 = pow(10,9)+9
    self.hash1 = [0 for _ in range(len(s)+1)]
    self.hash2 = [0 for _ in range(len(s)+1)]
    self.pow1 = [1 for _ in range(len(s)+1)]
    self.pow2 = [1 for _ in range(len(s)+1)]
    for i in range(len(s)):
      self.hash1[i+1] = (self.hash1[i] * self.base1 + ord(s[i])) % self.mod1
      self.hash2[i+1] = (self.hash2[i] * self.base2 + ord(s[i])) % self.mod2
      self.pow1[i+1] = self.pow1[i] * self.base1 % self.mod1
      self.pow2[i+1] = self.pow2[i] * self.base2 % self.mod2

  def get(self, l, r):
    t1 = (self.hash1[r] - self.hash1[l] * self.pow1[r-l]) % self.mod1
    t2 = (self.hash2[r] - self.hash2[l] * self.pow2[r-l]) % self.mod2
    return t1, t2

  def add(self, t):
    offset = len(self.hash1)
    self.hash1 += [0 for _ in range(len(t))]
    self.hash2 += [0 for _ in range(len(t))]
    self.pow1 += [0 for _ in range(len(t))]
    self.pow2 += [0 for _ in range(len(t))]
    for i in range(offset, offset + len(t)):
      self.hash1[i] = (self.hash1[i-1] * self.base1 + t[i]) % self.mod1
      self.hash2[i] = (self.hash2[i-1] * self.base2 + t[i]) % self.mod2
      self.pow1[i] = self.pow1[i-1] * self.base1 % self.mod1
      self.pow2[i] = self.pow2[i-1] * self.base2 % self.mod2


class UnionFind:
  def __init__(self, size):
    self.parent = [i for i in range(size)]  # i番目の親ノードを表す
    self.height = [1 for _ in range(size)]  # 高さ
    self.size = [1 for _ in range(size)]  # 集合のサイズ

  def root(self, x):
    """
    xの親ノードを返す
    """
    if self.parent[x] != x:
      self.parent[x] = self.root(self.parent[x])  # 辺の縮約
    return self.parent[x]

  def union(self, x, y):
    """
    xとyの併合
    """
    px, py = self.root(x), self.root(y)
    if px == py:
      return
    if self.height[px] <= self.height[py]:
      self.parent[px] = py
      self.size[py] += self.size[px]
      if self.height[px] == self.height[py]:
        self.height[py] += 1
    else:
      self.parent[py] = px
      self.size[px] += self.size[py]


def main():
  s = input().strip()
  t = input().strip()
  ns = len(s)
  nt = len(t)
  s = s * (len(t) // len(s) + 1) * 2
  srol = RollingHash(s)
  trol = RollingHash(t)
  uni = UnionFind(ns)
  same = [False for _ in range(ns)]
  for i in range(len(s) - len(t) + 1):
    if srol.get(i, i+nt) == trol.get(0, nt):
      same[i % ns] = True

  for i in range(ns):
    if same[i] and same[(i+nt)%ns]:
      if uni.root(i) == uni.root((i+nt)%ns):
        print(-1)
        sys.exit(0)
      else:
        uni.union(i, (i+nt)%ns)

  ans = 0
  for i in range(ns):
    if same[i]:
      ans = max(ans, uni.size[i])

  print(ans)


if __name__ == '__main__':
  main()
