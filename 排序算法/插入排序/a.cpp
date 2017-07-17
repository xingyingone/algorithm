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
        inserter=a[k];//将待排序的元素放入变量inserter中
        index=k-1;
        while(index>=0&&inserter<a[index])//寻找插入点
        {
              a[index+1]=a[index];//元素后挪一个位置
              index--;   //插入点向前移                                   
        }
        a[index+1]=inserter;//插入
        cout<<"第"<<k<<"轮排序后：";
        for(int j=0;j<size;j++)
        {
           cout<<a[j]<<",";
           if(j==k) //已排序与未排序的分界线
              cout<<"| ";    
        }
        cout<<endl;     
     }
}