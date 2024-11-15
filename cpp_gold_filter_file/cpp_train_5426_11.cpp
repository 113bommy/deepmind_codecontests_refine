#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pill = pair<int, ll>;
using plli = pair<ll, int>;
using pdd = pair<double, double>;
using pld = pair<ld, ld>;
constexpr const char nl = '\n', sp = ' ';
constexpr const int INT_INF = 0x3f3f3f3f;
constexpr const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
constexpr const double D_INF = numeric_limits<double>::infinity();
constexpr const ld LD_INF = numeric_limits<ld>::infinity();
constexpr const double EPS = 1e-9;
template <class T>
constexpr bool flt(const T& x, const T& y) {
  return x < y - EPS;
}
template <class T>
constexpr bool fgt(const T& x, const T& y) {
  return x > y + EPS;
}
template <class T>
constexpr bool feq(const T& x, const T& y) {
  return abs(x - y) <= EPS;
}
template <class T>
constexpr bool in(const T& v, const T& lo, const T& hi) {
  return !(v < lo || hi < v);
}
template <class T>
constexpr const T& _min(const T& x, const T& y) {
  return x < y ? x : y;
}
template <class T>
constexpr const T& _max(const T& x, const T& y) {
  return x < y ? y : x;
}
template <class T, class... Ts>
constexpr const T& _min(const T& x, const Ts&... xs) {
  return _min(x, _min(xs...));
}
template <class T, class... Ts>
constexpr const T& _max(const T& x, const Ts&... xs) {
  return _max(x, _max(xs...));
}
template <class T, class... Ts>
void MIN(T& x, const Ts&... xs) {
  x = _min(x, xs...);
}
template <class T, class... Ts>
void MAX(T& x, const Ts&... xs) {
  x = _max(x, xs...);
}
template <class T>
constexpr const T& _clamp(const T& v, const T& lo, const T& hi) {
  return v < lo ? lo : hi < v ? hi : v;
}
template <class T>
void CLAMP(T& v, const T& lo, const T& hi) {
  v = _clamp(v, lo, hi);
}
template <class T, class... Args>
unique_ptr<T> _make_unique(Args&&... args) {
  return unique_ptr<T>(new T(forward<Args>(args)...));
}
template <class T, class... Args>
shared_ptr<T> _make_shared(Args&&... args) {
  return shared_ptr<T>(new T(forward<Args>(args)...));
}
template <class... Ts>
using uset = unordered_set<Ts...>;
template <class... Ts>
using umap = unordered_map<Ts...>;
template <class... Ts>
using pq = priority_queue<Ts...>;
template <class T>
using minpq = pq<T, vector<T>, greater<T>>;
template <class T>
using maxpq = pq<T, vector<T>, less<T>>;
template <class T1, class T2, class H1 = hash<T1>, class H2 = hash<T2>>
struct pair_hash {
  size_t operator()(const pair<T1, T2>& p) const {
    return 31 * H1{}(p.first) + H2{}(p.second);
  }
};
template <class T>
struct is_iterator {
  template <class U, typename enable_if<!is_convertible<U, const char*>::value,
                                        int>::type = 0>
  constexpr static auto has_indirection(int)
      -> decltype(*declval<U>(), bool()) {
    return true;
  }
  template <class>
  constexpr static bool has_indirection(long) {
    return false;
  }
  constexpr static bool value = has_indirection<T>(0);
};
seed_seq seq{(uint64_t)chrono::duration_cast<chrono::nanoseconds>(
                 chrono::high_resolution_clock::now().time_since_epoch())
                 .count(),
             (uint64_t)__builtin_ia32_rdtsc(),
             (uint64_t)(uintptr_t)_make_unique<char>().get()};
mt19937 rng(seq);
mt19937_64 rng64(seq);
constexpr const int _bufferSize = 4096, _maxNumLength = 128;
char _inputBuffer[_bufferSize + 1],
    *_inputPtr = _inputBuffer, _outputBuffer[_bufferSize], _c, _sign,
    *_tempInputBuf = nullptr, _numBuf[_maxNumLength],
    _tempOutputBuf[_maxNumLength], _fill = ' ';
FILE *_input = stdin, *_output = stdout, *_error = stderr;
const char* _delimiter = " ";
int _cur, _outputPtr = 0, _numPtr = 0, _precision = 6, _width = 0,
          _tempOutputPtr = 0, _cnt;
ull _precisionBase = 1000000;
void read(int& x) {
  do {
    do {
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                                              _bufferSize, _input)] = '\0',
                           *_inputPtr++));
    } while ((x) <= ' ');
    _sign = (x) == '-';
    if (_sign)
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                                              _bufferSize, _input)] = '\0',
                           *_inputPtr++));
    for ((x) -= '0';
         (_c = (*_inputPtr ? *_inputPtr++
                           : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                             _bufferSize, _input)] = '\0',
                                          *_inputPtr++))) >= '0';
         (x) = (x)*10 + _c - '0')
      ;
    if (_sign) (x) = -(x);
  } while (0);
}
void read(uint& x) {
  do {
    do {
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                                              _bufferSize, _input)] = '\0',
                           *_inputPtr++));
    } while ((x) <= ' ');
    _sign = (x) == '-';
    if (_sign)
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                                              _bufferSize, _input)] = '\0',
                           *_inputPtr++));
    for ((x) -= '0';
         (_c = (*_inputPtr ? *_inputPtr++
                           : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                             _bufferSize, _input)] = '\0',
                                          *_inputPtr++))) >= '0';
         (x) = (x)*10 + _c - '0')
      ;
    if (_sign) (x) = -(x);
  } while (0);
}
void read(ll& x) {
  do {
    do {
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                                              _bufferSize, _input)] = '\0',
                           *_inputPtr++));
    } while ((x) <= ' ');
    _sign = (x) == '-';
    if (_sign)
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                                              _bufferSize, _input)] = '\0',
                           *_inputPtr++));
    for ((x) -= '0';
         (_c = (*_inputPtr ? *_inputPtr++
                           : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                             _bufferSize, _input)] = '\0',
                                          *_inputPtr++))) >= '0';
         (x) = (x)*10 + _c - '0')
      ;
    if (_sign) (x) = -(x);
  } while (0);
}
void read(ull& x) {
  do {
    do {
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                                              _bufferSize, _input)] = '\0',
                           *_inputPtr++));
    } while ((x) <= ' ');
    _sign = (x) == '-';
    if (_sign)
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                                              _bufferSize, _input)] = '\0',
                           *_inputPtr++));
    for ((x) -= '0';
         (_c = (*_inputPtr ? *_inputPtr++
                           : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                             _bufferSize, _input)] = '\0',
                                          *_inputPtr++))) >= '0';
         (x) = (x)*10 + _c - '0')
      ;
    if (_sign) (x) = -(x);
  } while (0);
}
void read(double& x) {
  do {
    do {
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                                              _bufferSize, _input)] = '\0',
                           *_inputPtr++));
    } while ((x) <= ' ');
    _sign = (x) == '-';
    if (_sign)
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                                              _bufferSize, _input)] = '\0',
                           *_inputPtr++));
    for ((x) -= '0';
         (_c = (*_inputPtr ? *_inputPtr++
                           : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                             _bufferSize, _input)] = '\0',
                                          *_inputPtr++))) >= '0';
         (x) = (x)*10 + _c - '0')
      ;
    if (_c == '.')
      for (double _div = 1.0;
           (_c = (*_inputPtr ? *_inputPtr++
                             : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                               _bufferSize, _input)] = '\0',
                                            *_inputPtr++))) >= '0';
           (x) += (_c - '0') / (_div *= 10))
        ;
    if (_sign) (x) = -(x);
  } while (0);
}
void read(ld& x) {
  do {
    do {
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                                              _bufferSize, _input)] = '\0',
                           *_inputPtr++));
    } while ((x) <= ' ');
    _sign = (x) == '-';
    if (_sign)
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                                              _bufferSize, _input)] = '\0',
                           *_inputPtr++));
    for ((x) -= '0';
         (_c = (*_inputPtr ? *_inputPtr++
                           : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                             _bufferSize, _input)] = '\0',
                                          *_inputPtr++))) >= '0';
         (x) = (x)*10 + _c - '0')
      ;
    if (_c == '.')
      for (ld _div = 1.0;
           (_c = (*_inputPtr ? *_inputPtr++
                             : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                               _bufferSize, _input)] = '\0',
                                            *_inputPtr++))) >= '0';
           (x) += (_c - '0') / (_div *= 10))
        ;
    if (_sign) (x) = -(x);
  } while (0);
}
void read(char& x) {
  do {
    do {
      (x) = (*_inputPtr ? *_inputPtr++
                        : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                                              _bufferSize, _input)] = '\0',
                           *_inputPtr++));
    } while ((x) <= ' ');
  } while (0);
}
void read(char* x) {
  do {
    _cur = 0;
    do {
      _c = (*_inputPtr ? *_inputPtr++
                       : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                                             _bufferSize, _input)] = '\0',
                          *_inputPtr++));
    } while (_c <= ' ');
    do {
      (x)[_cur++] = _c;
    } while (
        (_c = (*_inputPtr ? *_inputPtr++
                          : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                                                _bufferSize, _input)] = '\0',
                             *_inputPtr++))) > ' ');
    (x)[_cur] = '\0';
  } while (0);
}
void read(string& x) {
  do {
    if (!_tempInputBuf) assert(0);
    do {
      _cur = 0;
      do {
        _c = (*_inputPtr ? *_inputPtr++
                         : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                                               _bufferSize, _input)] = '\0',
                            *_inputPtr++));
      } while (_c <= ' ');
      do {
        (_tempInputBuf)[_cur++] = _c;
      } while (
          (_c = (*_inputPtr ? *_inputPtr++
                            : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                                                  _bufferSize, _input)] = '\0',
                               *_inputPtr++))) > ' ');
      (_tempInputBuf)[_cur] = '\0';
    } while (0);
    (x) = string(_tempInputBuf, _cur);
  } while (0);
}
void readln(char* x) {
  do {
    _cur = 0;
    do {
      _c = (*_inputPtr ? *_inputPtr++
                       : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                                             _bufferSize, _input)] = '\0',
                          *_inputPtr++));
    } while (_c <= ' ');
    do {
      (x)[_cur++] = _c;
    } while (
        (_c = (*_inputPtr ? *_inputPtr++
                          : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                                                _bufferSize, _input)] = '\0',
                             *_inputPtr++))) >= ' ');
    (x)[_cur] = '\0';
  } while (0);
}
void readln(string& x) {
  do {
    if (!_tempInputBuf) assert(0);
    do {
      _cur = 0;
      do {
        _c = (*_inputPtr ? *_inputPtr++
                         : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                                               _bufferSize, _input)] = '\0',
                            *_inputPtr++));
      } while (_c <= ' ');
      do {
        (_tempInputBuf)[_cur++] = _c;
      } while (
          (_c = (*_inputPtr ? *_inputPtr++
                            : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                                                  _bufferSize, _input)] = '\0',
                               *_inputPtr++))) >= ' ');
      (_tempInputBuf)[_cur] = '\0';
    } while (0);
    (x) = string(_tempInputBuf, _cur);
  } while (0);
}
template <class T1, class T2>
void read(pair<T1, T2>& x) {
  read(x.first);
  read(x.second);
}
template <class T>
void read(complex<T>& x) {
  T _re, _im;
  read(_re);
  read(_im);
  x.real(_re);
  x.imag(_im);
}
template <class T>
void read(T& x);
template <class T, class... Ts>
void read(T& x, Ts&&... xs);
template <class It>
typename enable_if<is_iterator<It>::value>::type read(It st, It en) {
  for (It _i = st; _i != en; _i++) read(*_i);
}
template <class It, class... Ts>
typename enable_if<is_iterator<It>::value>::type read(It st, It en,
                                                      Ts&&... xs) {
  read(st, en);
  read(forward<Ts>(xs)...);
}
template <class T>
void read(T& x) {
  for (auto&& _i : x) read(_i);
}
template <class T, class... Ts>
void read(T& x, Ts&&... xs) {
  read(x);
  read(forward<Ts>(xs)...);
}
bool hasNext() {
  while ((*_inputPtr || !feof(_input)) &&
         (*_inputPtr ? *_inputPtr
                     : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1,
                                           _bufferSize, _input)] = '\0',
                        *_inputPtr)) <= ' ')
    (*_inputPtr ? *_inputPtr++
                : (_inputBuffer[fread(_inputPtr = _inputBuffer, 1, _bufferSize,
                                      _input)] = '\0',
                   *_inputPtr++));
  return (*_inputPtr || !feof(_input));
}
void setInput(FILE* file) {
  *_inputPtr = '\0';
  _input = file;
}
void setInput(const char* second) {
  *_inputPtr = '\0';
  _input = fopen(second, "r");
}
void setInput(const string& second) {
  *_inputPtr = '\0';
  _input = fopen(second.c_str(), "r");
}
void writeDelimiter() {
  for (const char* _p = _delimiter; *_p;
       (_outputBuffer[_outputPtr == _bufferSize
                          ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                             _outputPtr = 0)
                          : _outputPtr] = (*_p++),
                            _outputPtr++))
    ;
}
void write(const bool& x) {
  do {
    if (x)
      (_tempOutputBuf[_tempOutputPtr++] = ('1'));
    else
      (_tempOutputBuf[_tempOutputPtr++] = ('0'));
    int _tempLen = _tempOutputPtr;
    for (int _i = 0; _i < (_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == _bufferSize
                         ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
    for (int _i = 0; _i < _tempOutputPtr;
         (_outputBuffer[_outputPtr == _bufferSize
                            ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                               _outputPtr = 0)
                            : _outputPtr] = (_tempOutputBuf[_i++]),
                              _outputPtr++))
      ;
    _tempOutputPtr = 0;
    for (int _i = 0; _i < (-_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == _bufferSize
                         ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
  } while (0);
}
void write(const int& x) {
  do {
    if ((x) < 0) {
      (_tempOutputBuf[_tempOutputPtr++] = ('-'));
      _cnt = 0;
      for (uint _y = (-(x)); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < 1; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
    } else {
      _cnt = 0;
      for (uint _y = (x); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < 1; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
    }
    int _tempLen = _tempOutputPtr;
    for (int _i = 0; _i < (_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == _bufferSize
                         ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
    for (int _i = 0; _i < _tempOutputPtr;
         (_outputBuffer[_outputPtr == _bufferSize
                            ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                               _outputPtr = 0)
                            : _outputPtr] = (_tempOutputBuf[_i++]),
                              _outputPtr++))
      ;
    _tempOutputPtr = 0;
    for (int _i = 0; _i < (-_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == _bufferSize
                         ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
  } while (0);
}
void write(const uint& x) {
  do {
    if ((x) < 0) {
      (_tempOutputBuf[_tempOutputPtr++] = ('-'));
      _cnt = 0;
      for (uint _y = (-(x)); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < 1; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
    } else {
      _cnt = 0;
      for (uint _y = (x); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < 1; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
    }
    int _tempLen = _tempOutputPtr;
    for (int _i = 0; _i < (_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == _bufferSize
                         ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
    for (int _i = 0; _i < _tempOutputPtr;
         (_outputBuffer[_outputPtr == _bufferSize
                            ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                               _outputPtr = 0)
                            : _outputPtr] = (_tempOutputBuf[_i++]),
                              _outputPtr++))
      ;
    _tempOutputPtr = 0;
    for (int _i = 0; _i < (-_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == _bufferSize
                         ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
  } while (0);
}
void write(const ll& x) {
  do {
    if ((x) < 0) {
      (_tempOutputBuf[_tempOutputPtr++] = ('-'));
      _cnt = 0;
      for (ull _y = (-(x)); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < 1; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
    } else {
      _cnt = 0;
      for (ull _y = (x); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < 1; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
    }
    int _tempLen = _tempOutputPtr;
    for (int _i = 0; _i < (_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == _bufferSize
                         ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
    for (int _i = 0; _i < _tempOutputPtr;
         (_outputBuffer[_outputPtr == _bufferSize
                            ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                               _outputPtr = 0)
                            : _outputPtr] = (_tempOutputBuf[_i++]),
                              _outputPtr++))
      ;
    _tempOutputPtr = 0;
    for (int _i = 0; _i < (-_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == _bufferSize
                         ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
  } while (0);
}
void write(const ull& x) {
  do {
    if ((x) < 0) {
      (_tempOutputBuf[_tempOutputPtr++] = ('-'));
      _cnt = 0;
      for (ull _y = (-(x)); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < 1; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
    } else {
      _cnt = 0;
      for (ull _y = (x); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < 1; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
    }
    int _tempLen = _tempOutputPtr;
    for (int _i = 0; _i < (_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == _bufferSize
                         ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
    for (int _i = 0; _i < _tempOutputPtr;
         (_outputBuffer[_outputPtr == _bufferSize
                            ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                               _outputPtr = 0)
                            : _outputPtr] = (_tempOutputBuf[_i++]),
                              _outputPtr++))
      ;
    _tempOutputPtr = 0;
    for (int _i = 0; _i < (-_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == _bufferSize
                         ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
  } while (0);
}
void write(const double& x) {
  do {
    if (std::isnan(x)) {
      do {
        int _slen = strlen("NaN");
        for (int _i = 0; _i < (_width - _slen); _i++)
          (_outputBuffer[_outputPtr == _bufferSize
                             ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                                _outputPtr = 0)
                             : _outputPtr] = (_fill),
           _outputPtr++);
        for (const char* _p = ("NaN"); *_p;
             (_outputBuffer[_outputPtr == _bufferSize
                                ? (fwrite(_outputBuffer, 1, _outputPtr,
                                          _output),
                                   _outputPtr = 0)
                                : _outputPtr] = (*_p++),
                                  _outputPtr++))
          ;
        for (int _i = 0; _i < (-_width - _slen); _i++)
          (_outputBuffer[_outputPtr == _bufferSize
                             ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                                _outputPtr = 0)
                             : _outputPtr] = (_fill),
           _outputPtr++);
      } while (0);
    } else if (std::isinf(x)) {
      do {
        int _slen = strlen("Inf");
        for (int _i = 0; _i < (_width - _slen); _i++)
          (_outputBuffer[_outputPtr == _bufferSize
                             ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                                _outputPtr = 0)
                             : _outputPtr] = (_fill),
           _outputPtr++);
        for (const char* _p = ("Inf"); *_p;
             (_outputBuffer[_outputPtr == _bufferSize
                                ? (fwrite(_outputBuffer, 1, _outputPtr,
                                          _output),
                                   _outputPtr = 0)
                                : _outputPtr] = (*_p++),
                                  _outputPtr++))
          ;
        for (int _i = 0; _i < (-_width - _slen); _i++)
          (_outputBuffer[_outputPtr == _bufferSize
                             ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                                _outputPtr = 0)
                             : _outputPtr] = (_fill),
           _outputPtr++);
      } while (0);
    } else if ((x) < 0) {
      (_tempOutputBuf[_tempOutputPtr++] = ('-'));
      ull _I = (ull)(-(x));
      ull _F = ((-(x)) - _I) * _precisionBase + (double)(0.5);
      if (_F >= _precisionBase) {
        _I++;
        _F = 0;
      }
      _cnt = 0;
      for (ull _y = (_I); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < 1; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
      (_tempOutputBuf[_tempOutputPtr++] = ('.'));
      _cnt = 0;
      for (ull _y = (_F); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < _precision; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
    } else {
      ull _I = (ull)(x);
      ull _F = ((x)-_I) * _precisionBase + (double)(0.5);
      if (_F >= _precisionBase) {
        _I++;
        _F = 0;
      }
      _cnt = 0;
      for (ull _y = (_I); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < 1; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
      (_tempOutputBuf[_tempOutputPtr++] = ('.'));
      _cnt = 0;
      for (ull _y = (_F); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < _precision; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
    }
    int _tempLen = _tempOutputPtr;
    for (int _i = 0; _i < (_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == _bufferSize
                         ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
    for (int _i = 0; _i < _tempOutputPtr;
         (_outputBuffer[_outputPtr == _bufferSize
                            ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                               _outputPtr = 0)
                            : _outputPtr] = (_tempOutputBuf[_i++]),
                              _outputPtr++))
      ;
    _tempOutputPtr = 0;
    for (int _i = 0; _i < (-_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == _bufferSize
                         ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
  } while (0);
}
void write(const ld& x) {
  do {
    if (std::isnan(x)) {
      do {
        int _slen = strlen("NaN");
        for (int _i = 0; _i < (_width - _slen); _i++)
          (_outputBuffer[_outputPtr == _bufferSize
                             ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                                _outputPtr = 0)
                             : _outputPtr] = (_fill),
           _outputPtr++);
        for (const char* _p = ("NaN"); *_p;
             (_outputBuffer[_outputPtr == _bufferSize
                                ? (fwrite(_outputBuffer, 1, _outputPtr,
                                          _output),
                                   _outputPtr = 0)
                                : _outputPtr] = (*_p++),
                                  _outputPtr++))
          ;
        for (int _i = 0; _i < (-_width - _slen); _i++)
          (_outputBuffer[_outputPtr == _bufferSize
                             ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                                _outputPtr = 0)
                             : _outputPtr] = (_fill),
           _outputPtr++);
      } while (0);
    } else if (std::isinf(x)) {
      do {
        int _slen = strlen("Inf");
        for (int _i = 0; _i < (_width - _slen); _i++)
          (_outputBuffer[_outputPtr == _bufferSize
                             ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                                _outputPtr = 0)
                             : _outputPtr] = (_fill),
           _outputPtr++);
        for (const char* _p = ("Inf"); *_p;
             (_outputBuffer[_outputPtr == _bufferSize
                                ? (fwrite(_outputBuffer, 1, _outputPtr,
                                          _output),
                                   _outputPtr = 0)
                                : _outputPtr] = (*_p++),
                                  _outputPtr++))
          ;
        for (int _i = 0; _i < (-_width - _slen); _i++)
          (_outputBuffer[_outputPtr == _bufferSize
                             ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                                _outputPtr = 0)
                             : _outputPtr] = (_fill),
           _outputPtr++);
      } while (0);
    } else if ((x) < 0) {
      (_tempOutputBuf[_tempOutputPtr++] = ('-'));
      ull _I = (ull)(-(x));
      ull _F = ((-(x)) - _I) * _precisionBase + (ld)(0.5);
      if (_F >= _precisionBase) {
        _I++;
        _F = 0;
      }
      _cnt = 0;
      for (ull _y = (_I); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < 1; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
      (_tempOutputBuf[_tempOutputPtr++] = ('.'));
      _cnt = 0;
      for (ull _y = (_F); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < _precision; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
    } else {
      ull _I = (ull)(x);
      ull _F = ((x)-_I) * _precisionBase + (ld)(0.5);
      if (_F >= _precisionBase) {
        _I++;
        _F = 0;
      }
      _cnt = 0;
      for (ull _y = (_I); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < 1; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
      (_tempOutputBuf[_tempOutputPtr++] = ('.'));
      _cnt = 0;
      for (ull _y = (_F); _y; _y /= 10, _cnt++)
        _numBuf[_numPtr++] = '0' + _y % 10;
      for (; _cnt < _precision; _cnt++) _numBuf[_numPtr++] = '0';
      for (; _numPtr; (_tempOutputBuf[_tempOutputPtr++] = (_numBuf[--_numPtr])))
        ;
      ;
    }
    int _tempLen = _tempOutputPtr;
    for (int _i = 0; _i < (_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == _bufferSize
                         ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
    for (int _i = 0; _i < _tempOutputPtr;
         (_outputBuffer[_outputPtr == _bufferSize
                            ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                               _outputPtr = 0)
                            : _outputPtr] = (_tempOutputBuf[_i++]),
                              _outputPtr++))
      ;
    _tempOutputPtr = 0;
    for (int _i = 0; _i < (-_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == _bufferSize
                         ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
  } while (0);
}
void write(const char& x) {
  do {
    (_tempOutputBuf[_tempOutputPtr++] = (x));
    int _tempLen = _tempOutputPtr;
    for (int _i = 0; _i < (_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == _bufferSize
                         ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
    for (int _i = 0; _i < _tempOutputPtr;
         (_outputBuffer[_outputPtr == _bufferSize
                            ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                               _outputPtr = 0)
                            : _outputPtr] = (_tempOutputBuf[_i++]),
                              _outputPtr++))
      ;
    _tempOutputPtr = 0;
    for (int _i = 0; _i < (-_width - _tempLen); _i++)
      (_outputBuffer[_outputPtr == _bufferSize
                         ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
  } while (0);
}
void write(const char* x) {
  do {
    int _slen = strlen(x);
    for (int _i = 0; _i < (_width - _slen); _i++)
      (_outputBuffer[_outputPtr == _bufferSize
                         ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
    for (const char* _p = (x); *_p;
         (_outputBuffer[_outputPtr == _bufferSize
                            ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                               _outputPtr = 0)
                            : _outputPtr] = (*_p++),
                              _outputPtr++))
      ;
    for (int _i = 0; _i < (-_width - _slen); _i++)
      (_outputBuffer[_outputPtr == _bufferSize
                         ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
  } while (0);
}
void write(const string& x) {
  do {
    for (int _i = 0; _i < (_width - int((x).length())); _i++)
      (_outputBuffer[_outputPtr == _bufferSize
                         ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
    for (int _i = 0; _i < int((x).length());
         (_outputBuffer[_outputPtr == _bufferSize
                            ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                               _outputPtr = 0)
                            : _outputPtr] = (x[_i++]),
                              _outputPtr++))
      ;
    for (int _i = 0; _i < (-_width - int((x).length())); _i++)
      (_outputBuffer[_outputPtr == _bufferSize
                         ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                            _outputPtr = 0)
                         : _outputPtr] = (_fill),
       _outputPtr++);
  } while (0);
}
template <class T1, class T2>
void write(const pair<T1, T2>& x) {
  write(x.first);
  writeDelimiter();
  write(x.second);
}
template <class T>
void write(const complex<T>& x) {
  write(x.real());
  writeDelimiter();
  write(x.imag());
}
template <class T>
void write(const T& x);
template <class T, class... Ts>
void write(const T& x, Ts&&... xs);
template <class It>
typename enable_if<is_iterator<It>::value>::type write(It st, It en) {
  bool _first = 1;
  for (It _i = st; _i != en; _i++) {
    if (_first)
      _first = 0;
    else
      writeDelimiter();
    write(*_i);
  }
}
template <class It, class... Ts>
typename enable_if<is_iterator<It>::value>::type write(It st, It en,
                                                       Ts&&... xs) {
  write(st, en);
  writeDelimiter();
  write(forward<Ts>(xs)...);
}
template <class T>
void write(const T& x) {
  bool _first = 1;
  for (auto&& _i : x) {
    if (_first)
      _first = 0;
    else
      writeDelimiter();
    write(_i);
  }
}
template <class T, class... Ts>
void write(const T& x, Ts&&... xs) {
  write(x);
  writeDelimiter();
  write(forward<Ts>(xs)...);
}
void writeln() {
  (_outputBuffer[_outputPtr == _bufferSize
                     ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                        _outputPtr = 0)
                     : _outputPtr] = ('\n'),
   _outputPtr++);
}
template <class... Ts>
void writeln(Ts&&... xs) {
  write(forward<Ts>(xs)...);
  (_outputBuffer[_outputPtr == _bufferSize
                     ? (fwrite(_outputBuffer, 1, _outputPtr, _output),
                        _outputPtr = 0)
                     : _outputPtr] = ('\n'),
   _outputPtr++);
}
void flush() {
  do {
    (fwrite(_outputBuffer, 1, _outputPtr, _output), _outputPtr = 0);
    fflush(_output);
  } while (0);
}
class IOManager {
 public:
  ~IOManager() {
    flush();
    if (_tempInputBuf) delete[](_tempInputBuf);
  }
};
unique_ptr<IOManager> iomanager = _make_unique<IOManager>();
void setOutput(FILE* file) {
  flush();
  _output = file;
}
void setOutput(const char* second) {
  flush();
  _output = fopen(second, "w");
}
void setOutput(const string& second) {
  flush();
  _output = fopen(second.c_str(), "w");
}
template <class... Ts>
void debug(const Ts&... xs) {
  FILE* _temp = _output;
  setOutput(_error);
  write(xs...);
  setOutput(_temp);
}
template <class... Ts>
void debugln(const Ts&... xs) {
  FILE* _temp = _output;
  setOutput(_error);
  writeln(xs...);
  setOutput(_temp);
}
void setError(FILE* file) {
  flush();
  _error = file;
}
void setError(const char* second) {
  flush();
  _error = fopen(second, "w");
}
void setError(const string& second) {
  flush();
  _error = fopen(second.c_str(), "w");
}
template <const int MAXN, const bool ONE_INDEXED>
struct SegmentTree_SAM_RQ {
  using Data = pii;
  int N;
  Data T[2 * MAXN];
  const Data def = make_pair(INT_INF, -INT_INF);
  const Data qdef = make_pair(INT_INF, -INT_INF);
  Data merge(Data l, Data r) {
    return make_pair(_min(l.first, r.first), _max(l.second, r.second));
  }
  Data applyVal(Data l, Data r) { return r; }
  template <class it>
  void init(it st, it en) {
    N = en - st;
    for (int i = 0; i < N; i++) T[N + i] = *(st + i);
    for (int i = N - 1; i > 0; i--) T[i] = merge(T[i << 1], T[i << 1 | 1]);
  }
  void init(int size) {
    N = size;
    for (int i = 1; i < 2 * N; i++) T[i] = def;
  }
  void update(int i, Data v) {
    for (i += N - ONE_INDEXED, T[i] = applyVal(T[i], v); i >>= 1;)
      T[i] = merge(T[i << 1], T[i << 1 | 1]);
  }
  Data query(int l, int r) {
    Data ql = qdef, qr = qdef;
    for (l += N - ONE_INDEXED, r += N - ONE_INDEXED; l <= r; l >>= 1, r >>= 1) {
      if (l & 1) ql = merge(ql, T[l++]);
      if (!(r & 1)) qr = merge(T[r--], qr);
    }
    return merge(ql, qr);
  }
};
const int MAXN = 1e5 + 5, MAXLGN = 20;
int N, R[MAXN], ans[MAXN];
SegmentTree_SAM_RQ<MAXN * 3, false> T[MAXLGN];
pii RANGE[MAXLGN][MAXN * 3];
int main() {
  read(N);
  read(R, R + N);
  if (N == 1) {
    writeln(0);
    return 0;
  }
  for (auto i = (0); i < (MAXLGN); i++) T[i].init(3 * N);
  for (auto j = (0); j < (3 * N); j++)
    T[0].update(j, RANGE[0][j] = make_pair(_max(0, j - R[j % N]),
                                           _min(3 * N - 1, j + R[j % N])));
  for (auto i = (1); i < (MAXLGN); i++)
    for (auto j = (0); j < (3 * N); j++)
      T[i].update(j, RANGE[i][j] = T[i - 1].query(RANGE[i - 1][j].first,
                                                  RANGE[i - 1][j].second));
  for (auto i = (0); i < (N); i++) {
    ans[i] = 1;
    pii cur = make_pair(N + i, N + i);
    for (auto j = (MAXLGN - 1); j > (-1); j--) {
      pii nxt = T[j].query(cur.first, cur.second);
      if (nxt.second - nxt.first + 1 < N) {
        ans[i] += 1 << j;
        cur = nxt;
      }
    }
  }
  writeln(ans, ans + N);
  return 0;
}
