def cumsum(li):
    ret = []
    sum = 0
    for i in li:
        sum += i
        ret.append(sum)
    return ret


class BinaryIndexedTree:
    # http://hos.ac/slides/20140319_bit.pdf
    def __init__(self, size):
        """
        :param int size:
        """
        self._bit = [0 for _ in range(size)]
        self._size = size

    def add(self, i, w):
        """
        i 番目に w を加える
        :param int i:
        :param int w:
        :return:
        """
        x = i + 1
        while x <= self._size:
            self._bit[x - 1] += w
            x += x & -x

    def sum(self, i):
        """
        0 番目から i 番目までの合計
        :param int i:
        :return:
        """
        ret = 0
        x = i + 1
        while x > 0:
            ret += self._bit[x - 1]
            x -= x & -x
        return ret

    def __len__(self):
        return self._size


def count_inversions(li, max=None):
    """
    リストから転倒数 (li[i] > li[j] (i < j) となる (i, j) の組み合わせ数) を返す
    バブルソートするときに反転する必要がある数。
    :param numpy.ndarray | list of int li:
            すべての要素が 0 以上の int である配列。
            BIT を使うので、マイナスを含んだり最大値が大きい場合は np.argsort の結果を指定
            ただしリストに重複を含む場合は np.argsort は unstable なので別の方法使うこと
            https://docs.scipy.org/doc/numpy/reference/generated/numpy.sort.html
    :param int max: li の最大値。わかる場合は指定
    :rtype: int
    """
    if not max:
        max = __builtins__.max(li)
    bit = BinaryIndexedTree(size=max + 1)
    ret = 0
    for i in range(len(li)):
        ret += i - bit.sum(li[i])
        bit.add(li[i], 1)
    return ret


def bisect_left_callable(fn, x, lo, hi):
    """
    lo から hi-1 のうち、fn の結果が x 以上となる、最も左の値
    bisect.bisect_left と同じ
    https://docs.python.org/ja/3/library/bisect.html
    :param callable fn:
    :param x:
    :param int lo: 最小値
    :param int hi: 最大値 + 1
    :return: lo <= ret <= hi
    """
    while lo < hi:
        mid = (lo + hi) // 2
        if fn(mid) < x:
            lo = mid + 1
        else:
            hi = mid
    return lo


N = int(input())
series = list(map(int, input().split()))

series_sorted = sorted(series)

# L と r の選び方の組み合わせ数。1 から N までの和に等しい
lr_size = (N + 1) * N / 2


# cumsum[L] <= cumsum[r] となる (L, r) の組み合わせ数を数える
# 転倒数を数えて lr_size から引けばいい
# それが (lr_size + 1) // 2 以上である一番大きい x を探す
def solve(i):
    x = series_sorted[i]
    # series を x 以上かどうかで 1 と 0 に置換し累積和を取る
    cumsum_li = [0] + cumsum([1 if s >= x else -1 for s in series])
    # 転倒数 (cumsum にマイナスを含むので最小でも 0 になるよう N を加算）
    inversions = count_inversions([N + i for i in cumsum_li], max=N + N)
    if lr_size - inversions >= (lr_size + 1) // 2:
        return i
    else:
        return float('inf')


ans_i = bisect_left_callable(solve, float('inf'), lo=0, hi=N)
print(series_sorted[max(0, min(N - 1, ans_i - 1))])
