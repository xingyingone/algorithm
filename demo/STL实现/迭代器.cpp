#include<iostream>  
#include<algorithm>  
using namespace std;

template<typename T>
struct ListItem {  //����ڵ����ݽṹ  
	ListItem() :m_next(nullptr) {}//Ĭ�Ϲ��캯��  
	ListItem(T value, ListItem* p = nullptr) { m_value = value; m_next = p; } //���캯��  
	ListItem* Next() const { return m_next; }  //����m_nextָ��  
	T Value() const { return m_value; } //����ֵ  
	T m_value;  //�洢������  
	ListItem* m_next; //ָ����һ��ListItem��ָ��  
};

template<typename T>
class List { //�������ݽṹ  
public:
	List() :m_begin(nullptr), m_befend(nullptr), m_end(nullptr) {} //Ĭ�Ϲ��캯��  
	void Push_back(T value) {  //������β������Ԫ��  
		ListItem<T>* temp = new ListItem<T>(value, nullptr);
		if (m_begin == nullptr) {
			m_begin = m_befend = temp;
		}
		else {
			m_befend->m_next = temp;
			m_befend = temp;
		}
	}
	void Push_front(T value) {  //������ͷ������Ԫ��  
		ListItem<T>* temp = new ListItem<T>(value);
		if (m_begin == nullptr) {
			m_begin = m_befend = temp;
		}
		else {
			temp->m_next = m_begin;
			m_begin = temp;
		}

	}
	ListItem<T>* Begin() const { return m_begin; }  //��������ͷ��ָ��  
	ListItem<T>* End() const { return m_end; }      //��������β��ָ��  
	void Print(ostream& os = cout) const {        //��ӡ����Ԫ��  
		for (ListItem<T>* p = Begin(); p != End(); p = p->Next())
			os << p->Value() << " ";
		os << endl;
	}
private:
	ListItem<T>* m_begin; //ָ��Listͷ����ָ��  
	ListItem<T>* m_befend; //ָ��List���һ��Ԫ�ص�ָ��  
	ListItem<T>* m_end; //ָ��Listβ����ָ��  
	long m_size; //List�ĳ���  
};
// ListIter�̳�STL�ṩ��iterator����֤����STL����֮�淶  
template<typename T>
class ListIter :public iterator<forward_iterator_tag, T> {
public:
	ListIter(T* p = nullptr) :m_ptr(p) {}   //Ĭ�Ϲ��캯��  
	T& operator*() const { return *m_ptr; }; //dereference,������  
	T* operator->() const { return m_ptr; } //member access,��Ա����  
	ListIter& operator++() { m_ptr = m_ptr->Next(); return *this; } //ǰ��++����,��¶��ListItem��Next()  
	ListIter operator++(int) { ListIter temp = *this; ++*this; return temp; }//����++����  
	bool operator==(const ListIter& i)const { return m_ptr == i.m_ptr; }//�ж�����ListIter�Ƿ�ָ����ͬ�ĵ�ַ  
	bool operator!=(const ListIter& i)const { return m_ptr != i.m_ptr; }//�ж�����ListIter�Ƿ�ָ��ͬ�ĵ�ַ  
private:
	T* m_ptr;  //����������֮���һ����ϵ  
};

template<typename T>  //������value���ͱ���int��iter���ͱ���ListItem<int>,����дoperator==���غ���  
bool operator==(const ListItem<T>& item, const T& n) {
	return item.Value() == n;
}

//template<typename T>  //STLԴ��������˵��Ҫдoperator!=���غ�������������߲��ɹ�����Ҫд����operator==���غ���  
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

	ListIter<ListItem<int>> begin(mylist.Begin()); //��¶��ListItem  
	ListIter<ListItem<int>> end(mylist.End()); //��¶��ListItem  
	ListIter<ListItem<int>> iter;

	iter = find(begin, end, 1);//�������в���3  
	if (iter == end)
		cout << "not found" << endl;
	else
		cout << "found" << endl;     //���found  

	iter = find(begin, end, 7);//�������в���3  
	if (iter == end)
		cout << "not found" << endl;  //���not found  
	else
		cout << "found" << endl;

	system("pause");
	return 0;
}