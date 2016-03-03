#include "linkedlist.h"

linkedList::linkedList()
{
    head = tail = NULL;
    qty = 0;
}

linkedList::~linkedList()
{
    nukem();
}

bool linkedList::empty()
{
    return !qty;
}

void linkedList::clear()
{
    nukem();
}

size_t linkedList::size()
{
    return qty;
}

void linkedList::insert_at_head (baseNode* newNode)
{
    newNode->set_next(head);
    head = newNode;
    if (tail==NULL)
        tail = head;
    ++qty;
}

void linkedList::insert_at_tail(baseNode *newNode)
{
    if (head == NULL)
    {
        head = tail = newNode;
        qty++;
        return;
    }
    else
    {
    tail->set_next(newNode);
    tail = tail->get_next();
    qty++;
    }
}

void linkedList::remove_from_head()
{
    baseNode *delete_ptr = head;
    head = head->get_next();

    delete delete_ptr;
    --qty;
}


void linkedList::nukem()
{
    while (head != NULL)
        remove_from_head();
    tail = NULL;
    qty = 0;
}
