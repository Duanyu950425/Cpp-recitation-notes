#include<iostream>
using namespace std;

template<class T>
class Queue
{
public:
	Queue() {};
	~Queue();
	bool IsEmpty() const;
	const T &getFront() const;
	void enqueue(const T &x);
	T dequeue();
	void makeEmpty();
private:
	struct ListNode
	{
		T element;
		ListNode *next;
		ListNode(const T &theElement, ListNode *n = 0) :element(theElement), next(n) {}
	};
	ListNode *front;
	ListNode *back;
};

template<class T>
Queue<T>::~Queue()
{
	makeEmpty();
}

template<class T>
bool Queue<T>::IsEmpty() const
{
	return front == 0;
}

template<class T>
void Queue<T>::makeEmpty()
{
	while (!IsEmpty())
		dequeue();
}

template<class T>
const T& Queue<T>::getFront() const
{
	if (IsEmpty())
		throw "Queue is empty!";
	return front->element;
}

template<class T>
void Queue<T>::enqueue(const T &x)
{
	if (IsEmpty())
		back = front = new ListNode(x);
	else
		back = back->next = new ListNode(x);
}

template<class T>
T Queue<T>::dequeue()
{
	T frontItem = getFront();

	ListNode *old = front;
	front = front->next;
	delete old;

	return frontItem;
}

int main05()
{
	Queue<int> myQ;
	myQ.enqueue(10);
	myQ.enqueue(20);
	myQ.enqueue(30);

	cout << myQ.getFront() << endl;

	myQ.dequeue();
	cout << myQ.getFront() << endl;
	cout << myQ.dequeue() << endl;

	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
			myQ.enqueue(i);
		while (!myQ.IsEmpty())
			cout << myQ.dequeue() << endl;
	}
	return 0;
}