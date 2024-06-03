typedef long long ll;

ll kruskal(vector<pair<ll, pair<int, int>>> edges, int n)
{
  sort(all(edges));
  UnionFind dsu(n + 1);
  int countEdges = 0;
  ll res = 0;
  for (auto edge : edges)
  {
    ll weight = edge.f;
    int u = edge.s.f;
    int v = edge.s.s;
    if (dsu.join(u, v))
    {
      countEdges++;
      res += weight;
    }

    if (countEdges == n - 1)
      return res;
  }

  if (countEdges < n - 1)
    return -1;

  return res;
}