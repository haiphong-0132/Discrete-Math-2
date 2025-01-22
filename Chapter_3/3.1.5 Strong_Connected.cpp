#include <iostream>
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

int Strong_Connected(){
	for (int i = 1; i <= n; i++){
		if (BFS(i) != n){
			return 0;
		}
		else{
			for (int i = 1; i <= n; i++){
				visited[i] = 0;
			}
		}
	}
	return 1;
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

	if (Strong_Connected()){
		cout<<"Do thi lien thong manh";
	}
	else{
		cout<<"Do thi khong lien thong manh";
	}
	
}
