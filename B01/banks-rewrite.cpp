#include <bits/stdc++.h>

using namespace std;

struct edge {
  int src;
  int dest;
  int cost;
};

int main () {
  int Z;
  cin>>Z;
  while(Z--) {
    int banks,edges;
    cin>>banks>>edges;
    vector<edge> connects (edges);
    vector<int> dist (banks);
    int start,end,cost;

    for (int i=0;i<edges;i++) {
      cin>>start>>end>>cost;
      connects[i]={--start,--end,cost};
    }
    cin>>start>>end;
    start--;
    end--;

    for(int i=0;i<banks;i++) {
      dist[i]=INT_MAX;
    }
    dist[start]=0;

    for(int i=1;i<banks;i++) {
      for(int j=0;j<edges;j++) {
        int src = connects[j].src;
        int dest = connects[j].dest;
        int cost = connects[j].cost;
        if(dist[src]!=INT_MAX && dist[src]+cost<dist[dest]) {
          dist[dest] = dist[src]+cost;
        }
      }
    }

    bool hole=true;

    for(int i=0;i<edges;i++) {
      int src = connects[i].src, dest = connects[i].dest, cost=connects[i].cost;
      if(dist[src]!=INT_MAX && dist[src]+cost<dist[dest] && hole) {
        cout<<"Luka w systemie bankowym!\n";
        hole=false;
      }
    }

    if(dist[end]!=INT_MAX && hole) {
      cout<<"Minimalny koszt: "<<dist[end]<<endl;
    } else if (hole) {
      cout<<"Bank niedostepny!\n";
    }
  }
}
