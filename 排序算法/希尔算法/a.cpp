//ϣ������
#include <iostream>
using namespace std;

/*
 * ϣ������
 *
 * ����˵����
 *     a -- �����������
 *     n -- ����ĳ���
 */
void shellSort1(int* a, int n)
{
	int i, j, gap;
	int t;
	for (gap = n / 2; gap > 0; gap /= 2) {
		for (i = 0; i <= gap; ++i) {
			for (j = i + gap; j < n; j+=gap) {
				t = j;
				while (t-gap>=0 && a[t] < a[t - gap]) {
					swap(a[t], a[t - gap]);
					t -= gap;
				}
			}
		}
	}
}

/*
 * ��ϣ�������еĵ������������
 *
 * ����˵����
 *     a -- �����������
 *     n -- �����ܵĳ���
 *     i -- �����ʼλ��
 *     gap -- ��Ĳ���
 *
 *  ����"��i��ʼ�������gap���ȵ�����ȡ��"����ɵģ�
 */
void groupSort(int* a, int n, int i,int gap)
{
    int j;

    for (j = i + gap; j < n; j += gap) 
    {
        // ���a[j] < a[j-gap]����Ѱ��a[j]λ�ã������������ݵ�λ�ö����ơ�
        if (a[j] < a[j - gap])
        {
            int tmp = a[j];
            int k = j - gap;
            while (k >= 0 && a[k] > tmp)
            {
                a[k + gap] = a[k];
                k -= gap;
            }
            a[k + gap] = tmp;
        }
    }
}

/*
 * ϣ������
 *
 * ����˵����
 *     a -- �����������
 *     n -- ����ĳ���
 */
void shellSort2(int* a, int n)
{
    int i,gap;

    // gapΪ������ÿ�μ�Ϊԭ����һ�롣
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        // ��gap���飬��ÿһ�鶼ִ��ֱ�Ӳ�������
        for (i = 0 ;i < gap; i++)
            groupSort(a, n, i, gap);
    }
}

int main()
{
    int i;
    int a[] = {80,30,60,40,20,10,50,70,100};
    int ilen = (sizeof(a)) / (sizeof(a[0]));

    cout << "before sort:";
    for (i=0; i<ilen; i++)
        cout << a[i] << " ";
    cout << endl;

    shellSort1(a, ilen);
    //shellSort2(a, ilen);

    cout << "after  sort:";
    for (i=0; i<ilen; i++)
        cout << a[i] << " ";
    cout << endl;
	return 0;
}