typedef long long ll;

vector<vector<ll>> floydWarshall(vector<vector<pair<ll, ll>>> graph, int n)
{
  vector<vector<ll>> dis(n + 1, vl(n + 1, INF));
  forn(i, n) dis[i][i] = 0;

  forn(u, n)
  {
    for (auto to : graph[u])
    {
      ll v = to.f, w = to.s;
      dis[u][v] = min(dis[u][v], w);
      dis[v][u] = min(dis[v][u], w);
    }
  }

  forn(k, n)
  {
    forn(u, n)
    {
      forn(v, n) dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
    }
  }

  return dis;
}