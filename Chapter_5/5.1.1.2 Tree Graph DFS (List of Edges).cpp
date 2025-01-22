#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct Edge{
	int initial;
	int terminal;
};

int n, e;
map<int, vector<int>> m;
int visited[10000] = {0};

void Tree_DFS(int u, vector<Edge> &T){
	visited[u] = 1;
	for (auto i: m[u]){
		if (!visited[i]){
			T.push_back({u, i});
			Tree_DFS(i, T);
		}
	}
}

void Tree_Graph_DFS(){
	int u;
	cout<<"Nhap dinh bat dau cay khung: ";
	cin>>u;
	vector<Edge> T;
	Tree_DFS(u, T);
	if (T.size() < n - 1){
		cout<<"Do thi khong lien thong, khong ton tai cay khung";
	}
	else{
		cout<<"Cac canh cua cay khung T: ";
		for (auto i: T){
			cout<<"("<<i.initial<<", "<<i.terminal<<") ";
		}
	}
}

int main(){
	cout<<"Nhap so dinh cua do thi: ";
	cin>>n;
	cout<<"Nhap so canh cua do thi: ";
	cin>>e;	
	cout<<"Nhap danh sach canh:\n";
	for (int i = 0; i < e; i++){
		int x, y;
		cin>>x>>y;
		m[x].push_back(y);
		m[y].push_back(x);
	}
	
	Tree_Graph_DFS();
}
