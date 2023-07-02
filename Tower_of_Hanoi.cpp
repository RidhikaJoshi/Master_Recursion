/*
Tower of Hanoi is a mathematical puzzle where we have three rods (A, B, and C) and N disks. Initially, all the disks are stacked in decreasing value of diameter i.e., the smallest disk is placed on the top and they are on rod A. The objective of the puzzle is to move the entire stack to another rod (here considered C), obeying the following simple rules: 

- Only one disk can be moved at a time.
- Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
- No disk may be placed on top of a smaller disk.
*/

#include<bits/stdc++.h>
using namespace std;

void toh(int n,int a,int c,int b,vector<vector<int>>&res)
{
    if(n==1)
    {        
        res.push_back({a,c});
        return ;
    }
    else
    {
        toh(n-1,a,b,c,res);
        res.push_back({a,c});
        toh(n-1,b,c,a,res);
    }
}
vector<vector<int>> towerOfHanoi(int n)
{
   int a=1,b=2,c=3;
   vector<vector<int>>res;
    toh(n,a,c,b,res);
   return res;
}

int main()
{
    int t,n;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> n;
        vector<vector<int>> res=towerOfHanoi(n);
        for(int i=0;i<res.size();i++)
        {
            cout << res[i][0] << " "  << res[i][1] << endl; 
        }
    }
    return 0;
}