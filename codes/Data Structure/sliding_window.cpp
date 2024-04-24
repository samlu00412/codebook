//same size
for(i = 0; i < m; i++){//making first window
    LL color = discret[a[right]];
    cnt[color]++;
    if(cnt[color] == 1) n_color++;
    right++;
}
while(right < n){
    if(n_color == m)
        ans++;
    LL l_remove = discret[a[left]];
    cnt[l_remove]--;//remove left one
    left++;
    if(cnt[l_remove] == 0) n_color--;
    LL add = discret[a[right]];
    cnt[add]++,right++;//add next one
    if(cnt[add] == 1) n_color++;
}
