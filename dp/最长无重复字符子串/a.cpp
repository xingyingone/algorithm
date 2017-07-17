//�ҵ��ַ�������ظ��ַ��Ӵ�
//sp.get()[i] ���i��Ԫ�ع������ظ��ַ������������� 
//imap[str[i]]  ��һ�γ���str[i]��λ��
#include<iostream>
#include<map>
#include<memory>
#include<string>
using namespace std;
int maxlen(string str) {
	if (str.size() == 0)
		return 0;
	int n = str.size(), res=1;
	map<char, int>imap;
	shared_ptr<int> sp = shared_ptr<int>(new int[n]);
	sp.get()[0] = 0;
	imap[str[0]] = 0;
	for (int i = 1; i < n; ++i) {
		if (imap.count(str[i]) == 0) {
			imap[str[i]] = i;
			sp.get()[i] = sp.get()[i - 1];
		}
		else if (imap.count(str[i])!=0) {
			if (sp.get()[i - 1] <= imap[str[i]]) {
				sp.get()[i] = imap[str[i]] + 1;
				imap[str[i]] = i;
			}
			else if (sp.get()[i - 1] > imap[str[i]]) {
				sp.get()[i] = sp.get()[i - 1];
				imap[str[i]] = i;
			}
		}
		res = res > i - sp.get()[i] + 1 ? res : i - sp.get()[i] + 1;
	}
	return res;
}
int main() {
	string str = "aaaaa";
	cout << maxlen(str);
}