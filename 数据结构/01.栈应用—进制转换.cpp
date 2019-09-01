/*
ջӦ�á�������ת��
���������������ʮ����������N���ֱ����������N�Ķ����ơ��˽��ơ�ʮ�����Ƶ���
��ʽ��N = (N div d) * d + N mod d(div��ʾ������mod��ʾ���ࣩ
��1348����ʮ���ƣ� = ��2504�����˽��ƣ� = ��544����ʮ�����ƣ� = ��10101000100���������ƣ�
�̳���
N		N div 8		N mod 8
1348        168          4
168         21          0
21          2          5
2          0          2

N		N div 16	N mod 16
1348       84             4
84        5             4
5        0             5
Ŀ�ģ�ͨ��ʵ���������ջ���Ƶ�ʹ�ü���
*/
#include<iostream>
using namespace std;

#define BINARY			2
#define OCTONARY		8
#define HEXADECIMAL		16


template<typename T>
class MyStack
{
public:
	MyStack(int size);
	~MyStack();
	bool stackEmpty();
	bool stackFull();
	void clearStack();
	int stackLength();
	bool Push(T elem);
	bool Pop(T &elem);
	void stackTraverse(bool isFromButtom);//����
private:
	T *m_pBuffer;
	int m_iSize;
	int m_iTop;
};

template<typename T>
MyStack<T>::MyStack(int size)
{
	m_iSize = size;
	m_pBuffer = new T[size];
	m_iTop = 0;
}

template<typename T>
MyStack<T>::~MyStack()
{
	delete[]m_pBuffer;
	m_pBuffer = NULL;
}

template<typename T>
bool MyStack<T>::stackEmpty()
{
	return m_iSize == 0 ? true : false;
}

template<typename T>
bool MyStack<T>::stackFull()
{
	return m_iTop == m_iSize ? true : false;
}

template<typename T>
void MyStack<T>::clearStack()
{
	m_iTop = 0;
}

template<typename T>
int MyStack<T>::stackLength()
{
	return m_iTop;
}

template<typename T>
bool MyStack<T>::Push(T elem)
{
	if (stackFull())
		return false;
	m_pBuffer[m_iTop] = elem;
	m_iTop++;
	return true;
}

template<typename T>
bool MyStack<T>::Pop(T &elem)
{
	if (stackEmpty())
		return false;
	elem = m_pBuffer[--m_iTop];
	return true;
}

template<typename T>
void MyStack<T>::stackTraverse(bool isFromButtom)
{
	if (!isFromButtom)
	{
		for (int i = m_iTop - 1; i >= 0; i--)
		{
			cout << m_pBuffer[i];
		}
		cout << endl;
	}
	else
	{
		for (int i = 0; i < m_iTop; i++)
		{
			cout << m_pBuffer[i];
		}
		cout << endl;
	}
}
int main01()
{
	MyStack<int> *pStack = new MyStack<int>(30);
	int N = 24;
	int mod = 0;
	while (N != 0)
	{
		mod = N % OCTONARY;
		pStack->Push(mod);
		N = N / OCTONARY;
	}
	bool isFromButtom = false;
	pStack->stackTraverse(isFromButtom);
	return 0;
}