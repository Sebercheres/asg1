#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    Node *next;
}*head,*tail;

int max=0;
int min=100;

Node *createNode(int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->value=value;
    newNode->next=NULL;
    if(max<value)max=value;
    if(min>value)min=value;
    return newNode;
}

void pushHead(int value){
    Node *temp = createNode(value);
    if(!head){
        head=tail=temp;
    }else{
        temp->next=head;
        head=temp;
    }
}

void pushTail(int value){
    Node *temp = createNode(value);
    if(!head){
        head=tail=temp;
    }else{
        tail->next=temp;
        tail=temp;
    }
}

void popHead() {
	if(!head) {
    	return;
	} else if(head == tail) { 
    	free(head);
    	head = tail = NULL;
	} else {
    	Node *temp = head->next;
    	head->next = NULL; 
    	free(head); 
    	head = temp; 
  	}
}

void popTail() {
	if(!head) { 
    	return;
	} else if(head == tail) { 
    	free(head); 
    	head = tail = NULL; 
	} else {
    	Node *temp = head; 

	while(temp->next != tail) { 
    	temp = temp->next; 
    }
	temp->next = NULL; 
    free(tail); 
    tail = temp;
  	}
}
int main(){
    //soal 1->2->3->4->5
    pushHead(1);
    pushTail(2);
    pushTail(3);
    pushTail(4);
    pushTail(5);
    //jawab
    int jawab=max-min;
    return 0;
}