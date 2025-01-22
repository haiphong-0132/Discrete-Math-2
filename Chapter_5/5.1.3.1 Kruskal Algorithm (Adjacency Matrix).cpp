#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
    int source;
    int destination;
    int weight;
};

int n, a[100][100];
vector <Edge> edges;
vector <Edge> T;
int length = 0;
int root[10000] = {0};

bool compare(Edge a, Edge b){
	if (a.weight == b.weight){
		if (a.source == b.source){
			return a.destination < b.destination;
		}
		return a.source < b.source;
	}
	return a.weight < b.weight;
}

int find_root(int u){
	if (root[u] == 0){
		return u;
	}
	return find_root(root[u]);
}

void union_set(int u, int v){
	int a = find_root(u);
	int b = find_root(v);
	if (a != b){
		root[b] = a; 	
	}
}

void Kruskal(){
	for (auto i: edges){
		int u = find_root(i.source);
		int v = find_root(i.destination);
		
		if (u != v){
			Edge e = {i.source, i.destination, i.weight};
			union_set(i.source, i.destination);
			T.push_back(e);
			length += i.weight;
			if (T.size() == n - 1){
				break;
			}
		}
	}
	cout<<"Do dai cay khung nho nhat: "<<length<<"\n";
	cout<<"Cac canh cua cay khung do:\n";
	for (auto i: T){
		cout<<"("<<i.source<<", "<<i.destination<<") ";
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

    for (int i = 1; i <= n - 1; i++){
        for (int j = i + 1; j <= n; j++){
            if (a[i][j] != 0){
                edges.push_back({i, j, a[i][j]});
            }
        }
    }
	
	sort(edges.begin(), edges.end(), compare);
	Kruskal();
}
