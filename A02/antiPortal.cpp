#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector <int> enemies;
queue <int> places;

bool BFS (int place) {
  for (int i: graph[place]) {
    if(enemies[place]!=enemies[i]) {
      enemies[i]=1-enemies[place];
      places.push(i);
    } else {
      return true;
    }
  }
  return false;
}

int main () {
  int z;
  cin >> z;
  while (z--) {

    int ppl, enem;
    cin >> ppl >> enem;
    graph = vector <vector<int>> (ppl);
    enemies = vector<int> (ppl);
    places = queue <int> ();

    for (int i = 0 ; i < enem ; i++) {
      int temp1, temp2;
      cin >> temp1 >> temp2;
      graph [--temp1] .push_back (--temp2);
      graph [temp2] .push_back (temp1);
    }

    for (int i=0;i<ppl;i++) {
      enemies[i]=-1;
    }
    enemies[0]=0;
    places.push(0);

    /*for (int i=0;i<ppl;i++) {
      cout<<enemies[i]<<", ";
    }
    cout<<endl;*/

    bool FuckUp=true;

    while (!places.empty()) {
      int temp = places.front();
      places.pop();
      bool broken = BFS(temp);
      if (broken) {
        cout<<"NIE"<<endl;
        break;
        FuckUp=false;
      }
    }
    if (FuckUp) {
      for (int i=0;i<ppl;i++) {
        if (enemies[i]==0)
          cout<<"A ";
        else
          cout<<"B ";
      }
      cout<<endl;
    }
  }
  return 0;
}
