int lcs(string &s1, string &s2) {
  int m = sz(s1), n = sz(s2);

  vector<vi> dp(m + 1, vi(n + 1, 0));
  forx(i, 1, m + 1) {
    forx(j, 1, n + 1) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      if (s1[i - 1] == s2[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
    }
  }

  return dp[m][n];
}