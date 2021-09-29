#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	struct node * next;
	int data;
};
typedef struct node node;

typedef struct
{
	node * head;
	node * tail;
	int size;
} LinkedList;

void make_node(node* n, int data)
{
	n->next = NULL;
	n->data = data;
}

void make_list(LinkedList* l) 	
{
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
}

int list_size(LinkedList l)
{
	return l.size;
}

void list_print(LinkedList l)
{
	printf("{ ");
	for(node * current = l.head; current != NULL; current = current->next)
		printf("%d ", current->data);
	printf("}\n");
}

void list_add(LinkedList* l, int data)
{
	node * n = (node*) malloc(sizeof(node));
	make_node(n, data);
	
	if(l->head == NULL && l->tail == NULL) //empty list
	{
		l->head = n;
		l->tail = n;
	}
	else
	{
		l->tail->next = n;
		l->tail = n;
	}

	l->size = l->size + 1;
}

bool list_remove(LinkedList* l, int data)
{
	node * prev = NULL;
	for(node * current = l->head; current != NULL; current = current->next)
	{
		if(current->data == data)
		{
			prev->next = current->next;
			free(current);
			l->size--;
			return true;
		}
		prev = current;
	}

	return false;
}

void list_delete(LinkedList* l)
{
	node * next = NULL;
	node * current = l->head;

	while(current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

int main()
{
	LinkedList l; //allocated on stack
	make_list(&l);
	printf("l : %p %p %d\n", l.head, l.tail, l.size);

	list_print(l);

	for(int i = 0; i < 5; i++)
		list_add(&l, i * 2);

	list_print(l);	

	bool r = list_remove(&l, 4);

	printf("%s\n", r ? "true" : "false");
	list_print(l);

	r = list_remove(&l, 40);	

	printf("%s\n", r ? "true" : "false");
	list_print(l);

	/** seg fault
	LinkedList * l2;
	make_list(l2);
	printf("l2 : %p %p %d\n", l2->head, l2->tail, l2->size);

	list_print(*l2);	
	*/

	LinkedList * l3 = (LinkedList*) malloc(sizeof(LinkedList)); //allocated on heap
	make_list(l3);
	printf("l3 : %p %p %d\n", l3->head, l3->tail, l3->size);

	list_print(*l3);
	
	for(int i = 0; i < 5; i++)
		list_add(l3, i * 3);

	list_print(*l3);

	free(l3);
	
	//free(l3); //most likely seg fault
}
