1)The Floyd–Warshall algorithm provides an alternative way to approach the problem of finding shortest paths.It finds all shortest paths between the nodes in a single run.

2)The algorithm maintains a two-dimensional array that contains distances between the nodes. First, distances are calculated only using direct edges between the nodes, and after this, the algorithm reduces distances by using intermediate nodes in paths.

3)The graph may have negative weight edges, but no negative weight cycles (for then the shortest path is undefined).

4)Before k-th phase (k=1…n), d[i][j] for any vertices i and j stores the length of the shortest path between the vertex i and vertex j, which contains only the vertices {1,2,...,k−1} as internal vertices in the path.

5)It is easy to make sure that this property holds for the first phase. For k=0, we can fill matrix with d[i][j]=wij if there exists an edge between i and j with weight wij and d[i][j]=∞ if there doesnt exist an edge. In practice ∞ will be some high value. As we shall see later, this is a requirement for the algorithm.

for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {
        if(i==j)dis[i][j]=0;
        else if(adj[i][j])dis[i][j]=adj[i][j];
        else dis[i][j]=INF;
    }
}

for(int k=1;k<=n;k++)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dis[i][k]<INF&&dis[k][j]<INF)//neg edge weights
            dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
}

6)Retrieving the sequence of vertices in the shortest path:

For this, in addition to the distance matrix d[][], a matrix of ancestors p[][] must be maintained, which will contain the number of the phase where the shortest distance between two vertices was last modified. It is clear that the number of the phase is nothing more than a vertex in the middle of the desired shortest path. Now we just need to find the shortest path between vertices i and p[i][j], and between p[i][j] and j. This leads to a simple recursive reconstruction algorithm of the shortest path.

7)The case of real weights

If the weights of the edges are not integer but real, it is necessary to take the errors, which occur when working with float types, into account.

The Floyd-Warshall algorithm has the unpleasant effect, that the errors accumulate very quickly. In fact if there is an error in the first phase of δ, this error may propagate to the second iteration as 2δ, to the third iteration as 4δ, and so on.

To avoid this the algorithm can be modified to take the error (EPS = δ) into account by using following comparison:

if (d[i][k] + d[k][j] < d[i][j] - EPS)
    d[i][j] = d[i][k] + d[k][j]; 

8)Negative cycles:
Formally the Floyd-Warshall algorithm does not apply to graphs containing negative weight cycle(s). But for all pairs of vertices i and j for which there doesnt exist a path starting at i, visiting a negative cycle, and end at j, the algorithm will still work correctly.

For the pair of vertices for which the answer does not exist (due to the presence of a negative cycle in the path between them), the Floyd algorithm will store any number (perhaps highly negative, but not necessarily) in the distance matrix. However it is possible to improve the Floyd-Warshall algorithm, so that it carefully treats such pairs of vertices, and outputs them, for example as −INF.

This can be done in the following way: let us run the usual Floyd-Warshall algorithm for a given graph. Then a shortest path between vertices i and j does not exist, if and only if, there is a vertex t that is reachable from i and also from j, for which d[t][t]<0.

In addition, when using the Floyd-Warshall algorithm for graphs with negative cycles, we should keep in mind that situations may arise in which distances can get exponentially fast into the negative. Therefore integer overflow must be handled by limiting the minimal distance by some value (e.g. −INF).