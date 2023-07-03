/*
We are given a sequence of numbers in array. We need to return a sorted sequence of given numbers in non decreasing order using merge sort algorithm.
*/
#include<bits/stdc++.h>
using namespace std;

void Merge(vector<int>&arr,int low,int mid,int high)
{
    vector<int>temp;
    int i=low,j=mid+1;
    while(i<=mid && j<=high)
    {
        if(arr[i]<arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=high)
    {
        temp.push_back(arr[j]);
        j++;
    }
    int z=0;
    for(int k=low;k<=high;k++)
    {
        arr[k]=temp[z];
        z++;

    }
}
void MergeSort(vector<int>&arr,int low,int high)
{
    if(low<high)
    {
        int mid=low+(high-low)/2;
        MergeSort(arr,  low, mid);
        MergeSort(arr, mid+1, high);
        Merge(arr,low,mid,high);
    }
}
void mergeSort(vector < int > & arr, int n)
{
   int low=0,high=n-1;
   MergeSort(arr,low,high);
}

int main()
{
    int t,n;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        mergeSort(arr,n);
        for(int i=0;i<n;i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}