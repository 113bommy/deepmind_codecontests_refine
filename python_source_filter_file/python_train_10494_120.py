# 入力
N, A, B, C, D = map(int, input().split())
S = input()

# AからDの間に岩が二つ連続で置かれている箇所があれば不可
# C > D の場合、すぬけ君はふぬけ君を追い越す必要があることに注意
ans = (
    'Yes' if ('##' not in S[(A - 1):D]) and (
        C < D or
        '...' in S[(A - 1):D]
    ) else
    'No'
)

# 出力
print(ans)
