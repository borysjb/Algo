#include <bits/stdc++.h>

using namespace std;

struct node {
  int x;
  int y;
  int h;
};

node tmp1,tmp2,tmp3,tmp4,tmp5,tmp6,tmp7,tmp8;



struct DONE {};
queue <node> BFSq;
int exitdist;
node stairs;
void BFS (char*** graph, int*** dist, node place, int height, int width) {
  //cout<<"got into BFS"<<endl;;
  tmp1.x=place.x+1; tmp1.y=place.y; tmp1.h=place.h;
  tmp2.x=place.x; tmp2.y=place.y+1; tmp2.h=place.h;
  tmp3.x=place.x-1; tmp3.y=place.y; tmp3.h=place.h;
  tmp4.x=place.x; tmp4.y=place.y-1; tmp4.h=place.h;
  tmp5.x=place.x+1; tmp5.y=place.y; tmp5.h=1-place.h;
  tmp6.x=place.x; tmp6.y=place.y+1; tmp6.h=1-place.h;
  tmp7.x=place.x-1; tmp7.y=place.y; tmp7.h=1-place.h;
  tmp8.x=place.x; tmp8.y=place.y-1; tmp8.h=1-place.h;
  node BFSs [4]={tmp1,tmp2,tmp3,tmp4};
  node BFSswir [8]={tmp1,tmp2,tmp3,tmp4,tmp5,tmp6,tmp7,tmp8};
  //cout<<place.x<<" "<<place.y<<" "<<place.h<<" "<<graph[place.x][place.y][place.h]<<endl;
  if(graph[place.x][place.y][place.h]=='%') {

    for(int i=0;i<8;i++) {
      node temp=BFSswir[i];
      //cout<<graph.size();
      //cout<<temp.x<<","<<temp.y<<","<<temp.h<<endl;
      if(temp.x<height&&temp.y<width&&temp.x>=0&&temp.y>=0) {
        //cout<<"checking BFSs (wir) "<<temp.x<<" "<<temp.y<<" "<<temp.h<<endl;
        if ((graph[temp.x][temp.y][temp.h]=='.'||graph[temp.x][temp.y][temp.h]=='%')&&dist[temp.x][temp.y][temp.h]==-1) {
          //cout<<"found space on "<<place.x<<","<<place.y<<","<<place.h<<endl;
          BFSq.push(temp);
          dist[temp.x][temp.y][temp.h]=dist[place.x][place.y][place.h]+1;
        }
      }
      //cout<<"end of for";
    }
  } else {
    for(int i=0;i<4;i++) {
      node temp=BFSs[i];
      //cout<<graph.size();

      if(temp.x<height&&temp.y<width&&temp.x>=0&&temp.y>=0) {
        //cout<<"checking BFSs (one floor) "<<temp.x<<" "<<temp.y<<" "<<temp.h<<endl;
        if ((graph[temp.x][temp.y][temp.h]=='.'||graph[temp.x][temp.y][temp.h]=='%')&&dist[temp.x][temp.y][temp.h]==-1) {
          //cout<<"found space on "<<place.x<<","<<place.y<<endl;
          BFSq.push(temp);
          dist[temp.x][temp.y][temp.h]=dist[place.x][place.y][place.h]+1;
        } else if (graph[temp.x][temp.y][temp.h]=='>'&&dist[temp.x][temp.y][temp.h]==-1) {
          //cout<<"found the end"<<endl;
          exitdist=dist[place.x][place.y][place.h]+1;
          throw DONE();
        }
      }
      //cout<<"end of for";
    }
  }
  //cout<<"exiting BFS"<<endl;
}
void getData (char*** tab, int*** dist, int height, int width) {
  node tempnode;
  for(int i=0;i<height;i++) {
    string tmp1;
    cin >> tmp1;
    for(int j=0;j<width;j++) {
      char tmp2;
      tmp2=tmp1[j];
      if (tmp2=='.') {
        tab[i][j][0]='.';
        tab[i][j][1]='.';
        dist[i][j][0]=-1;
        dist[i][j][1]=-1;
      } else if (tmp2=='@') {
        tempnode.x=i;
        tempnode.y=j;
        tempnode.h=0;
        BFSq.push(tempnode);
        dist[i][j][0]=0;
        dist[i][j][1]=-1;
        tab[i][j][0]='.';
        tab[i][j][1]='.';
      } else if (tmp2=='#') {
        tab[i][j][0]='#';
        dist[i][j][0]=-1;
        tab[i][j][1]='#';
        dist[i][j][1]=-1;
      } else if (tmp2=='>') {
        tab[i][j][0]='>';
        dist[i][j][0]=-1;
        tab[i][j][1]='.';
        dist[i][j][1]=-1;
        stairs.x=i;
        stairs.y=j;
        stairs.h=0;
      } else if (tmp2=='+') {
        tab[i][j][0]='.';
        dist[i][j][0]=-1;
        tab[i][j][1]='#';
        dist[i][j][1]=-1;
      } else if (tmp2=='o') {
        tab[i][j][0]='#';
        dist[i][j][0]=-1;
        tab[i][j][1]='.';
        dist[i][j][1]=-1;
      } else if (tmp2=='%') {
        tab[i][j][0]='%';
        dist[i][j][0]=-1;
        dist[i][j][1]=-1;
        tab[i][j][1]='%';
      }
    }
  }
}
int main () {
  int z;
  cin >> z;
  while  (z--) {
    int height,width;
    cin>>height>>width;
    exitdist=0;
    BFSq=queue<node> ();
    char ***graph;
    int ***dist;
    graph = new char**[height];
    dist=new int**[height];
    for(int i=0;i<height;i++) {
      graph[i] = new char*[width];
      dist[i] = new int*[width];
      for (int j=0;j<width;j++) {
        graph[i][j] = new char[2];
        dist[i][j] = new int[2];
      }
    }
    getData(graph,dist,height,width);
    while (!BFSq.empty()) {
      node temp=BFSq.front();
      BFSq.pop();
      try {
        BFS(graph,dist,temp,height,width);
      } catch (DONE) {
        cout << exitdist << endl;
        goto exit;
      }
    }
    cout<<"NIE"<<endl;
    exit:0 ;
    //cout<<exitdist<<" "<<dist[stairs.x][stairs.y][stairs.h];
  }
  return 0;
}
