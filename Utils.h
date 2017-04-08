#ifndef UTILS_H
#define UTILS_H
#include <array>

//template method checking does array contains desired value
template<std::size_t size>
bool ContainsValue(std::array<int, size>& tab, int desired_value)
{
    return std::any_of(begin(tab), end(tab),[desired_value](int value) {return value == desired_value;});
}



#endif // UTILS_H
