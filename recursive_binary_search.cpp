#include <iostream>
#include <array>

int recursive_binary_search(int* array, int first, int last, int target)
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
            return recursive_binary_search(array, first, mid, target);
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



    int index = recursive_binary_search(arr, 0, 9, 1);  
    verify(index);
   
}
