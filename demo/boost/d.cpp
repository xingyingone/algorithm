#include<iostream>
#include<vector>
#include <boost/function.hpp>
#include <boost/bind.hpp>
using namespace std;
class Compare
{
public:
	typedef boost::function<void()> ThreadFunc;
	ThreadFunc fun;
	Compare(const ThreadFunc&T) {
		fun = T;
		fun();
	}
};
void add(int a, int b) {
	cout << a + b << endl;
}
void add1() {
	cout <<"╪ссм"<< endl;
}
void main() {
	Compare a(add1);
	boost::function<void(int)>fp = boost::bind(add,1,_1);
	fp(22);
	boost::bind(add, 3, 4)();
}
//void fun(int x, int y) {
//	cout << x << ", " << y << endl;
//}
//void main() {
//	boost::bind(&fun, 3, 4)();
//}