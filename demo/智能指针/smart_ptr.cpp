#include<iostream>
#include<string>
#include<memory>
using namespace std;
namespace xy {
	class test {
	private:
		char* name;
	public:
		test() { name = NULL; }
		test(const char*str ){
			name = new char[strlen(str)+1];
			strcpy_s(name,strlen(str) + 1,str);
		}
		test&operator=(const char*str) {
			if (name != str) {
				if (name != NULL)
					delete name;
				name = new char[strlen(str) + 1];
				strcpy_s(name, strlen(str) + 1, str);
			}
			return *this;
		}
		void show() {
			cout << name<<endl;
		}
		~test() {
			if (name != NULL)
				delete name;
			name = NULL;
			cout << "test 析构完成" << endl;
		}
	};
}
namespace smart_ptr {
	template <class T>
	class Smart_ptr {
	private:
		size_t *m_count;
		T* m_ptr;
		void de_count() {
			if (*m_count == 1) {
				delete m_count;
				delete m_ptr;
			}
			else
				--*m_count;
		}
	public:
		void number() {
			cout << *m_count << endl;
		}
		//构造函数
		Smart_ptr(T*p = 0){
			m_ptr = p;
			m_count = new size_t(1);
		}
		//拷贝构造函数
		Smart_ptr(const Smart_ptr&src) {
			m_ptr = src.m_ptr;
			m_count = src.m_count;
			++*m_count;
		}
		Smart_ptr&operator=(const Smart_ptr&src) {
			++*src.m_count;
			de_count();
			m_ptr = src.m_ptr;
			m_count = src.m_count;
			return *this;
		}
		~Smart_ptr() {
			de_count();
			cout << "smart_ptr 析构完成" << endl;
		}
		T*operator->() {
			if (m_ptr)
				return m_ptr;
			throw std::runtime_error("-> error");
		}
		T& operator*() {
			if (m_ptr)
				return *m_ptr;
			throw std::runtime_error(". error");
		}
	};	
}
void main() {
	using namespace xy;
	using namespace smart_ptr;
	Smart_ptr<test>test_ptr(new test("xingying"));
	test_ptr->show();
	*test_ptr = "haha";
	test_ptr->show();
	test_ptr.number();
	
	//Smart_ptr<test>test_ptr_1(new test("xingying"));
	Smart_ptr<test>test_ptr_1 = test_ptr;
	test_ptr_1->show();
	*test_ptr_1 = "haha";
	test_ptr_1->show();
	test_ptr_1.number();
}