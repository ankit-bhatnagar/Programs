/*
 * Author:      Deepak Singh Rawat (drawat@usc.edu)
 *
 */
#include <iostream>

#include "myqueue.h"

using namespace std;

int main()
{
    cout << "Queue Test - General Test\n";
    MyQueue test_queue(5);
    MyQueue test_queue1(5);

    test_queue.enqueue(12);
    test_queue.enqueue(15);
    test_queue.enqueue(32);
    test_queue.enqueue(5);
    cout << test_queue.dequeue() << endl;
    cout << test_queue.dequeue() << endl;
    cout << test_queue.dequeue() << endl;
    cout << test_queue.dequeue() << endl;

    cout << "Queue Test - Over flow Test\n";
    try
    {
        test_queue.enqueue(12);
        test_queue.enqueue(12);
        test_queue.enqueue(12);
        test_queue.enqueue(12);
        test_queue.enqueue(12);
        /* Uncomment to test */
        //test_queue.enqueue(12);
        cout << "No Overflow - Uncomment to test\n";
    }
    catch (int e)
    {
        if (e == QUEUE_FULL_EXCEPTION)
        {
            cout << "Overflow Exception Occured\n";
        }
    }

    cout << "Queue Test - Under flow Test\n";
    try
    {
        test_queue1.enqueue(12);
        test_queue1.dequeue();
        /* Uncomment to test */
        //test_queue1.dequeue();
        cout << "No Underflow - Uncomment to test\n";
    }
    catch (int e)
    {
        if (e == QUEUE_EMPTY_EXCEPTION)
        {
            cout << "Underflow Exception Occured\n";
        }
    }

    return 0;
}
