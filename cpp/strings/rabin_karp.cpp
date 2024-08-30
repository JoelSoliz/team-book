const ll mod[2] = {1000000007, 998244353};
const ll px[2] = {29, 31};

vl rabin_karp(string &s, string &p) {
  vl ss[2], pp[2], ppx[2];
  for (ll i = 0; i < 2; i++)
    ss[i] = rolling_hash(s, px[i], mod[i]),
    pp[i] = rolling_hash(p, px[i], mod[i]);

  vi res;
  for (int i = 0; i + sz(p) - 1 < sz(s); i++) {
    ll ok = 1;
    for (ll j = 0; j < 2; j++) {
      int fh = fast_hash(ss[j], px[j], mod[j], i, i + sz(p) - 1) % mod[j];
      ok &= (fh == pp[j].back());
    }
    if (ok) res.pb(i + 1);
  }

  return res;
}