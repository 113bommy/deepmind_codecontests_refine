while True:
    h, w = list(map(int, input().split()))
    a, b = divmod(h, 2)
    c, d = divmod(w, 2)
    if h == w == 0:
        break
    print(('#.' * a + '#' * b + '\n' + '.#' * a + '.' * b + '\n') * c
          + ('#.' * a + '#' * b + '\n') * d)