#ifndef LIST_H
#define LIST_H
#include "deadline.h"

struct Node
{
    Deadline* object;
    Node *next, *prev;
};
class List;

class Iterator
{
public:
    friend List;
    Iterator();
    Iterator(const Iterator&);
    Iterator(Node *);
    ~Iterator();
    Iterator& operator ++();
    Iterator& operator ++(int);
    Iterator& operator --();
    Iterator& operator --(int);
    bool operator == (Iterator const &) const;
    bool operator != (Iterator const &) const;
    Deadline* operator *();
private:
    Node *node;
};

class List
{
public:

    friend Iterator;
    List();
    ~List();
    List(const List&);
    void addNode(const Deadline&);
    void deleteNode(Iterator&);
    void deleteNode(Node*);
    Node* getHead() const;
    Node* getTail() const;
    void deleteList();
    Iterator begin() const;
    Iterator end() const;
    int getLength() const;
    Deadline* findDish(const float &) const;
    bool operator == (List const &) const;
    bool operator != (List const &) const;
private:
    Node *head, *tail;
    int _length;
};
#endif // LIST_H