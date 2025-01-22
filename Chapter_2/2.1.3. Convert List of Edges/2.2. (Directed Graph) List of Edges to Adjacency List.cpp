#include <iostream>
#include <vector>
#include <map>
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

map<int, vector<int>> Adjacency_List(vector<Edge> list, int n, int m){
	map<int, vector<int>> result;
	for (auto i: list){
		result[i.initial].push_back(i.terminal);
	}
	return result;
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
	
	map<int, vector<int>> result = Adjacency_List(list, n, m);
	int count = 0;
	for (auto i: result){
		vector<int> temp = i.second;
		count += temp.size();
		cout<<count<<" ";
		
		for (auto j: temp){
			cout<<j<<" ";
		}
		cout<<"\n";
	}
	
}
//Note: Danh sach canh tuan theo khuon dang luu tru trong giao trinh
