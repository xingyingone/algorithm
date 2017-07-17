#include<iostream>
#include<stack>
using namespace std;
/*仅仅使用递归算法使一个栈逆序*/

// 想想只有两个元素 代码是如何迭代的  
int getLastElement(stack<int> &s) {
	int result = s.top();
	s.pop();
	if (s.empty()) return result;    // 如果只有一个元素即为栈底的元素 返回  
	else {
		int last = getLastElement(s);   // 得到栈底元素  
		s.push(result);   // 并栈顶元素压栈  
		return last;
	}
}

void reverseStack(stack<int> &s) {
	if (s.empty()) return;    // 递归结束的终止条件  
	int i = getLastElement(s);   // 得到栈底的最后一个元素 剩下元素依旧  
	reverseStack(s);    // reverse 剩下  
	s.push(i);  // 将i push进去  

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