template <typename T>
LinkedListStack<T>::LinkedListStack(){
    // To do: construcotr??
    top = nullptr;
    this->length = 0;
}

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    // TO DO: Delete all the elements in the stack
    Node<T>* curr = top;            // make curr
    while (curr != nullptr){
        Node<T>* temp = curr;
        curr = curr->next;                  /// traverse and del as go
        delete temp;
    }
    top = nullptr;
    this->length = 0;               // stack empty and size reset
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    // TO DO: Implement copy 
    Node<T>* curr = copyObj.top;        // start at top
    Node<T>* last = nullptr;
    top = nullptr;                      // make stack empty
    this->length = 0;

    while (curr != nullptr){                    // traverse and make a new node
        Node<T>* newNode = new Node<T>(curr->data);

        if (top == nullptr){            // if empty then make top neww and last new
            top = newNode;
            last = newNode;
        }
        else{
            last->next = newNode;           // else attatch node to end
            last = newNode;
        }
        this->length++;             // increase length and move to next node
        curr = curr->next;
    }
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    return this->length;
}


template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
T LinkedListStack<T>::peek() const {
    // TO DO: implement peek
    if (isEmpty()){
        throw runtime_error("Stack is empty!!");
    }
    return top->data;           // literally return the data at top
}

template <typename T>
void LinkedListStack<T>::pop() {
    // TO DO: Implement pop
    if (isEmpty()){     // if empty return 
        return;
    }
    Node<T>* temp = top;        // save top and move top to next node
    top = top->next;
    delete temp;                // delete old top and decrease stack size
    this->length--;
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    // TO DO: Implement push
    Node<T>* newNode = new Node<T>(elem);
    newNode->next = top;        // make new node and then point it to current top
    top = newNode;              // move top 
    this->length++;             // increase length
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TO DO: Implement rotate
    if (this->length <= 1) {        // if 0-1 elem thee is nothing to rot
        return;
    }
    if (dir == Stack<T>::LEFT) {
        Node<T>* firstNode = top;           // save top node and make last node
        Node<T>* lastNode = top;             

        while (lastNode->next != nullptr) { //search for last node
            lastNode = lastNode->next;
        }
        top = firstNode->next;              // second node becomes new top and then detatch firt node and attatch to end
        firstNode->next = nullptr;
        lastNode->next = firstNode;
    }
    else {
        Node<T>* prevNode = nullptr;                
        Node<T>* lastNode = top;

        while (lastNode->next != nullptr) {
            prevNode = lastNode;                    // find last node
            lastNode = lastNode->next;
        }
        prevNode->next = nullptr;               // detatch and last node becomes new top
        lastNode->next = top;
        top = lastNode;
    }
}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        Node<T> *curr = top;
        while (curr != nullptr){
            cout <<  curr->data  << "\t";
            curr = curr->next;
        }
    }

    cout << endl;
}
