#include <bits/stdc++.h>

using namespace std;

vector < vector < int >> graph;
vector <int> dist;
queue < int > places;

void BFS (int place) {
  for(int i:graph[place]) {
     if(dist[i] == -1) {
       dist[i] = dist[place]+1;
       places.push(i);
     }
  }
  return;
}

bool funcsLeft () {
  for(int i=0;i<dist.size();i++) {
    if(dist[i]==-1){
      return true;
    }
  }
  return false;
}

int main() {
  int z;
  cin >> z;
  while (z--) {

    int ppl, con;
    cin >> ppl >> con;
    graph=vector <vector<int>> (ppl);
    dist = vector<int> (ppl);
    places = queue <int> ();

    for (int i = 0; i < con; i++) {
      int tmp1, tmp2;
      cin >> tmp1 >> tmp2;
      graph[--tmp1].push_back(--tmp2);
      graph[tmp2].push_back(tmp1);

    }

    int myNum;
    cin >> myNum;

    places.push(--myNum);


    for (int i = 0; i < ppl; i++) {
      dist[i] = -1;
    }

    dist[myNum] = 0;

    while (!places.empty()) {
      int temp = places.front();
      places.pop();
      BFS(temp);
      }

    cout << "Znajomi numeru " << myNum + 1 << ':' << endl;

    for (int y = 0; y < ppl; y++) {

      if (dist[y] > 0) {
        cout << y + 1 << ": " << dist[y] << endl;
      }
    }

    int groups=1;
    while(funcsLeft()) {
      for(int i=0;i<ppl;i++) {
        if(dist[i]==-1) {
          places.push(i);
          dist[i]=0;
          break;
        }
      }
      while (!places.empty()) {
        int temp = places.front();
        places.pop();
        BFS(temp);
      }
      groups++;
    }

  cout<<"Grup znajomych jest "<<groups<<"."<<endl;

  graph.resize(0);
  dist.resize(0);
  }
  return 0;
}
