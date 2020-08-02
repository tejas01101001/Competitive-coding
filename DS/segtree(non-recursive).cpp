1)Segment tree with single element modification:

Operation 1:modify an element
Operation 2:Sum over a interval [l,r)

>Children of node i are 2i(left child) and 2i+1(right child);
>Array is zero based here 
>Actual array stored in t[n] to t[2n-1]

const lli N =          // limit for array size
lli n;                 // array size
lli t[2 * N];
 
void build()
{   // build the tree
    for (int i = n - 1; i > 0; --i)
        t[i] = t[i << 1] + t[i << 1 | 1];
}
 
void modify(lli p, lli value)
{   // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1)
        t[p >> 1] = t[p] + t[p ^ 1];
}
 
lli query(lli l, lli r)
{   // sum on interval [l, r]
    lli res = 0;
    r++;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res += t[l++];
        if (r & 1)
            res += t[--r];
    }
    return res;
}

>Before doing any queries we need to bulid the tree bulid();in 
O(n)

http://i.imgur.com/GGBmcEP.png

>Refer the above image for query [3,11)

General idea is the following. If l, the left interval border, 
is odd (which is equivalent to l&1) then l is the right child of 
its parent. Then our interval includes node l but doesnt include 
its parent. 

So we add t[l] and move to the right of l parent by 
setting l = (l + 1) / 2. If l is even, it is the left child,
and the interval includes its parent as well 
(unless the right border interferes),

so we just move to it by setting l = l / 2. 
Similar argumentation is applied to the right border. 
We stop once borders meet.

>If n is not a power of 2 consider a set of balanced binary trees 
which can be shown to above tree .Hence the above code works

2)Modification on a interval,single element access

//WE DONT NEED TO BULID THE TREE IN THIS CASE
Operation 1:Add a value to a range 
Operation 2:Compute an element at some pos;

void modify(lli l,lli r,lli value) 
{
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            t[l++] += value;
        if (r & 1)
            t[--r] += value;
    }
}

lli query(lli p) 
{
    lli res = 0;
    for (p += n; p > 0; p >>= 1)
        res += t[p];
    return res;
}

>But at some point we need to inspect all the elements in the array,
we can push all the modications to the leaves.

After that we can just traverse elements starting with index n 
This way we can reduce the TC from O(nlogn) to O(n)

//SIMILAR TO BUILD FUNCTION
void push() 
{
    for (int i = 1; i < n; ++i)
    {
        t[i << 1] += t[i];
        t[i << 1 | 1] += t[i];
        t[i] = 0;
    }
}

3)NON-commutative combiner functions:

We have considered commutative combiner functions like 
+,max,min,&,|,^ 

Initial query res to apt infinity while using mix,max

>>If combiner function is not commutative

We define structure S and combine function for it. 
In method build we just change + to this function. 
In modify we need to ensure the correct ordering of children, 
knowing that left child has even index. 

When answering the query, we note that nodes corresponding 
to the left border are processed from left to right, 
while the right border moves from right to left.

void modify(int p, const S& value) 
{
    for (t[p += n] = value; p >>= 1;)
        t[p] = combine(t[p << 1], t[p << 1 | 1]);
}

S query(int l, int r) 
{
    S resl, resr;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            resl = combine(resl, t[l++]);
        if (r & 1)
            resr = combine(t[--r], resr);
    }
    return combine(resl, resr);
}

Refer:https://codeforces.com/contest/380/submission/66448115
Kadane algo with queries:https://www.codechef.com/viewsolution/30682984
