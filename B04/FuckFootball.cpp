#include <bits/stdc++.h>

using namespace std;

vector<vector<int>>graph;
vector<vector<int>>invertedGraph;
vector<int>state;
stack<int>firstOut;
vector<int>teams;
vector<int>SecondState;

void DFS (int place) {
  if(!state[place]) {
    //cout<<"checking: "<<place<<endl;
    state[place]=1;
    for(int i:graph[place]) {
      DFS(i);
    }
    //cout<<"pushing to post: "<<place<<endl;
    firstOut.push(place);
  }

  return;
}

void SecondDFS(int place,int team) {
  if(!SecondState[place]) {
    //cout<<"checking in second DFS: "<<place<<"for team: "<<team<<endl;
    SecondState[place]=1;
    teams[place]=team;
    for(int i:invertedGraph[place]) {
      SecondDFS(i,team);
    }
  }
  return;
}

int main () {

  iostream::sync_with_stdio(false);
  cin.tie(0);

  size_t Z;
  cin>>Z;
  while(Z--) {

    size_t cities,roads;
    cin>>cities>>roads;

    SecondState=vector<int>(cities,0);
    graph=vector<vector<int>> (cities);
    invertedGraph=vector<vector<int>>(cities);
    state=vector<int>(cities,0);
    firstOut=stack<int>();
    teams=vector<int>(cities);


    for (size_t i = 0; i < roads; i++) {
      size_t temp1,temp2;
      cin>>temp1>>temp2;
      graph[--temp1].push_back(--temp2);
      invertedGraph[temp2].push_back(temp1);
    }

    for (size_t i = 0; i < cities; i++) {
      if(!state[i]) {
        DFS(i);
      }
    }

    while(!firstOut.empty()) {
      int tmp=firstOut.top();
      firstOut.pop();
      if(!SecondState[tmp]) {
        SecondDFS(tmp,tmp);
      }
    }

    size_t matches;
    cin>>matches;
    for (size_t i = 0; i < matches; i++) {
      int temp1,temp2;
      cin>>temp1>>temp2;
      if(teams[--temp1]==teams[--temp2]) {
        printf("TAK\n");
      } else {
        printf("NIE\n");
      }
    }
  }
}
