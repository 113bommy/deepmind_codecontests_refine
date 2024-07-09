class RollingHash:
    def __init__(self, s: list, base: int = 1007, mod: int = 10**9 + 7):
        self.s = s
        self.n = len(s)
        self.base = base
        self.mod = mod

        # preprocess
        self.h_cum = [0] * (self.n + 1)  # h_cum[i] = (hash of s[:i])
        self.b_pow = [1] * (self.n + 1)  # b_pow[i] = base ** i
        for i in range(self.n):
            self.h_cum[i + 1] = (self.h_cum[i] * base + s[i]) % mod
            self.b_pow[i + 1] = (self.b_pow[i] * base) % mod

    def get_hash(self, l: int, r: int) -> int:
        # get hash value of the substring s[l:r]
        hash_val = self.h_cum[r] - self.h_cum[l] * self.b_pow[r - l] % self.mod
        if hash_val < 0:
            hash_val += self.mod
        return hash_val


class RollingHashMulti:
    def __init__(self,
                 s: list,
                 base_list: list = [1007, 2009],
                 mod_list: list = [10**9 + 7, 10**9 + 9]):
        self.n = len(base_list)
        self.base_list = base_list
        self.mod_list = mod_list
        self.rh_list = [
            RollingHash(s, base_list[i], mod_list[i]) for i in range(self.n)
        ]

    def get_hash(self, l: int, r: int) -> tuple:
        return tuple(self.rh_list[i].get_hash(l, r) for i in range(self.n))


n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

a_xor = [a[i % n] ^ a[(i + 1) % n] for i in range(n * 2)]
b_xor = [b[i % n] ^ b[(i + 1) % n] for i in range(n * 2)]

a_xor_rh = RollingHashMulti(a_xor)
b_xor_rh = RollingHashMulti(b_xor)

for k in range(n):
    if a_xor_rh.get_hash(k, k + n) == b_xor_rh.get_hash(0, n):
        x = a[k] ^ b[0]
        print(k, x)
