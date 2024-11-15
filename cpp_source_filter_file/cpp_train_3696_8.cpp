#include <bits/stdc++.h>
using namespace std;
pair<int, int> operator+(pair<int, int> p1, pair<int, int> p2) {
  return pair<int, int>(p1.first + p2.first, p1.second + p2.second);
}
int localiza(vector<int> &v, int x) {
  if (int(v.size()) == 0 or x < v[0]) return -1;
  int inf = 0;
  int sup = int(v.size());
  while (inf + 1 < sup) {
    int med = (inf + sup) / 2;
    if (v[med] <= x)
      inf = med;
    else
      sup = med;
  }
  return inf;
}
int localizari(vector<int> &v, int x) {
  if (int(v.size()) == 0 or v.back() < x) return -1;
  int inf = -1;
  int sup = int(v.size()) - 1;
  while (inf + 1 < sup) {
    int med = (inf + sup) / 2;
    if (v[med] < x)
      inf = med;
    else
      sup = med;
  }
  return sup;
}
int s;
pair<int, int> calcula(vector<int> posicion[3],
                       vector<pair<int, int> > precalculo[3], int pos,
                       vector<pair<int, int> > &lista) {
  if (pos <= s) return pair<int, int>(0, 0);
  if (int(lista.size()) == 0) return pair<int, int>(-1, -1);
  if (lista.back().first + s < pos) return pair<int, int>(-1, -1);
  int p2 = localiza(posicion[2], pos - 1);
  int pos2 = 0;
  pair<int, int> pre2(0, 0);
  if (p2 != -1) {
    pos2 = posicion[2][p2];
    pre2 = precalculo[2][p2];
  }
  if (pos - s <= pos2) return pre2;
  int p1ri = localizari(posicion[1], pos - s);
  if (p1ri == -1 or pos <= posicion[1][p1ri]) {
    int p1 = localiza(posicion[1], pos - s);
    if (p1 == -1 or posicion[1][p1] <= pos2)
      return pair<int, int>(pos - s - pos2, 0) + pre2;
    return pair<int, int>(pos - s - posicion[1][p1], 0) + precalculo[1][p1];
  }
  int amount1 = pos - posicion[1][p1ri];
  if (pos - s - amount1 <= pos2)
    return pair<int, int>(0, pos - s - pos2) + pre2;
  int p1 = localiza(posicion[1], pos - s - 1);
  if (p1 == -1 or posicion[1][p1] <= pos2)
    return pair<int, int>(pos - s - amount1 - pos2, amount1) + pre2;
  if (pos - s - amount1 <= posicion[1][p1])
    return pair<int, int>(0, pos - s - posicion[1][p1]) + precalculo[1][p1];
  return pair<int, int>(pos - s - amount1 - posicion[1][p1], amount1) +
         precalculo[1][p1];
}
pair<int, int> precalcula(vector<int> posicion[3],
                          vector<pair<int, int> > precalculo[3], int pos,
                          vector<pair<int, int> > &lista, int tipoini) {
  if (tipoini == 2) return calcula(posicion, precalculo, pos, lista);
  int p1 = localiza(posicion[1], pos - 1);
  int p2 = localiza(posicion[2], pos - 1);
  if (p1 == -1 and p2 == -1) {
    if (tipoini == 0) return pair<int, int>(pos, 0);
    if (pos <= s) return pair<int, int>(0, pos);
    return pair<int, int>(pos - s, s);
  }
  pair<int, int> anterior(0, 0);
  int posanterior = 0;
  if (p1 != -1 and posanterior < posicion[1][p1]) {
    anterior = precalculo[1][p1];
    posanterior = posicion[1][p1];
  }
  if (p2 != -1 and posanterior < posicion[2][p2]) {
    anterior = precalculo[2][p2];
    posanterior = posicion[2][p2];
  }
  if (tipoini == 0) return pair<int, int>(pos - posanterior, 0) + anterior;
  if (pos - s <= posanterior)
    return pair<int, int>(0, pos - posanterior) + anterior;
  return pair<int, int>(pos - s - posanterior, s) + anterior;
}
void precalcula(vector<int> posicion[3], vector<pair<int, int> > precalculo[3],
                vector<pair<int, int> > &lista) {
  for (int i = 0; i < int(lista.size()); i++) {
    pair<int, int> &p = lista[i];
    precalculo[p.second].push_back(
        precalcula(posicion, precalculo, p.first, lista, p.second));
  }
}
vector<int> posicion[2][3];
vector<pair<int, int> > precalculo[2][3];
vector<pair<int, int> > lista[2];
int main() {
  ios::sync_with_stdio(false);
  int e, n, m;
  cin >> e >> s >> n >> m;
  for (int i = 0; i < n; i++) {
    int t, x;
    cin >> t >> x;
    if (e == x)
      ;
    else if (e < x)
      lista[0].push_back(pair<int, int>(x - e, t - 1));
    else
      lista[1].push_back(pair<int, int>(e - x, t - 1));
  }
  for (int k = 0; k < 2; k++) {
    vector<pair<int, int> > &v = lista[k];
    sort(v.begin(), v.end());
    vector<pair<int, int> > nextv;
    for (int i = 0; i < int(v.size()); i++) {
      if ((i == 0 and v[i].first <= s) or
          (i > 0 and v[i].first - v[i - 1].first <= s)) {
        posicion[k][v[i].second].push_back(v[i].first);
        nextv.push_back(v[i]);
      } else
        break;
    }
    v = nextv;
  }
  for (int k = 0; k < 2; k++) precalcula(posicion[k], precalculo[k], lista[k]);
  for (int k = 0; k < m; k++) {
    int f;
    cin >> f;
    pair<int, int> p;
    if (e == f)
      p = pair<int, int>(0, 0);
    else if (e < f)
      p = calcula(posicion[0], precalculo[0], f - e, lista[0]);
    else
      p = calcula(posicion[1], precalculo[1], e - f, lista[1]);
    cout << p.first << " " << p.second << endl;
  }
}
