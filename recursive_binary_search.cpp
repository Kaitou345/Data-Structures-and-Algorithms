#include <iostream>
#include <array>

/// Takes the array to search, the first index, the last index 
/// and the target to search
template <typename T>
int recursive_binary_search(T* array, int first, int last, T target)
{
    if(first > last)
        return -1;
    else
    {
        int mid = (first + last) / 2;
        if(array[mid] == target)
        {
            return mid;
        }
        else if(array[mid] < target)
        {
            return recursive_binary_search(array, mid + 1, last, target);
        }    
        else
        {
            return recursive_binary_search(array, first, mid - 1, target);
        }
    }
}

void verify(int index)
{
    if(index == -1)
        std::cout << "FALSE" << std::endl;
    else
        std::cout << "TRUE" << std::endl;    
}



int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    int index = recursive_binary_search<int>(arr, 0, 9,1);  
    verify(index);
   
}
