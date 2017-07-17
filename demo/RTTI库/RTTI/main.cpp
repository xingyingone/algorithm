#include <iostream>
#include <memory>
#include <ctime>
#include <vector>
#include "rtti.hpp"

using namespace rttilib;
using namespace std;

// ������������ڲ��Կ�Ķ����临�ӵļ̳й�ϵ
class A : public rttiport<A> {};
class B : public rttiport<B> {};
class C : public rttiport<C> {};
class D : public rttiport<D> {};
class E : public rttiport<E> {};
class AB : public virtual A, public virtual B, public rttiport<AB> {};
class CD : public virtual C, public virtual D, public rttiport<CD> {};
class AB_CD : public virtual AB, public virtual CD, public rttiport<AB_CD> {};
class AB_CD_E : public virtual AB, public virtual CD, public virtual E, public rttiport<AB_CD_E> {};

void test_speed() {
	std::time_t rttilib_t = 0;
	std::time_t dyncast_t = 0;
	const int times = 10;
	const int size = 80000;

	for (int a = 0; a < times; a++) {
		std::vector<std::shared_ptr<A>> vec;
		for (int i = 0; i < size; i++)
			vec.push_back(std::make_shared<AB_CD_E>());
		std::time_t t = clock();
		for (int i = 0; i < size; i++)
			rttilib::cast<AB_CD_E>(vec[i].get());
		rttilib_t += clock() - t;

		t = clock();
		for (int i = 0; i < size; i++)
			dynamic_cast<AB_CD_E*>(vec[i].get());
		dyncast_t += clock() - t;
		vec.clear();
	}
	std::cout << "avg time of rtti_library: " << rttilib_t / times << std::endl;
	std::cout << "avg time of dynamic_cast: " << dyncast_t / times << std::endl;
}


void test_useage() {
	std::cout.setf(std::ios::boolalpha);

	// ������� AB_CD_E, �ö���̳��� AB,CD,E, ���� AB �� CD �ֱ�̳��� A,B �� C,D
	AB_CD_E* obj1 = new AB_CD_E();

	// ʹ�� `isKindOf` �������ж� AB_CD_E �����Ƿ��� A ���͵Ķ���, true
	cout << "Is object of A type? " << obj1->isKindOf(rttiport<A>::type()) << endl;
	// �ṩ����һ��ʹ�÷��� rttilib::is
	cout << "Is object of A type? " << rttilib::is<A>(obj1) << endl;
	// �ж� AB_CD_E �����Ƿ��� E ���͵Ķ���, true
	cout << "Is object of E type? " << obj1->isKindOf(rttiport<E>::type()) << endl;
	// �ṩ����һ��ʹ�÷��� rttilib::is
	cout << "Is object of E type? " << rttilib::is<E>(obj1) << endl;
	delete obj1;
	cout << endl;

	A* obj2 = new AB_CD_E();
	// �ж� A ��ָ��ָ��� AB_CD_E �����Ƿ��� A ���͵Ķ���, true
	cout << "Is object of A type? " << obj2->isKindOf(rttiport<A>::type()) << endl;
	// �ж� A ��ָ��ָ��� AB_CD_E �����Ƿ��� E ���͵Ķ���, true
	cout << "Is object of E type? " << obj2->isKindOf(rttiport<E>::type()) << endl;
	delete obj2;
	cout << endl;


	AB* obj3 = new AB();
	// �ж� AB ��ָ��ָ��� AB �����Ƿ��� A ���͵Ķ���, true
	cout << "Is object of A type? " << obj3->isKindOf(rttiport<A>::type()) << endl;
	// �ж� AB ��ָ��ָ��� AB �����Ƿ��� E ���͵Ķ���, true
	cout << "Is object of E type? " << obj3->isKindOf(rttiport<E>::type()) << endl;
	delete obj3;
	cout << endl;

	CD* obj4 = new CD();
	// �ж� CD ��ָ��ָ��� CD �����Ƿ��� A ���͵Ķ���, true
	cout << "Is object of A type? " << obj4->isKindOf(rttiport<A>::type()) << endl;
	// �ж� CD ��ָ��ָ��� CD �����Ƿ��� E ���͵Ķ���, true
	cout << "Is object of E type? " << obj4->isKindOf(rttiport<E>::type()) << endl;
	delete obj4;
	cout << endl;
}
int main(int argc, char* argv[])
{
	test_speed();
	test_useage();
	return 0;
}