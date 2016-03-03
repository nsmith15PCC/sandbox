#ifndef LINKEDLIST
#define LINKEDLIST
#include <iostream>
#include <cstdlib>

#include "node.h"

class linkedList
{
public:
    linkedList();
    virtual ~linkedList();
    linkedList(const linkedList& other);

    void operator=(const linkedList& other);

    bool empty();
    void clear();

    size_t size();

    void insert_at_head (baseNode* newNode);

    void insert_at_tail (baseNode* newNode);

    void remove_from_head();

protected:
    baseNode *head, *tail;
    size_t qty;
    void nukem();
};

#endif // LINKEDLIST

