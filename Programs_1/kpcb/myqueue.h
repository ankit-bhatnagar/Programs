/*
 * Author:      Deepak Singh Rawat (drawat@usc.edu)
 *
 */
#include <cstddef>

#define QUEUE_FULL_EXCEPTION    -1001
#define QUEUE_EMPTY_EXCEPTION   -1002

struct QueueElem
{
    int data;
    struct QueueElem * next;
};

class MyQueue
{
    private:
        QueueElem * head;
        QueueElem * tail;
        unsigned int queue_capacity;
        unsigned int queue_current_length;
    public:
        MyQueue(int capacity);
        int enqueue(int item);
        int dequeue();
};
