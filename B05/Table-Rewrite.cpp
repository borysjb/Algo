#include <bits/stdc++.h>

using namespace std;

//zmiana planow, robimy jednowymiarową tablice xD

vector <int> parent;
vector <int> ranga;
vector <vector <int>> graph;
int side;
stack <int> rats;
vector <bool> state;
int piecesnumber;
stack <int> pieces;

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
  piecesnumber--;
}


void add (int x) {
  //cout<<"adding\n";
  piecesnumber++;
  state[x]=true;
  for(int i:graph[x]) {
    if(state[i]) {
      //cout<<"uniting\n";
      unite(x,i);
    }
  }
  pieces.push(piecesnumber);
}

int main () {

  ios_base::sync_with_stdio(false);
  cin.tie(0);

 int Z;
 cin>>Z;
 while (Z--) {

   scanf("%d",&side);

   parent = vector<int>(side*side);
   ranga = vector<int>(side*side);
   graph = vector<vector<int>>(side*side);
   state = vector<bool>(side*side);
   rats = stack<int>();
   piecesnumber=0;
   pieces=stack<int>();
   for (int i = 0; i < side*side; i++) {
     parent[i]=i;
     ranga[i]=0;
     state[i]=false;
   }

   for (int i = 0; i < side; i++) {
     for (int j = 0; j < side; j++) {
       if(i>0) {
         graph[i*side+j].push_back((i-1)*side+j);
       }
       if(i<side-1){
          graph[i*side+j].push_back((i+1)*side+j);
       }
       if(j>0) {
         graph[i*side+j].push_back(i*side+j-1);
       }
       if(j<side-1) {
         graph[i*side+j].push_back(i*side+j+1);
       }
     }
   }

   for (int i = 0; i < side*side; i++) {
     int tmp1,tmp2;
     scanf("%d %d",&tmp1,&tmp2);
     rats.push((--tmp1)*side+(--tmp2));
     //cout<<"pushing "<<(tmp1)*side+(tmp2)<<"\n";
   }

   while(!rats.empty()) {
     int tmp=rats.top();
     rats.pop();
     add(tmp);
   }

   pieces.pop();
   while(!pieces.empty()) {
     cout<<pieces.top()<<" ";
     pieces.pop();
   }
   cout<<"0\n";
 }
 return 0;
}
