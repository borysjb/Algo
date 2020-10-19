#include <bits/stdc++.h>

using namespace std;

vector <int> state;
vector <vector <int>> graph;
stack <int> out;
bool fuckedup;
vector <int> thisrun;


void DFS (int place) {
  if(state[place]==0) {
    state[place]=1;
    for (int i:graph[place]) {
      DFS(i);
    }
  } else if (state[place]==1) {
    fuckedup=true;
    return;
  } else {
    return;
  }
  state[place]=2;
  out.push(place);
  return;
}

int main () {
  int z;
  cin>>z;
  while (z--) {
    int ppl,con;
    cin>>ppl>>con;
    graph=vector<vector<int>> (ppl);
    state = vector<int> (ppl);
    out = stack<int> ();
    fuckedup=false;

    for (int i=0;i<con;i++) {
      int tmp1,tmp2;
      cin>>tmp1>>tmp2;
      graph[--tmp1].push_back(--tmp2);
    }

    for (int i = 0; i < ppl; i++) {
      state[i] = 0;
    }

    for (int i=0;i<ppl;i++) {
      if(state[i]==0) {
        DFS(i);
      }
      if(fuckedup) {
        break;
      }
      /*if (thisrun.size()>out.size()) {
        out.resize(thisrun.size());
        for (int y=0;y<thisrun.size();y++) {
          out[y]=thisrun[y];
        }
      }
      thisrun.resize(0);*/
    }
    if(fuckedup) {
      cout<<"CYKL"<<endl;
    } else {
      cout<<"OK"<<endl;
      while(!out.empty()) {
        cout<<out.top()+1<<" ";
        out.pop();
      }
      cout<<endl;
    }
  }


  return 0;
}
