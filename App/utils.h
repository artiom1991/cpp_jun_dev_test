#pragma once
#include <vector>


template <typename T>
std::vector<T> slice(const std::vector<T>& vec, int start, int end) {                                               // Кастомный метод для более удобного получения элементов по индексу
    if (start < 0) start = vec.size() + start;                                                                      // как положительных с начала так и отрицательных с конца вектора - 1, -2, ...
    if (end < 0) end = vec.size() + end;
    return std::vector<T>(vec.begin() + start, vec.begin() + end);
}
