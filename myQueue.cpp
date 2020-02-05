#include <iostream>
using namespace std;

#define SIZE 100000
template <class X>
class queue
{
	X *arr;
	int capacity;
	int frnt;
	int rear;
	int count;

public:
	queue(int size = SIZE)
        {
                arr = new X[size];
                capacity = size;
                frnt = 0;
                rear = -1;
                count = 0;
        }
	void pop()
	{
                frnt = (frnt + 1) % capacity;
                count--;
        }
	void push(X item)
	{
                rear = (rear + 1) % capacity;
                arr[rear] = item;
                count++;
        }
	X front()
	{
                return arr[frnt];
        }
	int size(){ return count; }
	bool isEmpty(){ return (size() == 0); }
};


int main()
{
	queue<string> q;

	q.push("a");
	q.push("b");
	q.push("c");

	cout << "frnt element is: " << q.front() << endl;
	q.pop();

	q.push("d");

	cout << "Queue size is " << q.size() << endl;

	q.pop();
	q.pop();
	q.pop();

	if (q.isEmpty())
		cout << "Queue Is Empty\n";
	else
		cout << "Queue Is Not Empty\n";

	return 0;
}
