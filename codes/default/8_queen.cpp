LL nqueen(LL n){
    int p[17],total = 0;
    for(int i = 0; i < n; i++)
        p[i] = i;
    do{
        bool valid = true;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(abs(p[i]-p[j]) == j-i){//same diagonal
                    valid = false;
                    break;
                }
            }
        }
        if(valid) total++;
    } while (next_permutation(p,p+n));
    return total;
}