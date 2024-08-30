// Example answer aabb#aaxnaabba -> 01000210041001
vi alz(const string &s) // pattern#where_to_look
{
	int n = s.size();
	vi z(n, 0);
	for(int i = 1, l = 0, r = 0; i < n; i++)
	{
		if(i <= r)
			z[i] = min(z[i - l], r - i + 1);
		while(i + z[i] < n && s[z[i]] == s[i + z[i]])
			z[i]++;
		if(r < i + z[i] - 1)
			l = i, r = i + z[i] - 1;
	}
	return z;
}
