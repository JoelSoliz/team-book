int orientation(pt a, pt b, pt c) {
  lf v = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
  if (v < 0) return -1; // clockwise
  if (v > 0) return 1; // counter-clockwise
  return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
  int o = orientation(a, b, c);
  return o < 0 || (include_collinear && o == 0);
}

bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<pt>& a, bool include_collinear) {
  pt p0 = *min_element(all(a), [](pt a, pt b) {
    return make_pair(a.y, a.x) < make_pair(b.y, b.x);
  });
  sort(all(a), [&p0](const pt& a, const pt& b) {
    int o = orientation(p0, a, b);
    if (o == 0) 
      return (p0.x - a.x) * (p0.x - a.x) + (p0.y - a.y) * (p0.y - a.y) 
            < (p0.x - b.x) * (p0.x - b.x) + (p0.y - b.y) * (p0.y - b.y);

    return o < 0;
  });

  if (include_collinear) {
    int i = sz(a) - 1;
    while (i >= 0 && collinear(p0, a[i], a.back())) i--;
    reverse(a.begin() + i + 1, a.end());
  }

  vector<pt> st;
  for (int i = 0; i < sz(a); i++) {
    while (sz(st) > 1 && !cw(st[sz(st) - 2], st.back(), a[i], include_collinear))
      st.pop_back();

    st.push_back(a[i]);
  }

  a = st;
}

lf area(const vector<pt>& fig) {
  lf res = 0;
  for (unsigned i = 0; i < fig.size(); i++) {
    pt p = i ? fig[i - 1] : fig.back();
    pt q = fig[i];
    res += (p.x - q.x) * (p.y + q.y);
  }

  return fabs(res) / 2;
}

lf areaPolygon(const vector<pt>& fig) {
  lf area = 0;
  int n = fig.size();
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    area += fig[i].x * fig[i].y;
    area -= fig[j].x * fig[j].y;
  }

  return fabs(area) / 2;
}
