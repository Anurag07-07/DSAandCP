//
// Created by anura on 24-05-2026.
//
//
// Created by anura on 24-05-2026.
//
#include <bits/stdc++.h>
using namespace std;

bool Brute(vector<vector<int>> matrix,int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; ++i) {
        if (matrix[i][0]>=target && target<=matrix[i][m-1]) {
            int start = 0;int end = m-1;
            while (start<=end) {
                int mid = start+(end-start)/2;
                if (matrix[i][mid]==target) {
                    return true;
                }else if (matrix[i][mid]>target) {
                    end = mid-1;
                }else {
                    start = mid+1;
                }
            }
        }
    }
    return false;
}

bool Better(vector<vector<int>> matrix,int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int start = 0;
    int end = n*m-1;
    while (start<=end) {
        int mid = start+(end-start)/2;
        int row = mid/m;
        int col = mid%m;
        if (matrix[row][col]==target) {
            return true;
        }else if (matrix[row][col]>target) {
            end = mid-1;
        }else {
            start = mid+1;
        }
    }
    return false;
}

bool Optimal(vector<vector<int>> matrix,int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int i = 0;int j = m-1;
    while (i<n && j>=0) {
        if (matrix[i][j]==target) {
            return true;
        }else if (matrix[i][j]>target) {
            j--;
        }else {
            i++;
        }
    }
    return false;
}


int main(int argc, char *argv[]) {
    vector<vector<int>> nums{
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}};
    int target = 2;
    cout<<Brute(nums,target);
    cout<<Better(nums,target);
    cout<<Optimal(nums,target);
}
