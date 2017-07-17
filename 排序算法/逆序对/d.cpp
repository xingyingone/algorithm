#include "iostream"
#include "string"
#include "vector"
using namespace std;
int fun(vector<int>& data, int start, int end) {
	static int res = 0;
	if (start == end || start + 1 == end) {
		if (data[start] > data[end]) {
			res++;
			swap(data[start], data[end]);
		}
		return 0;
	}
	fun(data, start, (start + end) / 2);
	fun(data, (start + end) / 2 + 1, end);
	int ls = start, ln = (start + end) / 2, rs = (start + end) / 2 + 1, rn = end;
	vector<int> temp;
	while (ls <= ln && rs <= rn) {
		if (data[ls]<data[rs]) {
			temp.push_back(data[ls]);
			++ls;
		}
		else if (data[ls]>data[rs]) {
			temp.push_back(data[rs]);
			res += ln - ls + 1;
			++rs;
		}
	}
	while (ls <= ln)
		temp.push_back(data[ls++]);

	while (rs <= rn)
		temp.push_back(data[rs++]);
	int i = 0;
	for (vector<int>::iterator it = temp.begin(); it != temp.end(); ++it)
		data[start + i++] = *it;
	return res % 1000000007;
}
int InversePairs_1(vector<int> data) {
	int n = data.size();
	if (n <= 1)
		return 0;
	return fun(data, 0, n - 1);
}
int getnum(vector<int>& data, int *copy, int start, int end) {
	if (start == end) {
		//copy[start] = data[start];
		return 0;
	}
	int res = 0;
	int mid = (start + end) / 2;
	int leftnum = getnum(data, copy, start, mid);
	int rightnum = getnum(data, copy, mid + 1, end);
	int i = mid;
	int j = end;
	int pos = end;
	while (i >= start && j >= mid + 1) {
		if (data[i]>data[j]) {
			res += j - mid;
			copy[pos--] = data[i--];
			if (res >= 1000000007)
				res %= 1000000007;
		}
		else if (data[i]<data[j]) {
			copy[pos--] = data[j--];
		}
	}
	while (i >= start) {
		copy[pos--] = data[i--];
	}
	while (j >= mid + 1) {
		copy[pos--] = data[j--];
	}
	for (int i = start; i <= end; ++i)
		data[i] = copy[i];
	return (res + leftnum + rightnum) % 1000000007;
}
int InversePairs_2(vector<int> data) {
	if (data.size() == 0 || data.size() == 1)
		return data.size();
	int n = data.size();
	int *copy = new int[n];
	int res = getnum(data, copy, 0, data.size() - 1);
	delete[]copy;
	return res;
}
void main()
{
	int a[] = { 26819,20714,95790,59566,59801,74575,55921,11824,21360,60903,32601,77290,41967,16961,24908,58967,77548,68095,57695,52833,98112,4569,64913,44157,21769,28303,53555,37085,11466,20822,12,38285,57888,12154,97851,17689,86729,70124,45866,24441,31027,78467,1732,89347,11781,26640,48314,89329,11088,6009,58514,9200,26931,23427,69710,65052,68082,23265,18489,79549,60439,18501,17834,18328,30656,32038,52369,33737,2162,98235,74531,49542,93055,76263,38889,4836,19255,3555,10517,46695,9565,69032,55896,52848,8811,25606,17900,76894,65223,36390,56443,25662,71243,90629,60342,18251,22667,12712,68341,41182,27299,42872,7076,20354,35487,62317,41542,71094,65872,68412,17790,91789,53796,90038,60989,78959,15644,78890,55853,97219,31632,28648,39233,19227,19278,99576,37479,58297,28640,22172,15831,72291,81396,39259,92646,16883,17928,50540,87977,153,35304,22119,91942,89100,12157,52932,84412,44153,48174,40265,41372,96158,85266,96958,15385,20896,12886,69216,95545,41526,7740,27729,30169,89136,66988,39167,6019,1269,89708,10349,1422 };
	int n = sizeof(a) / sizeof(int);
	vector<int> data_1(a, a + n);
	vector<int> data_2(a, a + n);
	if (InversePairs_1(data_1) == InversePairs_2(data_2))
		cout << 1;
	else
		cout << 0;
}