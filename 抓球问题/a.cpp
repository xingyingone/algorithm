#include<iostream>   
#define MAX 1005  
using namespace std;
int cont[MAX];   //A输用0表示，赢用1表示   
int main() {
	int n; 
	cin >> n;
	memset(cont, 0, sizeof(cont));
	for (int i = 1; i<MAX; i++) {
		if (cont[i] == 0) {     //从一个球开始，若为必败态，可推出必胜态   
			cont[i + 1] = 1, cont[i + 3] = 1, cont[i + 7] = 1, cont[i + 8] = 1;
		}
	}
	while (n--) {
		int sum; cin >> sum;
		cout << cont[sum] << endl;
	}
}