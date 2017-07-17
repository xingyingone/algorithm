#include <iostream>
using namespace std;

class BirdType//鸟类
{};

class InsectType//昆虫类
{};

class BeastType//走兽类
{};

template <typename A>
class Traits
{};

template <>
class Traits<BirdType>
{
public:
	void fly()
	{
		cout << "Birder fly " << endl;
	}
};

template <>
class Traits<InsectType>
{
public:
	void fly()
	{
		cout << "Insect fly " << endl;
	}
};

template <>
class Traits<BeastType>
{
public:
	void fly()
	{
		cout << "Beast can't fly " << endl;
	}
};

template <typename T>
class Animal
{
public:
	void Fly()
	{
		Traits<T>().fly();
	};
};

namespace Computer {
#include<iostream>
	template <typename T>
	struct TraitsHelper {
		typedef T ret_type;
		typedef T par_type;
	};
	template <>
	struct TraitsHelper<int> {
		typedef int ret_type;
		typedef int par_type;
	};
	template <>
	struct TraitsHelper<float> {
		typedef int ret_type;
		typedef float par_type;
	};
	template <typename T>
	class Test {
	public:
		typename TraitsHelper<T>::ret_type Compute(typename TraitsHelper<T>::par_type d)
		{
			return d;
		}
	private:
		T mData;
	};
	void main()
	{
		Test<float>a;
		float b = 1.0;
		std::cout << typeid(a.Compute(b)).name();
	}
}

void main()
{
	Animal<BirdType> brider;
	brider.Fly();

	Animal<InsectType> insect;
	insect.Fly();

	Animal<BeastType> beast;
	beast.Fly();
}