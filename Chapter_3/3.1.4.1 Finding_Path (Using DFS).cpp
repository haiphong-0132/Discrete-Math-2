#include <iostream>
using namespace std;

int n;
int a[100][100];
int visited[10000] = {0};
int truoc[10000] = {0};

void DFS(int u){
	visited[u] = 1;
	for (int i = 1; i <= n; i++){
		if (a[u][i] and !visited[i]){
			truoc[i] = u;
			DFS(i);
			
		}
	}
}

void Path(int s, int t){
	DFS(s);
	if (truoc[t] == 0){
		cout<<"Khong co duong di tu "<<s<<" toi "<<t;
	}
	else{
		cout<<t<<" <- ";
		int u = truoc[t];
		while (u != s){
			cout<<u<<" <- ";
			u = truoc[u];
		}
		cout<<s;
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
	
	int s, t;
	cout<<"Nhap dinh bat dau va ket thuc: ";
	cin>>s>>t;

	Path(s, t);
	
}
