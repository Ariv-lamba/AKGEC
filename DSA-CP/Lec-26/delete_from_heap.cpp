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

    void deleteRoot()
    {
        if(size == 0)
            return;

        arr[0] = arr[size - 1];

        size--;

        int i = 0;

        while(true)
        {
            int largest = i;

            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if(left < size && arr[left] > arr[largest])
                largest = left;

            if(right < size && arr[right] > arr[largest])
                largest = right;

            if(largest == i)
                break;

            swap(arr[i], arr[largest]);

            i = largest;
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

    cout << "Before Delete\n";
    h.print();

    h.deleteRoot();

    cout << "After Delete\n";
    h.print();

    return 0;
}