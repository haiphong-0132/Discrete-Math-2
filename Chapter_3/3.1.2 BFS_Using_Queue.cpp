#include <iostream>
#include <queue>
using namespace std;

int n;
int a[100][100];
int visited[10000] = {0};

void BFS(int u){
	queue<int> q;
	q.push(u);
	visited[u] = 1;
	while (!q.empty()){
		int t = q.front();
		cout<<t<<" ";
		q.pop();
		for (int i = 1; i <= n; i++){
			if (a[t][i] and !visited[i]){
				q.push(i);
				visited[i] = 1;
			}
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
	cout<<"Nhap dinh bat dau: ";
	cin>>u;
	
	cout<<"Ket qua duyet dinh bat dau tu "<<u<<":\n";
	BFS(u);
	
}
