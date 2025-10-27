#pragma once

#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

template <typename T>
typename T::const_iterator easyfind(const T &container, int num);

#include "easyfind.tpp"

#endif