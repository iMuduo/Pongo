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

int minLength(const char *s)
{
	char stack[201];
	int i,top=0;
	int min_len=0,sum='a'+'b'+'c';
	for(i=0;i < strlen(s);i++)
	{
		stack[top++]=s[i];
		stack[top]='\0';
		printf("%s\n",stack);
		while(top>1 && stack[top-1] != stack[top-2])
		{
			stack[top-2]=sum-stack[top-1]-stack[top-2];
			top--;
		}
	}
	stack[top]='\0';
	printf("%s\n",stack);
	return top;
}

#endif