#include <iostream>
#include <array>

/// the template takes the array type and the size
/// Argument takes the std::array and the target to search
template<typename T, int S>
int binary_search(std::array<T, S>& array, T target)
{
    int first = 0; 
    int last = array.size() - 1;
    
    while (first <= last)
    {
        int mid = (first + last) / 2;

        if(array[mid] == target)
            return mid;
        else if(array[mid] <  target)
            first = mid  + 1;
        else
            last = mid - 1;
    }
    return -1;
}

void verify(int index)
{
    if(index == -1)
        std::cout << "FALSE " << index << std::endl;
    else
        std::cout << "TRUE " << index << std::endl;
    
}

int main()
{
    std::array<int, 10> arr = {1,2,3,4,5,6,7,8,9,10};


    int index = binary_search<int, arr.size()>(arr, 4);
    verify(index);
        
}