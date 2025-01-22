#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n, a[100][100];

void Euler_Path(int u){
	stack <int> st;
	vector<int> CE;
	st.push(u);
	
	while (!st.empty()){
		int s = st.top();
		int ok = 0;
		for (int i = 1; i <= n; i++){
			if (a[s][i]){
				st.push(i);
				a[s][i] = a[i][s] = 0;
				ok = 1;			
				break;
			}
		}
		
		if (!ok){
			st.pop();
			CE.push_back(s);
		}
	}
	for (int i = CE.size() - 1; i >= 0; i--){
		cout<<CE[i]<<" ";
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
	int u;
	for (int i = 1; i <= n; i++){
		int current_degree = 0;
		for (int j = 1; j <= n; j++){
			current_degree += a[i][j];
		}
		if (current_degree % 2 != 0){
			u = i;
			break;
		}
	}
	cout<<"Duong di Euler cua do thi:\n";
	Euler_Path(u);
}
