#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int a[100][100];
int visited[10000] = {0};

int BFS(int u){
	queue<int> q;
	q.push(u);
	visited[u] = 1;
	int count = 0;
	while (!q.empty()){
		int t = q.front();
		count++;
		q.pop();
		for (int i = 1; i <= n; i++){
			if (a[t][i] and !visited[i]){
				q.push(i);
				visited[i] = 1;
			}
		}			
	}
	return count;
}

void reInit(){
	for (int j = 1; j <= n; j++){
		visited[j] = 0;
	}
}

void Graph_Orientation(){
	vector<pair<int, int>> result;
	reInit();
	for (int i = 1; i <= n - 1; i++){
		for (int j = i + 1; j <= n; j++){
			if (a[i][j]){
				a[i][j] = 0;
				if (BFS(1) != n){
					result.push_back({i, j});
				}
				a[i][j] = 1;
				reInit();
			}

		}
	}
	if (result.size() == 0){
		cout<<"Do thi dinh chieu duoc";
	}
	else{
		cout<<"Do thi khong dinh chieu duoc";
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

	Graph_Orientation();
}
