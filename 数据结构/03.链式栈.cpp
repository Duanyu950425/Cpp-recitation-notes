#include<iostream>
using namespace std;

template<class T> class LinkedStack;

template<typename T>
class ChainNode//这是一个节点类
{
	friend class LinkedStack<T>;
private:
	ChainNode(const T& theData, ChainNode *n = 0) :data(theData), link(n) {}
	T data;
	ChainNode<T> *link;//指向下一个节点
};

template<typename T>
class LinkedStack
{
public:
	LinkedStack() :top(0) {}
	~LinkedStack() { MakeEmpty(); }
	bool IsEmptyLinked()const;
	T& LinkedTop()const;
	void LinkedPush(const T& e);
	void LinkedPop();
	void MakeEmpty();
private:
	ChainNode<T> *top;
};

template<typename T>
bool LinkedStack<T>::IsEmptyLinked() const
{
	return top == 0;
}

template<typename T>
T& LinkedStack<T>::LinkedTop() const
{
	if (IsEmptyLinked())
		throw " Stack is empty!";
	return top->data;
}

template<typename T>
void LinkedStack<T>::LinkedPush(const T& e)
{
	top = new ChainNode<T>(e, top);
}

template<typename T>
void LinkedStack<T>::LinkedPop()
{
	if (IsEmptyLinked())
		throw " Stack is empty!";
	ChainNode<T> *delNode = top;
	top = top->link;
	delete delNode;
}

template<typename T>
void LinkedStack<T>::MakeEmpty()
{
	while (!IsEmptyLinked())
		LinkedPop();
}

int main04()
{
	LinkedStack<int> s;
	s.LinkedPush(10);
	cout << s.LinkedTop() << endl;
	s.LinkedPush(20);
	cout << s.LinkedTop() << endl;
	s.LinkedPush(30);
	cout << s.LinkedTop() << endl;

	s.LinkedPop();
	cout << s.LinkedTop() << endl;
	return 0;
}