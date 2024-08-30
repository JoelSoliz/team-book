const int K = 2;
struct Hash {
  const ll MOD[K] = {999727999, 1070777777};
  const ll P = 1777771;
  vector<ll> h[K], p[K];
  Hash(string &s) {
    int n = s.size();
    for(int k = 0; k < K; k++) {
      h[k].resize(n + 1, 0);
      p[k].resize(n + 1, 1);
      for(int i = 1; i <= n; i++) {
        h[k][i] = (h[k][i - 1] * P + s[i - 1]) % MOD[k];
        p[k][i] = (p[k][i - 1] * P) % MOD[k];
      }
    }
  }
  vector<ll> get(int i, int j) { // hash [i, j]
    j++;
    vector<ll> r(K);
    for(int k = 0; k < K; k++) {
      r[k] = (h[k][j] - h[k][i] * p[k][j - i]) % MOD[k];
      r[k] = (r[k] + MOD[k]) % MOD[k];
    }
    return r;
  }
};

// Other
ll pow(ll b, ll e, ll m) {
  ll res = 1;
  for (; e; e >>= 1, b = (b * b) % m)
  if (e & 1) res = (res * b) % m;
  return res;
}

ll inv(ll b, ll e, ll m) {
  return pow(pow(b, e, m), m - 2, m);
}

vl rolling_hash(string &s, ll p, ll m) {
  ll n = sz(s);
  vl v(n, 0);
  v[0] = (s[0]) % m;
  for (ll i = 1; i < n; i++) 
    v[i] = (v[i - 1] + (s[i] * pow(p, i, m)) % m) % m;

  return v;
}

ll fast_hash(vl &v, ll p, ll m, ll i, ll j) {
  return (((v[j] - (i ? v[i - 1] : 0) + m) % m) * inv(p, i, m)) % m;
}

// Hash 128
#define bint __int128
struct Hash {
  bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
  vector<bint> h,pi;
  Hash(string& s){
    assert((P*PI)%MOD==1);
    h.resize(s.size()+1);pi.resize(s.size()+1);
    h[0]=0;pi[0]=1;
    bint p=1;
    forx(i,1,s.size()+1){
      h[i]=(h[i-1]+p*s[i-1])%MOD;
      pi[i]=(pi[i-1]*PI)%MOD;
      p=(p*P)%MOD;
    }
  }
  ll get(int s, int e){
    return (((h[e]-h[s]+MOD)%MOD)*pi[s])%MOD;
  }
};