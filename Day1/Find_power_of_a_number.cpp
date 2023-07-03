/*
We are given two intergers N and X. We need to find 'X' to the power 'N'
i.e ('X' ^ 'N') 
*/

#include <bits/stdc++.h> 
using namespace std;

long long PowRecursion(int X,int N,long long res)
{
    if(N==0)
        return res;

    else 
    return PowRecursion(X,N-1,res*X);
}

long long Pow(int X, int N)
{
    long long res=1;
    return  PowRecursion(X,N,res);
    
    
}
int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int X,N;
        cin >> X >> N;
        long long ans=Pow(X,N);
        cout << ans << endl;
    }
    return 0;
}