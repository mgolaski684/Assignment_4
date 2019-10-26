#include <iostream>
#include <cstdlib>
using namespace std;
#define SIZE 10

// Class for queue
class queue
{
	int* arr;		// array to store queue elements
	int capacity;	// maximum capacity of the queue
	int front;		// front points to front element in the queue (if any)
	int rear;		// rear points to last element in the queue
	int count;		// current size of the queue

public:
	queue(int size = SIZE); 	// constructor
	~queue();   				// destructor

	void pop();
	void push(int x);
	int peek();
	int size();
	bool isEmpty();
	bool isFull();
};

// Constructor to initialize queue
queue::queue(int size)
{
	arr = new int[size];
	capacity = size;
	front = 0;
	rear = -1;
	count = 0;
}

// Destructor to free memory allocated to the queue
queue::~queue()
{
	delete arr;
}

// Utility function to remove front element from the queue
void queue::pop()
{
	// check for queue underflow
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Popping " << arr[rear] << " out of the Stack" << '\n';

	rear = (rear - 1) % capacity;
	count++;
}

// Utility function to add an item to the queue
void queue::push(int item)
{
	// check for queue overflow
	if (isFull())
	{
		cout << "OverFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Pushing " << item << " into the Stack" <<'\n';

	rear = (rear + 1) % capacity;
	arr[rear] = item;
	count++;
}

// Utility function to return front element in the queue
int queue::peek()
{
	if (isEmpty())
	{
		cout << "UnderFlow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	return arr[front];
}

// Utility function to return the size of the queue
int queue::size()
{
	return count;
}

// Utility function to check if the queue is empty or not
bool queue::isEmpty()
{
	return (size() == 0);
}

// Utility function to check if the queue is full or not
bool queue::isFull()
{
	return (size() == capacity);
}

// main function
int main()
{
	// create a queue of capacity 5
	queue q(5);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	//cout << "Front element is: " << q.peek() << endl;
	//cout << "Queue size is " << q.size() << endl;
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	if (q.isFull())
		cout << "Queue is Full\n";
	else
		cout << "Queue is not full\n";

	if (q.isEmpty())
		cout << "Queue Is Empty\n";
	else
		cout << "Queue Is Not Empty\n";
	return 0;
}