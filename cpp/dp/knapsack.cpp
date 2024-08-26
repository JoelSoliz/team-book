ll knapsack(ll W, vi weights, vi profits, int n) {
  vector<vi> dp(n + 1, vi(W + 1));
  forn(i, n + 1) {
    forn(w, W + 1) {
      if (i == 0 || w == 0) dp[i][w] = 0;
      else if (weights[i - 1] <= w)
        dp[i][w] = max(
          profit[i - 1] + dp[i - 1][w - weights[i - 1]],
          dp[i - 1][w]);
      else
        dp[i][w] = dp[i - 1][w];
    }
  }

  return dp[n][W];
}