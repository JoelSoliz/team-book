int N;
int dp[1 << N][N + 1];
int F[1 << N];
int A[1 << N];

forn(mask, 1 << N) F[mask] = A[mask];
forn(i, N) {
  forn(mask, 1 << N) {
    if (mask & (1 << i)) F[mask] += F[mask ^ (1 << i)];
  }
}