#include <iostream>
using namespace std;

#define SIZE 100000
template <class X>
class stack
{
	X *arr;
	int at;
	int capacity;

public:
	stack(int size = SIZE)
        {
                arr = new X[size];
                capacity = size;
                at = -1;
        }
	void push(X x)
	{
                arr[++at] = x;
        }
	void pop()
	{
                at--;
        }
	X top()
	{
                return arr[at];
        }
	int size(){ return at + 1; }
	bool isEmpty(){  return at == -1; }

	~stack(){
		delete[] arr;
	}
};


// main function
int main()
{
	stack<string> pt;

	pt.push("A");
	pt.push("B");

	pt.pop();
	pt.pop();

	pt.push("C");

 	// Prints the at of the stack
 	cout << "at element is: " << pt.top() << endl;

	// Returns the number of elements present in the stack
	cout << "Stack size is " << pt.size() << endl;

	pt.pop();

	// check if stack is empty or not
	if (pt.isEmpty())
		cout << "Stack Is Empty\n";
	else
		cout << "Stack Is Not Empty\n";

	return 0;
}
