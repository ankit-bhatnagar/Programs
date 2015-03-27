/*
 * Author:      Deepak Singh Rawat (drawat@usc.edu)
 *
 */
#include "myqueue.h"

MyQueue::MyQueue(int capacity)
{
    queue_capacity = capacity;
    queue_current_length = 0;
    head = NULL;
    tail = NULL;
}

void * MyQueue::enqueue(void * item)
{
    QueueElem * new_elem = new QueueElem;
    new_elem->data = item;
    new_elem->next = NULL;

    if (head == NULL)
    {
        /* First entry in the queue */
        head = new_elem;
    }
    else
    {
        /* If below capacity add the entry in the last */
        if (queue_current_length >= queue_capacity)
        {
            delete new_elem;
            throw QUEUE_FULL_EXCEPTION;
        }
        else
        {
            tail->next = new_elem;
        }
    }
    tail = new_elem;
    queue_current_length++;
    return item;
}

void * MyQueue::dequeue()
{
    QueueElem * temp_elem;
    void * temp_data;

    if (queue_current_length <= 0)
    {
        throw QUEUE_EMPTY_EXCEPTION;
    }
    else
    {
        temp_elem = head;
        head = temp_elem->next;
        temp_data = temp_elem->data;
        queue_current_length--;
        delete temp_elem;

        if (queue_current_length == 0)
        {
            /* head already set NULL in above step */
            tail = NULL;
        }
    }

    return temp_data;
}

bool MyQueue::isQueueEmpty()
{
    if (queue_current_length == 0)
        return true;
    else
        return false;
}

void MyQueue::deleteQueue()
{
    QueueElem * temp = head;

    if (head == NULL)
        return;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    head = NULL;
    tail = NULL;
}