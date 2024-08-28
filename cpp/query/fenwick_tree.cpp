struct BIT { // 1-index
  vl bit;
  ll n;

  BIT(int n) : bit(n+1), n(n) {}

  ll lsb(int i) { return i & -i; }

  void add(int i, ll x) {
    for (; i <= n; i += lsb(i)) bit[i] += x;
  }

  ll sum(int r) {
    ll res = 0;
    for (; r > 0; r -= lsb(r)) res += bit[r];
    return res;
  }

  ll sum(int l, int r) {
    return sum(r) - sum(l-1);
  }

  void set(int i, ll x) {
    add(i, x - sum(i, i));
  }
};
