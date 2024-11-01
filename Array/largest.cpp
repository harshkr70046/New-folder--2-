#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void input_array(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        int num;
        cout<<"\nenter the element of the array = ";
        cin>>num;
        arr.push_back(num);
    }
}
void print_array(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"     ";
    }
    cout<<endl;
}
// Q1. largest element of the array
int largest_ele(vector<int>&arr,int n){
    int max_ele = -1;
    for(int i=0;i<n;i++){
        if(arr[i]>max_ele){
            max_ele = arr[i];
        }
    }
    return max_ele;
}
// Q2.second largest element of the array;
int second_larger(vector<int>&arr,int n){
    int larg_ele = -1;
    int second_large = -1;
    for(int i=0;i<n;i++){
        if(arr[i]>larg_ele){
            second_large = larg_ele;
            larg_ele = arr[i];
        }
        if(arr[i]>second_large && arr[i]<larg_ele){
            second_large = arr[i];
        }

    }
    return second_large;
}
// Q3.check is the array is sorted or not
bool is_sorted(vector<int>&arr,int n){
    for(int i=1;i<n;i++){
        if(arr[i-1]>arr[i]) return false;
    }
    return true;
}
// Q4. remove duplicate from sorted array;
vector<int> duplicate_remove(vector<int>&arr,int n){
    vector<int>ans;
    for(int i=0;i<n;i++){
        if(ans.empty() || ans.back()!=arr[i]){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}
// Q5. rotate array by one place
void rotate_array_anti_clock(vector<int>&arr,int n){
    int temp = arr[0];
    for(int i=1;i<n;i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}
// Q.6 rotate array by one polace clock wise 
void rotate_array_clock_wise(vector<int>&arr,int n){
    int temp = arr[n-1];
    for(int i=n-1;i>=1;i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}
// Q7.left rotate by d place
void reverse(vector<int>&arr,int start,int end){
    while(start<end){
        swap(arr[start++],arr[end--]);
    }
}
void left_rotate_by_d_place(vector<int>&arr,int n,int d){
    d = d % n; // Handle cases where d >= n
    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);
}
// Q.8 linear search
bool linear_search(vector<int>&arr,int n,int target){
    for(int i=0;i<n;i++){
        if(arr[i]==target) return true;
    }
    return false;
}
// Q9.move zero to end;
void zero_mover(vector<int>&arr,int n){
    int ind = -1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            ind = i;
            break;
        }
    }
    if(ind==-1) return;
    int i = ind;
    int j = ind+1;
    while(j<arr.size()){
        if(arr[j]!=0){
            swap(arr[i],arr[j]);
            i++;
        }
        j++;
    }
}
// Q10. union of two array
vector<int> union_of_two_array(vector<int>&arr,vector<int>&brr,int n,int m){
    vector<int>ans;
    int i = 0,j = 0;
    while(i<n && j<m){
        if(arr[i]==brr[i]){
            ans.push_back(arr[i]);
            i++;
            j++;
        }
        else if(arr[i]<arr[j]) i++;
        else j++;
    }
    return ans;
}
int main(){
    int n;
    cout<<"\nenter the size of the array = ";
    cin>>n;
    vector<int>arr;
    input_array(arr,n);
    print_array(arr,n);
    // cout<<"\nlargest_ele = "<<largest_ele(arr,n);
    // cout<<"\nSecond_largest_ele = "<<second_larger(arr,n);
    // cout<<"\nis_sorted = "<<is_sorted(arr,n);
    // vector<int>ans = duplicate_remove(arr,n);
    // cout<<endl;
    // print_array(ans,ans.size());
    // zero_mover(arr,n);
    // print_array(arr,n);
}