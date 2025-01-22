#include <iostream>
using namespace std;

int n;
int a[100][100];
int visited[10000] = {0};

void DFS(int u){
	cout<<u<<" ";
	visited[u] = 1;
	for (int i = 1; i <= n; i++){
		if (a[u][i] == 1 and !visited[i]){
			DFS(i);
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
	DFS(u);
	
}
