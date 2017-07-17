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
	// ��Ƿ��š�С���㡢e�Ƿ���ֹ�
	bool sign = false, decimal = false, hasE = false;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 'e' || str[i] == 'E') {
			if (i == strlen(str) - 1) return false; // e����һ��Ҫ������
			if (hasE) return false;  // ����ͬʱ��������e
			hasE = true;
		}
		else if (str[i] == '+' || str[i] == '-') {
			// �ڶ��γ���+-���ţ�����������e֮��
			if (sign && str[i - 1] != 'e' && str[i - 1] != 'E') return false;
			// ��һ�γ���+-���ţ��Ҳ������ַ�����ͷ����Ҳ���������e֮��
			if (!sign && i > 0 && str[i - 1] != 'e' && str[i - 1] != 'E') return false;
			sign = true;
		}
		else if (str[i] == '.') {
			// e���治�ܽ�С���㣬С���㲻�ܳ�������
			if (hasE || decimal) return false;
			if(i==0 || !isdigit(str[i-1])) return false;
			decimal = true;
		}
		else if (str[i] < '0' || str[i] > '9') // ���Ϸ��ַ�
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