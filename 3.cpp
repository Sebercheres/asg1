#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    Node *next;
}*head,*tail;

int counter=0;

Node *createNode(int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->value=value;
    newNode->next=NULL;
    counter++;
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
    int middle=counter/2;
    Node *curr=head;
    for(int i=0;i<middle;i++){
        curr=curr->next;
    }
    printf("%d",curr->value);
    return 0;
}