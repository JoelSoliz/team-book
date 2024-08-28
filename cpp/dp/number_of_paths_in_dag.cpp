ll dp[10006];
ll mod = 1e9 + 7;

ll count_paths(vector<vl> &graph, ll source, ll dest) {
  if (source == dest) return 1;

  if (dp[source] != -1) return dp[source];

  ll current = 0;
  each(neigh, graph[source]) {
    ll x = count_paths(graph, neigh, dest);
    if (x != -1) c = (c % mod + x % mod) % mod;
  }

  return (dp[source] = (c == 0) ? -1 : c);
}

void solve() {
  memset(dp, -1, sizeof dp);
  ll paths = count_paths(graph, source, dest);
  if (paths == -1) paths = 0;
}