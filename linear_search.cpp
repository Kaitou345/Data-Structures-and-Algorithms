#include <iostream>
#include <array>

/// the template takes the array type and the size
/// Argument takes the std::array and the target to search
template<typename T, int S>
int linear_search(std::array<T, S>& array, T target)
{
    for(int i = 0; i < array.size(); i++)
    {
        if(array[i] == target)
            return i;
    }

    return -1;
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
    std::array<int, 10> arr = {1,2,3,4,5,6,7,8,9,10};

    int index = linear_search<int, arr.size()>(arr, 12);  
    verify(index);
}