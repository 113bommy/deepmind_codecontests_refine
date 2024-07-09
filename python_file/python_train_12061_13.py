import sys
input = sys.stdin.readline

def main():
  N, constW = map(int, input().split())
  WV = [list(map(int, input().split())) for _ in range(N)]
  W0 = WV[0][0]
  L = [[] for _ in range(4)]
  for w, v in WV:
    w -= W0
    L[w].append(v)
  L[0].sort(reverse=True)
  L[1].sort(reverse=True)
  L[2].sort(reverse=True)
  L[3].sort(reverse=True)
  ans = 0
  for i in range(1, constW//W0 + 1):
    rest = constW - i*W0
    for j in range(min(rest//3, i) + 1):
      rest1 = rest - 3*j
      for k in range(min(rest1//2, i-j) + 1):
        rest2 = rest1 - 2*k
        for l in range(min(rest2, i-j-k) + 1):
          temp = sum(L[3][:j]) + sum(L[2][:k]) + sum(L[1][:l]) + sum(L[0][:i-j-k-l])
          ans = max(ans, temp)
  print(ans)

if __name__ == "__main__":
  main()