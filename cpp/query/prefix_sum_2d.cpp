void solve() {
  ll n, q;
  cin >> n >> q;
  vector<string> s(n); // 0-index

  vector<vl> prefix(n + 1, vl(n + 1)); // 1-index
  forn(i, n) {
    forn(j, n) {
      ll value = s[i][j] == '*';
      prefix[i + 1][j + 1] = (value
                              + prefix[i][j + 1]
                              + prefix[i + 1][j]
                              - prefix[i][j]);
    }
  }

  while (q--) {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;

    ll sum = (prefix[x2 + 1][y2 + 1]
              - prefix[x1][y2 + 1]
              - prefix[x2 + 1][y1]
              + prefix[x1][y1]); // 0-index query
    cout << sum << '\n';
  }
}
