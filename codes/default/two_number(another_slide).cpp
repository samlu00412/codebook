#include<bits/stdc++.h>

#define good ios_base::sync_with_stdio(0);cin.tie(0)
#define SIZE 100005
typedef long long LL;

using namespace std;

int main(){
    good;
    LL i,j,m,n,k,ans = 0;
    LL A[SIZE],B[SIZE];
    cin >> m >> n >> k;
    for(i = 0; i < m; i++)
        cin >> A[i];
    for(i = 0; i < n; i++)
        cin >> B[i];
    sort(A,A+m);
    sort(B,B+n);
    j = n-1;
    for(i = 0; i < m; i++){
        while(j > 0 && B[j] > k-A[i])
            j--;
        if(A[i] + B[j] == k)
            ans++;
    }
    cout << ans << endl;
    return 0;
}