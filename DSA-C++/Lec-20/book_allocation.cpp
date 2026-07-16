#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int>& books, int students, int maxPages)
{
    int student = 1;
    int pages = 0;

    for(int i = 0; i < books.size(); i++)
    {
        if(books[i] > maxPages)
            return false;

        if(pages + books[i] <= maxPages)
        {
            pages += books[i];
        }
        else
        {
            student++;
            pages = books[i];

            if(student > students)
                return false;
        }
    }

    return true;
}

int allocateBooks(vector<int>& books, int students)
{
    if(students > books.size())
        return -1;

    int low = *max_element(books.begin(), books.end());

    int high = 0;

    for(int x : books)
        high += x;

    int ans = -1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(isPossible(books, students, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> books = {12,34,67,90};

    int students = 2;

    cout << "Minimum Maximum Pages = "
         << allocateBooks(books, students);

    return 0;
}