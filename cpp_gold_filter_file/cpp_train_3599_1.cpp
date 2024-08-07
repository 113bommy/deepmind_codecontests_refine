#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXH = 1000;
const int MAXW = 1000;
const int MAXB = 10;
const int MAXSEG = 2 + 9 * MAXB;
const int MAXC = 2 * MAXH * MAXW + 2;
const int MAXFREQ = 5;
const int MAXP = MAXFREQ * MAXH * MAXW;
const int DX[] = {-1, 0, +1, 0}, DY[] = {0, +1, 0, -1};
int h, w, nq;
char g[MAXH][MAXW + 1];
int ncyc;
int clen[MAXC];
int coff[MAXC + 1];
int np;
int px[MAXP], py[MAXP], pd[MAXP];
int pcyc[MAXH][MAXW][MAXFREQ], pcycidx[MAXH][MAXW][MAXFREQ],
    pcyccnt[MAXH][MAXW];
int topcyc, botcyc;
int xycyc[MAXH][MAXW];
int xydcyc[MAXH][MAXW][4], xydcycidx[MAXH][MAXW][4];
set<long long> common;
int normidx(int c, int idx) {
  while (idx < 0) idx += clen[c];
  while (idx >= clen[c]) idx -= clen[c];
  return idx;
}
int getcycx(int c, int idx) { return px[coff[c] + idx]; }
int getcycy(int c, int idx) { return py[coff[c] + idx]; }
int getcycd(int c, int idx) { return pd[coff[c] + idx]; }
int createcyc(int sx, int sy, int sd) {
  int x = sx, y = sy, d = sd, c = ncyc++;
  clen[c] = 0;
  while (true) {
    int p = np++;
    ++clen[c];
    int nx, ny;
    if (sx == 0 && sy == 0 && sd == 0 && x == h - 1 && y == w - 1 && d == 1)
      d = 4;
    if (sx == h - 1 && sy == w - 1 && sd == 2 && x == 0 && y == 0 && d == 3)
      d = 4;
    while (d != 4) {
      nx = x + DX[d], ny = y + DY[d];
      if (0 <= nx && nx < h && 0 <= ny && ny < w && g[nx][ny] == '.') break;
      assert(xydcyc[x][y][d] == -1);
      xydcyc[x][y][d] = c;
      xydcycidx[x][y][d] = p - coff[c];
      d = (d + 1) % 4;
    }
    px[p] = x, py[p] = y, pd[p] = d;
    if (d == 4 || nx == sx && ny == sy) break;
    x = nx, y = ny, d = (d + 3) % 4;
  }
  coff[ncyc] = coff[c] + clen[c];
  return c;
}
void precalc() {
  ncyc = 0, np = 0;
  coff[0] = 0;
  memset(xydcyc, -1, sizeof(xydcyc));
  memset(xydcycidx, -1, sizeof(xydcycidx));
  memset(xycyc, -1, sizeof(xycyc));
  topcyc = createcyc(0, 0, 0);
  botcyc = createcyc(h - 1, w - 1, 2);
  static int qx[MAXH * MAXW], qy[MAXH * MAXW], qhead, qtail;
  static bool reach[MAXH][MAXW];
  qhead = qtail = 0;
  memset(reach, false, sizeof(reach));
  qx[qhead] = 0, qy[qhead] = 0, ++qhead, reach[0][0] = true;
  while (qtail < qhead) {
    int x = qx[qtail], y = qy[qtail];
    ++qtail;
    for (int k = (0); k < (4); ++k) {
      int nx = x + DX[k], ny = y + DY[k];
      if (0 <= nx && nx < h && 0 <= ny && ny < w && g[nx][ny] == '.' &&
          !reach[nx][ny])
        qx[qhead] = nx, qy[qhead] = ny, ++qhead, reach[nx][ny] = true;
    }
  }
  for (int x = (0); x < (h); ++x)
    for (int y = (0); y < (w); ++y)
      if (reach[x][y])
        for (int k = (0); k < (4); ++k) {
          int nx = x + DX[k], ny = y + DY[k];
          if (0 <= nx && nx < h && 0 <= ny && ny < w && g[nx][ny] != '.' &&
              xydcyc[x][y][k] == -1)
            createcyc(x, y, k);
        }
  for (int x = (0); x < (h); ++x)
    for (int y = (0); y < (w); ++y)
      if (g[x][y] == '.') {
        int c = xycyc[x][y] = ncyc++;
        int p = np++;
        px[p] = x, py[p] = y, pd[p] = 4;
        clen[c] = 1;
        coff[ncyc] = coff[c] + clen[c];
      }
  memset(pcyccnt, 0, sizeof(pcyccnt));
  for (int c = (0); c < (ncyc); ++c)
    for (int j = (coff[c]); j < (coff[c + 1]); ++j) {
      int x = px[j], y = py[j], d = pd[j];
      int i = pcyccnt[x][y]++;
      pcyc[x][y][i] = c;
      pcycidx[x][y][i] = j - coff[c];
    }
  common.clear();
  for (int x = (0); x < (h); ++x)
    for (int y = (0); y < (w); ++y)
      for (int i = (0); i < (pcyccnt[x][y]); ++i)
        for (int j = (0); j < (pcyccnt[x][y]); ++j)
          if (pcyc[x][y][i] < pcyc[x][y][j])
            common.insert((long long)ncyc * pcyc[x][y][i] + pcyc[x][y][j]);
  common.erase((long long)ncyc * topcyc + botcyc);
  common.erase((long long)ncyc * botcyc + topcyc);
}
typedef struct Seg {
  int cyc, l, r, len, nd, prv, nxt;
} Seg;
int nb;
int bx[MAXB], by[MAXB];
int bcnt[MAXB], bat[MAXB], bseg[MAXB], bpos[MAXB];
int q[4 * MAXB], qhead, qtail;
int shead[2];
Seg seg[MAXSEG];
int scnt;
void printpath(int s) {
  while (seg[s].prv != -1) s = seg[s].prv;
  for (; s != -1; s = seg[s].nxt) {
    printf("\t\t[%d,%d]", getcycx(seg[s].cyc, seg[s].l),
           getcycy(seg[s].cyc, seg[s].l));
    if (seg[s].l != seg[s].r)
      printf("-[%d,%d]", getcycx(seg[s].cyc, seg[s].r),
             getcycy(seg[s].cyc, seg[s].r));
    printf("<%d-%d-%d>(%d)\n", seg[s].prv, s, seg[s].nxt, seg[s].len);
  }
}
int createseg(int cyc, int l, int r, int len, int nd) {
  seg[scnt].cyc = cyc, seg[scnt].l = l, seg[scnt].r = r, seg[scnt].len = len,
  seg[scnt].nd = nd, seg[scnt].prv = seg[scnt].nxt = -1;
  return scnt++;
}
bool xyoncyc(int x, int y, int i, int c) { return pcyc[x][y][i] == c; }
int getxycycpos(int x, int y, int i, int c) { return pcycidx[x][y][i]; }
bool xyonseg(int x, int y, int i, int s) {
  if (pcyc[x][y][i] == seg[s].cyc) {
    int idx = pcycidx[x][y][i];
    if (seg[s].l <= seg[s].r && seg[s].l <= idx && idx <= seg[s].r) return true;
    if (seg[s].l > seg[s].r && (idx <= seg[s].r || idx >= seg[s].l))
      return true;
  }
  return false;
}
int getxysegpos(int x, int y, int i, int s) {
  if (pcyc[x][y][i] == seg[s].cyc) {
    int idx = pcycidx[x][y][i];
    if (seg[s].l <= seg[s].r && seg[s].l <= idx && idx <= seg[s].r)
      return idx - seg[s].l;
    if (seg[s].l > seg[s].r && (idx <= seg[s].r || idx >= seg[s].l))
      return idx - seg[s].l + (idx <= seg[s].r ? clen[seg[s].cyc] : 0);
  }
  assert(false);
  return -1;
}
bool bonseg(int b, int i, int s) { return xyonseg(bx[b], by[b], i, s); }
bool banyonseg(int b, int s) {
  for (int j = (0); j < (pcyccnt[bx[b]][by[b]]); ++j)
    if (bonseg(b, j, s)) return true;
  return false;
}
int getbsegpos(int b, int i, int s) { return getxysegpos(bx[b], by[b], i, s); }
int getonlybsegpos(int b, int s) {
  int ret = -1;
  for (int j = (0); j < (pcyccnt[bx[b]][by[b]]); ++j)
    if (bonseg(b, j, s)) {
      assert(ret == -1);
      ret = getbsegpos(b, j, s);
    }
  assert(ret != -1);
  return ret;
}
int findnxtcycpos(int c, int idx, int x, int y) {
  int ret = -1;
  for (int j = (0); j < (pcyccnt[x][y]); ++j)
    if (xyoncyc(x, y, j, c)) {
      int cur = getxycycpos(x, y, j, c);
      if (ret == -1 || (ret >= idx && cur >= idx && cur < ret ||
                        ret < idx && (cur >= idx || cur < ret)))
        ret = cur;
    }
  assert(ret != -1);
  return ret;
}
void getsegxyd(int s, int pos, int &x, int &y, int &d) {
  int idx = normidx(seg[s].cyc, seg[s].l + pos);
  x = getcycx(seg[s].cyc, idx), y = getcycy(seg[s].cyc, idx),
  d = pos == seg[s].len - 1 ? seg[s].nd : getcycd(seg[s].cyc, idx);
}
void ssplit(int s, int pos, int &pseg, int &nseg) {
  while (pos <= 0) {
    assert(seg[s].prv != -1);
    s = seg[s].prv;
    pos += seg[s].len;
  }
  while (pos > seg[s].len) {
    assert(seg[s].nxt != -1);
    pos -= seg[s].len;
    s = seg[s].nxt;
  }
  if (pos == seg[s].len) {
    assert(seg[s].nxt != -1);
    pseg = s, nseg = seg[s].nxt;
    seg[pseg].nxt = seg[nseg].prv = -1;
    return;
  }
  int nr = normidx(seg[s].cyc, seg[s].l + pos - 1),
      nl = normidx(seg[s].cyc, seg[s].l + pos);
  nseg = createseg(seg[s].cyc, nl, seg[s].r, seg[s].len - pos, seg[s].nd);
  seg[nseg].nxt = seg[s].nxt;
  if (seg[nseg].nxt != -1) seg[seg[nseg].nxt].prv = nseg;
  pseg = s, seg[pseg].r = nr, seg[pseg].len = pos,
  seg[pseg].nd = getcycd(seg[s].cyc, nr);
  seg[pseg].nxt = -1, seg[nseg].prv = -1;
  for (int i = (0); i < (nb); ++i)
    if (bcnt[i] == 1 && bseg[i] == pseg && bpos[i] >= pos)
      bseg[i] = nseg, bpos[i] -= pos;
}
void smerge(int pseg, int d, int nseg) {
  seg[pseg].nxt = nseg;
  seg[pseg].nd = d;
  seg[nseg].prv = pseg;
}
void sadd(int at, int nseg) {
  for (int i = (0); i < (nb); ++i)
    for (int j = (0); j < (pcyccnt[bx[i]][by[i]]); ++j)
      if (bonseg(i, j, nseg)) {
        int pos = getbsegpos(i, j, nseg);
        ++bcnt[i], bat[i] = at, bseg[i] = nseg, bpos[i] = pos, q[qhead++] = i;
        assert(bcnt[i] == 1);
      }
}
void sremove(int s) {
  while (seg[s].prv != -1) s = seg[s].prv;
  while (s != -1) {
    for (int i = (0); i < (nb); ++i)
      for (int j = (0); j < (pcyccnt[bx[i]][by[i]]); ++j)
        if (bonseg(i, j, s)) {
          --bcnt[i];
          assert(bcnt[i] == 0);
        }
    s = seg[s].nxt;
  }
}
bool intersectspath(int s, int at) {
  for (int ss = shead[at]; ss != -1; ss = seg[ss].nxt) {
    int a = seg[s].cyc, b = seg[ss].cyc;
    if (a > b) swap(a, b);
    if (a == b || common.count((long long)a * ncyc + b)) return true;
  }
  return false;
}
void fixprefix(int &lst, int &d, int &s) {
  for (int i = (0); i < (nb); ++i)
    if (bcnt[i] > 0)
      for (int j = (0); j < (pcyccnt[bx[i]][by[i]]); ++j)
        if (bonseg(i, j, s)) {
          int ss = lst;
          while (ss != -1 && !banyonseg(i, ss)) ss = seg[ss].prv;
          if (ss == -1) continue;
          int spos = getbsegpos(i, j, s), sspos = getonlybsegpos(i, ss);
          int ss1, ss2;
          ssplit(ss, sspos, ss1, ss2);
          lst = ss1;
          d = seg[ss1].nd;
          sremove(ss2);
          if (spos != 0) {
            int s1, s2;
            ssplit(s, spos, s1, s2);
            s = s2;
          }
        }
}
bool fixsuffix(int &s, int &d, int &fst) {
  bool ret = false;
  for (int i = (0); i < (nb); ++i)
    if (bcnt[i] > 0)
      for (int j = (0); j < (pcyccnt[bx[i]][by[i]]); ++j)
        if (bonseg(i, j, s)) {
          int ss = fst;
          while (ss != -1 && !banyonseg(i, ss)) ss = seg[ss].nxt;
          if (ss == -1) continue;
          int spos = getbsegpos(i, j, s), sspos = getonlybsegpos(i, ss);
          int ss1, ss2;
          ssplit(ss, sspos + 1, ss1, ss2);
          fst = ss2;
          d = seg[ss1].nd;
          sremove(ss1);
          if (spos != seg[s].len - 1) {
            int s1, s2;
            ssplit(s, spos + 1, s1, s2);
            s = s1;
          }
          ret = true;
        }
  if (ret) return ret;
  int vx = getcycx(seg[s].cyc, seg[s].r), vy = getcycy(seg[s].cyc, seg[s].r),
      wx = getcycx(seg[fst].cyc, seg[fst].l),
      wy = getcycy(seg[fst].cyc, seg[fst].l);
  if (vx == wx && vy == wy) {
    int ss = fst, ss1, ss2;
    ssplit(ss, 1, ss1, ss2);
    fst = ss2;
    d = seg[ss1].nd;
    sremove(ss1);
    ret = true;
  }
  return ret;
}
void fixinternal(int &s) {
  int mn[MAXB], mx[MAXB];
  for (int i = (0); i < (nb); ++i) mn[i] = mx[i] = -1;
  for (int i = (0); i < (nb); ++i)
    for (int j = (0); j < (pcyccnt[bx[i]][by[i]]); ++j)
      if (bonseg(i, j, s)) {
        int cur = getbsegpos(i, j, s);
        if (mn[i] == -1 || cur < mn[i]) mn[i] = cur;
        if (mx[i] == -1 || cur > mx[i]) mx[i] = cur;
      }
  while (true) {
    int bidx = -1;
    for (int i = (0); i < (nb); ++i)
      if (mn[i] != -1 && mx[i] != -1 && mn[i] != mx[i] &&
          (bidx == -1 || mx[i] > mx[bidx]))
        bidx = i;
    if (bidx == -1) return;
    for (int i = (0); i < (nb); ++i)
      if (mn[i] != -1 && mx[i] != -1 && mn[i] != mx[i])
        assert(mn[bidx] <= mn[i] && mx[i] <= mx[bidx] || mx[i] < mn[bidx]);
    if (mn[bidx] == 0) {
      int s3, s4;
      ssplit(s, mx[bidx] - mn[bidx], s3, s4);
      s = s4;
    } else {
      int s1, s2;
      ssplit(s, mn[bidx], s1, s2);
      int s3, s4;
      ssplit(s2, mx[bidx] - mn[bidx], s3, s4);
      smerge(s1, seg[s1].nd, s4);
      s = s1;
    }
    for (int i = (0); i < (nb); ++i)
      if (i != bidx && mn[i] != -1 && mx[i] != -1 && mn[i] != mx[i] &&
          mx[i] >= mn[bidx])
        mn[i] = mx[i] = -1;
    mn[bidx] = mx[bidx] = -1;
  }
}
bool solve() {
  qhead = qtail = scnt = 0;
  memset(bcnt, 0, sizeof(bcnt));
  int topinit = createseg(topcyc, 0, clen[topcyc] - 1, clen[topcyc], 4);
  fixinternal(topinit);
  for (int s = topinit; s != -1; s = seg[s].nxt) sadd(0, s);
  shead[0] = topinit;
  int botinit = createseg(botcyc, 0, clen[botcyc] - 1, clen[botcyc], 4);
  fixinternal(botinit);
  for (int s = botinit; s != -1; s = seg[s].nxt) sadd(1, s);
  shead[1] = botinit;
  while (qtail < qhead) {
    int bidx = q[qtail++], at = bat[bidx];
    if (bcnt[bidx] != 1) continue;
    int sseg, pseg, qseg, tseg;
    ssplit(bseg[bidx], bpos[bidx], sseg, pseg);
    ssplit(pseg, 1, qseg, tseg);
    sremove(qseg);
    int sx, sy, sd;
    getsegxyd(sseg, seg[sseg].len - 1, sx, sy, sd);
    int tx, ty, td;
    getsegxyd(tseg, 0, tx, ty, td);
    int cseg = sseg, cx = sx, cy = sy, cd = sd;
    if (sx == tx && sy == ty) {
      int s1, s2;
      ssplit(tseg, 1, s1, s2);
      sremove(s1);
      smerge(sseg, seg[s1].nd, s2);
    } else
      while (true) {
        if (cx + DX[cd] == bx[bidx] && cy + DY[cd] == by[bidx])
          cd = (cd + 1) % 4;
        int vx = cx + DX[cd], vy = cy + DY[cd];
        assert(vx >= 0 && vx < h && vy >= 0 && vy < w);
        int wx, wy, wd, nseg;
        if (g[vx][vy] == '.') {
          wx = vx, wy = vy, wd = (cd + 3) % 4;
          nseg = createseg(xycyc[vx][vy], 0, 0, 1, wd);
        } else {
          int c = xydcyc[cx][cy][cd], idx = xydcycidx[cx][cy][cd];
          assert(c != -1 && idx != -1 && getcycx(c, idx) == cx &&
                 getcycy(c, idx) == cy);
          cd = getcycd(c, idx);
          int sidx = normidx(c, idx + 1);
          int tidx = findnxtcycpos(c, sidx, bx[bidx], by[bidx]);
          tidx = normidx(c, tidx - 1);
          vx = getcycx(c, sidx), vy = getcycy(c, sidx), wx = getcycx(c, tidx),
          wy = getcycy(c, tidx), wd = getcycd(c, tidx);
          int len = tidx - sidx + 1;
          if (len <= 0) len += clen[c];
          nseg = createseg(c, sidx, tidx, len, wd);
        }
        if (intersectspath(nseg, 1 - at)) return false;
        fixprefix(cseg, cd, nseg);
        bool done = fixsuffix(nseg, wd, tseg);
        fixinternal(nseg);
        for (int s = nseg; s != -1; s = seg[s].nxt) sadd(at, s);
        smerge(cseg, cd, nseg);
        while (seg[nseg].nxt != -1) nseg = seg[nseg].nxt;
        if (done) {
          smerge(nseg, wd, tseg);
          break;
        }
        cseg = nseg, cx = wx, cy = wy, cd = wd;
      }
  }
  return true;
}
void run() {
  scanf("%d%d%d", &h, &w, &nq);
  for (int x = (0); x < (h); ++x) scanf("%s", g[x]);
  precalc();
  for (int i = (0); i < (nq); ++i) {
    scanf("%d", &nb);
    for (int j = (0); j < (nb); ++j)
      scanf("%d%d", &bx[j], &by[j]), --bx[j], --by[j];
    bool have = solve();
    printf("%s\n", have ? "YES" : "NO");
    fflush(stdout);
  }
}
int main() {
  run();
  return 0;
}
