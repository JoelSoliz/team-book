vector<int> subsequence_sum(vector<int> nums, int total) {
  map<int, vector<int>> dp;
  dp[0] = {};

  for (int num : nums) {
    map<int, vector<int>> new_sums;
    for (const auto& [sum, sequence] : dp) {
      int new_sum = sum + num;
      if (new_sum == total) {
        vector<int> res = sequence;
        res.pb(num);
        return res;
      }

      if (dp.find(new_sum) == dp.end()) {
        new_sums[new_sum] = sequence;
        new_sums[new_sum].pb(num);
      }
    }

    dp.insert(all(new_sums));
  }

  return {};
}