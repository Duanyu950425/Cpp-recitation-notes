#include<iostream>
#include<string>
using namespace std;

class Person
{
	friend ostream &operator<< (ostream &out, Person &person);
public:
	string name;
	string phone;
	Person &operator = (Person &person);
	bool operator==(Person &person);
};

Person& Person::operator=(Person &person)
{
	this->name = person.name;
	this->phone = person.phone;
	return *this;
}

bool Person::operator==(Person &person)
{
	if (this->name == person.name && this->phone == person.phone)
		return true;
	return false;
}

ostream &operator<< (ostream &out, Person &person)
{
	out << person.name << "..........." << person.phone << endl;
	return out;
}

class Node
{
public:
	Person data;
	Node *next;
	void PrintNode();
};

void Node::PrintNode()
{
	cout << data << endl;
}

class List
{
public:
	List();
	~List();
	void ClearList();
	bool ListEmpty();
	bool ListInsertHead(Node *pNode);
	bool ListInsertTail(Node *pNode);
	bool ListDeleteName(Node *pNode);
	void ListTraverse();//遍历
private:
	Node *m_pList;
	int m_iLength;
};

List::List()
{
	m_pList = new Node;
	m_pList->next = NULL;
	m_iLength = 0;
}
List::~List()
{
	ClearList();
	delete m_pList;
	m_pList = NULL;
}

void List::ClearList()
{
	Node *currentNode = m_pList->next;
	while (currentNode != NULL)
	{
		Node *temp = currentNode->next;
		delete currentNode;
		currentNode = temp;
	}
	m_pList = NULL;
}

bool List::ListEmpty()
{
	return m_iLength == 0 ? true : false;
}

bool List::ListInsertHead(Node *pNode)
{
	Node *currentNode = m_pList->next;
	Node *newNode = new Node;
	if (newNode == NULL)
		return false;
	newNode->data = pNode->data;
	m_pList->next = newNode;
	newNode->next = currentNode;
	m_iLength++;
	return true;
}

bool List::ListInsertTail(Node *pNode)
{
	Node *currentNode = m_pList;
	while (currentNode->next != NULL)
		currentNode = currentNode->next;
	Node *newNode = new Node;
	if (newNode == NULL)
		return false;
	newNode->data = pNode->data;
	newNode->next = NULL;
	currentNode->next = newNode;
	
	m_iLength++;
	return true;
}

bool List::ListDeleteName(Node *pNode)
{
	Node *currentNode = m_pList;
	Node *currentNodeBefore = NULL;
	while (currentNode->next != NULL)
	{
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
		if (currentNode->data == pNode->data)
		{
			currentNodeBefore->next = currentNode->next;
			delete currentNode;
			currentNode = NULL;
			m_iLength--;
			return true;
		}
	}
	return false;
}

void List::ListTraverse()
{
	Node *currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		currentNode->PrintNode();
	}
}

int menu()
{
	cout << "1.新建联系人" << endl;
	cout << "2.删除联系人" << endl;
	cout << "3.浏览通讯录" << endl;
	cout << "4.退出通讯录" << endl;

	cout << "请输入：";
	int order;
	cin >> order;
	return order;
}

void createPerson(List *pList)
{
	Node node;
	Person person;
	cout << "请输入姓名：";
	cin >> node.data.name;
	cout << "请输入电话：";
	cin >> node.data.phone;
	pList->ListInsertTail(&node);
}

void Delete(List *pList)
{
	Node node;
	Person person;
	cout << "请输入要删除的联系人的姓名：";
	cin >> node.data.name;
	cout << "请输入电话：";
	cin >> node.data.phone;
	pList->ListDeleteName(&node);
}

int main06()
{
	int userOrder = 0;
	List *m_pList = new List();

	while (userOrder != 4)
	{
		userOrder = menu();
		switch (userOrder)
		{
		case 1:
			cout << "用户指令——》新建联系人：" << endl;
			createPerson(m_pList);
			break;
		case 2:
			cout << "用户指令——》删除联系人：" << endl;
			Delete(m_pList);
			break;
		case 3:
			cout << "用户指令——》浏览通讯录：" << endl;
			m_pList->ListTraverse();
			break;
		case 4:
			cout << "用户指令——》退出通讯录：" << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}