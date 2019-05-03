#include<iostream>
using namespace std;

typedef struct Node
{
	int data;
	Node*ptr;
}*node;

void show(node head) 
{
	head = head->ptr;
	while (head!= NULL)
	{
		cout << head->data << ' ';
		head = head->ptr;
	}
}

void insert(node& head,int x)
{
	node a = new Node;
	if (a == NULL)
	{
		cout << "申请失败";
		return;
	}
	a->ptr = head->ptr;
	a->data = x;
	head->ptr = a;

}

void shanchu(node& head,int x)
{
	node a = new Node;
	node b = new Node;
	if (a == NULL || b == NULL)
	{
		cout << "申请失败";
		return;
	}
	a = head->ptr;
	b = head;
	while (a != NULL)
	{
		if (a->data == x)
		{
			b->ptr = a->ptr;
			delete a;
			a = NULL;
			return;
		}
		b = a;
		a = a->ptr;
	}   
}

void fanzhuan(node&head)
{
	if (head == NULL||head->ptr==NULL)
	{
		cout << "空链表";
		return;
	}
	node a = new Node;
	node b = new Node;
	if (a == NULL || b == NULL)
	{
		cout << "申请失败";
		return;
	}
	a = head->ptr;
	while (a->ptr!= NULL)
	{
		b = a->ptr;
		a->ptr = a->ptr->ptr;
		b->ptr = head->ptr;
		head->ptr = b;
	}
}

int main()
{
	node head = new Node;
	if (head != NULL)
	{
		head->ptr = NULL;
		head->ptr = 0;
	}
  
	for (int i = 0; i < 100; i++)
	{
		insert(head,i);
	}
	show(head);
	cout << endl << endl;

	fanzhuan(head);
	show(head);
	cout << endl << endl;

	for (int i = 0; i < 50; i++)
	{
		shanchu(head, i + 25);
	}
	show(head);
  
	return 0;
}
