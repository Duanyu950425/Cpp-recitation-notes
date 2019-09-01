#include<iostream>
using namespace std;

/*template<typename T>
class MyQueue
{
public:
	MyQueue(int QueueCapacity);
	bool IsEmpty() const;
	T& Front() const;
	T& Rear() const;
	void Push(const T& item);
	void Pop();
private:
	T *queue;
	int front;
	int rear;
	int capacity;
};

template<typename T>
MyQueue<T>::MyQueue(int QueueCapacity)
{
	capacity = QueueCapacity;
	queue = new T[capacity];
	front = 0;
	rear = 0;
}

template<typename T>
bool MyQueue<T>::IsEmpty() const
{
	return front == rear;
}

template<typename T>
T& MyQueue<T>::Front() const
{
	if (IsEmpty())
		throw "Queue is empty, No front element";
	return queue[(front + 1) % capacity];
}

template<typename T>
T& MyQueue<T>::Rear() const
{
	if (IsEmpty())
		throw "Queue is empty, No front element";
	return queue[rear];
}

template<typename T>
void MyQueue<T>::Pop()
{
	if (IsEmpty())
		throw "Queue is empty, No front element";
	front = (front + 1) % capacity;
	queue[front].~T();
}

template<typename T>
void MyQueue<T>::Push(const T& item)
{
	if ((rear + 1) % capacity == front)
	{
		T* newQueue = new T[2 * capacity];
		int start = (front + 1) % capacity;
		if (start < 2)
			std::copy(queue + start, queue + start + capacity - 1, newQueue);
		else
		{
			std::copy(queue + start, queue + capacity, newQueue);
			std::copy(queue, queue + rear + 1, newQueue + capacity - start);
		}
		front = 2 * capacity - 1;
		rear = capacity - 2;
		capacity *= 2;
		delete[]queue;
		queue = newQueue;
	}
	rear = (rear + 1) % capacity;
	queue[rear] = item;
}

int main04()
{
	MyQueue<char> q(5);
	q.Push('A');
	q.Push('B');
	q.Push('C');
	cout << q.Front() << "," << q.Rear() << endl;
	return 0;
}*/