#pragma once
#include <algorithm>
#define REMOVE_BY_VALUE(vector, value) vector.erase(std::remove(vector.begin(), vector.end(), value), vector.end());
