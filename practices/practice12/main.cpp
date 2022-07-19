#include "queue.h"
#include "circular_queue.h"
#include "customer.h"
#include "photo_order.h"

#include <iostream>

#define INPUT_BOOL_ARRAY_SIZE 10

using namespace std;
using namespace cvs_stores::cvs_orders;

//-------------------------------------------------------------------------------------------
//assume everything like the input and input array size are all valid.
unsigned short BitsToDecimal(bool (&input)[INPUT_BOOL_ARRAY_SIZE]) {
	unsigned short result = 0x00;
	
	for (int i = 0; i < INPUT_BOOL_ARRAY_SIZE; i++) {
		result |= input[i] << (INPUT_BOOL_ARRAY_SIZE - 1 - i);
	}

	return result;
}
//-------------------------------------------------------------------------------------------

/*
 There are three parts in the main():
 
 Part1: test Question: Write a 10 Bit array to 2 Btyes function.
	   Given size 10 array, with values either true or false. 
	   Convert the input array into unsigned short, then return.
 
 Part2: test the Queue and CircularQueue. 
                       Queue (base)
                           |
                           | public inherit
                           |
                      Circular Queue (derive)


 Part3: test CVS Photo Order Queue. CVS means the CVS pharmacy I am working at.
 Improvements: use Json objects as input data.

                                            (vendor)     send
                Customer ----------------> PhotoOrder ==========> Order_Queue (workers can see the queue) 
		           (association)
*/

int main() {	
	//Part 1
	cout << "\nPart 1:\n\n";
	bool input[INPUT_BOOL_ARRAY_SIZE] = { true, false, false, false, true, true, true, false, true, true};

    for (int i = 0; i < 10; i++) {
        cout << input[i];
    }

	cout << "\n";

	//cout << hex << BitsToDecimal(input); //using std::hex is bad because this overrides cout for numbers like 10 will now be a.
	cout << BitsToDecimal(input);
	cout << "\n-------------------------------------------------------------\n";
	cout << "Part 2:\n\n";
	/*  
	  when I set the queue capacity to 7, the message from Full() will print out. 
	  Since Full() a virtual function, 
	  for Queue is 
		"private member function Full() from queue."
	  for CircularQueue is 
		"private member function Full() from circular_queue."
	*/

	try {
		//Part 2
		my_queues::Queue<int>* q = new my_queues::Queue<int>(8);
		my_queues::Queue<int>* q1 = new my_queues::CircularQueue<int>(8);

		cout << "Normal queue with default capacity 8\n";
		q->Enqueue(1);
		q->Enqueue(2);
		q->Enqueue(3);
		q->Enqueue(4);
		q->Enqueue(5);
		q->Enqueue(6);
		q->Enqueue(7);
		q->Enqueue(8);
		q->Display();
		cout << "Dequeue(): " << q->Dequeue() << "\n";
		cout << "Peek(): " << q->Peek() << "\n";
		cout << "Dequeue(): " << q->Dequeue() << "\n";
		cout << "Dequeue(): " << q->Dequeue() << "\n";
		cout << "Dequeue(): " << q->Dequeue() << "\n";
		cout << "Peek(): " << q->Peek() << "\n";
		cout << "Dequeue(): " << q->Dequeue() << "\n";
		cout << "Dequeue(): " << q->Dequeue() << "\n";
		cout << "Dequeue(): " << q->Dequeue() << "\n";
		cout << "Dequeue(): " << q->Dequeue() << "\n";
		q->Display();
		cout << "Queue size: " << q->get_current_size();

		delete q;

		cout << "\n\n";

		cout << "Circular Queue with default capacity 8\n";
		q1->Enqueue(1);
		q1->Enqueue(2);
		q1->Enqueue(3);
		q1->Enqueue(4);
		cout << "Peek(): " << q1->Peek() << "\n";
		q1->Enqueue(5);
		q1->Enqueue(6);
		q1->Enqueue(7);
		q1->Enqueue(8);
		cout << "Dequeue(): " << q1->Dequeue() << "\n";
		cout << "Dequeue(): " << q1->Dequeue() << "\n";
		q1->Enqueue(9);
		q1->Enqueue(10);
		cout << "Peek(): " << q1->Peek() << "\n";
		cout << "Updated queue\n";
		q1->Display();
		cout << "Circular Queue size: " << q1->get_current_size();

		delete q1;
		cout << "\n\n";
		//Part 3
		cout << "\n-------------------------------------------------------------\n";
		cout << "Part 3:\n\n";

		//customers go to CVS and fill in their information to develop their camera film roll.
		Customer* customer1 = new Customer("John", "johneie123@gmail.com", "975-222-3333", "10-4'x6'");
		Customer* customer2 = new Customer("John", "johneie123@gmail.com", "975-222-1033", "20-8'x10'");
		Customer* customer3 = new Customer("John", "johneie123@gmail.com", "975-222-5958", "3-8'x11'");
		Customer* customer4 = new Customer("Berry", "berry222@yahoo.com", "745-222-1356", "28-4'x6'");
		Customer* customer5 = new Customer("Kolin", "kolin@gmail.com", "301-252-6333", "9-4'x6'");
		Customer* customer6 = new Customer("Mary", "maryling@yahoo.com", "202-222-0125", "2-8'x10'");
		Customer* customer7 = new Customer("Lin", "Lin-yyu0101@gmail.com", "301-251-4561", "30-4'x6'");
		Customer* customer8 = new Customer("Nacy", "Nancy999@yahoo.com", "202-331-7979", "1-8'x10'");

		//customers make photo orders from differen stores. Photo orders will get sent to the vendor from CVS stores. 
		PhotoOrder* order1 = new PhotoOrder(5674, "GM646KW9", *customer1);
		PhotoOrder* order2 = new PhotoOrder(5674, "GM646KW9", *customer2);
		PhotoOrder* order3 = new PhotoOrder(5674, "GM646KW9", *customer3);
		PhotoOrder* order4 = new PhotoOrder(5674, "GM646KW9", *customer4);
		PhotoOrder* order5 = new PhotoOrder(5674, "GM646KW9", *customer5);
		PhotoOrder* order6 = new PhotoOrder(5674, "GM646KW9", *customer6);
	    PhotoOrder* order7 = new PhotoOrder(5674, "GM646KW9", *customer7);
		PhotoOrder* order8 = new PhotoOrder(5674, "GM646KW9", *customer8);

		my_queues::Queue<PhotoOrder>* order_queue = new my_queues::Queue<PhotoOrder>(8);
		my_queues::Queue<PhotoOrder>* order_recieve_queue = new my_queues::Queue<PhotoOrder>();

		//vendor recieves orders.		
		order_queue->Enqueue(*order1);
		order_queue->Enqueue(*order2);
		order_queue->Enqueue(*order3);
		order_queue->Enqueue(*order4);
		order_queue->Enqueue(*order5);
		order_queue->Enqueue(*order6);
		order_queue->Enqueue(*order7);
		order_queue->Enqueue(*order8);
		
		//Now, a worker checks the computer and sees a list of orders. 
		//So, Dequeue(), process film roll to digital photos, and then send them back to CVS stores in digital form. 
		order_queue->Display();
		cout << "Vendor worker is now processing orders...\n";
		cout << "Sending back to the CVS store.\n";

		for (int i = 0; i < 8; i++) {
			order_recieve_queue->Enqueue(order_queue->Dequeue());
		}

		cout << "\nCompleted!\n\n";

		cout << "CVS store 5674 import Photo Queue: \n";
		order_recieve_queue->Display();

	} catch (const char* message) {
		cout << message << "\n";
	}
	
	return 0;
}
