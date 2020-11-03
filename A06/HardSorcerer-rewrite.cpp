#include <bits/stdc++.h>

#define space 0
#define wall 1
#define entrance 2
#define exit 3
#define tp 4
#define door 5
#define adoor 6

using namespace std;

struct position {
  bool astral;
  int x,y;
};

int main () {
  int Z;
  cin>>Z;
  while(Z--) {
    int height,width;
    cin>>height>>width;

    short graph[height][width];
    int dist[height][width][2];
    position entry;

    for (int i=0;i<height;i++) {
      string in;
      cin>>in;
      for(int j=0;j<width;j++) {
        switch(in[j]) {
        case '.':
          dist[i][j][0]=dist[i][j][1]=-1;
          graph[i][j]=space;
          break;
        case '#':
          graph[i][j]=wall;
          break;
        case '@':
          dist[i][j][0]=0;
          dist[i][j][1]=-1;
          graph[i][j]=space;
          entry = {false,i,j};
          break;
        case '>':
          dist[i][j][0]=dist[i][j][1]=-1;
          graph[i][j]=exit;
          break;
        case '%':
          dist[i][j][0]=dist[i][j][1]=-1;
          graph[i][j]=tp;
          break;
        case '+':
          dist[i][j][0]=dist[i][j][1]=-1;
          graph[i][j]=door;
          break;
        case 'o':
          dist[i][j][0]=dist[i][j][1]=-1;
          graph[i][j]=adoor;
          break;
        }
      }
    }

/*
    for(int i=0;i<height;i++) {
      for(int j=0;j<width;j++) {
        cout<<graph[i][j];
      }
      cout<<endl;
    }
*/

    queue<position> BFSq;
    BFSq.push(entry);
    while(!BFSq.empty()) {
      position temp=BFSq.front();
      BFSq.pop();

      vector<position>neighbors;

      if(graph[temp.x][temp.y]==tp) {
        neighbors = {
          {false,temp.x-1,temp.y},{false,temp.x+1,temp.y},{false,temp.x,temp.y-1},{false,temp.x,temp.y+1},
          {true,temp.x-1,temp.y},{true,temp.x+1,temp.y},{true,temp.x,temp.y-1},{true,temp.x,temp.y+1}
        };
      } else {
        neighbors = {
          {temp.astral,temp.x-1,temp.y},{temp.astral,temp.x+1,temp.y},
          {temp.astral,temp.x,temp.y-1},{temp.astral,temp.x,temp.y+1}
        };
      }

      for(position place:neighbors) {
        //cout<<"checking:"<<place.x<<","<<place.y<<","<<place.astral<<endl;
        if(place.x<height&&place.y<width&&place.x>=0&&place.y>=0){
          if(place.astral && graph[place.x][place.y]==door){
            continue;
          }
          if(!place.astral && graph[place.x][place.y]==adoor) {
            continue;
          }
          if(graph[place.x][place.y]==wall) {
            continue;
          }
          if(graph[place.x][place.y]==exit && !place.astral) {
            cout<<dist[temp.x][temp.y][temp.astral]+1<<endl;
            goto end;
            break;
          }
          if(dist[place.x][place.y][place.astral]==-1) {
            //cout<<"pushing shit"<<endl;
            dist[place.x][place.y][place.astral]=dist[temp.x][temp.y][temp.astral]+1;
            BFSq.push(place);
          }
        }
      }
    }

    cout<<"NIE"<<endl;

    end:;
  }
}
