#include "linkedList.h"


linkedList::linkedList(){
    head=NULL;
    tail=NULL;
}


void linkedList::createNode(QString value)
{
    node *temp=new node;
    temp->data=value;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        temp=NULL;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }
}

void linkedList::insertStart(QString value)
{
    node *temp=new node;
    temp->data=value;
    temp->next=head;
    head=temp;
}
void linkedList::insertPosition(int pos, QString value)
{
    node *pre=new node;
    node *cur=new node;
    node *temp=new node;
    cur=head;
    for(int i=1;i<pos;i++)
    {
        pre=cur;
        cur=cur->next;
    }
    temp->data=value;
    pre->next=temp;
    temp->next=cur;
}
void linkedList::deleteFirst()
{
    node *temp=new node;
    temp=head;
    head=head->next;
    delete temp;
}
void linkedList::deleteLast()
{
    node *current=new node;
    node *previous=new node;
    current=head;
    while(current->next!=NULL)
    {
        previous=current;
        current=current->next;
    }
    tail=previous;
    previous->next=NULL;
    delete current;
}
void linkedList::deletePosition(int pos)
{
    node *current=new node;
    node *previous=new node;
    current=head;
    if(pos == 0){
    deleteFirst();
    }
    for(int i=0;i<pos;i++)
    {
        previous=current;
        current=current->next;
    }
    previous->next=current->next;
}

int linkedList::size(){
    int count = 0; // Initialize count
    node* current = head; // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

bool linkedList::contains(QString value){
    node* current = head; // Initialize current
    while (current != NULL)
    {
        if (current->data == value){
            return true;
        }
        current = current->next;

    }
    return false;
}

void linkedList::deleteList(){

    /* deref head_ref to get the real head */
    node* current = head;
    node* next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    /* deref head_ref to affect the real head back
        in the caller. */
   head = NULL;
}

void linkedList::swap(int posA, int posB){
    node* nodeA = nodeAtPos(posA);
    node* nodeB = nodeAtPos(posB);

    QString temp = nodeA->data;
    nodeAtPos(posA)->data= nodeB->data;
    nodeB->data = temp;
}

node* linkedList::nodeAtPos(int pos){
    node* temp=head;
    for(int i=0;i<pos;i++)
    {
        temp = temp->next;
    }
    return temp;
}

QString linkedList::getDataAtPos(int pos){
    node *cur=new node;
    cur=head;
    for(int i=0;i<pos;i++)
    {
        cur=cur->next;
    }
    QString value = cur->data;
    return value;
}

void linkedList::deleteData(QString data){
    node* current = head; // Initialize current
    node *previous=new node;
    while (current != NULL)
    {
        if (current->data == data){
            previous=current;
            current=current->next;
            break;
        }

    }
    previous->next=current->next;
}
