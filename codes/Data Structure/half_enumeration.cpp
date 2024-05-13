#include<bits/stdc++.h>

#define good ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long LL;
using namespace std;

LL sa[1<<18],sb[1<<18],no[1<<18];//subset product of a and b

LL subset(LL num[],LL length,LL product[],LL p){//pass by pointer
    LL k = 0,i,j;//count
    for(i = 0; i < length; i++){
        for(j = 0; j < k; j++){
            product[k+j] = (product[j]*num[i]) % p;//old product times num[i]
        }
        product[k] = num[i];//for num[i] itself
        k += k+1;
    }
    return k;//return the size of subset
}

LL exp_modp(LL x,LL y,LL p){
    if(y == 0) return 1;
    if(y % 2) return (exp_modp(x,y-1,p)*x) % p;
    else{
        LL temp = exp_modp(x,y/2,p);
        return (temp*temp) % p;
    }
}
int main(){
    good;
    LL i,n,p;
    LL a[30],b[30];
    cin >> n >> p;
    int len_a = n/2,len_b = n - len_a;
    for(i = 0; i < len_a; i++)
        cin >> a[i];
    for(i = 0; i < len_b; i++)
        cin >> b[i];
    LL len_sa = subset(a,len_a,sa,p);
    LL len_sb = subset(b,len_b,sb,p);
    sort(sb,sb+len_sb);

    LL len_sb2 = 1;//len_sb2 followed by i below
    no[0] = 1;//assume not empty(check later)
    for(i = 1; i < len_sb; i++){
        if(sb[i] != sb[i-1]){//new element
            sb[len_sb2] = sb[i];
            no[len_sb2] = 1;
            len_sb2++;
        }
        else//old element
            no[len_sb2-1]++;
    }
    LL ans = (sb[0] == 1) ? no[0]%p : 0;
    for(i = 0; i < len_sa; i++){
        if(sa[i] == 1) ans = (ans+1) % p;
        LL y = exp_modp(sa[i],p-2,p);//module inverse
        int it = lower_bound(sb,sb+len_sb2,y) - sb;
        if(it < len_sb2 && sb[it] == y){
            ans = (ans + no[it]) % p;
        }
    }
    cout << ans << '\n';
    return 0;
}