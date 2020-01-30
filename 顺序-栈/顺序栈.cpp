#include<iostream>
#define MAX 100
#define ERROR -1
#define OK 1
using namespace std;

typedef struct
{
	int *top;
	int *base;
	int stacksize;
}SqStack;

int InitStack(SqStack &S)//��ʼ��ջ
{
	S.base = new int[MAX];
	if (!S.base) { cout << "�ڴ����ʧ�ܣ�"; return ERROR; }
	S.top = S.base;
	S.stacksize = MAX;
	return OK;
}

int Push(SqStack &S, int e)//Ԫ����ջ
{
	if (S.top - S.base == S.stacksize)
	{
		cout << "ջ����������" << endl;
		return ERROR;
	}
	*S.top++ = e;//topָ��ջ�������λ��
	return OK;
}

int Pop(SqStack &S)//��ջ
{
	if (S.base == S.top)//ջ��
	{
		cout << "ջ�գ�����" << endl;
		return ERROR;
	}
	int e = *--S.top;//�� --����*
	return e;
}

int GetTop(SqStack S)//ȡջ��Ԫ��
{
	if (S.base == S.top)
	{
		cout << "ջ�գ�����" << endl;
		return ERROR;
	}
	return *(S.top - 1);
}

int StackEmpty(SqStack S)//�ж�ջ�Ƿ�Ϊ��
{
	if (S.base == S.top)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	SqStack S;

	InitStack(S);
	int n;
	cin >> n;
	while (n)
	{
		Push(S, n % 8);
		n /= 8;
	}
	while (StackEmpty(S))
	{
		cout << Pop(S);
	}
	cout << endl;
	return 0;
}