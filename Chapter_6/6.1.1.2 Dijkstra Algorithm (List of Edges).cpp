#include <iostream>
#include <climits>
#include <vector>
#include <map>
using namespace std;

int n, e;
map<int, vector<pair<int, int>>> m;
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
		d[i] = INT_MAX;
		truoc[i] = s;
	}
	for (auto i: m[s]){
		d[i.first] = i.second; 
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
		for (auto i: m[u]){
			if (T[i.first]){
				if (d[i.first] > d[u] + i.second){
					d[i.first] = d[u] + i.second;
					truoc[i.first] = u;
				}
			}
		}
	}
	
	ShortestPath(s);
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
		pair<int, int> p = {y, z};
		m[x].push_back(p);
	}
	
	int s;
	cout<<"Nhap dinh bat dau duong di: ";
	cin>>s;
	
	Dijkstra(s);
}
