// Hello!

#include <iostream>
#include <sstream>
#include <string>
#include "stack.h"

using namespace std;

int main()
{

    stack<char*> myStack, myOtherStack;
    char* list = "Here I am it's me!";
    stringstream ss;

    ss << list;

    ss >> myOtherStack;

    cout<<myOtherStack;



    return 0;
}


//Adding
//A
//Bunch
//Of
//Stuff Here
