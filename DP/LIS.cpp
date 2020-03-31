//LIS IN O(nlogn)
//LIS IN O(n^2) can be done by finding LCS of (sorted vector a) and (vector a)

vector<lli> lis(vector<lli> &a)
{
	int n = int(a.si);
	vector<lli> parent(n);
	vector<lli> incsub(n + 1);
	int length = 0;

	forz(i, n)
	{
		int l = 1, r = length;
		while (l <= r)
		{
			lli mid = l + (r - l) / 2;
			if (a[incsub[mid]] < a[i])
				l = mid + 1;
			else
				r = mid - 1;
		}

		int pos = l;
		parent[i] = incsub[pos - 1];
		incsub[pos] = i;

		if (pos > length)
			length = pos;
	}
	
	vector<lli> v(length);
	int k = incsub[length];

	for (int j = length - 1; j >= 0; j--)
	{
		v[j] = a[k];
		k = parent[k];
	}

	return v;
}
