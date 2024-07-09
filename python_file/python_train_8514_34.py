def main():
    s = input()
    t = input()
    if not set(t).issubset(set(s)):
        return -1
    m = 0
    st = s
    for i in t:
        if i in st:
            j = st.index(i)
            m += j + 1
            st = st[j+1:]
        else:
            m += len(st)
            st = s
            j = st.index(i)
            st = st[j+1:]
            m += j + 1
    return m
print(main())
