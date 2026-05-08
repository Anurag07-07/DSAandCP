//
// Created by anura on 09-05-2026.

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr,int start,int end) {
    int pos = start;

    for (int i = start; i <= end; ++i) {
        if (arr[i]<=arr[end]) {
            swap(arr[pos],arr[i]);
            pos++;
        }
    }

    return pos-1;
}

void QuickSort(vector<int>& arr,int start,int end) {
    if (start>=end) return;

    //Find Pivot
    int pivot = partition(arr,start,end);
    //Apply sorting in left array
    //Apply sorting in left array
    QuickSort(arr,start,pivot-1);
    QuickSort(arr,pivot+1,end);
}

int main() {
    vector<int> arr{4,8,3,1,2,1,1,5,1,3};
    int start = 0;
    int end = arr.size();
    QuickSort(arr,start,end);

    for (auto x: arr) {
        cout << x << " ";
    }
    return 0;
}

