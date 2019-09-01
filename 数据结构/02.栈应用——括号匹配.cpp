/**********************************************************/
/*
栈应用——括号匹配
描述：任意输入一组括号，可以判断括号是否匹配
字符串示例：[()] [()()] [()[()]] [[()]
目的：通过实例灵活掌握栈机制的使用技巧
*/
/**********************************************************/
#include<iostream>
#include<string>
using namespace std;

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
	void stackTraverse(bool isFromButtom);//遍历
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

int main02()
{
	string str;
	MyStack<char> *pStack = new MyStack<char>(30);
	MyStack<char> *pNeedStack = new MyStack<char>(30);
	char currentNeed = 0;
	while (cin >> str)
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != currentNeed)
			{
				pStack->Push(str[i]);
				switch (str[i])
				{
				case '[':
					if (currentNeed != 0)
						pNeedStack->Push(currentNeed);
					currentNeed = ']';
					break;
				case '(':
					if (currentNeed != 0)
						pNeedStack->Push(currentNeed);
					currentNeed = ')';
					break;
				default:
					cout << "不匹配" << endl;
					break;
				}
			}
			else
			{
				char elem;
				pStack->Pop(elem);
				if (pNeedStack->Pop(currentNeed))
					currentNeed = 0;
			}
		}
		if (pStack->stackEmpty())
			cout << "匹配" << endl;
		else
			cout << "不匹配" << endl;
	}
	return 0;
}