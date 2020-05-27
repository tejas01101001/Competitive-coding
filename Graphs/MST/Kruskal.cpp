Kruskals Algo
1)A spanning tree of a graph consists of all nodes of the graph and some of the edges of the graph so that there is a path between any two nodes. Like trees in general, spanning trees are connected and acyclic. Usually there are several ways to construct a spanning tree.
2)In Kruskal’s algorithm1, the initial spanning tree only contains the nodes of the graph and does not contain any edges. Then the algorithm goes through the edges ordered by their weights, and always adds an edge to the tree if it does not create a cycle.
3)edges are sorted in asc,des order depending on their weights.
(edge is added between two nodes if they dont belong to same component)

USE disjoint set union.

struct edge
{
  lli u,v,weight;
  bool operator<(edge const& other)
  {
    return weight<other.weight;
  }
};
vector<edge>edges,result;
lli cost=0;
sort(all(edges));
for(edge e:edges)
{
  if(find(e.u)!=find(e.v))
  {
    cost+=e.weight;
    result.pb(e);
    merge(e.u,e.v);
  }
}
