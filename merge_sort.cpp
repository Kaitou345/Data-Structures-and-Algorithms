#include <iostream>
#include <string>

using namespace std;

template <typename T>
void merge(T* array, int left, int mid, int right)
{
    int left_size = mid - left + 1;
    int right_size = right - mid;
    

    T* left_array = new T[left_size];
    T* right_array = new T[right_size];
    
    int left_index = 0;
    for(int i = left; i <= mid; i++)
    {
        left_array[left_index] = array[i];
        left_index++;
    }

    int right_index = 0;
    for(int i = mid + 1; i <= right; i++)
    {
        right_array[right_index] = array[i];
        right_index++;
    }

    left_index = 0;
    right_index = 0;
    int i = left;
    while(left_index < left_size && right_index < right_size)
    {
        if(left_array[left_index] < right_array[right_index])
        {
            array[i] = left_array[left_index];
            left_index++; i++;
            
        }
        else
        {
            array[i] = right_array[right_index];
            right_index++; i++;
        }
    }      

    while (left_index < left_size)
    {
        array[i] = left_array[left_index];
        left_index++; i++;
    }
    
    while (right_index < right_size)
    {
        array[i] = right_array[right_index];
        right_index++; i++;
    }
}

/// Takes the array to sort, the leftmost and the rightmost index
template <typename T>
void merge_sort(T* array, int left, int right)
{
    if(left - right == 0)
    {
        return;
    }

    int mid = (left + right) / 2;
    merge_sort(array, left, mid);
    merge_sort(array, mid + 1, right);


    merge<T>(array, left, mid, right);
}

int main()
{
    int arr[] = {5,4,3,2,1};
    merge_sort<int>(arr, 0, 4);

    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}