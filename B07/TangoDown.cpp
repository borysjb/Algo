#include <bits/stdc++.h>

using namespace std;

vector<vector<long long>> graph;
vector <bool> visited;
vector <long long> intime;
vector <long long> low;
vector <long long> parent;
vector <stack <long long>> cutTrees;
vector <long long> underTree;
long long timer;

long long DFS (long long place) {
if(!visited[place]){
  visited[place]=true;
  intime[place]=timer;
  low[place]=timer++;

  for(long long i:graph[place]) {
    if(!visited[i]) {

      parent[i]=place;
      underTree[place]+=DFS(i);
      low[place] = min(low[place],low[i]);

      if(parent[place]==place && graph[place].size() > 1) {
        cutTrees[place].push(underTree[i]);
      }

      if(parent[place]!=place && low[i]>= intime[place]) {
        cutTrees[place].push(underTree[i]);
      }

    } else if(parent[place]!=i) {
      low[place] = min(low[place],intime[i]);
    }
  }

  return underTree[place];
} else {
  return 0;
}
}

int main () {
  long long Z;
  cin>>Z;
  while (Z--) {
    long long idiots, connections;
    cin>>idiots>>connections;

    graph = vector <vector <long long>> (idiots);
    visited = vector <bool> (idiots, 0);
    intime = vector <long long> (idiots, -1);
    low = vector <long long> (idiots, LLONG_MAX);
    cutTrees = vector <stack <long long>> (idiots);
    underTree = vector <long long> (idiots,1);
    timer = 0;
    parent = vector <long long> (idiots,-1);

    for (long long i = 0; i < connections; i++) {
      long long tmp1, tmp2;
      cin>>tmp1>>tmp2;
      graph[--tmp1].push_back(--tmp2);
      graph[tmp2].push_back(tmp1);
    }

    parent[0]=0;
    long long treesize = DFS(0);

    for (long long i = 0; i < idiots; i++) {
      long long rest = idiots-1;
      long long papers = 0;
      while (!cutTrees[i].empty()) {
        papers += cutTrees[i].top()*(cutTrees[i].top()-1);
        rest -= cutTrees[i].top();
        cutTrees[i].pop();
      }
      papers+=rest*(rest-1);
      cout<<papers<<endl;
    }
  }
  return 0;
}
