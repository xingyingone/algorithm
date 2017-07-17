#include"memorypool.h"
#include<iostream>
#include<vector>
#include<string>
#include <Windows.h>
using namespace std;
#define  N = 1000;
#define  t = 5;

void TestObjectPool()
{
	vector<int*> v;

	MemoryPool<int> pool;
	for (size_t i = 0; i < 32; ++i)
	{
		v.push_back(pool.New());
		printf("Pool New [%d]: %p\n", i, v.back());
	}

	while (!v.empty())
	{
		pool.Delete(v.back());
		v.pop_back();
	}

	for (size_t i = 0; i < 32; ++i)
	{
		v.push_back(pool.New());
		printf("Pool New [%d]: %p\n", i, v.back());
	}

	v.push_back(pool.New());
}
void main()
{
	TestObjectPool();

}