#include <iostream>
#include <stack>
using namespace std;

int n;
int a[100][100];
int visited[10000] = {0};

void DFS(int u){
	stack<int> st;
	st.push(u);
	cout<<u<<" ";
	visited[u] = 1;
	while (!st.empty()){
		int t = st.top();
		st.pop();
		for (int i = 1; i <= n; i++){
			if (a[t][i] and !visited[i]){
				st.push(t);
				st.push(i);
				cout<<i<<" ";
				visited[i] = 1;
				break;
			}
		}
	}
}

int main(){
	cout<<"Nhap so dinh cua do thi: ";
	cin>>n;
	cout<<"Nhap ma tran ke:\n ";
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
