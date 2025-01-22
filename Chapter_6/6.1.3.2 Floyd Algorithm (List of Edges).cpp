#include <iostream>
#include <climits>
#include <vector>
#include <map>
using namespace std;

int n, e;
int d[100][100], Next[100][100];
map<int, vector<pair<int, int>>> m;


void Floyd(){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (i == j){
				d[i][j] = 0;
				Next[i][j] = j;
			}
			else{
				d[i][j] = INT_MAX;
				Next[i][j] = -1;
			}
		}
	}
	
	for (auto i: m){
		int u = i.first;
		for (auto j: i.second){
			int v = j.first;
			int w = j.second;
			d[u][v] = w;
			Next[u][v] = v;
		}
	}
	
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				if (d[i][k] < INT_MAX and d[k][j] < INT_MAX){
					if (d[i][j] > d[i][k] + d[k][j]){
						d[i][j] = d[i][k] + d[k][j];
						Next[i][j] = Next[i][k];
					}
				}
			}
		}
	}
}

void Reconstruct_Path(int u, int v){
	if (Next[u][v] == -1){
		cout<<"Khong co duong di tu "<<u<<" den "<<v<<"\n";
	}
	else{
		vector<int> path;
		path.push_back(u);
		while (u != v){
			u = Next[u][v];
			path.push_back(u);
		}
		cout<<"Duong di tu "<<path[0]<<" den "<<v<<": ";
		for (int i = 0; i < path.size() - 1; i++){
			cout<<path[i]<<" -> ";
		}
		cout<<v<<", co do dai bang "<<d[path[0]][v];
		cout<<"\n";
	}
}


int main(){
	cout<<"Nhap so dinh cua do thi: ";
	cin>>n;
	cout<<"Nhap so canh cua do thi: ";
	cin>>e;
	cout<<"Nhap danh sach canh:\n";
	for (int i = 1; i <= e; i++){
		int x, y, z;
		cin>>x>>y>>z;
		m[x].push_back({y, z});
	}
	
	Floyd();
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (i != j){
				Reconstruct_Path(i, j);
			}
		}
		cout<<"\n";
	}
}
