#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    Node *next;
}*head, *tail, *head1, *tail1;

Node *createNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value=value;
    newNode->next=NULL;
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

void popHead(){
    if(!head){
        return;
    }else if(head==tail){
        free(head);
        head=tail=NULL;
    }else{
        Node *temp=head->next;
        free(head);
        head->next=NULL;
        head=temp;
    }
}

void popTail(){
    if(!head){
        return;
    }else if(head == tail){
        free(head);
        head=tail=NULL;
    }else{
        Node *temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        free(tail);
        tail=temp;
    }
}

void pushHead1(int value){
    Node *temp = createNode(value);
    if(!head1){
        head1=tail1=temp;
    }else{
        temp->next=head1;
        head1=temp;
    }
}

void pushTail1(int value){
    Node *temp = createNode(value);
    if(!head1){
        head=tail1=temp;
    }else{
        tail1->next=temp;
        tail1=temp;
    }
}

void popHead1(){
    if(!head1){
        return;
    }else if(head1==tail1){
        free(head1);
        head1=tail1=NULL;
    }else{
        Node *temp=head1->next;
        free(head1);
        head1->next=NULL;
        head1=temp;
    }
}

void popTail1(){
    if(!head1){
        return;
    }else if(head1 == tail1){
        free(head1);
        head1=tail1=NULL;
    }else{
        Node *temp=head;
        while(temp->next!=tail1){
            temp=temp->next;
        }
        temp->next=NULL;
        free(tail1);
        tail1=temp;
    }
}


int main(){
    //soal 1 -> 2 -> 3 -> 4 -> 5
    pushHead(1);
    pushTail(2);
    pushTail(3);
    pushTail(4);
    pushTail(5);
    //jawaban
    pushHead1(5);
    pushTail1(4);
    pushTail1(3);
    pushTail1(2);
    pushTail1(1);;
    
    return 0;
}