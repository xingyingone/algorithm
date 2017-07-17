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
 * ������a�����ɴκϲ�������a���ܳ���Ϊlen��������Ϊ���ɸ�����Ϊgap�������飻
 *             ��"ÿ2�����ڵ�������" ���кϲ�����
 *
 * ����˵����
 *     a -- �����������
 *     len -- ����ĳ���
 *     gap -- ������ĳ���
 */
void mergeGroups(int* a, int len, int gap)
{
    int i;
   // int twolen = 2 * gap;    // �������ڵ�������ĳ���

    // ��"ÿ2�����ڵ�������" ���кϲ�����
    for(i = 0; i+2*gap-1 < len; i+=(2*gap))
    {
        merge(a, i, i+gap-1, i+2*gap-1);
    }

    // �� i+gap-1 < len-1����ʣ��һ��������û����ԡ�
    // ����������ϲ���������������С�
    if ( i+gap-1 < len-1)
    {
        merge(a, i, i + gap - 1, len - 1);
    }
}

/*
 * �鲢����(��������)
 *
 * ����˵����
 *     a -- �����������
 *     len -- ����ĳ���
 */
void mergeSortDown2Up(int* a, int len)
{
    int n;

    if (a==NULL || len<=0)
        return ;

    for(n = 1; n < len; n*=2)
        mergeGroups(a, len, n);
}

int main()
{
    int i;
    int a[] = {80,30,60,40,20};
    int ilen = (sizeof(a)) / (sizeof(a[0]));

    cout << "before sort:";
    for (i=0; i<ilen; i++)
        cout << a[i] << " ";
    cout << endl;

   
    mergeSortDown2Up(a, ilen);            // �鲢����(��������)

    cout << "after  sort:";
    for (i=0; i<ilen; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}