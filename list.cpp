#include "list.h"
#include <assert.h>

float absoluteDiff(float first, float second)
{
    return first > second ? first - second : second - first;
}

Iterator::Iterator():
    node(nullptr)
{
}

Iterator::Iterator(const Iterator& existing):
    node(existing.node)
{
}

Iterator::Iterator(Node *existing):
    node(existing)
{
}

Iterator::~Iterator()
{
}

Deadline *Iterator::operator *()
{
    return node->object;
}

Iterator& Iterator::operator++()
{
    node = node->next;
    return *this;
}

Iterator& Iterator::operator++(int)
{
    Iterator prev = *this;
    node = node->next;
    return prev;
}

Iterator& Iterator::operator--()
{
    node = node->prev;
    return *this;
}

Iterator& Iterator::operator--(int)
{
    Iterator prev = *this;
    node = node->prev;
    return prev;
}

bool Iterator::operator == (Iterator const &right) const
{
    return node == right.node;
}

bool Iterator::operator != (Iterator const &right) const
{
    return node != right.node;
}

List::List():
    head(nullptr),
    tail(nullptr),
    _length(0)
{
}

List::List(const List &existing):
    head(nullptr),
    tail(nullptr)
{
    Node *newNode, *existingNode = existing.head;
    Deadline *tempDish;
    _length = 0;
    if(existing._length)
    {
        tempDish = new Deadline(*(existingNode->object));
        newNode = new Node;
        newNode->object = tempDish;
        newNode->prev = nullptr;
        existingNode = existingNode->next;
        _length++;
        head = newNode;
        tail = head;
        tail->next = nullptr;
        while(existingNode)
        {
            tempDish = new Deadline(*(existingNode->object));
            tail = new Node;
            newNode->next = tail;
            tail->prev = newNode;
            tail->next = nullptr;
            tail->object = tempDish;
            existingNode = existingNode->next;
            newNode = tail;
            _length++;
        }
    }

}

List::~List()
{
    while(head)
    {
        tail = head->next;
        delete head;
        head = tail;
    }
}

void List::addNode(const Dish& existing)
{
    if(!head)
    {
        head = new Node;
        head->object = new Dish(existing);
        head->next = nullptr;
        head->prev = nullptr;
        tail = head;
    }
    else
    {
        Node* temp = head;
        while(temp)
        {
            if(temp->object->getEnergyValueOn100() > existing.getEnergyValueOn100())
                break;
            temp = temp->next;
        };
        Node* added = new Node;
        added->object = new Dish(existing);
        if(!temp)
        {
            tail->next = added;
            added->next = nullptr;
            added->prev = tail;
            tail = added;
        }
        else
        {
            added->next = temp;
            added->prev = temp->prev;
            if( temp == head)
            {
                head = added;
            }
            else
            {
                temp->prev->next = added;
            }
            temp->prev = added;
        }
    }
    _length++;
}

void List::deleteNode(Node* existing)
{
    Node* temp = head;
    do
    {
        if(temp == existing)
        {
            if(temp == head)
            {
                head = temp->next;
                head->prev = nullptr;
            }
            else
            {
                if(temp == tail)
                {
                    tail = temp->prev;
                    tail->next = nullptr;
                }
                else
                {
                    temp->next->prev = temp->prev;
                    temp->prev->next = temp->next;
                }
            }
            delete existing;
            _length--;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }while(temp);
}

void List::deleteList()
{
    while(head)
    {
        tail = head->next;
        delete head;
        head = tail;
    }
    head = tail = nullptr;
    _length = 0;
}

int List::getLength() const
{
    return _length;
}

Iterator List::begin() const
{
    Iterator temp(head);
    return temp;
}

Iterator List::end() const
{
    Iterator temp(tail);
    return temp;
}

Node* List::getHead() const
{
    return head;
}

Node* List::getTail() const
{
    return tail;
}

void List::deleteNode(Iterator &current)
{
    this->deleteNode(current.node);
}

Deadline *List::findDish(const float &energyValue) const
{
    Iterator iterator;
    iterator = this->begin();
    iterator++;
    Dish* answer;
    answer = head->object;
    float difference;
    difference = absoluteDiff(answer->getEnergyValueOn100(), energyValue);
    for(; iterator != nullptr; iterator++)
    {
        if(absoluteDiff((*iterator)->getEnergyValueOn100(), energyValue) < difference)
        {
            answer = *iterator;
            difference = absoluteDiff((*iterator)->getEnergyValueOn100(), energyValue);
        }
    }
    return answer;
}

bool List::operator==(List const &existingList) const
{
    Iterator firstIterator, secondIterator;
    if( _length != existingList._length)
    {
        return false;
    }
    bool answer = true;
    for(firstIterator = Iterator(head), secondIterator = Iterator(existingList.getHead());
        firstIterator != nullptr; firstIterator++, secondIterator++)
    {
        if(*(*firstIterator) != *(*secondIterator))
        {
            answer = false;
        }
    }
    return answer;
}

bool List::operator!=(List const &existingList) const
{
    Iterator firstIterator, secondIterator;
    if( _length != existingList._length)
    {
        return true;
    }
    bool answer = false;
    for(firstIterator = Iterator(head), secondIterator = Iterator(existingList.getHead());
        firstIterator != nullptr; firstIterator++, secondIterator++)
    {
        if(*(*firstIterator) != *(*secondIterator))
        {
            answer = true;
            break;
        }
    }
    return answer;
}