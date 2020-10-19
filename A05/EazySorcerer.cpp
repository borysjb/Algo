#include <bits/stdc++.h>

using namespace std;

struct para {
  int x;
  int y;
};

struct DONE {};

vector <vector<int>> graph;
queue <para> BFSq;
vector<vector<int>> dist;
int exitdist;

void BFS (para place) {
  para tmp1,tmp2,tmp3,tmp4;
  tmp1.x=place.x+1;
  tmp1.y=place.y;
  tmp2.x=place.x;
  tmp2.y=place.y+1;
  tmp3.x=place.x-1;
  tmp3.y=place.y;
  tmp4.x=place.x;
  tmp4.y=place.y-1;
  para BFSs [4]={tmp1,tmp2,tmp3,tmp4};
  for(para i:BFSs) {
    if (graph[i.x][i.y]==1&&dist[i.x][i.y]!=-1) {
      BFSq.push(i);
      dist[i.x][i.y]=dist[place.x][place.y]+1;
    } else if (graph[i.x][i.y]==2&&dist[i.x][i.y]!=-1) {
      exitdist=dist[place.x][place.y]+1;
      throw DONE();
    }
  }
  return;
}

void getData (int height, int width) {
  para temppara;
  for(int i=0;i<height;i++) {
    string tmp1;
    cin >> tmp1;
    for(int j=0;j<width;j++) {
      char tmp2;
      tmp2=tmp1[j];
      if (tmp2=='.'||tmp2=='+') {
        graph[i].push_back(1);
        dist[i].push_back(-1);
      } else if (tmp2=='@') {
        temppara.x=i;
        temppara.y=j;
        BFSq.push(temppara);
        dist[i].push_back(0);
        graph[i].push_back(1);
      } else if (tmp2=='#') {
        graph[i].push_back(0);
        dist[i].push_back(-1);
      } else if (tmp2=='>') {
        graph[i].push_back(2);
        dist[i].push_back(-1);
      }
    }
  }
}

void zero (int height,int width) {
  graph = vector<vector<int>> (height);
  BFSq=queue<para> ();
  dist = vector<vector<int>> (height);

  exitdist=0;
}

int main () {
  int z;
  cin >> z;
  while  (z--) {
    int height,width;
    cin>>height>>width;

    zero(height,width);
    getData(height,width);


    /*cout<<endl;
    for(int i=0;i<height;i++) {
      for(int j=0;j<width;j++) {
        cout<<graph[i][j];
      }
      cout<<endl;
    }

    cout<<endl;
    for(int i=0;i<height;i++) {
      for(int j=0;j<width;j++) {
        cout<<dist[i][j];
      }
      cout<<endl;
    }*/

    while (!BFSq.empty()) {
      para temp=BFSq.front();
      BFSq.pop();
      try {
        BFS(temp);
      } catch (DONE) {
        cout << exitdist << endl;
      }
    }


  }
  return 0;
}
