#include<iostream>   
#define MAX 1005  
using namespace std;
int cont[MAX];   //A����0��ʾ��Ӯ��1��ʾ   
int main() {
	int n; 
	cin >> n;
	memset(cont, 0, sizeof(cont));
	for (int i = 1; i<MAX; i++) {
		if (cont[i] == 0) {     //��һ����ʼ����Ϊ�ذ�̬�����Ƴ���ʤ̬   
			cont[i + 1] = 1, cont[i + 3] = 1, cont[i + 7] = 1, cont[i + 8] = 1;
		}
	}
	while (n--) {
		int sum; cin >> sum;
		cout << cont[sum] << endl;
	}
}