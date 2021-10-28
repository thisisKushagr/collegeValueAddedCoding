#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t, n, i, j, k, mid;
    cin>>t;
    for(i=0; i<t; i++){
        cin>>n;
        int arr[n];
        for(j=0; j<n; j++){
            cin>>arr[j];
        }
        sort(arr, arr+n);
        j=0; k=n-1;
        mid = (j+k)/2;
        cout<<arr[mid]<<endl;
    }
    return 0;
}
