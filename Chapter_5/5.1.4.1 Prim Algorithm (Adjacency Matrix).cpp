#include <iostream>
#include <climits>
#include <vector>
using namespace std;

struct Edge{
    int source;
    int destination;
    int weight;
};

int n, a[100][100];
vector <Edge> T;
int length = 0;
int VH[10000] = {0};  

void Prim(int s){
	int count = n - 1;
	VH[s] = 1;
	a[0][0] = INT_MAX;
	while (count--){
		int min_source_vertex = 0;
		int min_destination_vertex = 0;
		
		for (int i = 1; i <= n; i++){
			if (VH[i]){
				for (int j = 1; j <= n; j++){
					if (a[i][j] and !VH[j]){
						if (a[min_source_vertex][min_destination_vertex] > a[i][j]){
							min_source_vertex = i;
							min_destination_vertex = j;
						}
					}
				}
			}
		}
		length += a[min_source_vertex][min_destination_vertex];
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
	cout<<"Nhap ma tran ke:\n";
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin>>a[i][j];
		}
	}
	
	int s;
	cout<<"Nhap dinh bat dau cay khung: ";
	cin>>s;
	
	Prim(s);
    
}
