#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <stack>

using namespace std;

void addEdge(vector<vector<int>> &adj, int v, int u) {
  adj[v].push_back(u);
  adj[u].push_back(v);
}

void bfs(vector<vector<int>> adj) {
  stack<int> q;
  unordered_set<int> track;
  q.push(1);

  while (!q.empty()) {
    int cur = q.top();
    q.pop();
    if (track.find(cur) != track.end()) {
      continue;
    }
    track.insert(cur);
    cout << cur << " ";
    for (int e : adj[cur]) {
      q.push(e);
    }
  }
  cout << endl;
}

void dfs(vector<vector<int>> adj) {
  queue<int> q;
  unordered_set<int> track;
  q.push(1);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (track.find(cur) != track.end()) {
      continue;
    }
    track.insert(cur);
    cout << cur << " ";
    for (int e : adj[cur]) {
      q.push(e);
    }
  }
  cout << endl;
}

int main() {
  const int N = 6;
  int Root = 1;
  vector<vector<int> > adj(N+1, vector<int>());
  addEdge(adj, 1, 2);
  addEdge(adj, 1, 3);
  addEdge(adj, 2, 6);
  addEdge(adj, 3, 4);
  addEdge(adj, 2, 5);
  bfs(adj);
  dfs(adj);
}
