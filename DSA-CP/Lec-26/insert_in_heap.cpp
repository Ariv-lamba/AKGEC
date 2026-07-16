#include<iostream>
using namespace std;

class MaxHeap
{
public:
    int arr[100];
    int size;

    MaxHeap()
    {
        size = 0;
    }

    void insert(int val)
    {
        size++;

        int index = size - 1;

        arr[index] = val;

        while(index > 0)
        {
            int parent = (index - 1) / 2;

            if(arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                break;
        }
    }

    void print()
    {
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main()
{
    MaxHeap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    return 0;
}