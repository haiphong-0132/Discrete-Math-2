#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int n, a[100][100];
int d[100][100], Next[100][100];

void Floyd(){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			d[i][j] = a[i][j];
			if (a[i][j] != INT_MAX){
				Next[i][j] = j;
			}
			else{
				Next[i][j] = -1;
			}
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
	cout<<"Nhap ma tran ke:\n";
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin>>a[i][j];
			if (a[i][j] == 0){
				a[i][j] = INT_MAX;
			}
		}
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
