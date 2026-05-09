cmake_minimum_required(VERSION 4.2)
project(DSA)

set(CMAKE_CXX_STANDARD 20)

add_executable(DSA
        Sorting/QuickSort.cpp
        Sorting/MergeSort.cpp
        Neetcode/ArrayandHashing/ConcatenationofArray.cpp
        Neetcode/ArrayandHashing/ContainsDuplicate.cpp
        Neetcode/ArrayandHashing/ValidAnagram.cpp
        Recursion/Print1toN.cpp
        Recursion/PrintNto1.cpp
        Recursion/PrintallEven.cpp
        Recursion/PrintAllOdd.cpp
        Recursion/FactorialofN.cpp
        Recursion/SumofN.cpp
        Recursion/Powerof2.cpp
        Recursion/SumofSquare.cpp
        Recursion/FibonacciSeries.cpp
        Recursion/NthStair.cpp
        Recursion/GCDofTwoNumber.cpp
        Biweekly182/ScoreValidator.cpp
        Recursion/PrintTheArray.cpp
        Recursion/SumofElement.cpp
        Recursion/MinimumElement.cpp
        Recursion/CheckPalindrone.cpp
        Recursion/CountVowels.cpp
        Recursion/ReverseTheString.cpp
        Recursion/LowerCaseAndUpperCase.cpp
)
