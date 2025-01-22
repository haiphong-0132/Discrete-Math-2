#include <iostream>
#include <climits>
#include <map>
#include <vector>
using namespace std;

struct Edge{
    int source;
    int destination;
    int weight;
};

int n, e;
map<int, vector<pair<int, int>>> m;
vector <Edge> T;
int length = 0;
int VH[10000] = {0};  

void Prim(int s){
	int count = n - 1;
	VH[s] = 1;
	while (count--){
		int min_source_vertex = 0;
		int min_destination_vertex = 0;
		int min_value = INT_MAX;
		
		for (int i = 1; i <= n; i++){
			if (VH[i]){
				for (auto j: m[i]){
					if (!VH[j.first]){
						if (min_value > j.second){
							min_source_vertex = i;
							min_destination_vertex = j.first;
							min_value = j.second;
						}
					}
				}
			}
		}
		length += min_value;
		T.push_back({min_source_vertex, min_destination_vertex});
		VH[min_destination_vertex] = 1;

	}
	
	if (T.size() < n - 1){
		cout<<"Do thi khong lien thong";
	}
	else{
		cout<<"Do dai cay khung nho nhat: "<<length<<"\n";
		cout<<"Cac canh cua cay khung do:\n";
		for (auto i: T){
			cout<<"("<<i.source<<", "<<i.destination<<") ";
		}
	}
}

int main(){
    cout<<"Nhap so dinh cua do thi: ";
	cin>>n;
	cout<<"Nhap so canh cua do thi: ";
	cin>>e;
	cout<<"Nhap danh sach canh:\n";
	for (int i = 1; i <= e; i++){
		int x, y, z;
		cin>>x>>y>>z;
		pair<int, int> p1 = {y, z};
		m[x].push_back(p1);
		pair<int, int> p2 = {x, z};
		m[y].push_back(p2);
	}
	
	int s;
	cout<<"Nhap dinh bat dau cay khung: ";
	cin>>s;
	
	Prim(s);
    
}
