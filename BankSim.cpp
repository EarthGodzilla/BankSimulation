#include <iostream>
#include <cstdlib>
#include <ctime>
#include "QueType.h"

using namespace std;

int main()
{
    QueType queue(10);

    int served = 0;
    int turnedAway = 0;
    int idle = 0;

    char customer = 'A';
    char item;

    srand(time(0));

    for (int i = 0; i < 100; i++)
    {
        int action = rand() % 3; // 0,1 = enqueue and 2 = dequeue

        // enqueue (2x more likely)
        if (action < 2)
        {
            try
            {
                queue.Enqueue(customer);
                cout << "Enqueued: " << customer <<"\n";

                customer++;
                if (customer > 'Z'){ 
                    customer = 'A';
                }
            }
            catch (FullQueue)
            {
                turnedAway++;
                cout << "Customer turned away (full)\n";
            }
        }
        else // dequeue
        {
            try
            {
                queue.Dequeue(item);
                served++;
                cout << "Served: " << item <<"\n";
            }
            catch (EmptyQueue)
            {
                idle++;
                cout << "Teller idle (empty)\n";
            }
        }
        cout << "Queue: ";
        queue.PrintQueue();
        cout <<"\n" << "------------------\n";
    }

    cout << "\n--- Simulation Results ---\n";
    cout << "Served customers: " << served <<"\n";
    cout << "Customers left in line: " << queue.GetLength() <<"\n"; 
    cout << "Turned away: " << turnedAway <<"\n";
    cout << "Idle times: " << idle <<"\n";

    return 0;
}