int main(){
    good;
    //freopen("file name", "r", stdin); //input redirection
    LL n,i,length = 0,num;
    cin >> n;
    LL last[RSIZE];//長度為it的最小可能結尾
    for(i = 0; i < n; i++){
        cin >> num;
        LL it = lower_bound(last,last+length,num)-last;
        last[it] = num;
        if(it == length) length++;
    }
    cout << length;
    return 0;
}