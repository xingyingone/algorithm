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
	cout << c.m_price << endl;  // 此时并不会输出理想中的8.8
}