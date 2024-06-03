struct UnionFind
{
  vector<int> p;
  UnionFind(int n) : p(n, -1) {}

  int find(int x)
  {
    if (p[x] == -1)
      return x;

    return p[x] = find(p[x]);
  }

  bool join(int x, int y)
  {
    x = find(x), y = find(y);
    if (x == y)
      return 0;

    p[y] = x;
    return 1;
  }
};