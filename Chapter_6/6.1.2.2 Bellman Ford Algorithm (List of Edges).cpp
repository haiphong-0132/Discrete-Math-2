#include <iostream>
#include <climits>
#include <vector>
#include <map>
using namespace std;

int n, e;
int d[10000], truoc[10000];
map<int, vector<pair<int, int>>> m;
map<int, vector<pair<int, int>>> in;

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
		d[v] = INT_MAX;
		truoc[v] = s;
	}
	
	for (auto i: m[s]){
		d[i.first] = i.second;
	}
	
	d[s] = 0;
	for (int k = 1; k <= n - 1; k++){
		int change = 0;
		for (int v = 1; v <= n; v++){
			if (v != s){
				for (auto u: in[v]){
					if (d[u.first] < INT_MAX and d[v] > d[u.first] + u.second){
						d[v] = d[u.first] + u.second;
						truoc[v] = u.first;
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
	cout<<"Nhap so canh cua do thi: ";
	cin>>e;
	cout<<"Nhap danh sach canh:\n";
	for (int i = 1; i <= e; i++){
		int x, y, z;
		cin>>x>>y>>z;
		m[x].push_back({y, z});
		in[y].push_back({x, z});
	}
	
	int s;
	cout<<"Nhap dinh bat dau duong di: ";
	cin>>s;
	
	Bellman_Ford(s);
}
