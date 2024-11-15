#include <bits/stdc++.h>
using namespace std;
complex<double> leer() {
  double x, y;
  cin >> x >> y;
  return complex<double>(x, y);
}
void leer(double input[3]) {
  complex<double> in[3];
  for (int i = 0; i < 3; i++) in[i] = leer();
  for (int i = 0; i < 3; i++) {
    int nexti = (i + 1) % 3;
    input[i] = abs(in[nexti] - in[i]);
  }
}
struct punt {
  double x, y;
};
punt point2punt(complex<double> p) {
  punt pp;
  pp.x = real(p);
  pp.y = imag(p);
  return pp;
}
complex<double> punt2point(punt p) { return complex<double>(p.x, p.y); }
double error = 1e-7;
bool menor(double x, double y) { return x < y - error; }
bool menorigual(double x, double y) { return x < y + error; }
bool igual(double x, double y) { return x > y - error and x < y + error; }
bool operator<(punt p1, punt p2) {
  return menor(p1.x, p2.x) or (igual(p1.x, p2.x) and menor(p1.y, p2.y));
}
double t[4][3];
int sol = 9;
void calculaciclo4() {
  int total = 3 * 3 * 3 * 3;
  double longitud[4];
  for (int c = 0; c < total; c++) {
    int cc = c;
    for (int i = 0; i < 4; i++) {
      int b = cc % 3;
      cc /= 3;
      longitud[i] = t[i][b];
    }
    if (menorigual(longitud[0], longitud[3]) and
        menorigual(longitud[1], longitud[3]) and
        menorigual(longitud[2], longitud[3]) and
        menorigual(longitud[3], longitud[0] + longitud[1] + longitud[2])) {
      sol = min(sol, 8);
      return;
    }
  }
}
complex<double> elige(double a, double b, double c, int indice) {
  if (indice == 0 or indice == 1) {
    double alfa = acos((a * a + b * b - c * c) / (2.0 * a * b));
    if (indice == 0) return complex<double>(b * cos(alfa), b * sin(alfa));
    return complex<double>(b * cos(alfa), -b * sin(alfa));
  }
  double alfa = acos((a * a + c * c - b * b) / (2.0 * a * c));
  if (indice == 2) return complex<double>(c * cos(alfa), c * sin(alfa));
  return complex<double>(c * cos(alfa), -c * sin(alfa));
}
void calculaciclo4con2() {
  int total = 3 * 3 * 3 * 3;
  double eleccion[4][3];
  double longitud[4];
  double longi[3];
  for (int c = 0; c < total; c++) {
    int cc = c;
    for (int i = 0; i < 4; i++) {
      int b = cc % 3;
      cc /= 3;
      if (b == 0) {
        eleccion[i][0] = t[i][0];
        eleccion[i][1] = t[i][1];
        eleccion[i][2] = t[i][2];
      } else if (b == 1) {
        eleccion[i][0] = t[i][1];
        eleccion[i][1] = t[i][0];
        eleccion[i][2] = t[i][2];
      } else {
        eleccion[i][0] = t[i][2];
        eleccion[i][1] = t[i][0];
        eleccion[i][2] = t[i][1];
      }
      longitud[i] = t[i][b];
    }
    if (not igual(longitud[0], longitud[1])) continue;
    for (int i0 = 0; i0 < 4; i0++) {
      complex<double> p0 =
          elige(eleccion[0][0], eleccion[0][1], eleccion[0][2], i0);
      for (int i1 = 0; i1 < 4; i1++) {
        complex<double> p1 =
            elige(eleccion[1][0], eleccion[1][1], eleccion[1][2], i1);
        longi[0] = abs(p1 - p0);
        longi[1] = longitud[2];
        longi[2] = longitud[3];
        sort(longi, longi + 3);
        if (menorigual(longi[0], longi[2]) and
            menorigual(longi[1], longi[2]) and
            menorigual(longi[2], longi[0] + longi[1])) {
          sol = min(sol, 7);
          return;
        }
      }
    }
  }
}
set<punt> vector2set(vector<punt> &v) {
  set<punt> s;
  for (int i = 0; i < int(v.size()); i++) s.insert(v[i]);
  return s;
}
complex<double> normaliza(complex<double> p) {
  if (igual(abs(p), 0.0)) return p;
  return p / abs(p);
}
void calculaciclo3() {
  int total = 3 * 3 * 3 * 3;
  double eleccion[4][3];
  double longitud[4];
  for (int c = 0; c < total; c++) {
    int cc = c;
    for (int i = 0; i < 4; i++) {
      int b = cc % 3;
      cc /= 3;
      if (b == 0) {
        eleccion[i][0] = t[i][0];
        eleccion[i][1] = t[i][1];
        eleccion[i][2] = t[i][2];
      } else if (b == 1) {
        eleccion[i][0] = t[i][1];
        eleccion[i][1] = t[i][0];
        eleccion[i][2] = t[i][2];
      } else {
        eleccion[i][0] = t[i][2];
        eleccion[i][1] = t[i][0];
        eleccion[i][2] = t[i][1];
      }
      longitud[i] = t[i][b];
    }
    if (menorigual(longitud[0], longitud[2]) and
        menorigual(longitud[1], longitud[2]) and
        menorigual(longitud[2], longitud[0] + longitud[1])) {
      vector<punt> v(6);
      complex<double> p0(0, 0);
      v[0] = point2punt(p0);
      complex<double> p1(eleccion[0][0], 0);
      v[1] = point2punt(p1);
      for (int i = 0; i < 2; i++) {
        complex<double> p2 = elige(longitud[0], longitud[2], longitud[1], i);
        v[2] = point2punt(p2);
        for (int i0 = 0; i0 < 4; i0++) {
          v[3] = point2punt(
              elige(eleccion[0][0], eleccion[0][1], eleccion[0][2], i0));
          for (int i1 = 0; i1 < 4; i1++) {
            v[4] = point2punt(p1 + ((p2 - p1) / abs(p2 - p1)) *
                                       elige(eleccion[1][0], eleccion[1][1],
                                             eleccion[1][2], i1));
            for (int i2 = 0; i2 < 4; i2++) {
              v[5] = point2punt(p2 + ((p0 - p2) / abs(p0 - p2)) *
                                         elige(eleccion[2][0], eleccion[2][1],
                                               eleccion[2][2], i2));
              set<punt> s = vector2set(v);
              sol = min(sol, int(s.size()) + 2);
              for (set<punt>::iterator it0 = s.begin(); it0 != s.end(); it0++) {
                complex<double> q0 = punt2point(*it0);
                set<punt>::iterator it1 = it0;
                it1++;
                for (; it1 != s.end(); it1++) {
                  complex<double> q1 = punt2point(*it1);
                  if (igual(abs(q1 - q0), eleccion[3][0])) {
                    sol = min(sol, int(s.size()) + 2);
                    set<punt>::iterator it2 = it1;
                    it2++;
                    for (; it2 != s.end(); it2++) {
                      complex<double> q2 = punt2point(*it2);
                      if ((igual(abs(q2 - q1), eleccion[3][1]) and
                           igual(abs(q0 - q2), eleccion[3][2])) or
                          (igual(abs(q2 - q1), eleccion[3][2]) and
                           igual(abs(q0 - q2), eleccion[3][1])))
                        sol = min(sol, int(s.size()));
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
void calculaciclo2y2() {
  int total = 3 * 3 * 3 * 3;
  double eleccion[4][3];
  double longitud[4];
  for (int c = 0; c < total; c++) {
    int cc = c;
    for (int i = 0; i < 4; i++) {
      int b = cc % 3;
      cc /= 3;
      if (b == 0) {
        eleccion[i][0] = t[i][0];
        eleccion[i][1] = t[i][1];
        eleccion[i][2] = t[i][2];
      } else if (b == 1) {
        eleccion[i][0] = t[i][1];
        eleccion[i][1] = t[i][0];
        eleccion[i][2] = t[i][2];
      } else {
        eleccion[i][0] = t[i][2];
        eleccion[i][1] = t[i][0];
        eleccion[i][2] = t[i][1];
      }
      longitud[i] = t[i][b];
    }
    if (igual(longitud[0], longitud[1]) and igual(longitud[2], longitud[3])) {
      int count0 = 4;
      if ((igual(eleccion[0][1], eleccion[1][1]) and
           igual(eleccion[0][2], eleccion[1][2])) or
          (igual(eleccion[0][2], eleccion[1][1]) and
           igual(eleccion[0][1], eleccion[1][2])))
        count0 = 3;
      int count2 = 4;
      if ((igual(eleccion[2][1], eleccion[3][1]) and
           igual(eleccion[2][2], eleccion[3][2])) or
          (igual(eleccion[2][2], eleccion[3][1]) and
           igual(eleccion[2][1], eleccion[3][2])))
        count2 = 3;
      sol = min(sol, count0 + count2 - 1);
    }
  }
}
void calculaciclo2() {
  int total = 3 * 3 * 3 * 3;
  double eleccion[4][3];
  double longitud[4];
  for (int c = 0; c < total; c++) {
    int cc = c;
    for (int i = 0; i < 4; i++) {
      int b = cc % 3;
      cc /= 3;
      if (b == 0) {
        eleccion[i][0] = t[i][0];
        eleccion[i][1] = t[i][1];
        eleccion[i][2] = t[i][2];
      } else if (b == 1) {
        eleccion[i][0] = t[i][1];
        eleccion[i][1] = t[i][0];
        eleccion[i][2] = t[i][2];
      } else {
        eleccion[i][0] = t[i][2];
        eleccion[i][1] = t[i][0];
        eleccion[i][2] = t[i][1];
      }
      longitud[i] = t[i][b];
    }
    if (igual(longitud[0], longitud[1])) {
      if (igual(longitud[1], longitud[2])) {
        sol = min(sol, 7);
        if (igual(longitud[2], longitud[3])) sol = min(sol, 6);
      }
      int count0 = 4;
      if ((igual(eleccion[0][1], eleccion[1][1]) and
           igual(eleccion[0][2], eleccion[1][2])) or
          (igual(eleccion[0][2], eleccion[1][1]) and
           igual(eleccion[0][1], eleccion[1][2])))
        count0 = 3;
      sol = min(sol, count0 + 4);
    }
  }
}
double input[4][3];
int indice[4];
int main() {
  for (int i = 0; i < 4; i++) {
    leer(input[i]);
    indice[i] = i;
  }
  do {
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 3; j++) t[i][j] = input[indice[i]][j];
    calculaciclo4();
    calculaciclo4con2();
    calculaciclo3();
    calculaciclo2y2();
    calculaciclo2();
  } while (next_permutation(indice, indice + 4));
  cout << sol << endl;
}
