vi kmp_builder(string &s, int n) {
  vi dp(n, 0);
  int j = 0;
  forx(i, 1, n) {
    while (j && s[i] != s[j]) j = dp[j - 1];
    
    if (s[i] == s[j]) dp[i] = ++j;
    else dp[i] = 0;
  }

  return dp;
}

// Return all occurrences of the pattern in the text 
vi kmp(string &t, string &p) {
  string q = p + "#" + t;
  vi v = kmp_builder(q, sz(q));
  vi res;
  forn(i, sz(q)) if (v[i] == sz(p)) res.pb(i - 2 * sz(p) + 1);

  return res;
}