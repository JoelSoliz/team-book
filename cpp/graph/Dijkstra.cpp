typedef long long ll;

const long long INF = 4e18;

vector<ll> dijkstra(vector<vector<pair<ll, ll>>> graph, int n, int initial_node)
{
  vector<ll> dis(n + 1, INF);
  dis[initial_node] = 0;

  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  pq.push({0, initial_node});
  while (!pq.empty())
  {
    pll minor = pq.top();
    pq.pop();
    ll actual_cost = minor.f;
    int node = minor.s;
    if (dis[node] < actual_cost)
      continue;

    for (auto to : graph[node])
    {
      int neighbor = to.f;
      ll cost = to.s;
      if (dis[node] + cost < dis[neighbor])
      {
        dis[neighbor] = dis[node] + cost;
        pq.push({dis[neighbor], neighbor});
      }
    }
  }

  return dis;
}