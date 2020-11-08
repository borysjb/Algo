#include <bits/stdc++.h>

using namespace std;

struct edge {
	int dest,cost;
};

vector <int> dist;

struct number {
	int x;
};

bool operator< (number a,number b) {
	return dist[a.x]>dist[b.x];
}

int main () {
	int Z;
	cin>>Z;
	while(Z--) {
		int rooms,tunnels;
		cin>>rooms>>tunnels;
		dist = vector <int> (rooms);
		vector <vector <edge>>neighb(rooms);
		bool processed[rooms]={false};
		
		for(int i=0;i<tunnels;i++) {
			int src,dest,cost;
			cin>>src>>dest>>cost;
			neighb[--src].push_back({--dest,cost});
		}		
		for(int i=1;i<rooms;i++) {
			dist[i]=INT_MAX;
		}
		dist[0]=0;

		priority_queue <number> DijksQ;
		DijksQ.push({0});

		while (!DijksQ.empty()) {
			number tmp= DijksQ.top();
			DijksQ.pop();
			if(!processed[tmp.x]) {
				processed[tmp.x]=true;
				//cout<<"checking: "<<tmp.x<<endl;
				for(int i=0;i<neighb[tmp.x].size();i++) {
					edge temp=neighb[tmp.x][i];
					if(!processed[temp.dest]) {
						if(dist[temp.dest]>dist[tmp.x]+temp.cost) {
							dist[temp.dest]=dist[tmp.x]+temp.cost;
						}
						DijksQ.push({temp.dest});
						//cout<<"pushing: "<<temp.dest<<endl;
					}	
				}
			}
		}

		if(dist[rooms-1]!=INT_MAX) {
			cout<<dist[rooms-1]<<endl;;
		} else {
			cout<<"BRAK\n";
		}
		
	}
}
