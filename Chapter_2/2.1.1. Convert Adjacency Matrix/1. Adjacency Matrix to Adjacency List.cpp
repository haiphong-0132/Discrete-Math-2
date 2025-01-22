#include <iostream>
#include <vector>
using namespace std;

void Input(int a[100][100], int n){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin>>a[i][j];
		}
	}
}

vector<vector<int>> Adjacency_List(int a[100][100], int n){
	vector<vector<int>> result;
	result.push_back({n}); // Store the quantity of vertex.
	
	int count = 0;
	for (int i = 1; i <= n; i++){
		vector<int> Ke;
		Ke.push_back(count);
		for (int j = 1; j <= n; j++){
			if (a[i][j]){
				Ke.push_back(j);
				Ke[0]++;
			}
		}
		if (count == Ke[0]){
			Ke[0]++;
		}
		count = Ke[0];
		result.push_back(Ke);
	}
	
	return result;
}

int main(){
	int n;
	cout<<"Nhap so dinh cua do thi: ";
	cin>>n;
	int a[100][100];
	cout<<"Nhap ma tran ke: \n";
	Input(a, n);
	
	vector<vector<int>> result = Adjacency_List(a, n);
	
	cout<<"Danh sach ke: \n";
	for (auto i: result){
		for (auto j: i){
			cout<<j<<" ";
		}
		cout<<"\n";
	}
}

//Note: Danh sach ke tuan theo khuon dang luu tru trong giao trinh
