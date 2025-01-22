#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

struct Edge{
	int initial;
	int terminal;
};

int n, e;
map<int, vector<int>> m;
int visited[10000] = {0};

void Tree_BFS(int u){
	vector<Edge> T;
	queue<int> q;
	q.push(u);
	visited[u] = 1;
	
	while (!q.empty()){
		int s = q.front();
		q.pop();
		for (auto i: m[s]){
			if (!visited[i]){
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
	cout<<"Nhap so canh cua do thi: ";
	cin>>e;	
	cout<<"Nhap danh sach canh:\n";
	for (int i = 0; i < e; i++){
		int x, y;
		cin>>x>>y;
		m[x].push_back(y);
		m[y].push_back(x);
	}
	int u;
	cout<<"Nhap dinh bat dau cay khung: ";
	cin>>u;
	Tree_BFS(u);
}
