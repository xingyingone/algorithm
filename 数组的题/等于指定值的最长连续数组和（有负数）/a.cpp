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
//// 基本操作与set类型,牢记map中所有元素都是pair  
//// 对于自定义类,初学者会觉得比较函数如何构造很麻烦,这个可以参照前面的书写示例  
//// 但若设置键值为int或char类型，无须构造比较函数  
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
//		{ "童进",23,"武汉","XXX" },
//		{ "老大",23,"武汉","XXX" },
//		{ "饺子",23,"武汉","XXX" },
//		{ "王老虎",23,"武汉","XXX" },
//		{ "周润发",23,"武汉","XXX" },
//		{ "周星星",23,"武汉","XXX" }
//	};
//	pair<int, student> p1(4, s[0]);
//	pair<int, student> p2(2, s[1]);
//	pair<int, student> p3(3, s[2]);
//	pair<int, student> p4(4, s[3]);  //键值key与p1相同  
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
//	cout << "班上key值为" << i->first << "的学生有：" << a.count(4) << "名," << "   他们是:" << endl;
//	for (int_multimap k = p.first; k != p.second; k++)
//	{
//		cout << k->second.name << endl;
//	}
//	cout << "删除重复键值的同学" << endl;
//	a.erase(i);
//	cout << "现在班上总人数为：" << a.size() << ".   人员如下：" << endl;
//	for (multimap<int, student>::iterator j = a.begin(); j != a.end(); j++)
//	{
//		cout << "The name: " << j->second.name << "      " << "age: " << j->second.age << "   "
//			<< "city: " << j->second.city << "      " << "phone: " << j->second.phone << endl;
//	}
//
//	return 0;
//}