#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n, a[100][100];

void Euler_Cycle(int u){
	stack <int> st;
	vector<int> CE;
	st.push(u);
	
	while (!st.empty()){
		int s = st.top();
		int ok = 0;
		for (int i = 1; i <= n; i++){
			if (a[s][i]){
				st.push(i);
				a[s][i] = 0;
				a[i][s] = 0;
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
	cout<<"Nhap dinh bat dau chu trinh: ";
	cin>>u;
	cout<<"Chu trinh Euler xuat phat tu dinh "<<u<<":\n";
	Euler_Cycle(u);
}
