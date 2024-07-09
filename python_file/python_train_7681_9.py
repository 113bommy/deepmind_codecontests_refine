class SegTreeMax():
    def segfunc(self, x, y):
        if x > y:
            return x
        else:
            return y

    def __init__(self, ide, init_val):
        n = len(init_val)
        self.ide_ele = ide
        self.num = 2**(n-1).bit_length()
        self.seg = [self.ide_ele] * 2 * self.num
        for i in range(n):
            self.seg[i+self.num-1] = init_val[i]    
        for i in range(self.num-2,-1,-1):
            self.seg[i] = self.segfunc(self.seg[2*i+1],self.seg[2*i+2]) 
    def update(self, idx, val):
        idx += self.num-1
        self.seg[idx] = val
        while idx:
            idx = (idx-1)//2
            self.seg[idx] = self.segfunc(self.seg[idx*2+1], self.seg[idx*2+2])
    def query(self, begin, end):
        if end <= begin:
            return self.ide_ele
        begin += self.num-1
        end += self.num-2
        res = self.ide_ele
        while begin + 1 < end:
            if begin&1 == 0:
                res = self.segfunc(res, self.seg[begin])
            if end&1 == 1:
                res = self.segfunc(res, self.seg[end])
                end -= 1
            begin = begin//2
            end = (end-1)//2
        if begin == end:
            res = self.segfunc(res, self.seg[begin])
        else:
            res = self.segfunc(self.segfunc(res, self.seg[begin]), self.seg[end])
        return res

class SegTreeMin():
    def segfunc(self, x, y):
        if x < y:
            return x
        else:
            return y

    def __init__(self, ide, init_val):
        n = len(init_val)
        self.ide_ele = ide
        self.num = 2**(n-1).bit_length()
        self.seg = [self.ide_ele] * 2 * self.num
        for i in range(n):
            self.seg[i+self.num-1] = init_val[i]    
        for i in range(self.num-2,-1,-1):
            self.seg[i] = self.segfunc(self.seg[2*i+1],self.seg[2*i+2]) 
    def update(self, idx, val):
        idx += self.num-1
        self.seg[idx] = val
        while idx:
            idx = (idx-1)//2
            self.seg[idx] = self.segfunc(self.seg[idx*2+1], self.seg[idx*2+2])
    def query(self, begin, end):
        if end <= begin:
            return self.ide_ele
        begin += self.num-1
        end += self.num-2
        res = self.ide_ele
        while begin + 1 < end:
            if begin&1 == 0:
                res = self.segfunc(res, self.seg[begin])
            if end&1 == 1:
                res = self.segfunc(res, self.seg[end])
                end -= 1
            begin = begin//2
            end = (end-1)//2
        if begin == end:
            res = self.segfunc(res, self.seg[begin])
        else:
            res = self.segfunc(self.segfunc(res, self.seg[begin]), self.seg[end])
        return res

def main():
    n, k = map(int, input().split())
    p = list(map(int, input().split()))
    csum = [0]*n
    for i in range(1, n):
        csum[i] += csum[i-1]
        if p[i-1] > p[i]:
            csum[i] += 1
    seg_max = SegTreeMax(-float("inf"), p)
    seg_min = SegTreeMin( float("inf"), p)
    ans = 0
    f = True
    for i in range(k-1, n):
        if csum[i-k+1] == csum[i]:
            if f:
                ans += 1
                f = False
        elif k <= i and not(p[i-k] == seg_min.query(i-k, i) and p[i] == seg_max.query(i-k+1, i+1)):
            ans += 1
        elif i == k-1 and csum[i-k+1] < csum[i]:
            ans += 1
        #print(i, ans, p[i-k+1:i+1])
    print(ans)

if __name__ == "__main__":
    main()