#ifndef TASK_1_H
#define TASK_1_H

#include <iostream>

using namespace std;

template <typename T>

struct stack
{
    T Data;
    stack *next = nullptr;
};

template <typename T>
struct queue
{
    T Data;
    queue *next = nullptr;
    queue *prev = nullptr;
};

template <typename T>
class Container {
public:
virtual void push(T value) = 0;
virtual T pop() = 0;
virtual bool isEmpty()= 0;
};

template <typename T>
class Stack : public Container<T>
{
protected:
    stack<T> *head;
public:
    Stack() : head(nullptr){}
    ~Stack()
    {
        stack<T> *current = this->head;
        while(current != nullptr)
        {
            stack<T> *next = current->next;
            delete current;
            current = next;
        }
        cout << "Stack has been deleted" << endl; 
    }

    bool isEmpty()
    {
        return this->head == nullptr ? true : false;
    }

    void push(T value)
    {
        stack<T> *newNode = new stack<T>;
        newNode->next = this->head;
        newNode->Data = value;
        head = newNode;
        printList(head);
    }

    T pop()
    {
        if(isEmpty())
        {
            cout << "there is nothing to pop!!" << endl;
            return 0;
        }
        else
        {
            stack<T> *firstNode = this->head;
            head = head-> next;
            delete firstNode;
            printList(head);
            return 0;
        }
    }

    void printList(stack<T> *head)
    {
        while (head) 
        {
            if (head->next == NULL)
                cout << " [" << head->Data << "] " << " [" << head << "]->" << " (nil)" << endl;
            else
                cout << " [" << head->Data << "] " << " [" << head << "]->" << head->next << endl;
            head = head->next;
        }
        cout << endl << endl;
    }

}; 

template <typename T>
class Queue : public Container<T>
{
protected:
    queue<T> *head;
    queue<T> *tail;
public:
    Queue() : head(nullptr), tail(nullptr){}
    ~Queue()
    {
        queue<T> *current = this->head;
        while(current != nullptr)
        {
            queue<T> *next = current->next;
            delete current;
            current = next;
        }
        cout << "Queue has been deleted" << endl; 
    }
    
    bool isEmpty()
    {
        return (this->head == nullptr) ? true : false;
    }

    void push(T value)
    {
        queue<T> *newNode = new queue<T>;
        if(isEmpty())
        {
            newNode->Data = value;
            this->head = newNode;
            this->tail = newNode;
        }
        else
        {
            queue<T> *temp =  this->head;
            temp->prev = newNode;
            newNode->Data = value;
            newNode->next = temp;
            this->head = newNode;
        }  
        printList(head);
    }

    T pop()
    {   
        if(isEmpty())
        {
            cout << "there is nothing to pop!!" << endl;
            return 0;
        }
        else
        {
            queue<T> *lastNode = this->tail;
            if (lastNode->prev != nullptr)
                lastNode->prev->next = nullptr;
            tail = tail->prev;
            delete lastNode;
            if(tail == nullptr)
            {
                head = tail;
                return 0;
            }
            printList(head);
            return 0;
        }
    }

    void printList(queue<T> *head)
    {
        while (head) 
        {
            if (head->next == NULL)
                cout << " [" << head->Data << "] " << " [" << head << "]->" << " (nil)" << endl;
            else
                cout << " [" << head->Data << "] " << " [" << head << "]->" << head->next << endl;
            head = head->next;
        }
        cout << endl << endl;
    }

};

#endif