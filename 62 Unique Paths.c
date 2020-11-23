
"""
Created on Sun Nov. 22 01:01 2020

@author: Chiwen Chen
"""




int uniquePaths(int m, int n){
    // 每隔都有右邊跟下邊的選項
    // 先算m
    int ans=0;
    int max=m>n?m:n;
    int min=m>n?n:m;
    if(min==0)return 0;//
    if(min==1)return 1;//如果只有一列 只有一條的選項
    if(min==2)return max;//如果有兩條，就剛好是行
    for(int i=1;i<=max;i++)//超過兩條，就要計算C 排列 N!
    {
        ans=ans+i;
    }//哭阿 少算一格array [3 7]送進去一直算成21 想了十幾分鐘
    
    for(int i=3;i<min;i++)//正式計算 記得要去除前面的部分，不然<13會出錯
        for(int j=1;j<=max-1;j++)
        {
            ans=ans+uniquePaths(i,j);
        }//累積
    return ans;
}


"""別人寫的 記錄下來 很厲害
int uniquePaths(int m, int n) {
	if (m < n) return uniquePaths(n, m);
	double res = 1;
	for (int i = 0;i < n - 1;i++)
		res *= ((double)(m + n - 2 - i) / (i + 1));
	return (int)(res+0.5);
}
"""

"""
Runtime: 1452 ms, faster than 9.09% of C online submissions for Unique Paths. O(n^2}
Memory Usage: 5.6 MB, less than 44.76% of C online submissions for Unique Paths.

C（m + n-2，n-1）
種組合
"""