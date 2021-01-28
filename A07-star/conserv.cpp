#include <bits/stdc++.h>

using namespace std;

int main () {
  int Z;
  cin>>Z;
  while (Z--) {
    int ops,depends;
    cin>>ops>>depends;
    vector <bool> opers (ops);
    vector <vector <int>> neighb (ops);
    vector <int> ins (ops, 0);
    queue <int> Q1;
    queue <int> Q2;
    int travel1=0,travel2=0;

    for(int i=0;i<ops;i++) {
      int temp;
      cin>>temp;
      opers[i]=--temp;
    }
    for(int i=0;i<depends;i++) {
      int tmp1,tmp2;
      cin>>tmp1>>tmp2;
      neighb[--tmp1].push_back(--tmp2);
      ins[tmp2]++;
    }

    for(int i=0;i<ops;i++) {
      if(ins[i]==0) {
        if(!opers[i]) {
          Q1.push(i);
        } else {
          Q2.push(i);
        }
      }
    }

    while(!Q1.empty()||!Q2.empty()) {
      if(travel1%2==0) {
        int temp=Q1.front();
        Q1.pop();
        for(int i=0;i<neighb[temp].size();i++) {
          --ins[neighb[temp][i]];
          if(ins[neighb[temp][i]]==0) {
            if(!opers[neighb[temp][i]]) {
              Q1.push(neighb[temp][i]);
            } else {
              Q2.push(neighb[temp][i]);
            }
          }
        }
      } else {

      }
    }

  }
}
