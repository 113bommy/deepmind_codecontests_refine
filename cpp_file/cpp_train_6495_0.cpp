#include <bits/stdc++.h>
using namespace std;
template <class T>
T inline Abs(const T& x) {
  return x < 0 ? -x : x;
}
template <class T>
T inline Sqr(const T& x) {
  return x * x;
}
template <class TFlow = int, class TWeight = int>
struct TMaxFlowMinCostCalcer {
  struct TEdge {
    int From;
    int To;
    TFlow Capacity;
    TFlow Flow;
    TWeight Weight;
    int Back;
    TEdge(int from, int to, TFlow capacity, TFlow flow, TWeight weight,
          int back)
        : From(from),
          To(to),
          Capacity(capacity),
          Flow(flow),
          Weight(weight),
          Back(back) {}
  };
  vector<vector<TEdge> > Edges;
  bool HasNegative;
  TFlow TotalFlow;
  TWeight TotalWeight;
  void Initialize(int size, bool hasNegative = false) {
    Edges.assign(size, vector<TEdge>());
    HasNegative = hasNegative;
    TotalFlow = 0;
    TotalWeight = 0;
  }
  void AddEdge(int from, int to, TFlow capacity, TWeight weight) {
    TEdge forward(from, to, capacity, 0, weight, Edges[to].size());
    TEdge back(to, from, 0, 0, -weight, Edges[from].size());
    Edges[from].push_back(forward);
    Edges[to].push_back(back);
  }
  void CalcMaxFlow(int source, int sink) {
    const int N = Edges.size();
    vector<TWeight> phi(N, 0);
    if (HasNegative) {
      vector<bool> reachable(N, false);
      reachable[source] = true;
      for (int iter = 0; iter < N; ++iter) {
        for (int u = 0; u < N; ++u) {
          if (reachable[u]) {
            for (int i = 0; i < Edges[u].size(); ++i) {
              const TEdge& e = Edges[u][i];
              if (!reachable[e.To] || phi[e.To] > phi[u] + e.Weight) {
                reachable[e.To] = true;
                phi[e.To] = phi[u] + e.Weight;
              }
            }
          }
        }
      }
    }
    while (true) {
      vector<bool> reachable(N, false);
      reachable[source] = true;
      vector<TWeight> distance(N, 0);
      vector<TEdge*> previous(N);
      vector<bool> isProcessed(N, false);
      for (int iter = 0; iter < N; ++iter) {
        int nearest = -1;
        for (int i = 0; i < N; ++i) {
          if (!isProcessed[i] && reachable[i] &&
              (nearest == -1 || distance[i] < distance[nearest])) {
            nearest = i;
          }
        }
        if (nearest < 0) {
          break;
        }
        isProcessed[nearest] = true;
        for (int i = 0; i < Edges[nearest].size(); ++i) {
          const TEdge& e = Edges[nearest][i];
          const TWeight newDistance =
              distance[nearest] + e.Weight + phi[nearest] - phi[e.To];
          if (e.Flow < e.Capacity &&
              (!reachable[e.To] || distance[e.To] > newDistance)) {
            reachable[e.To] = true;
            distance[e.To] = newDistance;
            previous[e.To] = &Edges[nearest][i];
          }
        }
      }
      if (!reachable[sink]) {
        break;
      }
      TFlow flowGain = previous[sink]->Capacity - previous[sink]->Flow;
      for (int v = previous[sink]->From; v != source; v = previous[v]->From) {
        flowGain = min(flowGain, previous[v]->Capacity - previous[v]->Flow);
      }
      TWeight weightGain = 0;
      for (int v = sink; v != source; v = previous[v]->From) {
        TEdge& forward = *previous[v];
        TEdge& back = Edges[forward.To][forward.Back];
        forward.Flow += flowGain;
        back.Flow -= flowGain;
        weightGain += flowGain * forward.Weight;
      }
      TotalFlow += flowGain;
      TotalWeight += weightGain;
    }
  }
};
const int dx[4] = {-1, +1, 0, 0};
const int dy[4] = {0, 0, -1, +1};
const int maxn = 81;
int a[maxn][maxn];
int main(int argc, char* argv[]) {
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> a[i][j];
    }
  }
  TMaxFlowMinCostCalcer<int, int> flowCalcer;
  flowCalcer.Initialize(h * w + 2);
  int s = h * w;
  int t = h * w + 1;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if ((i + j) % 2 == 0) {
        flowCalcer.AddEdge(s, i * w + j, 1, 0);
        for (int q = 0; q < 4; ++q) {
          int ni = i + dy[q];
          int nj = j + dx[q];
          if (ni >= 0 && ni < h && nj >= 0 && nj < w) {
            flowCalcer.AddEdge(i * w + j, ni * w + nj, 1, a[i][j] != a[ni][nj]);
          }
        }
      } else {
        flowCalcer.AddEdge(i * w + j, t, 1, 0);
      }
    }
  }
  flowCalcer.CalcMaxFlow(s, t);
  cout << flowCalcer.TotalWeight << endl;
  return 0;
}
