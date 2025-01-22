#include <iostream>
#include <vector>
using namespace std;

struct Edge{
	int initial;
	int terminal;
};

int n, a[100][100];
int visited[10000] = {0};

void Tree_DFS(int u, vector<Edge> &T){
	visited[u] = 1;
	for (int i = 1; i <= n; i++){
		if (a[u][i] and !visited[i]){
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
	cout<<"Nhap ma tran ke:\n";
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin>>a[i][j];
		}
	}
	Tree_Graph_DFS();
}
