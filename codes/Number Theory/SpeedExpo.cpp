LL expo(LL a,LL b,LL p){
    if(b == 0) return 1;
    if(b & 1) return (expo(a,b-1,p)*a)%p;//b is odd
    LL temp = expo(a,b/2,p);
    return (temp*temp)%p;
}