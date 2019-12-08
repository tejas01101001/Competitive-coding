//BROWNINE TK
1)F(n) = a*F(n-1) + b*F(n-2) + c*F(n-3)   for n >= 3
LET THE SECOND MATRIX BE C
[First Matrix]  [Second matrix]       [Third Matrix]
| F(n)   |  =  | a b c |  *           | F(n-1) |
| F(n-1) |     | 1 0 0 |              | F(n-2) |
| F(n-2) |     | 0 1 0 |              | F(n-3) |
              - - - - - - - - n -2 times - - - -  -
| F(n)   |  =  | a b c | * | a b c | * ... * | a b c | * | F(2) |
| F(n-1) |     | 1 0 0 |   | 1 0 0 |         | 1 0 0 |   | F(1) |
| F(n-2) |     | 0 1 0 |   | 0 1 0 |         | 0 1 0 |   | F(0) |


| F(n)   |  =  [ | a b c | ] ^ (n-2)   *  | F(2) |
| F(n-1) |     [ | 1 0 0 | ]              | F(1) |
| F(n-2) |     [ | 0 1 0 | ]              | F(0) |

i.e,F(n)=C[0][0]*f(2)+C[0][1]*f(1)+C[0][2]*f(0);

//VERY IMP:
if M is multiplied n times then our job gets easier 
we just have to consider the 
F(n)=C[0][0]*f(0);
as the f(a)=0 for a<0


const int ms=matrixsize;
void mul(lli a[ms][ms],lli b[ms][ms])
{
  lli t[ms][ms]={0};
  forz(i,ms)forz(j,ms)forz(k,ms)
    t[i][j]=(t[i][j]+a[i][k]*b[k][j]);
  forz(i,ms)forz(j,ms)
    a[i][j]=t[i][j];
}

lli matpow(lli F[ms][ms],lli n)
{
  lli C[ms][ms]={{a,b,c},{1,0,0},{1,0,0}};
  if(n==1)
    return (F[0][0]*f(2)+F[0][1]*f(1)+F[0][2]*f(0));
  matpow(F,n/2);
  mul(F,F);
  if(n%2!=0)mul(F,C);
  return (F[0][0]*f(2)+F[0][1]*f(1)+F[0][2]*f(0));
}

lli findn(lli n)
{
  lli C[ms][ms]={{a,b,c},{1,0,0},{1,0,0}};
  return matpow(C,n-2);
}

2)f(n) = f(n-1) + f(n-2) + c

    |  f(n)  |   | f(n+1) |
M x | f(n-1) | = |  f(n)  |
    |    c   |   |    c   |

3)f(n) = if n is odd, f(n-1) else, f(n-2)
In short:
f(n) = (n&1) * f(n-1) + (!(n&1)) * f(n-2)

Here, we can just split the functions in the basis of odd even and keep 2 different matrix for both of them and calculate separately. Actually, there might appear many different patterns, but these are the basic patterns.

4)Lets put it altogether: find matrix suitable for
f(n) = a * f(n-1) + c * f(n-3) + d * f(n-4) + e.
matrix C
| a  0  c  d  1 |
| 1  0  0  0  0 |
| 0  1  0  0  0 |
| 0  0  1  0  0 |
| 0  0  0  0  1 |

5)Here, g(n+1) = 2g(n) + 2g(n-1) + f(n+1) and f(n+2) = 2f(n+1) + 2f(n).
Now, using the above process, we can generate the objective matrix C as follows:
|  g(n)  |
| g(n-1) |
| f(n+1) |
|  f(n)  |

| 2  2  1  0 |
| 1  0  0  0 |
| 0  0  2  2 |
| 0  0  1  0 |

IMPLEMENTATION USING STRUCTURES.
struct matrix
{
    vector <vector <lli>>m;
};
void msi(matrix &m,lli a,lli b)
{
    m.m.resize(a);
    forz(i,a)
       m.m[i].resize(b);
}
void minit(matrix &m,lli x)
{
    forz(i,m.m.size())
       forz(j,m.m[0].size())
           m.m[i][j]=x;
}
matrix mul(matrix m1,matrix m2)
{
    matrix m3;
    msi(m3,m1.m.size(),m2.m[0].size());
    forz(i,m3.m.size())
      {
          forz(j,m3.m[0].size())
          {    m3.m[i][j]=0;
               forz(k,m1.m[0].size())
                 m3.m[i][j]=(m3.m[i][j]+m1.m[i][k]*m2.m[k][j])%mod;
          }
      }
      return m3;
}
matrix mexp(matrix &mx,lli p)
{
   matrix res;
   msi(res,mx.m.size(),mx.m.size());
   minit(res,0);
   forz(i,mx.m.size())
      res.m[i][i]=1;
   while(p>0)
   {
     if(p&1)
       res=mul(res,mx);
     mx=mul(mx,mx);
     p=p>>1;
   }
   return res;
}
//CODE FOR FIBO
int main()
{
    kira;
    lli n;
    cin>>n;
    matrix ans;
    msi(ans,3,3);
    minit(ans,0);
    ans.m[0][0]=1;
    ans.m[0][1]=1;
    ans.m[0][2]=1;
    for(int i=1;i<3;i++)
    {
        ans.m[i][i-1]=1;
    }
    ans=mexp(ans,n);
    lli res=ans.m[0][0];
    cout<<res;
    return 0;
}
