#include <bits/stdc++.h>
class Scanner {
 private:
  static const int BUFFER_SIZE = 1 << 18;
  char buff[BUFFER_SIZE];
  char *buffPos, *buffLim;
  FILE* file;

 public:
  Scanner(FILE* file) {
    this->file = file;
    buffLim = buff + fread(buff, 1, BUFFER_SIZE, file);
    buffPos = buff;
  }

 private:
  inline void flushBuff() {
    buffLim = buff + fread(buff, 1, BUFFER_SIZE, file);
    if (buffLim == buff) {
      *buffLim++ = '\n';
    }
    buffPos = buff;
  }
  inline bool isWS(char t) { return t <= ' '; }
  inline bool isDig(char t) { return t >= '0' && t <= '9'; }
  inline void nextPos() {
    buffPos++;
    if (buffPos == buffLim) {
      flushBuff();
    }
  }

 public:
  inline char getchar() {
    char ch = *buffPos;
    nextPos();
    return ch;
  }
  inline void next(char* s) {
    while (isWS(*buffPos)) {
      nextPos();
    }
    while (!isWS(*buffPos)) {
      *s = *buffPos;
      s++;
      nextPos();
    }
    *s = '\0';
  }
  inline void nextLine(char* s) {
    while (*buffPos != '\n') {
      nextPos();
    }
    if (*buffPos == '\n') {
      nextPos();
    }
    while (*buffPos != '\n') {
      *s++ = *buffPos;
      nextPos();
    }
    *s = '\0';
  }
  inline int nextInt() {
    while (!isDig(*buffPos) && *buffPos != '-') {
      nextPos();
    }
    int sign = (*buffPos == '-') ? nextPos(), -1 : 1;
    int res = 0;
    while (isDig(*buffPos)) {
      res = res * 10 + *buffPos - '0';
      nextPos();
    }
    return res * sign;
  }
  inline long long nextLong() {
    while (!isDig(*buffPos) && *buffPos != '-') {
      nextPos();
    }
    long long sign = (*buffPos == '-') ? nextPos(), -1 : 1;
    long long res = 0;
    while (isDig(*buffPos)) {
      res = res * 10 + *buffPos - '0';
      nextPos();
    }
    return res * sign;
  }
  inline int n() {
    while (*buffPos < '0' || *buffPos > '9') {
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    int res = 0;
    while (*buffPos >= '0' && *buffPos <= '9') {
      res = res * 10 + (*buffPos - '0');
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    return res;
  }
  inline long long nl() {
    while (*buffPos < '0' || *buffPos > '9') {
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    long long res = 0;
    while (*buffPos >= '0' && *buffPos <= '9') {
      res = res * 10 + (*buffPos - '0');
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    return res;
  }
  inline long long nlm(const int MOD) {
    while (*buffPos < '0' || *buffPos > '9') {
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    long long res = 0;
    while (*buffPos >= '0' && *buffPos <= '9') {
      res = (res * 10 + (*buffPos - '0')) % MOD;
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    return res;
  }
  inline double nextDouble() {
    while (isWS(*buffPos)) {
      nextPos();
    }
    int sign = (*buffPos == '-') ? nextPos(), -1 : 1;
    double res = 0;
    while (isDig(*buffPos)) {
      res = res * 10 + *buffPos - '0';
      nextPos();
    }
    if (*buffPos == '.') {
      nextPos();
      double ep = 1;
      while (isDig(*buffPos)) {
        ep *= 0.1;
        res += ep * (*buffPos - '0');
        nextPos();
      }
    }
    return sign * res;
  }
  inline char nextChar() {
    while (isWS(*buffPos)) nextPos();
    char res = *buffPos;
    nextPos();
    return res;
  }
  ~Scanner() { fclose(file); }
};
Scanner sc(stdin);
template <class __TyFirst, class __TySecond>
std::ostream& operator<<(std::ostream& out,
                         const std::pair<__TyFirst, __TySecond>& o);
static std::string cout_list_sep = " ";
template <
    class IterateType, typename = decltype(std::declval<IterateType>().begin()),
    typename = decltype(std::declval<IterateType>().end()),
    typename = typename std::enable_if<std::is_convertible<
        typename std::iterator_traits<
            typename IterateType::iterator>::iterator_category,
        std::input_iterator_tag>::value>::type,
    typename = typename std::enable_if<!std::is_base_of<
        std::string, typename std::decay<IterateType>::type>::value>::type,
    typename value_type = typename IterateType::value_type>
std::ostream& operator<<(std::ostream& out, const IterateType& a) {
  for (const auto& i : a) out << i << cout_list_sep;
  return out;
}
template <class __TyFirst, class __TySecond>
std::ostream& operator<<(std::ostream& out,
                         const std::pair<__TyFirst, __TySecond>& o) {
  out << "(" << o.first << "," << o.second << ")";
  return out;
}
template <typename _ForwardIterator>
void logArray(_ForwardIterator, _ForwardIterator, const char* = 0) {}
namespace Temps {
template <typename _IntType>
class RangeInt {
  static_assert(std::is_integral<_IntType>::value,
                "RangeInt object must have integral value type");

 public:
  class iterator : public std::iterator<std::input_iterator_tag, _IntType,
                                        _IntType, const _IntType*, _IntType> {
    _IntType val, step;

   public:
    using typename std::iterator<std::input_iterator_tag, _IntType, _IntType,
                                 const _IntType*, _IntType>::reference;
    explicit constexpr iterator(int val, int step) noexcept
        : val(val), step(step) {}
    constexpr iterator& operator++() noexcept {
      val += step;
      return *this;
    }
    constexpr iterator operator++(int) noexcept {
      iterator ret = *this;
      val += step;
      return ret;
    }
    constexpr bool operator==(const iterator& rhs) const noexcept {
      return val == rhs.val;
    }
    constexpr bool operator!=(const iterator& rhs) const noexcept {
      return val != rhs.val;
    }
    constexpr reference operator*() const { return val; }
  };
  const _IntType _begin, _step, _end;
  explicit constexpr RangeInt(const _IntType end) noexcept
      : _begin(0), _step(1), _end(end > 0 ? end : 0) {}
  explicit constexpr RangeInt(const _IntType begin, const _IntType end) noexcept
      : _begin(begin), _step(1), _end(end > begin ? end : begin) {}
  explicit constexpr RangeInt(const _IntType begin, const _IntType end,
                              const _IntType step)
      : _begin(begin),
        _step(step),
        _end(((step > 0 && end <= begin) || (step < 0 && end >= begin))
                 ? begin
                 : (step > 0
                        ? begin + (end - begin + step - 1) / step * step
                        : begin + (begin - end - step - 1) / (-step) * step)) {}
  constexpr iterator begin() const noexcept { return iterator(_begin, _step); }
  constexpr iterator end() const noexcept { return iterator(_end, _step); }
  constexpr _IntType size() const noexcept { return (_end - _begin) / _step; }
};
template <class IntType, typename = typename std::enable_if<
                             std::is_integral<IntType>::value>::type>
inline constexpr RangeInt<IntType> range(IntType arg1) {
  return RangeInt<IntType>(arg1);
}
template <class IntType, typename = typename std::enable_if<
                             std::is_integral<IntType>::value>::type>
inline constexpr RangeInt<IntType> range(IntType arg1, IntType arg2) {
  return RangeInt<IntType>(arg1, arg2);
}
template <class IntType, typename = typename std::enable_if<
                             std::is_integral<IntType>::value>::type>
inline constexpr RangeInt<IntType> range(IntType arg1, IntType arg2,
                                         IntType arg3) {
  return RangeInt<IntType>(arg1, arg2, arg3);
}
}  // namespace Temps
using Temps::range;
namespace Temps {
template <class T>
inline bool checkMin(T& a, T b) {
  return (b < a ? a = b, 1 : 0);
}
template <class T>
inline bool checkMax(T& a, T b) {
  return (a < b ? a = b, 1 : 0);
}
template <class IntType, typename = typename std::enable_if<
                             std::is_integral<IntType>::value>::type>
IntType gcd(const IntType a, const IntType b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <class ForwardIterator, class OutputIterator>
void dissociate(ForwardIterator __begin, ForwardIterator __end,
                OutputIterator __dest) {
  std::vector<typename std::iterator_traits<ForwardIterator>::_IntType> values(
      __begin, __end);
  std::sort(values.begin(), values.end());
  std::unique(values.begin(), values.end());
  while (__begin != __end) {
    *__dest =
        std::distance(values.begin(),
                      std::lower_bound(values.begin(), values.end(), *__begin));
    __dest++;
    __begin++;
  }
}
}  // namespace Temps
using Temps::checkMax;
using Temps::checkMin;
namespace Temps {
template <class Type>
class Vector {
  static_assert(std::is_trivial<Type>::value,
                "Temps::Vector can only be used for trival types");

 public:
  typedef Type& reference;
  typedef const Type& const_reference;
  class iterator : public std::iterator<std::random_access_iterator_tag, Type> {
   public:
    friend class Vector;
    using typename std::iterator<std::random_access_iterator_tag,
                                 Type>::difference_type;
    using
        typename std::iterator<std::random_access_iterator_tag, Type>::pointer;
    using typename std::iterator<std::random_access_iterator_tag,
                                 Type>::reference;

   private:
    pointer ptr;
    iterator(pointer ptr) : ptr(ptr) {}

   public:
    bool operator==(const iterator rhs) const { return ptr == rhs.ptr; }
    bool operator!=(const iterator rhs) const { return ptr != rhs.ptr; }
    bool operator<(const iterator rhs) const { return ptr < rhs.ptr; }
    bool operator<=(const iterator rhs) const { return ptr <= rhs.ptr; }
    bool operator>(const iterator rhs) const { return ptr > rhs.ptr; }
    bool operator>=(const iterator rhs) const { return ptr >= rhs.ptr; }
    iterator operator++() { return iterator(++ptr); }
    iterator operator++(int) { return iterator(ptr++); }
    iterator operator--() { return iterator(--ptr); }
    iterator operator--(int) { return iterator(ptr--); }
    iterator operator+(const difference_type dif) const {
      return iterator(ptr + dif);
    }
    iterator operator-(const difference_type dif) const {
      return iterator(ptr - dif);
    }
    iterator operator+=(const difference_type dif) {
      ptr += dif;
      return *this;
    }
    iterator operator-=(const difference_type dif) {
      ptr -= dif;
      return *this;
    }
    difference_type operator-(const iterator& rhs) const {
      return ptr - rhs.ptr;
    }
    operator pointer() { return ptr; }
  };

 protected:
  Type* a = nullptr;
  unsigned int _capacity = 0, _size = 0;
  void __grow_capacity(unsigned int least_size) {
    if (_capacity >= least_size) {
      return;
    }
    if (_capacity == 0) {
      _capacity = 1;
    }
    while (_capacity < least_size) {
      _capacity = _capacity * 2;
    }
    a = static_cast<Type*>(realloc(a, sizeof(Type) * _capacity));
  }

 public:
  Vector() = default;
  explicit Vector(unsigned int size, const Type& initial_value = Type())
      : _capacity(size), _size(size) {
    a = static_cast<Type*>(malloc(sizeof(Type) * _capacity));
    Type *__first = a, *const __last = a + _size;
    while (__first != __last) {
      *__first++ = initial_value;
    }
  }
  Vector(const Vector& rhs) : _capacity(rhs._size), _size(rhs._size) {
    a = static_cast<Type*>(malloc(sizeof(Type) * _capacity));
    Type *__first = a, *__r_p = rhs.a, *const __last = a + _size;
    while (__first != __last) {
      *__first++ = *__r_p++;
    }
  }
  Vector(Vector&& rhs) : _capacity(rhs._capacity), _size(rhs._size) {
    a = rhs.a;
    rhs.a = nullptr;
  }
  template <typename Container,
            typename = decltype(std::declval<Container>().begin(),
                                std::declval<Container>().end())>
  Vector(const Container& list)
      : _capacity(std::distance(list.begin(), list.end())), _size(_capacity) {
    a = static_cast<Type*>(malloc(sizeof(Type) * _capacity));
    Type* p = a;
    for (const auto& i : list) {
      *p++ = i;
    }
  }
  template <
      typename _InputIterator,
      typename = typename std::enable_if<std::is_convertible<
          typename std::iterator_traits<_InputIterator>::iterator_category,
          std::input_iterator_tag>::value>::type>
  explicit Vector(_InputIterator __first, _InputIterator __last) {
    _size = _capacity = std::distance(__first, __last);
    a = static_cast<Type*>(malloc(sizeof(Type) * _capacity));
    Type* p = a;
    while (__first != __last) {
      *p++ = *__first++;
    }
  }
  inline bool empty() const { return _size == 0; }
  inline unsigned int size() const { return _size; }
  inline unsigned int capacity() const { return _capacity; }
  void reserve(unsigned int __capacity) {
    _capacity = __capacity;
    if (_size > _capacity) {
      _size = _capacity;
    }
    a = static_cast<Type*>(realloc(a, sizeof(Type) * _capacity));
  }
  void resize(unsigned int __size) {
    if (_size > __size) {
      _size = __size;
      return;
    }
    __grow_capacity(__size);
    Type *__un = a + _size, *const __ed = a + __size;
    while (__un != __ed) {
      *__un++ = Type();
    }
    _size = __size;
  }
  inline void clear() { resize(0); }
  Vector& operator=(const Vector& rhs) {
    __grow_capacity(rhs._size);
    _size = rhs._size;
    Type* __first = a;
    const Type *const __last = a + _size, *__r_p = rhs.a;
    while (__first != __last) {
      *__first++ = *__r_p++;
    }
    return *this;
  }
  Vector& operator=(Vector&& rhs) {
    _size = rhs._size;
    _capacity = rhs._capacity;
    free(a);
    a = rhs.a;
    rhs.a = nullptr;
    return *this;
  }
  Type operator[](const unsigned int id) const { return a[id]; }
  Type& operator[](const unsigned int id) { return a[id]; }
  Type front() const { return a[0]; }
  Type& front() { return a[0]; }
  Type back() const { return a[_size - 1]; }
  Type& back() { return a[_size - 1]; }
  void pop_back() { _size--; }
  Vector& push_back(const Type& b) {
    __grow_capacity(_size + 1);
    a[_size] = b;
    _size++;
    return *this;
  }
  Vector& push_back(const Vector& rhs) {
    __grow_capacity(_size + rhs._size);
    for (const auto& i : rhs) {
      a[_size++] = i;
    }
    return *this;
  }
  Vector& push_back(const std::initializer_list<Type>& rhs) {
    __grow_capacity(_size + rhs.size());
    for (const auto& i : rhs) {
      a[_size++] = i;
    }
    return *this;
  }
  inline iterator begin() const { return iterator(a); }
  inline iterator end() const { return iterator(a + _size); }
  ~Vector() { free(a); }
};
}  // namespace Temps
using Temps::Vector;
void preInit();
void init();
void solve();
int32_t main() {
  preInit();
  init();
  solve();
  return 0;
}
constexpr int N = 500005;
struct STree {
  struct Node {
    int a = 0, b = 0;
    bool flip_flag = false;
    Node() = default;
    Node(const Node& l, const Node& r)
        : a(std::max(l.a, r.a)), b(std::max(l.b, r.b)) {}
    void flip() {
      std::swap(a, b);
      flip_flag = !flip_flag;
    }
    void push_down(Node& l, Node& r) {
      if (flip_flag) {
        l.flip();
        r.flip();
        flip_flag = false;
      }
    }
  } p[N * 4];
  void init(int* a, int l, int r, int u) {
    if (r - l == 1) {
      p[u].a = a[l];
      return;
    }
    int mid = (l + r) / 2;
    init(a, l, mid, u + u);
    init(a, mid, r, u + u + 1);
    p[u] = Node(p[u + u], p[u + u + 1]);
  }
  void flip(int fl, int fr, int l, int r, int u) {
    if (fl <= l && r <= fr) {
      p[u].flip();
      return;
    }
    p[u].push_down(p[u + u], p[u + u + 1]);
    int mid = (l + r) / 2;
    if (fl < mid) flip(fl, fr, l, mid, u + u);
    if (fr > mid) flip(fl, fr, mid, r, u + u + 1);
    p[u] = Node(p[u + u], p[u + u + 1]);
  }
  Node query(int ql, int qr, int l, int r, int u) {
    if (ql <= l && r <= qr) {
      return p[u];
    }
    p[u].push_down(p[u + u], p[u + u + 1]);
    int mid = (l + r) / 2;
    if (ql >= mid) {
      return query(ql, qr, mid, r, u + u + 1);
    }
    if (qr <= mid) {
      return query(ql, qr, l, mid, u + u);
    }
    return Node(query(ql, qr, l, mid, u + u), query(ql, qr, mid, r, u + u + 1));
  }
};
Vector<int> e[N];
int u[N], v[N], w[N], n, m, r1, r2;
std::pair<int, int> get_farthest(int u, int f) {
  std::pair<int, int> res(-1, u);
  for (int v : e[u])
    if (v != f) {
      checkMax(res, get_farthest(v, u));
    }
  res.first++;
  return res;
}
struct Tree {
  STree st;
  int dep[N], dfnl[N], dfnr[N], dfn_top = 0;
  void dfs(int u, int f) {
    dfnl[u] = dfn_top++;
    dep[dfnl[u]] = dep[dfnl[f]] + 1;
    for (int v : e[u])
      if (v != f) dfs(v, u);
    dfnr[u] = dfn_top;
  }
  void init(int r) {
    dep[0] = -1;
    dfs(r, 0);
    st.init(dep, 0, n, 1);
  }
  void flip(int u, int v) {
    if (dep[dfnl[v]] > dep[dfnl[u]]) {
      u = v;
    }
    st.flip(dfnl[u], dfnr[u], 0, n, 1);
  }
  int query() { return st.query(0, n, 0, n, 1).a; }
} T1, T2;
void preInit() {}
void init() {
  n = sc.n();
  for (int i = 1; i < n; ++i) {
    u[i] = sc.n(), v[i] = sc.n(), w[i] = sc.n();
    e[u[i]].push_back(v[i]), e[v[i]].push_back(u[i]);
  }
  m = sc.n();
}
void solve() {
  r1 = get_farthest(1, 0).second;
  T1.init(r1);
  r2 = get_farthest(r1, 0).second;
  T2.init(r2);
  ;
  for (int i = 1; i < n; ++i)
    if (w[i]) {
      T1.flip(u[i], v[i]);
      T2.flip(u[i], v[i]);
    }
  for (int i = 0; i < m; ++i) {
    int id = sc.n();
    T1.flip(u[id], v[id]);
    T2.flip(u[id], v[id]);
    printf("%d\n", std::max(T1.query(), T2.query()));
  }
}
