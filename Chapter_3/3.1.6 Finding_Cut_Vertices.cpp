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

void Find_Cut_Vertices(){
	vector<int> result;
	visited[1] = 1;
	if (BFS(2) != n - 1){
		result.push_back(1);
	}
	reInit();
	for (int i = 2; i <= n; i++){
		visited[i] = 1;
		if (BFS(1) != n - 1){
			result.push_back(i);
		}
		reInit();
	}
	if (result.size() == 0){
		cout<<"Khong co dinh tru nao";
	}
	else{
		cout<<"Cac dinh tru: ";
		for (auto i: result){
			cout<<i<<" ";
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

	Find_Cut_Vertices();
}
