int dp[1002][1002],i,j; //text1 前i個 & text2 前j個
    for(i = 0; i < 1002; i++)
        dp[i][0] = 0,dp[0][i] = 0;
    for(i = 1; i <= text1.size(); i++){ //1 base <=
        for(j = 1; j <= text2.size(); j++){
            if(text1[i-1] == text2[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << dp[text1.size()][text2.size()];