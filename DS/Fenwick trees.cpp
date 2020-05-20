1)Even if the name of the structure is a binary indexed tree, 
it is usually represented as an array.

2)We assume that all arrays are (one-indexed),
to make implementation easier. 

3)Let p(k) denote the largest power of two that divides k .
We store a binary indexed tree as an array tree such that
tree[k]=sum(k-p(k)+1,k);

4)Using a binary indexed tree, any value of sum(1,k) 
can be calculated in O(log n) time, because a range [1,k] 
can always be divided into O(log n) ranges whose sums 
are stored in the tree.

5)sum(1,7)=sum(1,4)+sum(5,6)+sum(7,7)
6)sum(a,b)=sum(1,b)-sum(1,a-1);
7)p(k)=k&-k;

8)The following function calculates the sum in (1,k)

lli query(lli k)
{
    lli s=0;
    while(k>=1)
    {
        s+=fentree[k];
        k-=k&-k;
    }
    return s;
}

9)The following function increases the array value at pos k by x.
(x can be any integer)

void update(lli k,lli x)
{
    while(k<=n)
    {
        fentree[k]+=x;
        k+=k&-k;
    }
}

10)Time complexity of both the above functions is O(logn).

11)Counting Inversions:

Use co-ordinate Compression to make the elements less than n 
Sort the array in reverse order then traverse the array.
forz(i,n)
{
  //add the no of elements less than i to the ans
  ans+=query(a[i]-1);
  update(a[i],1);
}

12)Find the kth element in the array:
Binary search the prefix sum in the BIT 

https://codeforces.com/contest/1354/submission/80572075
int l = 1, r = n, id = -1;
while (l <= r)
{
  int mid = l + (r - l) / 2;
  if (query(mid)>=qk)
  {
     id = mid;
     r = mid - 1;
  }
  else
    l = mid + 1;
}

13)Range updates and point queries

>>update adds x at position k
>>to set position k as x use update(k,x-a[k])

void update(lli k,lli x)
{
    while(k<=n)
    {
        fentree[k]+=x;
        k+=k&-k;
    }
}

void range_upd(lli l,lli r,lli x)
{
    update(l,x);
    update(r+1,-x);
}

lli point_query(lli k)
{
    lli s=0;
    while(k>=1)
    {
        s+=fentree[k];
        k-=k&-k;
    }
    return s;
}

13)Point updates and Range queries
Typically two fenwick trees are maintained 

1)Query of type given [l,r]
find a[l]+a[l+1]*2+a[l+2]*3+....+a[r]*(r-l+1)

lli query(lli l,lli r)
{
    return query(r)-query(l-1);
}

Maintain two trees 
 a[0] , a[1] , a[2] , a[3] , a[4] ,.........   fentree[0]
a[0]*0,a[1]*1,a[2]*2,a[3]*3,a[4]*4,.........   fentree[1]

Suppose we want to query [3,5]:
fentree[1].query(3,5)-(2)*fentree[0].query(3,5)

lli qry(lli l,lli r)
{
    return fentree[1].query(l,r)-(l-1)*fentree[0].query(l,r);
}

2)Update i.e set the value at pos k as x

lli upd(lli k,lli x)
{
    fentree[0].update(k,x);
    fentree[1].update(k,k*(x-a[k]));
    a[k]=x;
}

14)Range updates and Range Queries:

https://cp-algorithms.com/data_structures/fenwick.html

We will use two BITs namely B1[] and B2[], 

we perform two point updates on B1: 
add(B1, l, x) and add(B1, r+1, -x). 
And we also update B2.

Updates on B2 are checked with sum[0,i]
for i<l
    l<=i<=r 
    i>r 
they should return the desired values 

>>Python code

def range_add(l, r, x):
    add(B1, l, x)
    add(B1, r+1, -x)
    add(B2, l, x*(l-1))
    add(B2, r+1, -x*r))

After the range update (l,r,x) 

We can write the range sum as difference of two terms,
where we use B1 for first term and B2 for second term.

The difference of the queries will give us prefix sum over [0,i].
sum[0,i]=sum(B1,i)⋅i−sum(B2,i)

The last expression is exactly equal to the required terms. 
Thus we can use B2 for shaving off extra terms when we multiply 
B1[i]×i.

We can find arbitrary range sums by computing the prefix sums 
for l−1 and r and taking the difference of them again.

def add(b, idx, x):
    while idx <= N:
        b[idx] += x
        idx += idx & -idx

def range_add(l,r,x):
    add(B1, l, x)
    add(B1, r+1, -x)
    add(B2, l, x*(l-1))
    add(B2, r+1, -x*r)

def sum(b, idx):
    total = 0
    while idx > 0:
        total += b[idx]
        idx -= idx & -idx
    return total

def prefix_sum(idx):
    return sum(B1, idx)*idx -  sum(B2, idx)

def range_sum(l, r):
    return prefix_sum(r) - prefix_sum(l-1)

