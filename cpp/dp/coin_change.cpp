void solve() {
  ll n_coins, total;
  cin >> n_coins >> total;
  vl dp(total + 1, INT32_MAX - 1);
  vl coins(n_coins);
  forn(i, n_coins) cin >> coins[i];

  dp[0] = 0;
  for(i, n_coins) {
    each(coin, coins) {
      if (coin + i > x) continue;
      dp[coin + i] = min(dp[coin + i], dp[i] + 1);
    }
  }

  if (dp[total] + 1 == INT32_MAX) cout << "-1\n";
  else cout << dp[total] << '\n';
}