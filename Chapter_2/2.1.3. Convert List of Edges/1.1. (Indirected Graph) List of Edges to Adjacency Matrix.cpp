#include <iostream>
#include <vector>
using namespace std;

struct Edge{
	int initial;
	int terminal;
};

void Input(vector<Edge>& list, int m){
	for (int i = 0; i < m; i++){
		int x, y;
		cin>>x>>y;
		list.push_back({x, y});
	}
}

void Adjacency_Matrix(int matrix[100][100], vector<Edge> list, int n, int m){
	for (auto i: list){
		matrix[i.initial][i.terminal] = 1;
		matrix[i.terminal][i.initial] = 1;
	}
	
	cout<<"Ma tran ke: \n";
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int main(){
	int n, m;
	cout<<"Nhap so dinh cua do thi: ";
	cin>>n;
	cout<<"Nhap so canh cua do thi: ";
	cin>>m;
	cout<<"Nhap danh sach canh: \n";
	vector<Edge> list;
	Input(list, m);
	
	int matrix[100][100] = {0};
	Adjacency_Matrix(matrix, list, n, m);

}
