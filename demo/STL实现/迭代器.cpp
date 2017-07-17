#include<iostream>  
#include<algorithm>  
using namespace std;

template<typename T>
struct ListItem {  //链表节点数据结构  
	ListItem() :m_next(nullptr) {}//默认构造函数  
	ListItem(T value, ListItem* p = nullptr) { m_value = value; m_next = p; } //构造函数  
	ListItem* Next() const { return m_next; }  //返回m_next指针  
	T Value() const { return m_value; } //返回值  
	T m_value;  //存储的数据  
	ListItem* m_next; //指向下一个ListItem的指针  
};

template<typename T>
class List { //链表数据结构  
public:
	List() :m_begin(nullptr), m_befend(nullptr), m_end(nullptr) {} //默认构造函数  
	void Push_back(T value) {  //从链表尾部插入元素  
		ListItem<T>* temp = new ListItem<T>(value, nullptr);
		if (m_begin == nullptr) {
			m_begin = m_befend = temp;
		}
		else {
			m_befend->m_next = temp;
			m_befend = temp;
		}
	}
	void Push_front(T value) {  //从链表头部插入元素  
		ListItem<T>* temp = new ListItem<T>(value);
		if (m_begin == nullptr) {
			m_begin = m_befend = temp;
		}
		else {
			temp->m_next = m_begin;
			m_begin = temp;
		}

	}
	ListItem<T>* Begin() const { return m_begin; }  //返回链表头部指针  
	ListItem<T>* End() const { return m_end; }      //返回链表尾部指针  
	void Print(ostream& os = cout) const {        //打印链表元素  
		for (ListItem<T>* p = Begin(); p != End(); p = p->Next())
			os << p->Value() << " ";
		os << endl;
	}
private:
	ListItem<T>* m_begin; //指向List头部的指针  
	ListItem<T>* m_befend; //指向List最后一个元素的指针  
	ListItem<T>* m_end; //指向List尾部的指针  
	long m_size; //List的长度  
};
// ListIter继承STL提供的iterator，保证符合STL所需之规范  
template<typename T>
class ListIter :public iterator<forward_iterator_tag, T> {
public:
	ListIter(T* p = nullptr) :m_ptr(p) {}   //默认构造函数  
	T& operator*() const { return *m_ptr; }; //dereference,解引用  
	T* operator->() const { return m_ptr; } //member access,成员访问  
	ListIter& operator++() { m_ptr = m_ptr->Next(); return *this; } //前置++操作,暴露了ListItem的Next()  
	ListIter operator++(int) { ListIter temp = *this; ++*this; return temp; }//后置++操作  
	bool operator==(const ListIter& i)const { return m_ptr == i.m_ptr; }//判断两个ListIter是否指向相同的地址  
	bool operator!=(const ListIter& i)const { return m_ptr != i.m_ptr; }//判断两个ListIter是否指向不同的地址  
private:
	T* m_ptr;  //保持与容器之间的一个联系  
};

template<typename T>  //本例中value的型别是int，iter的型别是ListItem<int>,必须写operator==重载函数  
bool operator==(const ListItem<T>& item, const T& n) {
	return item.Value() == n;
}

//template<typename T>  //STL源码剖析中说是要写operator!=重载函数，但是我这边不成功，需要写的是operator==重载函数  
//bool operator!=(const ListItem<T>& item, const T& n){  
//  return item.Value() != n;  
//}  

int main() {
	List<int> mylist;
	for (int i = 0; i < 5; ++i) {
		mylist.Push_front(i);
		mylist.Push_back(i + 2);
	}
	mylist.Print();

	ListIter<ListItem<int>> begin(mylist.Begin()); //暴露了ListItem  
	ListIter<ListItem<int>> end(mylist.End()); //暴露了ListItem  
	ListIter<ListItem<int>> iter;

	iter = find(begin, end, 1);//从链表中查找3  
	if (iter == end)
		cout << "not found" << endl;
	else
		cout << "found" << endl;     //输出found  

	iter = find(begin, end, 7);//从链表中查找3  
	if (iter == end)
		cout << "not found" << endl;  //输出not found  
	else
		cout << "found" << endl;

	system("pause");
	return 0;
}