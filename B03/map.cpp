#include <bits/stdc++.h>

using namespace std;

int main() {
  size_t Z;
  cin>>Z;
  while (Z--) {

    size_t cities;
    cin>>cities;
    string names [cities];
    for (size_t i = 0; i < cities; i++) {
      cin>>names[i];
    }
    unsigned int graph [cities][cities];
    for(size_t i=0;i < cities;i++) {
      for (size_t j = 0; j < cities; j++) {
        if(i==j) {
          graph[i][j]=0;
        } else {
          graph[i][j]=2000000001;
        }
      }
    }
    size_t highways;
    cin>>highways;
    string city1,city2;
    int dist;
    for (size_t i = 0; i < highways; i++) {
      cin>>city1>>city2>>dist;
      size_t citynum1=0,citynum2=0;
      for (size_t j = 0; j < cities; j++) {
        if(city1==names[j]) {
          citynum1=j;
        }
        if(city2==names[j]) {
          citynum2=j;
        }
      }
      //cout<<"city 1 is number "<<citynum1<<" and city 2 is number "<<citynum2<<endl;
      graph[citynum1][citynum2]=dist;
      graph[citynum2][citynum1]=dist;
    }

    for(size_t k=0;k<cities;k++) {
      for(size_t i=0;i<cities;i++) {
        for (size_t j = 0; j < cities; j++) {
          if(graph[i][k]+graph[k][j]<graph[i][j]) {
            graph[i][j]=graph[i][k]+graph[k][j];
          }
        }
      }
    }

    printf("%12s","");
    for (size_t i = 0; i < cities; i++) {
      printf("%12s",names[i].c_str());
    }
    cout<<endl;
    for (size_t i = 0; i < cities; i++) {
      printf("%12s",names[i].c_str());
      for (size_t j = 0; j < cities; j++) {
        printf("%12d", graph[i][j]);
      }
      cout<<endl;
    }
  }
}
