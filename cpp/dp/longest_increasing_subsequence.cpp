int lis(vi &original) {
  vi aux;
  forn(i, sz(original)) {
    auto it = lower_bound(all(aux), original[i]);
    if (it == aux.end()) aux.pb(original[i]);
    else *it = original[i];
  }

  return sz(aux);
}