// Given a pointer to the head node of a linked list, the task is to reverse the linked list

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *next;
};
Node *head = NULL;

void reverse(Node *head)
{
	Node *current, *prev, *next;
	current = head;
	prev = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	head = prev;
}

void reverseRecurse(Node *p)
{
	if (p->next == NULL)
	{
		head = p;
		return;
	}

	reverseRecurse(p->next);
	p->next->next = p;
	p->next = NULL;
}
