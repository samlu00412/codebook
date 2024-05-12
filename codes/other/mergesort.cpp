#include <bits/stdc++.h>
using namespace std;
#define good ios_base::sync_with_stdio(0);cin.tie(0)
#define NORMALSIZE 8
typedef long long LL;

void merge(LL *,LL,LL,LL);//prototype
void mergesort(LL *,LL,LL);

void mergesort(LL* arr,LL l,LL r){
    LL m;
    if(l < r){
        m = (l+r)/2;
        mergesort(arr,l,m);//sort left subarray
        mergesort(arr,m+1,r);//sort right sunarray
        merge(arr,l,m,r);
    }
    return;
}
void merge(LL* arr,LL l,LL m,LL r){
    LL left,right,tmp[NORMALSIZE],i;
    left = l; // left subarr.begin
    right = m+1; //right subarr.begin
    i = l;
    while ((left <= m) && (right <= r)){ //merging left subarr and right subarr
        if(arr[left] < arr[right]){ //left subarr is smaller
            tmp[i] = arr[left];
            i++,left++;
        }
        else{ //the other situation
            tmp[i] = arr[right];
            i++,right++;
        }
    }
    while(left <= m){ // right subarr is fully sorted
        tmp[i] = arr[left];
        i++,left++;
    }
    while(right <= r){ // left subarr is fully sorted
        tmp[i] = arr[right];
        i++,right++;
    }
    for(i = l; i <= r; i++)
        arr[i] = tmp[i];
}
