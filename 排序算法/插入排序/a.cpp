#include<iostream>
using namespace std;
void insertSort(int a[],int size);
int main()
{
   int array[]={34,65,12,43,67,5,78,10,3,70},k;
   int len=sizeof(array)/sizeof(int);
     cout<<"The orginal array are:"<<endl;
   for(k=0;k<len;k++)
     cout<<array[k]<<",";
   cout<<endl;
   insertSort(array,len);
   cout<<"The sorted array are:"<<endl;
   for(k=0;k<len;k++)
     cout<<array[k]<<",";
   cout<<endl;
   system("pause");
   return 0;
}
void insertSort(int a[],int size)
{
     int inserter,index,k;
     for(k=1;k<size;k++)
     {
        inserter=a[k];//���������Ԫ�ط������inserter��
        index=k-1;
        while(index>=0&&inserter<a[index])//Ѱ�Ҳ����
        {
              a[index+1]=a[index];//Ԫ�غ�Ųһ��λ��
              index--;   //�������ǰ��                                   
        }
        a[index+1]=inserter;//����
        cout<<"��"<<k<<"�������";
        for(int j=0;j<size;j++)
        {
           cout<<a[j]<<",";
           if(j==k) //��������δ����ķֽ���
              cout<<"| ";    
        }
        cout<<endl;     
     }
}