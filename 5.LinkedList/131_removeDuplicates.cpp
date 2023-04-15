//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	Node(int x)
	{
		data = x;
		next = NULL;
	}
};

void print(Node *root)
{
	Node *temp = root;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}
Node *removeDuplicates(Node *root);
int main()
{
	// your code goes here
	int T;
	cin >> T;

	while (T--)
	{
		int K;
		cin >> K;
		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < K; i++)
		{
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		Node *result = removeDuplicates(head);
		print(result);
		cout << endl;
	}
	return 0;
}
// } Driver Code Ends

/*
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

// Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
	Node *current = new Node(head->data);
	current = head;

	if (current->next == NULL)
	{
		return head;
	}

	Node *next = new Node(head->next->data);

	while (current != NULL && current->next != NULL)
	{
		next = current->next;
		if (current->next->data == current->data)
		{
			current->next = current->next->next;
			delete next;
		}
		else
		{
			current = current->next;
		}
	}
	return head;
}

// Issue faced -> for nodes with multiple repetition
// need to update the current pointer to current->next
// only if next->data != current->data
