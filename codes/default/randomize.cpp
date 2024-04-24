map<LL,LL> discret;
for(i = 0; i < n; i++){
        cin >> a[i];
        discret[a[i]] = 0;
    }
    LL index = 0;
    for(auto &it : discret)
        it.second = index++;