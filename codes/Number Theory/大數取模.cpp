LL exp(LL x,LL y,LL p){
    if(y == 0) return 1;
    if(y & 1) return (exp(x,y-1,p)*x) % p;//y is odd
    else{
        LL temp = exp(x,y/2,p);
        return (temp*temp) % p;
    }
}
LL calcmod(LL index,LL p){
    if(index == 0) return base[index]-'0';
    LL single = calcmod(index-1,p)*10;
    return (single%p + base[index]-'0')%p;
}