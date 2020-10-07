#include <bits/stdc++.h>

using namespace std;

int main()
{
  int z;
  cin>>z;
  while (z--)
  {
    int ppl, con;
    cin>>ppl>>con;
    cout<<ppl<<" "<<con<<endl;
    vector <vector <int>> graph (ppl);
    for(int i=0;i<con;i++)
    {
      int tmp1,tmp2;
      cin>>tmp1>>tmp2;
      graph[--tmp1].push_back(--tmp2);
      graph[--tmp2].push_back(--tmp1);
    }
    for (int i=0;i<ppl;i++)
    {
      cout<<"friends of "<<i<<": ";
      for(int j=0;j<graph[i].size();j++)
      {
        cout<<graph[i][j]<<", ";
      }
      cout<<endl;
    }
  }
  return 0;
}
