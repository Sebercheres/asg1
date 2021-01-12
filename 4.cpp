#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    Node *next;
}*head,*tail;

Node *createNode(int value){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->value=value;
    newNode->next=NULL;
    return newNode;
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

void pushHead(int value){
    Node *temp = createNode(value);
    if(!head){
        head=tail=temp;
    }else{
        if(temp->value==head->value){
            popHead();
            head=temp;
        }else{
            temp->next=head;
            head=temp;
        }   
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

void pushTail(int value){
    Node *temp = createNode(value);
    if(!head){
        head=tail=temp;
    }else{
        if(temp->value==tail->value){
            popTail();
            tail=temp;
        }else{
            tail->next=temp;
            tail=temp;
        }  
    }
}


int main(){
    //soal 1->1->2->3->4
    pushHead(1);
    pushTail(1);
    pushTail(2);
    pushTail(3);
    pushTail(4);
    
    return 0;
}