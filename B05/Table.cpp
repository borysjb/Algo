#include <bits/stdc++.h>

using namespace std;

struct coordinate {
  int x;
  int y;
};

struct pole {
  bool state;
  int rank;
  coordinate parent;
  coordinate place;
};

vector<vector<pole>> table;
stack <coordinate> rats;
stack <int> pieces;
int piecesRN;
int side;

pole find (pole x) {
  if(x.place.x==x.parent.x&&x.place.y==x.parent.y) {
    return x;
  } else {
    pole top = find(table[x.parent.x][x.parent.y]);
    return top;
  }
}

void uniting (pole x, pole y) {
  if(table[x.place.x][x.place.y].state&&table[y.place.x][y.place.y].state){
  cout<<"uniting"<<endl;
  pole xtop = find(x);
  pole ytop = find(y);
cout<<"found"<<endl;
  cout<<"parent of x: "<<xtop.place.x<<"/"<<xtop.place.y<<" of y: "<<ytop.place.x<<"/"<<ytop.place.y<<endl;
  if (ytop.place.x==xtop.place.x&&ytop.place.y==xtop.place.y)
    return;
  else {
    if (table[ytop.place.x][ytop.place.y].rank > table[xtop.place.x][xtop.place.y].rank) {
      table[xtop.place.x][xtop.place.y].parent.y=table[ytop.place.x][ytop.place.y].place.y;
      table[xtop.place.x][xtop.place.y].parent.x=table[ytop.place.x][ytop.place.y].place.x;
    } else if (table[ytop.place.x][ytop.place.y].rank < table[xtop.place.x][xtop.place.y].rank) {
      table[ytop.place.x][ytop.place.y].parent.x=table[xtop.place.x][xtop.place.y].place.x;
      table[ytop.place.x][ytop.place.y].parent.y=table[xtop.place.x][xtop.place.y].place.y;
    } else {
      table[xtop.place.x][xtop.place.y].parent.x=table[ytop.place.x][ytop.place.y].place.x;
      table[xtop.place.x][xtop.place.y].parent.y=table[ytop.place.x][ytop.place.y].place.y;
      table[ytop.place.x][ytop.place.y].rank++;
    }
    --piecesRN;
  }
  return;
}
}

void add (pole x) {
  cout<<"adding "<<x.place.x<<" "<<x.place.y<<endl;
  table[x.place.x][x.place.y].state=true;
  piecesRN++;
  if(x.place.x-1 >= 0) {
    cout<<"in if1"<<endl;
    uniting(x,table[x.place.x-1][x.place.y]);
  }
  if(x.place.x+1 < side) {
    cout<<"in if2"<<endl;;
    uniting(x,table[x.place.x+1][x.place.y]);
  }
  if(x.place.y-1 >= 0) {
    cout<<"in if3"<<endl;
    uniting(x,table[x.place.x][x.place.y-1]);
  }
  if(x.place.y+1 < side) {
    cout<<"in if4"<<endl;
    uniting(x,table[x.place.x][x.place.y+1]);
  }
  cout<<"pushing "<<piecesRN<<endl;
  pieces.push(piecesRN);
  return;
}

int main () {
  int Z;
  cin>>Z;
  while (Z--) {


    cin>>side;
    table = vector<vector<pole>>(side);
    rats = stack <coordinate>();
    pieces = stack<int>();
    pieces.push(0);
    piecesRN=0;
    for (int i = 0; i < side; i++) {
      for (int j = 0; j < side; j++) {
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;
        rats.push({--tmp1,--tmp2});
        table[i].push_back({false, 0, {i,j}, {i,j}});
      }
    }

    for (int i = 0; i < side*side; i++) {
      coordinate tmp = rats.top();
      rats.pop();
      add(table[tmp.x][tmp.y]);
    }

    while(!pieces.empty()) {
      pieces.pop();
      cout<<pieces.top()<<" ";
    }
    cout<<endl;
  }
  return 0;
}
