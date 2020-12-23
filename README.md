# HopcroftKarp-OS4
The task was to find the maximum matching in bipartite graph.
For that the Hopcroft-Karp algorytm was used

## Required terminology
**Free Node or Vertex:** Given a matching M, a node that is not part of matching is called free node. Initially all vertices as free.

**Matching and Not-Matching edges:** Given a matching M, edges that are part of matching are called Matching edges and edges that are not part of M (or connect free nodes) are called Not-Matching edges. 

**Alternating Paths:** Given a matching M, an alternating path is a path in which the edges belong alternatively to the matching and not matching. All single edges paths are alternating paths.

**Augmenting path:** Given a matching M, an augmenting path is an alternating path that starts from and ends on free vertices. All single edge paths that start and end with free vertices are augmenting paths. Note that the augmenting path always has one extra matching edge.

The Hopcroft-Karp algorithm is based on a concept that <br>
*A matching M is not maximum if there exists an augmenting path. It is also true other way, i.e, a matching is maximum if no augmenting path exists*

## Algorithm
1. Initialize M(matching) as empty
2. REPEAT
  - Use BFS (Breadth First Search) to build alternating level graph, rooted in unmatched vertices in Set U (only verticies on the left of the bipartite graph)
  - Augment current matching M with maximal set of vertex disjoint shortest length path (using DFS (Depth First Search))
3. Until there are no more augmenting paths.
4. return M

## Program execution example
```
Start matrix:
0 1 1 0 
1 0 1 1 
1 0 0 1 
0 0 0 1 

Matching:
0 1 0 0 
0 0 1 0 
1 0 0 0 
0 0 0 1 
```
