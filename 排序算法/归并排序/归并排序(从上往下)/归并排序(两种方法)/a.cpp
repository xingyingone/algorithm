
#include <iostream>
using namespace std;

/*
 * ��һ�������е�����������������ϲ���һ��
 *
 * ����˵����
 *     a -- ���������������������
 *     start -- ��1�������������ʼ��ַ��
 *     mid   -- ��1����������Ľ�����ַ��Ҳ�ǵ�2�������������ʼ��ַ��
 *     end   -- ��2����������Ľ�����ַ��
 */
void merge(int* a, int start, int mid, int end)
{
    int *tmp = new int[end-start+1];    // tmp�ǻ���2������������ʱ����
    int i = start;            // ��1��������������
    int j = mid + 1;        // ��2��������������
    int k = 0;                // ��ʱ���������

    while(i <= mid && j <= end)
    {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }

    while(i <= mid)
        tmp[k++] = a[i++];

    while(j <= end)
        tmp[k++] = a[j++];

    // ��������Ԫ�أ�ȫ�������ϵ�����a�С�
    for (i = 0; i < k; i++)
        a[start + i] = tmp[i];

    delete[] tmp;
}

/*
 * �鲢����(��������)
 *
 * ����˵����
 *     a -- �����������
 *     start -- �������ʼ��ַ
 *     endi -- ����Ľ�����ַ
 */
void mergeSortUp2Down(int* a, int start, int end)
{
    if(a==NULL || start >= end)
        return ;

    int mid = (end + start)/2;
    mergeSortUp2Down(a, start, mid); // �ݹ�����a[start...mid]
    mergeSortUp2Down(a, mid+1, end); // �ݹ�����a[mid+1...end]

    // a[start...mid] �� a[mid...end]����������ռ䣬
    // �����������һ������ռ�a[start...end]
    merge(a, start, mid, end);
}

int main()
{
    int i;
    int a[] = {80,30,60,40,20,10,50,70};
    int ilen = (sizeof(a)) / (sizeof(a[0]));

    cout << "before sort:";
    for (i=0; i<ilen; i++)
        cout << a[i] << " ";
    cout << endl;

    mergeSortUp2Down(a, 0, ilen-1);        // �鲢����(��������)

    cout << "after  sort:";
    for (i=0; i<ilen; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}