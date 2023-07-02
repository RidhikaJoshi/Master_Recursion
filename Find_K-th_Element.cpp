/*
Given two sorted arrays of size m and n respectively, you are tasked with finding the element that would be at the k’th position of the final sorted array.
*/

#include <bits/stdc++.h> 
using namespace std;
int find(vector<int> &arr1, vector<int> &arr2, int i,int j,int k,int res)
{
    if(k==0)
        return res;
    else
    {
        if(i<arr1.size() && j<arr2.size())
        {
            if( arr1[i]<arr2[j])
            {
                res=arr1[i];
                i++;
                return find(arr1,arr2,i,j,k-1,res);
            }
            else 
            {
                res=arr2[j];
                j++;
                return find(arr1,arr2,i,j,k-1,res);
            }
        }
        else if(i<arr1.size())
        {
            res=arr1[i];
                return find(arr1,arr2,i+1,j,k-1,res);
        }
        else
        {
            res=arr2[j];
                return find(arr1,arr2,i,j+1,k-1,res);
        }
    }
}
int findKthElement(vector<int> &arr1, vector<int> &arr2, int k)
{
    int i=0,j=0,res=0;
    int ans=find(arr1,arr2,i,j,k,res);
    return ans;
   
}
int main()
{
    int t,n,m,k;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> n >> m >> k;
        vector<int>arr1(n);
        for(int i=0;i<n;i++)
            cin >> arr1[i];
        vector<int>arr2(m);
        for(int j=0;j<m;j++)
            cin >> arr2[j];
        int ans=findKthElement(arr1,arr2,k);
        cout << ans << endl;

    }
    return 0;
}