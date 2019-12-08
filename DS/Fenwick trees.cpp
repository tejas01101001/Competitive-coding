1)Even if the name of the structure is a binary indexed tree, it is usually represented as an array.
2)We assume that all arrays are one-indexed,to make implementation easier. 
3)Let p(k) denote the largest power of two that divides k .
We store a binary indexed tree as an array tree such that
tree[k]=sum(k-p(k)+1,k);
4)Using a binary indexed tree, any value of sum(1,k) can be calculated in O(log n) time, because a range [1,k] can always be divided into O(log n) ranges whose sums are stored in the tree.
5)sum(1,7)=sum(1,4)+sum(5,6)+sum(7,7)
6)sum(a,b)=sum(1,b)-sum(1,a-1);
7)p(k)=k&-k;
8)The following function calculates the sum in (1,k)

lli query(lli k)
{
    lli s=0;
    while(k>=1)
    {
        s+=tree[k];
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
        tree[k]+=x;
        k+=k&-k;
    }
}

10)Time complexity of both the above functions is O(logn).
