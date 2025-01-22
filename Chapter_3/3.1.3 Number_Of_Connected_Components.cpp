#include <iostream>
#include <vector>
using namespace std;

int n;
int a[100][100];
int visited[10000] = {0};
vector<int> v;

void DFS(int u){
	v.push_back(u);
	visited[u] = 1;
	for (int i = 1; i <= n; i++){
		if (a[u][i] == 1 and !visited[i]){
			DFS(i);
		}
	}
}

vector<vector<int>> Number_Of_Connected_Components(){
	vector<vector<int>> result;
	int count = 0;
	for (int i = 1; i <= n; i++){
		if (!visited[i]){
			count++;
			DFS(i);
			result.push_back(v);
			v.clear();
		}
	}
	return result;
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
	
	vector<vector<int>> result = Number_Of_Connected_Components();
	for (int i = 0; i < result.size(); i++){
		cout<<"Thanh phan lien thong thu "<<i + 1<<": ";
		for (auto j: result[i]){
			cout<<j<<" ";
		}
		cout<<"\n";
	}
	
}
