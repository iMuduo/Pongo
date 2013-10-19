#include "lib.h"
#ifdef KILL_CHARS
/*
*
*	����һ���ַ���������a,b,c 3��Сд��ĸ��ɡ�����������������ͬ����ĸʱ�������������һ����ĸ�滻������
*
*	��ab��ba�������֣���������滻Ϊ��ĸc��
*	��ac��ca��������ʱ������԰������滻Ϊ��ĸb��
*	��bc��cb ��������ʱ������԰������滻Ϊ��ĸa��
*
*	����Բ��Ϸ������������������滻�����Ŀ����ʹ�����ս�����õ����ַ��������̣ܶ������ս������̳��ȡ�
*
*	���룺�ַ��������Ȳ�����200������abc����Сд��ĸ��ɡ�
*	����� �����������򲻶������滻�����õ����ַ�����̵ĳ��ȡ�
*
*	���磺����cab�����2����Ϊ���ǿ��԰�����Ϊbb���߱�Ϊcc��
*	����bcab�����1���������ǿ��԰�����Ϊaab -> ac -> b��Ҳ���԰�����Ϊbbb������Ϊǰ�߳��ȸ��̣��������1��
*
*/
#include <stdio.h>
#include <string.h>
#define swap(a,b) a^=b^=a^=b
int minLength(const char *s)
{
	char stack[201],tmp;
	int i,j,top,len=strlen(s);
	int min_len=300,sum='a'+'b'+'c';
	for(i=0;i < len;i++)
	{
		top=0;
		for (j=i-1;j>-1;j--)
		{
			stack[top++]=s[j];
			while(top>1 && stack[top-1] != stack[top-2])
			{
				stack[top-2]=sum-stack[top-1]-stack[top-2];
				top--;
			}
		}
		for (j=0;j<top;j++)
			swap(stack[j],stack[top-1-j]);
		for (j=i;j<len;j++)
		{
			stack[top++]=s[j];
			while(top>1 && stack[top-1] != stack[top-2])
			{
				stack[top-2]=sum-stack[top-1]-stack[top-2];
				top--;
			}
		}
		if(top<min_len)
			min_len=top;
	}
	return min_len;
}

#endif