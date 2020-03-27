bool dfsCycle(int v) {
  Vis[v] = 1;
  for (int s : Adj[v]) {
    if (Vis[s] == 1) { return true; }
    if (Vis[s] == 0 && dfsCycle(s))
      return true;
  }
 
  Vis[v] = 2;
  return false;
}
