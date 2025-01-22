#include <iostream>
#include <vector>
using namespace std;

struct Edge{
	int initial;
	int terminal;
};

void Input(int a[100][100], int n){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin>>a[i][j];
		}
	}
}

vector<Edge> List_of_Edges(int a[100][100], int n){
	vector<Edge> G;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (a[i][j]){
				G.push_back({i, j});
			}
		}
	}
	return G;
}


int main(){
	int n;
	cout<<"Nhap so dinh cua do thi: ";
	cin>>n;
	int a[100][100];
	cout<<"Nhap ma tran ke: \n";
	Input(a, n);
	
	vector<Edge> result = List_of_Edges(a, n);
	
	cout<<"Danh sach canh: \n";
	cout<<n<<" "<<result.size()<<"\n";
	for (auto i: result){
		cout<<i.initial<<" "<<i.terminal<<"\n";
	}
}
