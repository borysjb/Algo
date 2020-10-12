#include <bits/stdc++.h>

using namespace std;

vector < vector < int >> graph;
vector <int> dist;
queue < int > places;
bool fuckedup;

void BFS (int place) {
  for(int i:graph[place]) {
     if(dist[i] == -1) {
       dist[i] = dist[place]+1;
       places.push(i);
     }
     if (dist[i]%2==dist[place]%2) {
       fuckedup=true;
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
    fuckedup=false;

    for (int i = 0; i < con; i++) {
      int tmp1, tmp2;
      cin >> tmp1 >> tmp2;
      graph[--tmp1].push_back(--tmp2);
      graph[tmp2].push_back(tmp1);

    }

    /*
    int myNum;
    cin >> myNum;
    */

    places.push(0);


    for (int i = 0; i < ppl; i++) {
      dist[i] = -1;
    }

    dist[0] = 0;

    while (!places.empty()) {
      int temp = places.front();
      places.pop();
      BFS(temp);
      }


    /*
    cout << "Znajomi numeru " << myNum + 1 << ':' << endl;

    for (int y = 0; y < ppl; y++) {

      if (dist[y] > 0) {
        cout << y + 1 << ": " << dist[y] << endl;
      }
    }

 */
    //int groups=1;
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
      //groups++;
    }

  //cout<<"Grup znajomych jest "<<groups<<"."<<endl;

  if(fuckedup) {
    cout<<"NIE"<<endl;
  } else {
    cout<<"TAK"<<endl;
    for(int i=0;i<ppl;i++) {
      if(dist[i]%2==0) {
        cout<<"A ";
      } else {
        cout<<"B ";
      }
    }
    cout<<endl;
  }

  graph.resize(0);
  dist.resize(0);
  }
  return 0;
}

/*
2
5 6
1 4
3 2
2 1
4 5
3 4
5 2
4 4
1 2
2 3
2 4
3 1
*/
