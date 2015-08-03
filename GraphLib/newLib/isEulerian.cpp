/* The function returns one of the following values
   0 --> If grpah is not Eulerian
   1 --> If graph has an Euler path (Semi-Eulerian)
   2 --> If graph has an Euler Circuit (Eulerian)  */
int Graph::isEulerian()
{
  // Check if all non-zero degree vertices are connected
  if (isConnected() == false)
    return 0;

  // Count vertices with odd degree
  int odd = 0;
  for (int i = 0; i < V; i++)
    if (adj[i].size() & 1)
      odd++;

  // If count is more than 2, then graph is not Eulerian
  if (odd > 2)
    return 0;

  // If odd count is 2, then semi-eulerian.
  // If odd count is 0, then eulerian
  // Note that odd count can never be 1 for undirected graph
  return (odd) ? 1 : 2;
}
