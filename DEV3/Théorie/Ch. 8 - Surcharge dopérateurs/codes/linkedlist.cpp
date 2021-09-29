#include <iostream>

using namespace std;

class Node
{
	int _data;
	Node * _next;

	public:
		Node(int data, Node * next = nullptr) : _data(data), _next(next) {}
		inline int data() const { return _data; }
		inline Node* const next() const { return _next; }
		inline void setNext(Node * next) { _next = next; }
};

class NodeIterator
{
	Node* current;

	public:
		NodeIterator(Node * current) : current(current) {}

		int& operator *() { return current->data(); }

		NodeIterator& operator ++()
		{
			current = current->next();
			return *this;
		}

		bool operator !=(const NodeIterator& it) const
		{
			return current != it.current;
		}
};

class LinkedList
{
	Node* head; 
	Node* tail;
	
	public:
		LinkedList() : head(nullptr), tail(nullptr) {}

		//we should do something with copy, assignement and destruction

		void add(int data)
		{
			if(head == nullptr) //empty list
			{
				head = new Node(data);
				tail = head;
			}
			else
			{
				Node* last = new Node(data);
				tail->setNext(last);
				tail = last;
			}
		}		

		NodeIterator begin() { return NodeIterator(head); }
		NodeIterator end() { return NodeIterator(nullptr); }
};

int main()
{
	LinkedList l;
	for(int i = 0; i < 10; i++)
		l.add(i);

	for(auto i : l)
		cout << i << endl;
}
