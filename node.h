#ifndef NODE
#define NODE
#include <iostream>
#include <cstdlib>
#include "basenode.h"

using std::ostream;
using std::istream;
using std::endl;

template<typename data_type>
class node : public baseNode
{
public:
    node(const data_type &v = data_type(), baseNode* N = NULL, baseNode* P = NULL);
    inline ~node();
    node(const node<data_type> &other);

    void operator=(const node<data_type> &other);
    
    void set_value (const data_type &new_value);
    data_type get_value ();
    
    template <typename D>
    friend
    std::ostream& operator<<(std::ostream& out, node<D> theNode);
    
    template <typename D>
    friend
    std::istream& operator>>(std::istream& in, node<D> theNode);
    
private:
    data_type value;
    void copy (const node<data_type> &other);
};

template<typename data_type>
node<data_type>::node(const data_type &v, baseNode* N, baseNode* P)
{
    value = v;
    next = N;
    prev = P;
}


template<typename data_type>
node<data_type>::~node<data_type>()
{
    value = data_type();
    next = prev = NULL;
}

template<>
inline node<char*>::~node<char*>()
{
    delete [] value;
    value = NULL;
    next = prev = NULL;
}

template <typename data_type>
node<data_type>::node(const node<data_type> &other)
{
    copy (other);
}

template <typename data_type>
void node<data_type>::operator=(const node<data_type> &other)
{
    if (this == &other)
        return;
    else
        copy (other);
}

template <typename data_type>
void node<data_type>::set_value (const data_type &new_value)
{
    value = new_value;
}

template <typename data_type>
data_type node<data_type>::get_value ()
{
    return value;
}

template <typename D>
ostream& operator<<(ostream& out, node<D> theNode)
{
    out << theNode.value;
    return out;
}

template <typename D>
istream& operator>>(istream& in, node<D> theNode)
{
    in >> theNode.value;
    return in;
}

template <typename data_type>
void node<data_type>::copy (const node<data_type> &other)
{
    value = other.value;
    prev = next = NULL;
}

#endif // NODE
