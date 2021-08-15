# Fenwick Tree

1. Even if the name of the structure is a binary indexed tree, 
it is usually represented as an array.

2. We assume that all arrays are (one-indexed),
to make implementation easier. 

3. Let p(k) denote the largest power of two that divides k .
We store a binary indexed tree as an array tree such that
fentree[k] = sum(k - p(k) + 1, k);

4. Using a binary indexed tree, any value of sum(1,k) 
can be calculated in O(log n) time, because a range [1,k] 
can always be divided into O(log n) ranges whose sums 
are stored in the tree.

5. sum(1, 7) = sum(1, 4) + sum(5, 6) + sum(7, 7) = fentree[4] + fentree[6] + fentree[7]
6. sum(a, b) = sum(1, b) - sum(1, a-1);
7. p(k) = k & -k;

8. The query function calculates the sum in (1, k)
9. The update function **increases** the array value at pos k by x. (x can be any integer)

```C++
const int N = 2e5 + 5;
ll fentree[N];

ll query(ll k)
{
    ll s = 0;
    while (k >= 1)
    {
        s += fentree[k];
        k -= k & -k;
    }
    return s;
}

void update(ll k, ll x)
{
    while (k <= n)
    {
        fentree[k] += x;
        k += k & -k;
    }
}
```

10. Time complexity of both the above functions is O(logn).

## Counting Inversions:

1. Use co-ordinate Compression to make the elements less than n 
   
```C++
for (int i = 0; i < n; i++)
{
    //add the no of elements less than i to the ans
    ans += query(a[i] - 1);
    update(a[i], 1);
}
```

## Find the kth element in the array:

1. Binary search the prefix sum in the BIT 

2. [Multiset Codeforces](https://codeforces.com/contest/1354/submission/80572075)

```C++
int l = 1, r = n, id = -1;
while (l <= r)
{
    int mid = l + (r - l) / 2;
    if (query(mid) >= qk)
    {
        id = mid;
        r = mid - 1;
    }
    else
        l = mid + 1;
}
```

## Range updates and point queries

1. Update **adds x** at position k
2. To set position k as x use update(k, x-a[k])

```C++
void update(ll k, ll x)
{
    while (k <= n)
    {
        fentree[k] += x;
        k += k & -k;
    }
}

void range_upd(ll l, ll r, ll x)
{
    update(l, x);
    update(r + 1, -x);
}

ll point_query(ll k)
{
    ll s = 0;
    while (k >= 1)
    {
        s += fentree[k];
        k -= k & -k;
    }
    return s;
}
```

## Point updates and Range queries

### [Kickstart Question](https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/0000000000337b4d)

1. Typically two fenwick trees are maintained 
2. Query of type given `[l, r]` find 
3. `a[l] + a[l+1]*2 + a[l+2]*3 + .... + a[r]*(r-l+1)`

```C++
ll query(ll l, ll r)
{
    return query(r) - query(l - 1);
}
```

4. Maintain two trees 
```
 a[0] ,  a[1] ,  a[2] ,  a[3] ,  a[4] , .........   fentree[0]
a[0]*0, a[1]*1, a[2]*2, a[3]*3, a[4]*4, .........   fentree[1]
```

5. Suppose we want to query [3,5]:
6. fentree[1].query(3,5) - (2)*fentree[0].query(3,5)

```
ll qry(ll l, ll r)
{
    return fentree[1].query(l, r) - (l - 1) * fentree[0].query(l, r);
}
```

7. Update i.e set the value at pos k as x

```
ll upd(ll k, ll x)
{
    fentree[0].update(k, x - a[k]);
    fentree[1].update(k, k * (x - a[k]));
    a[k] = x;
}
```

## Range updates and Range Queries:

[Refer CP Algorithms](https://cp-algorithms.com/data_structures/fenwick.html)

## 2D Fenwick Tree

```C++
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
```