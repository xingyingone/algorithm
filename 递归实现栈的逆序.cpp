#include<iostream>
#include<stack>
using namespace std;
/*����ʹ�õݹ��㷨ʹһ��ջ����*/

// ����ֻ������Ԫ�� ��������ε�����  
int getLastElement(stack<int> &s) {
	int result = s.top();
	s.pop();
	if (s.empty()) return result;    // ���ֻ��һ��Ԫ�ؼ�Ϊջ�׵�Ԫ�� ����  
	else {
		int last = getLastElement(s);   // �õ�ջ��Ԫ��  
		s.push(result);   // ��ջ��Ԫ��ѹջ  
		return last;
	}
}

void reverseStack(stack<int> &s) {
	if (s.empty()) return;    // �ݹ��������ֹ����  
	int i = getLastElement(s);   // �õ�ջ�׵����һ��Ԫ�� ʣ��Ԫ������  
	reverseStack(s);    // reverse ʣ��  
	s.push(i);  // ��i push��ȥ  

}

void cattle11_1(stack<int> s) {
	reverseStack(s);
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}
void main() {
	stack<int>istack;
	istack.push(1);
	istack.push(2);
	istack.push(3);
	cattle11_1(istack);
}