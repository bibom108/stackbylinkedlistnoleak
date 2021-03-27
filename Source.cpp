#include <iostream>
using namespace std;
class Node {
public:
	int data;
	Node *next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};
class stock
{
public:
	stock();
	~stock();
	Node *head;
	Node *tail;
	int count;
	int size();
	void push(int val);
	int top();
	void pop();
};

stock::stock()
{
	head = NULL;
	tail = NULL;
	count = 0;
}

stock::~stock()
{
	while (this->count != 0) {
		this->pop();
	}
}

int stock::size() {
	return this->count;
}
void stock::push(int val) {
	Node *newNode = new Node(val);
	if (this->count == 0) {
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->next = head;
		head = newNode;
	}
	this->count++;
}
void stock::pop() {
	Node *p = head;
	head = head->next;
	delete p;
	this->count--;
}
int stock::top() {
	return head->data;
}

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);		//to check memory leak
	stock res;
	for (int i = 0; i < 10; i++) {
		res.push(i);
	}

	cout << "Done!";
}