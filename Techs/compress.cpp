//Co ordinate compression method:
//n Segments:
//l,r;

vector<pair<lli,lli>>v;
v.pb({l,+1});
v.pb({r+1,-1});
sort(all(v));
lli k=2*n-1;
lli c=0;
forz(i,k)
{
  c+=v[i].S;
  if(v[i].F!=v[i+1].F)
  {
    then c no of seg covers pts (v[i+1].F-v[i].F) in number
  }
}
