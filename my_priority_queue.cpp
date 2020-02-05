#include <iostream>
using namespace std;

// Data structure for Max Heap
int sz=100005;
template<class X>
class PriorityQueue
{
private:
        int cnt;
        X *A;

        void heapify_down(int i)
	{
		int left = i*2;
		int right = i*2 + 1;
		int largest = i;
		if (left <= cnt && A[left] > A[i])
			largest = left;
		if (right <= cnt && A[right] > A[largest])
			largest = right;
		if (largest != i) {
			swap(A[i], A[largest]);
			heapify_down(largest);
		}
	}

	void heapify_up(int i)
	{
		if (i>1 && A[i/2] < A[i])
		{
			swap(A[i], A[i/2]);
			heapify_up(i/2);
		}
	}

public:
        PriorityQueue(int SZ=sz )
        {
                A=new X[SZ];
                cnt=0;
        }

        int size(){return cnt;}
	bool empty(){return cnt == 0;}

	void push(X key)
	{
		cnt++;
		A[cnt]=(key);
		heapify_up(cnt);
	}

	void pop()
	{
                A[1] = A[cnt];
                cnt--;
                heapify_down(1);
	}

	X top(){return A[1];}
};

// Max Heap C++ implementation
int main()
{
	PriorityQueue<int>pq;

	// Note - Priority is decided by element's value

	pq.push(3);
	pq.push(2);
	pq.push(15);

	cout << "Size is " << pq.size() << endl;

	cout << pq.top() << " ";
	pq.pop();

	cout << pq.top() << " ";
	pq.pop();

	pq.push(5);
	pq.push(4);
	pq.push(45);

	cout << endl << "Size is " << pq.size() << endl;

	cout << pq.top() << " ";
	pq.pop();

	cout << pq.top() << " ";
	pq.pop();

	cout << pq.top() << " ";
	pq.pop();

	cout << pq.top() << " ";
	pq.pop();

	cout << endl <<  pq.empty();

	pq.top();	// top operation on an empty heap
	pq.pop();	// pop operation on an empty heap

	return 0;
}
