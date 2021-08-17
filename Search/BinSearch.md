# Binary search:

1. Basic structure

```C++
ll l = 0, r = n - 1;
while (l <= r)
{
  ll mid = l + (r - l) / 2;
  if (a[mid] == x)
    return mid;
  if (a[mid] < x)
    l = mid + 1;
  else
    r = mid - 1;
}
return -1;
```

2. Sometimes there is no array and we can still apply bins:
   
- Is x is a square

```C++
l = 0;
r = x;
m = l + (r - l) / 2;
m ^ 2 compared with x;
```

- Find first value >=x

```C++
x = 4
F F T T T T  T
2,3,5,6,8,10,12
```

- We have to keep on updating ans with better values.
- Think of binary search as as series of true and false.
- need to find boundary between the partially false and partially true.
- prefix of true and suffix of false or the other way.

```C++
ll l = 0, r = n - 1;
ll ans = -1;
while (l <= r)
{
  mid = l + (r - l) / 2;
  if (a[mid] >= x)
  {
    ans = a[mid];
    r = mid - 1;
  }
  else
    l = mid + 1;
}
return ans;
```

- Rotated array find the smallest element.

```C++
T T T T  T  F F
6,7,9,15,19,2,3

if (mid > a[n-1]) true;
else false;
```

- The array increases and then decreases   
Find the maximum.

```C++
? T T T T T T  F  F F F F
2,3,4,5,6,9,12,11,8,6,4,1

can take first ? as T
if(m == 0|| a[m] > a[m-1])then T
else F
look for last true
```

- Find sqrt with some precision

```C++
long double l = 0, r = x;
while (r - l > epsilon)
{
  mid = l + (r - l) / 2;
  if (mid * mid < x)
    l = mid;
  else
    r = mid;
}
return l + (r - l) / 2;
```
