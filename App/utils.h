#pragma once
#include <vector>


template <typename T>
std::vector<T> slice(const std::vector<T>& vec, int start, int end) {                                               // ��������� ����� ��� ����� �������� ��������� ��������� �� �������
    if (start < 0) start = vec.size() + start;                                                                      // ��� ������������� � ������ ��� � ������������� � ����� ������� - 1, -2, ...
    if (end < 0) end = vec.size() + end;
    return std::vector<T>(vec.begin() + start, vec.begin() + end);
}
