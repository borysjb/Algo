#include <bits/stdc++.h>

using namespace std;

vector <vector <long long>> graph;
vector <bool> visited;
vector <long long> findtime;
long long timer;
vector <long long> low;
vector <long long> parent;

long long DFS (long long place) {
  if(!visited[place]) {
    visited[place]=true;
    findtime[place] = timer;
    low[place] = timer++;

    for (long long i:graph[place]) {
      if(!visited[i]) {

      }
    }
  }
}

int main () {
  long long Z;
  cin>>Z;
  while (Z--) {
    long long people, connections;
    cin>>people>>connections;

    graph = vector <vector <long long>> (people);
    visited = vector <bool> (people, false);
    findtime = vector <long long> (people, -1);
    timer = 0;
    low = vector <long long> (people);

    for (size_t i = 0;i < connections; i++) {
      long long tmp1,tmp2;
      cin>>tmp1>>tmp2;
      graph[--tmp1].push_back(--tmp2);
      graph[tmp2].push_back(tmp1);
    }


  }
}
