map<LL,LL> S;
    for (LL i=0;i<n;i++)
        S[a[i]] = 0; // insert a[i] and set rank=0
    LL r=0;
    for (auto it=S.begin(); it!=S.end(); ++it)//traversal and set rank
        it->second = r++;
    // replace number with rank
    for (LL i=0;i<n;i++) {
        a[i] = S.lower_bound(a[i]) -> second;
        // find() return the iterator, then take the rank
        // or S.find(a[i]) -> second;
    }