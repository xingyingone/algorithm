#include<string>
#include<iostream>
#include<map>
using namespace std;
class CBook {
public:
	double m_price;
	CBook() {
		CBook(8.8);
	}
	CBook(double price) : m_price(price) { }
};
int main() {
	CBook c;
	cout << c.m_price << endl;  // ��ʱ��������������е�8.8
}