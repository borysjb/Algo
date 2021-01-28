#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int start;
  int dest;
  long long cost;
};

vector <int> parent;
vector <int> ranga;
vector <Edge> graph;

bool operator< (Edge a, Edge b) {
  return a.cost<b.cost;
}

int find(int x) {
  if(parent[x]!=x) {
    parent[x]=find(parent[x]);
  }
  return parent[x];
}

void unite (int a, int b) {
  int atop = find(a);
  int btop = find(b);
  //cout<<"found\n";
  if(atop==btop) {
    return;
  }
  if(ranga[atop]<ranga[btop]) {
    parent[atop] = btop;
  } else if (ranga[atop]>ranga[btop]) {
    parent[btop] = atop;
  } else {
    parent[atop] = btop;
    ranga[atop]++;
  }
}

long long tree (int lines) {
  long long minCost = 0,cost;
  int start, dest;
  for (size_t i = 0; i < lines; i++) {
    start = graph[i].start;
    dest = graph[i].dest;
    cost = graph[i].cost;
    if(find(start)!=find(dest)) {
      minCost+=cost;
      unite(start,dest);
    }
  }
  return minCost;
}

int main() {

  int Z;
  scanf("%d", &Z);
  while (Z--) {

    int stops, lines;
    scanf("%d %d", &stops, &lines);
    parent = vector <int> (stops);
    ranga = vector <int> (stops);
    graph = vector <Edge> ();
    for (int i = 0; i < stops; i++) {
      parent[i]=i;
      ranga[i]=0;
    }

    for (int i = 0; i < lines; i++) {
      int tmp1,tmp2;
      long long dist;
      scanf("%d %d %lld", &tmp1, &tmp2, &dist);
      graph.push_back({--tmp1,--tmp2,dist});
    }

    sort(graph.begin(), graph.end());

    long long minCost = tree(lines);

    printf("%lld \n", minCost);
  }
}
