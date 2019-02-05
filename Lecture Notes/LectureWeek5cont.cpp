#include <iostream>
#include <string>
using namespace std;

/*

Array Implementation:

	Back to static memory, indexes referencing an array!
	when top == 0, means empty

	private:
		int top; //top points to the next empty cell
		string a[maxsize]; //hardcoded
	public:
		void constructor () {
			top = 0;
			count = 0;
		}

		bool isFull () {
			check if top == maxsize
			return true;
		}

		bool isEmpty () {
			check if top == 0
			return true;
		}

		void push (newItem) {
			if (!isFull()) {
				a[top] = newItem;
				top++;
			}
			else cout << "stack overflow\n";
		}

		string pop() {
			out = "";
			if (!isEmpty()) {
				out = a[top];
				top --;
			}
			else {
				cout << "Stack is empty\n";
			} 
			return out;

		}

-------------------------------------------------------------------

Queue:

	- similar to stack
	- allows for specific order of perations
	- enqueue: to add a new element, always add at the tail
	- dequeue: to remove element, always remove from queue
	- A FIFO

	Sample Application:
	- Read and write commands are queued up in fast DRAM
	
	Implementations:
	- Can do a LL or and Array
		
		Simple Linear Queue:
		- When adding in, just increment the tail
		- When removing, remove from head
		- inefficient!!!! 

		Circular array Queue:
		- allow for both head and tail to shift
		- tail points to where the next element will go
		- head actually points to an element
		- when tail/head hits the limit, we have to reset to zero (the circular aspect)
		- if head = tail, return that the queue is full or empty
			* keep track with a varible called qsize, adding when tail moves and subtracting when thead moves
	Q ADP Implementayion:
		private:
			head;
			tail;
			queue size;
			data;
		public: 
			init // constructor
			isEmpty ();
			isFull();
			enque(newItem);
			item deque
			display();

	Circular Array Implementation:
		#define MAXSIZE
		class QueArrCir {
			private:
				int head, size, queSizeCurr;
				string a[MAXSIZE] // data

			public: 
				queArrCirc {    // constructor
					head = 0;
					tail = 0;
					queSize = 0;
				}
				bool isEmpty() {
					queSize == 0;
					return true
				}
				bool isFull() {
					queSize == MAXSIZE
					return true
				}
				void enque(string item) {
					// when enquing we only deal with the tail
					if(!isFull()){
						a[tail] = item;
						if(tail == MAXSIZE - 1) {
							tail = 0;
						}
						else tail++;
					}
				}

		}
		-





*/
int main() {
	return 0;
}
