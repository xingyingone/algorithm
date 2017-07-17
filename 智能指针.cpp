/*auto_ptr:会发生语义转移,不支持应用计数
scoped_ptr:不支持复制,只有自己可以管理指针
scoped_array:支持数组
shared_ptr:最好的智能指针，支持引用计数，容器操作等，复制指针时引用计数加一，当复制的对象析构时引用计数减1，当引用计数为0是析构对象
*/

#include <memory>
#include <iostream>
using namespace std;
class shared
{
private:
	shared_ptr<int> p;
public:
	shared(shared_ptr<int> _p) :p(_p) {}
	void print()
	{
		cout << "count:" << p.use_count() << "v = " << *p << endl;
	}
};

void print_func(shared_ptr<int> p)
{
	cout << "count:" << p.use_count() << "v = " << *p << endl;
}//退出函数时，p自动析构，引用计数减1

int main()
{
	shared_ptr<int> p(new int(100));
	shared s1(p);
	{
		shared s2(p);
		s2.print();//3
	}
	s1.print();//2
	*p = 20;
	print_func(p);//3
	s1.print();//2
	getchar();
}
//我一直想知道shared_ptr和auto_ptr什么区别，现在总算清楚了