#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <classfile.h>

struct node
{
            struct node *prev;
            QString data;
            struct node *next;
};
///This class handles the linked list data structure
///
///This class contains all the functions needed to utilise a linked list for the storage of QStrings and allows for sorting
class linkedList
{
public:
    linkedList();
    ///creates a new node at the end of the list
    ///@param value This is the data that is being put into the linked list
    void createNode(QString value);
    ///inserts a new node at the start of the linked list
    ///@param value This is the data that is being put into the linked list
    void insertStart(QString value);
    ///inserts a new node at the given position in the linked list
    ///@param pos This is the position in the linked list for the node to be created
    ///@param value This is the data to be inserted into the node
    void insertPosition(int pos, QString value);
    ///deletes the first node in the linked list
    ///
    ///Necessary as handling a deletion of a head or the first node is different to other nodes
    void deleteFirst();
    ///deletes last node in the linked list
    ///
    ///created in case of situations that we do not know the size of the linked list but want to delete the last node
    void deleteLast();
    ///deletes a node at a given position
    ///@param pos This is the index in the linked list selected to be deleted
    void deletePosition(int pos);
    ///returns the number of nodes in the linked list
    int size();
    ///tests if a given value is present in a linked list and returns true if it is
    ///@param value This is the data being tested if it already exists in the linked list
    bool contains( QString value);
    ///deletes the linked list entirely and frees the memory
    void deleteList();
    ///swap two nodes positions in the linked list
    ///@param posA and @param posB are the postions of the nodes in the linked list
    void swap(int posA, int posB);
    ///returns the data in a node at a given position
    ///@param i is the index of the node in the linked list
    QString getDataAtPos(int i);
    ///delete the node that has the given data in
    ///@param data is the data given to find the node that contains it
    void deleteData(QString data);

private:
    ///pointers to the head and tail of the linked list
    node *head, *tail;
    ///returns a pointer to the node at the position given
    ///@param pos This is the index of the node to be returned
    node* nodeAtPos(int pos);



};

#endif // DOUBLELINKEDLIST_H
