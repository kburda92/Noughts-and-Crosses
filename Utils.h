#ifndef UTILS_H
#define UTILS_H
#include <array>
#include <QList>

//template method checking does array contains desired value
template<std::size_t size>
bool ContainsValue(std::array<int, size>& tab, int desired_value)
{
    return std::any_of(begin(tab), end(tab),[desired_value](int value) {return value == desired_value;});
}

//template method converting std array to QList
template<std::size_t size>
QList<int> ConvertArrayToQList(const std::array<int, size>& tab)
{
    QList<int> list;
    for(auto& var : tab)
        list.append(var);
    return list;
}



#endif // UTILS_H
