#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int n, a[100][100];
int d[10000], truoc[10000];
vector<int> T(10000, 1);

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

void Dijkstra(int s){
	d[s] = 0;
	T[s] = 0;
	for (int i = 1; i <= n; i++){
		d[i] = a[s][i];
		truoc[i] = s;
	}
	
	int times_of_iterative = n - 1;
	
	while (times_of_iterative--){
		int u;
		int min_value = INT_MAX;
		for (int i = 1; i <= n; i++){
			if (T[i]){
				if (min_value > d[i]){
					min_value = d[i];
					u = i;
				}
			}
		}
		T[u] = 0;
		for (int i = 1; i <= n; i++){
			if (T[i]){
				if (a[u][i] < INT_MAX and d[u] < INT_MAX and d[i] > d[u] + a[u][i]){
					d[i] = d[u] + a[u][i];
					truoc[i] = u;
				}
			}
		}
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
	
	Dijkstra(s);
}
