#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int n, a[100][100];
int d[10000], truoc[10000];

void ShortestPath(int s){
	for (int i = 1; i <= n; i++){
		if (i != s){
			cout<<"Duong di ngan nhat tu dinh "<<s<<" toi dinh "<<i<<": ";
			if (d[i] < INT_MAX){
				int u = i;
				while (u != s){
					cout<<u<<" <- ";
					u = truoc[u];
				}
				cout<< s <<", co do dai bang "<<d[i]<<"\n";
			}
			
			else{
				cout<<"Khong co vi "<<"d["<<i<<"] = +infinity\n";
			}
			
		}
	}
}

void Bellman_Ford(int s){
	for (int v = 1; v <= n; v++){
		d[v] = a[s][v];
		truoc[v] = s;
	}
	
	d[s] = 0;
	for (int k = 1; k <= n - 1; k++){
		int change = 0;
		for (int v = 1; v <= n; v++){
			if (v != s){
				for (int u = 1; u <= n; u++){
					if (a[u][v] < INT_MAX and d[u] < INT_MAX and d[v] > d[u] + a[u][v]){
						d[v] = d[u] + a[u][v];
						truoc[v] = u;
						change = 1;
					}
				}
			}
		}
		if (!change) break;
	}
	
	ShortestPath(s);
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
			if (i == j) a[i][j] = 0;
		}
	}
	
	int s;
	cout<<"Nhap dinh bat dau duong di: ";
	cin>>s;
	
	Bellman_Ford(s);
}
