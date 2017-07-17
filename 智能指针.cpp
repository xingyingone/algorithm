/*auto_ptr:�ᷢ������ת��,��֧��Ӧ�ü���
scoped_ptr:��֧�ָ���,ֻ���Լ����Թ���ָ��
scoped_array:֧������
shared_ptr:��õ�����ָ�룬֧�����ü��������������ȣ�����ָ��ʱ���ü�����һ�������ƵĶ�������ʱ���ü�����1�������ü���Ϊ0����������
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
}//�˳�����ʱ��p�Զ����������ü�����1

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
//��һֱ��֪��shared_ptr��auto_ptrʲô�����������������