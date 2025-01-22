#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge{
	int initial;
	int terminal;
};

int n, a[100][100];
int visited[10000] = {0};

void Tree_BFS(int u){
	vector<Edge> T;
	queue<int> q;
	q.push(u);
	visited[u] = 1;
	
	while (!q.empty()){
		int s = q.front();
		q.pop();
		for (int i = 1; i <= n; i++){
			if (a[s][i] and !visited[i]){
				q.push(i);
				T.push_back({s, i});
				visited[i] = 1;
			}
		}
	}
	
	if (T.size() < n - 1){
		cout<<"Do thi khong lien thong, khong ton tai cay khung";
	}
	else{
		cout<<"Cac canh cua cay khung: ";
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
	int u;
	cout<<"Nhap dinh bat dau cay khung: ";
	cin>>u;
	Tree_BFS(u);
}
