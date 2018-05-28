#include "linkedlist.h"

void LinkedList::printLinkedList(Node* tr){
	while(tr != NULL){
		cout<<tr->data<<endl;
		tr = tr->next;
	}
}

void LinkedList::insertionFront(Node** head, int data){
	Node* first = new Node();
	first->data = data;
	first->next = *(head);
	*head =first;
}

void LinkedList::insertionLast(Node** tail,int data){
	Node* last = new Node();
	last->data = data;
	last->next = NULL;
	(*tail)->next = last;
}

void LinkedList::insertAfter(Node* prev, int data){
	if(prev->next == NULL)
		return;
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = prev->next;
	prev->next = newNode;
}

int LinkedList::length(Node* head){
	Node* current = head;
	int count=0;
	while(current != NULL){
		count++;
		current = current->next;
	}
	return count;
}

void LinkedList::deleteNode(Node** head_ref, int pos){
	if(*head_ref == NULL){
		cout <<"Empty List"<<endl;
		return;
	}
	Node* temp = *head_ref;

	if(pos == 0){
		*head_ref = temp->next;
		return;
	}

	for(int i=0; temp != NULL &&i<(pos-1);i++){
			temp =temp->next;
	}

	if(temp == NULL || temp->next == NULL)
		return;

	Node* next = temp->next->next;
	temp->next = next;
}
int main(int argc,char* argv[]){

	//UNUSED(argc);
	//UNUSED(argv);

	Node *head = new Node();
	Node *second = new Node();
	Node *third = new Node();

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next= NULL;

	LinkedList::insertionFront(&head,4);
	LinkedList::insertionLast(&third,5);
	LinkedList::insertAfter(second,6);

	LinkedList::deleteNode(&head,5);
	LinkedList::printLinkedList(head);

	cout << "Length of Linked List is: "<<LinkedList::length(head);
	return 0;
}
