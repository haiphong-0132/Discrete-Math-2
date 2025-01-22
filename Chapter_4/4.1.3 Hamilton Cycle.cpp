#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n, a[100][100];
int u;
int visited[10000] = {0};
int X[10000];

void Result(){
	for (int i = 1; i <= n + 1; i++){
		cout<<X[i]<<" ";
	}
	cout<<"\n";
}

void Hamilton(int k){
	int y = X[k - 1];
	for (int i = 1; i <= n; i++){
		if (a[y][i]){
			if (k == n + 1 and i == u){
				X[k] = u;
				Result();
			}
			else if (!visited[i]){
				X[k] = i;
				visited[i] = 1;
				Hamilton(k + 1);
				visited[i] = 0;
			}
		}
	}
}

void Hamilton_Cycle(int u){
	X[1] = u;
	visited[u] = 1;
	
	Hamilton(2);
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

	cout<<"Nhap dinh bat dau chu trinh Hamilton: ";
	cin>>u;
	cout<<"Chu trinh Hamilton bat dau tai dinh "<< u <<":\n";
	Hamilton_Cycle(u);
}
