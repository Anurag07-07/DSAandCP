cmake_minimum_required(VERSION 4.2)
project(DSA)

set(CMAKE_CXX_STANDARD 20)

add_executable(DSA
        Sorting/QuickSort.cpp
        Sorting/MergeSort.cpp
        Neetcode/ArrayandHashing/ConcatenationofArray.cpp
        Neetcode/ArrayandHashing/ContainsDuplicate.cpp
        Neetcode/ArrayandHashing/ValidAnagram.cpp
)
