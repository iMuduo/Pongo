#include "lib.h"
#ifdef ARR_SORT
/*
*
*	����һ������1-n�����У�����ͨ��������������Ԫ�ظ���������������������Ҫ���ٴν������ܰ������ųɰ�1-n������˳�����У����鳤�Ȳ�����100��
*	���磺
*	ԭ������3,2,1�� ����ֻ��Ҫ����1��3�����ˣ���������Ϊ1���������1��
*	ԭ������2,3,1��������Ҫ����2��1�����1,3,2���ٽ���3��2����Ϊ1��2��3���ܹ���Ҫ�Ľ�������Ϊ2���������2��
*
*/
#include <malloc.h>

void  swap(int *a,int *b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
}
int run(const int *a,int n)
{
	int *arr=malloc(sizeof(int)*(n+1));
	int i,count=0;
	for (i=1;i<n+1;i++)
		arr[i]=a[i-1];
	for (i=1;i<n+1;i++)
	{
		while (arr[i]!=i)
		{
			swap(arr+i,arr+arr[i]);
			count++;
		}
	}
	return count;
}
#endif
