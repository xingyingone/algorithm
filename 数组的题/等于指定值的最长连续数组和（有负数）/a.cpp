#include<iostream>
#include<iterator>
#include<algorithm>
#include<map>
using namespace std;
int maxint(int *a, int n, int m) {
	multimap<int, int>imap;
	imap.insert(make_pair(0,-1));
	//imap[0] = -1;
	int i = 0, sum = 0, res = -1, res1 = -1, res2 = -1;
	for (; i <= n - 1; ++i) {
		sum += a[i];
		imap.insert(make_pair(sum,i));
	}
	typedef multimap<int, int>::iterator int_multimap;
	multimap<int, int>::reverse_iterator it = imap.rbegin();	
	int cur = n - 1;
	while (it != imap.rend()) {
		if (imap.count(m - it->first))
		{
			pair<int_multimap, int_multimap> p = imap.equal_range(m - it->first);
			int_multimap iter = p.first;
			res1 = cur - iter->second;
			res = max(res1, res);
			}	 
		++it;
		--cur;
		}				
	return res;
}
void main() {
	int a[] = { 1,1,-1,1,-1,1,1,1,1,1 };
	int n = sizeof(a) / sizeof(int);
	cout << maxint(a, n, 5);
}

//#include <map>  
//#include <string>  
//#include <iostream>  
//
//// ����������set����,�μ�map������Ԫ�ض���pair  
//// �����Զ�����,��ѧ�߻���ñȽϺ�����ι�����鷳,������Բ���ǰ�����дʾ��  
//// �������ü�ֵΪint��char���ͣ����빹��ȽϺ���  
//
//struct student {
//	char* name;
//	int age;
//	char* city;
//	char* phone;
//};
//
//int main()
//{
//	using namespace std;
//
//	student s[] = {
//		{ "ͯ��",23,"�人","XXX" },
//		{ "�ϴ�",23,"�人","XXX" },
//		{ "����",23,"�人","XXX" },
//		{ "���ϻ�",23,"�人","XXX" },
//		{ "����",23,"�人","XXX" },
//		{ "������",23,"�人","XXX" }
//	};
//	pair<int, student> p1(4, s[0]);
//	pair<int, student> p2(2, s[1]);
//	pair<int, student> p3(3, s[2]);
//	pair<int, student> p4(4, s[3]);  //��ֵkey��p1��ͬ  
//	pair<int, student> p5(5, s[4]);
//	pair<int, student> p6(6, s[5]);
//	multimap<int, student> a;
//	a.insert(p1);
//	a.insert(p2);
//	a.insert(p3);
//	a.insert(p4);
//	a.insert(p5);
//	a.insert(p6);
//	typedef multimap<int, student>::iterator int_multimap;
//	pair<int_multimap, int_multimap> p = a.equal_range(4);
//	int_multimap i = a.find(4);
//	cout << "����keyֵΪ" << i->first << "��ѧ���У�" << a.count(4) << "��," << "   ������:" << endl;
//	for (int_multimap k = p.first; k != p.second; k++)
//	{
//		cout << k->second.name << endl;
//	}
//	cout << "ɾ���ظ���ֵ��ͬѧ" << endl;
//	a.erase(i);
//	cout << "���ڰ���������Ϊ��" << a.size() << ".   ��Ա���£�" << endl;
//	for (multimap<int, student>::iterator j = a.begin(); j != a.end(); j++)
//	{
//		cout << "The name: " << j->second.name << "      " << "age: " << j->second.age << "   "
//			<< "city: " << j->second.city << "      " << "phone: " << j->second.phone << endl;
//	}
//
//	return 0;
//}