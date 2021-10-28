#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int hartal(int *h, int p, int n){
    int i, j, f, s=0;
    for(i=1; i<=n; i++){
        if(i%7==0 || i%7==6) continue;
        f=0;
        for(j=0; j<p; j++)
            if(i%h[j]==0)
                f=1;
        if(f) s++;
    }
    return s;
}

int main() {
    int i, j, t, n, p;
    cin>>t;
    int w[t]={};
    
    for(i=0; i<t; i++){
        cin>>n;
        cin>>p;
        int h[p]={};
        for(j=0; j<p; j++){
            cin>>h[j];
        }
        w[i]=hartal(h, p, n);
    }
    
    for(i=0; i<t; i++){
        cout<<w[i]<<endl;
    }
    return 0;
}
