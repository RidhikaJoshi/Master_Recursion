/*
We are given a sequence of numbers in array. We need to return a sorted sequence of given numbers in non decreasing order using quick sort algorithm.
*/
#include <bits/stdc++.h> 
using namespace std;
int partition(vector<int>&arr,int low,int high)
{
    int pivot=arr[low],count=0;
    for(int i=low+1;i<=high;i++)
    {
        if(arr[i]<=pivot)
            count++;
    }
    int pivotindex=low+count;
    swap(arr[low],arr[pivotindex]);
    int i=low,j=high;
    while(i<pivotindex && j>pivotindex)
    {
        while(arr[i]<=pivot)
            i++;
        while(arr[j]>pivot)
            j--;

        if(i<pivotindex && j>pivotindex)
            swap(arr[i],arr[j]);
    }
    return pivotindex;
}
void QuickSort(vector<int>&arr,int low,int high)
{
    if(low<high)
    {
        int p=partition(arr,low,high);
        QuickSort(arr, low, p-1);
        QuickSort(arr, p+1,high);
    }
}
vector<int> quickSort(vector<int> arr)
{
    int low=0,high=arr.size()-1;
    QuickSort(arr,low,high);
    return arr;
}
int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin >> n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        vector<int>res=quickSort(arr);
        for(int i=0;i<n;i++)
        {
          cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}