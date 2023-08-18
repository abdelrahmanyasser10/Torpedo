#ifndef TASK_1_H
#define TASK_1_H

#include <iostream>

using namespace std;




struct stack
{
    int Data = 0;
    stack *next = nullptr;
};

struct queue
{
    int Data = 0;
    queue *next = nullptr;
    queue *prev = nullptr;
};

class Container {
public:
virtual void push(int value) = 0;
virtual int pop() = 0;
virtual bool isEmpty()= 0;
};


class Stack : public Container
{
protected:
    stack *head;
public:
    Stack() : head(nullptr){}
    ~Stack()
    {
        stack *current = this->head;
        while(current != nullptr)
        {
            stack *next = current->next;
            delete current;
            current = next;
        }
        cout << "Stack has been deleted" << endl; 
    }

    bool isEmpty()
    {
        return this->head == nullptr ? true : false;
    }

    void push(int value)
    {
        stack *newNode = new stack;
        newNode->next = this->head;
        newNode->Data = value;
        head = newNode;
        printList(head);
    }

    int pop()
    {
        if(isEmpty())
        {
            cout << "there is nothing to pop!!" << endl;
            return 0;
        }
        else
        {
            stack *firstNode = this->head;
            head = head-> next;
            delete firstNode;
            printList(head);
            return 0;
        }
    }

    void printList(stack *head)
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

class Queue : public Container
{
protected:
    queue *head;
    queue *tail;
public:
    Queue() : head(nullptr), tail(nullptr){}
    ~Queue()
    {
        queue *current = this->head;
        while(current != nullptr)
        {
            queue *next = current->next;
            delete current;
            current = next;
        }
        cout << "Queue has been deleted" << endl; 
    }
    
    bool isEmpty()
    {
        return (this->head == nullptr) ? true : false;
    }

    void push(int value)
    {
        queue *newNode = new queue;
        if(isEmpty())
        {
            newNode->Data = value;
            this->head = newNode;
            this->tail = newNode;
        }
        else
        {
            queue *temp =  this->head;
            temp->prev = newNode;
            newNode->Data = value;
            newNode->next = temp;
            this->head = newNode;
        }  
        printList(head);
    }

    int pop()
    {   
        if(isEmpty())
        {
            cout << "there is nothing to pop!!" << endl;
            return 0;
        }
        else
        {
            queue *lastNode = this->tail;
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

    void printList(queue *head)
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