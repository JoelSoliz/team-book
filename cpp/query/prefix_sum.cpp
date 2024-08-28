void solve() {
  ll n, q, x, y;
  cin >> n >> q;

  vl nums(n), prefix(n + 1);
  forn(i, n) cin >> nums[i], prefix[i + 1] = prefix[i] + nums[i];

  forn(i, q) {
    cin >> x >> y;
    cout << prefix[y] - prefix[x - 1] << '\n';
  }
}