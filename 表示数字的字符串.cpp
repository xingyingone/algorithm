#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
//bool isnum(char* string, bool flag, bool flag2) {
//	if (*string == '\0')
//		return true;
//	else if (isdigit(*string))
//		return isnum(string + 1, flag, flag2);
//	else if ((*string == 'e' || *string == 'E') && flag2 == false) {
//		flag = true, flag2 = true;
//		if ((*(string + 1) == '+' || *(string + 1) == '-') && isdigit(*(string + 2)))
//			return isnum(string + 3, flag, flag2);
//		else if (isdigit(*(string + 1)))
//			return isnum(string + 2, flag, flag2);
//		else
//			return false;
//	}
//	else if (*string == '.') {
//		if ( flag == false && isdigit(*(string + 1)) )
//			return isnum(string + 2, true, flag2);
//		else
//			return false;
//	}
//	return false;
//}
//bool isNumeric(char* string)
//{
//	bool flag = false,flag2=false;
//	if (string == NULL)
//		return false;
//	else if ( (*string == '+' || *string == '-') && isdigit(*(string+1)) )
//		return isnum(string + 2, flag, flag2);
//	else if (isdigit(*string))
//		return isnum(string, flag, flag2);
//	return false;
//}
bool isNumeric(char* str) {
	// 标记符号、小数点、e是否出现过
	bool sign = false, decimal = false, hasE = false;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 'e' || str[i] == 'E') {
			if (i == strlen(str) - 1) return false; // e后面一定要接数字
			if (hasE) return false;  // 不能同时存在两个e
			hasE = true;
		}
		else if (str[i] == '+' || str[i] == '-') {
			// 第二次出现+-符号，则必须紧接在e之后
			if (sign && str[i - 1] != 'e' && str[i - 1] != 'E') return false;
			// 第一次出现+-符号，且不是在字符串开头，则也必须紧接在e之后
			if (!sign && i > 0 && str[i - 1] != 'e' && str[i - 1] != 'E') return false;
			sign = true;
		}
		else if (str[i] == '.') {
			// e后面不能接小数点，小数点不能出现两次
			if (hasE || decimal) return false;
			if(i==0 || !isdigit(str[i-1])) return false;
			decimal = true;
		}
		else if (str[i] < '0' || str[i] > '9') // 不合法字符
			return false;
	}
	return true;
}

void main() {
	string str = "-.23";
	if (isNumeric(&str[0]))
		cout << 1;
	else
		cout << 0;
}