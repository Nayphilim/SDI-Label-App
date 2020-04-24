#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <classfile.h>

struct node
{
            struct node *prev;
            QString data;
            struct node *next;
};

class linkedList
{
public:
    linkedList();
    void createNode(QString value);
    void display();
    void insertStart(QString value);
    void insertPosition(int pos, QString value);
    void deleteFirst();
    void deleteLast();
    void deletePosition(int pos);
    int size();
    bool contains( QString value);
    void deleteList();
    void swap(int posA, int posB);
    QString getDataAtPos(int i);
    void deleteData(QString data);

private:
    node *head, *tail;
    node* nodeAtPos(int pos);



};

#endif // DOUBLELINKEDLIST_H
