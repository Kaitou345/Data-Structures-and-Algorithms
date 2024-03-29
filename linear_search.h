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
