#include <iostream>


using namespace std;

class LinkedList
{
	struct node
	{		
		node* next;
		int data;		

		inline node(int d) : next(nullptr), data(d) {}

	};
	
	node* head;
	node* tail;	
	int _size;

	public:
		LinkedList() : head(nullptr), tail(nullptr), _size(0) 
		{}

		LinkedList(const LinkedList& l) = delete; //cannot copy
		LinkedList& operator=(const LinkedList& l) = delete; //cannot re-affect

		~LinkedList()
		{
			node* current = head;
			node* next = nullptr;
		
			while(current != nullptr)
			{	
				next = current->next;
				cout << "I deleted " << current->data << endl;
				delete current;
				current = next;
			}
		}

		inline int size() const
		{ 
			return _size; 
		}		

		void add(int data)
		{
			node * toLink = new node(data);
			cout << "I created " << toLink->data << endl;
			
			if(head == nullptr)
			{
				head = toLink;
				tail = toLink;
			}
			else
			{
				tail->next = toLink;
				tail = toLink;				
			}

			_size++;
		}

		void remove(int data)
		{
			node* prev = nullptr;
			for(node * current = head; current != nullptr; current = current->next)
			{
				if(current->data == data)
				{
					prev->next = current->next;
					cout << "I deleted " << current->data << endl;
					delete current;
					_size--;
					return; //because I'm worth it
				}
				prev = current;
			}
		}

		void print()
		{
			cout << "{ ";
			for(node * current = head; current != nullptr; current = current->next)
				cout << current->data << " ";			
			cout << "}" << endl;
		}
};

void f(LinkedList l) {}
void g(LinkedList& l) {}

int main()
{
	LinkedList l;
	for(int i = 0; i < 6; i++)
		l.add(i);			
	l.print();

	l.remove(3);
	l.print();
		

	//f(l); // ko
	g(l);
	LinkedList ll;
	//ll = l; //ko
}
