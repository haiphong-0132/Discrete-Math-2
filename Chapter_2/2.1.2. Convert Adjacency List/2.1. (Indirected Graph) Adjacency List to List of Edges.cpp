#include <iostream>
#include <vector>
using namespace std;

struct Edge{
	int initial;
	int terminal;
};

void Input(vector<vector<int>>& list, int n){
	int cur_x, temp;
	int prev_x = 0;
	for (int i = 1; i <= n; i++){
		cin>>cur_x;
		vector<int> Ke;
		for (int j = 1; j <= cur_x - prev_x; j++){
			cin>>temp;
			Ke.push_back(temp);
		}
		list.push_back(Ke);
		prev_x = cur_x;
	}

}

vector<Edge> List_Of_Edges(vector<vector<int>> list, int n){
	vector<Edge> G;
	for (int i = 0; i < list.size(); i++){
		for (auto j: list[i]){
			if (i + 1 < j){
				G.push_back({i + 1, j});
			}
		}
	}
	return G;
}

int main(){
	int n;
	cout<<"Nhap so dinh cua do thi: ";
	cin>>n;
	cout<<"Nhap danh sach ke: \n";
	vector<vector<int>> list;
	Input(list, n);
	
	vector<Edge> G = List_Of_Edges(list, n);

	cout<<"Danh sach canh: \n";
	cout<<n<<" "<<G.size()<<"\n";
	for (auto i: G){
		cout<<i.initial<<" "<<i.terminal<<"\n";
	}
}

//Vi du:
//So dinh: 8
//Danh sach ke: (Tuan theo khuon dang luu tru trong giao trinh)
//3 2 3 4
//5 1 3
//8 1 2 4
//11 1 3 6
//13 6 7
//17 4 5 7 8
//20 5 6 8
//22 6 7
