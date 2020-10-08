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
    vector <vector <int>> graph (ppl);
    for(int i=0;i<con;i++)
    {
      int tmp1,tmp2;
      cin>>tmp1>>tmp2;
      graph[--tmp1].push_back(--tmp2);
      graph[tmp2].push_back(tmp1);
    }
    for(int i=0;i<ppl;i++)
    {
      cout<<"friends of "<<i<<": ";
      for(int j=0;j<graph[i].size();j++)
      {
        cout<<graph[i][j]<<", ";
      }
      cout<<endl;
    }
    int myNum;
    queue <int> BFS;
    BFS.push(--myNum);
    cout<<myNum;
    int dist [ppl];
    for(int i=0;i<ppl;i++)
    {
      dist[ppl]=-1;
    }
    dist[myNum]=0;
    cout<<endl;
    for(int i=0;i<ppl;i++)
    {
      cout<<dist[ppl]<<", ";
    }
    cout<<endl;
    while (!BFS.empty())
    {
      int temp=BFS.front();
      BFS.pop();
      for(int i:graph[temp])
      {
        cout<<i<<endl;
        if (dist[i]==-1)
        {
          cout <<dist[temp]<<endl;
          dist[i]=dist[temp]+1;
          BFS.push(i);
          cout<<BFS.front();
        }
      }

    }
    cout<<"znajomi numeru "<<myNum+1<<':'<<endl;
    for (int y=0;y<ppl;y++)
    {
      cout<<y+1<<", "<<dist[y]<<endl;

      if(dist[y]>0)
      {
        cout<<y+1<<": "<<dist[y]<<endl;
      }
    }
  }
  return 0;
}
