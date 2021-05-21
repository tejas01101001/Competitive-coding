const int N = 1e3 + 5;
int fentree[N][N];
int n, m, q;

void add(int x, int y, int val)
{
	int y1;
	while (x <= m)
	{
		y1 = y;
		while (y1 <= n)
		{
			fentree[x][y1] += val;
			y1 += (y1 & -y1);
		}
		x += (x & -x);
	}
}

int query(int x, int y)
{
	if (x == 0 || y == 0)
		return 0;

	int s = 0;
	int y1;
	while (x >= 1)
	{
		y1 = y;
		while (y1 >= 1)
		{
			s += fentree[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return s;
}