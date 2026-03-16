#include <iostream>
#include "StackFactory.hpp"
using namespace std;

int main() {

    Stack<int>* s = StackFactory<int>::GetStack(0);         // make a stack (linked list)
    cout << "Pushing 67, 6767, 676767\n";
    s->push(67); s->push(6767); s->push(676767);
    s->print();              // push nums and print reults 

    cout << "Peek: " << s->peek() << endl;      // show peek

    cout << "Pop 1\n";
    s->pop();                   // popping and print
    s->print();

    cout << "Rotate L\n";
    s->rotate(Stack<int>::LEFT);            // rot L
    s->print();

    cout << "Rotate R\n";
    s->rotate(Stack<int>::RIGHT);            // rot R
    s->print();

    cout << "Length: " << s->getLength() << endl; // show length

    cout << "Pop all\n";
    s->pop();                               /// pop all of it and print
    s->pop();
    s->print();

    cout << "Is empty??: " << s->isEmpty() << endl;           // check empty 

    delete s;       // delete and end
    return 0;
}