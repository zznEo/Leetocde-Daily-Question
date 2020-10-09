### 股票购买问题

[121.买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)

[122. 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)

[123. 买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)

[188. 买卖股票的最佳时机 IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/)

[309. 最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

[714. 买卖股票的最佳时机含手续费](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

​		从讨论区看到了一篇很好的题解，把这一类问题全部汇总了，自己尝试写一篇加深一下记忆。贴上[原文链接](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108870/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems)

​		以第四题为例

![0Dd1sS.png](https://s1.ax1x.com/2020/10/09/0Dd1sS.png)

​		第一题是只能进行一次买卖，所以 $k = 1$，第二题，可以进行多次交易即 $k = INF$，第三题，只能进行两次交易，即 $k = 2$，第四题如让，$k$ 可以是任意值，第五题与第六题都是 $k = INF$，只是多了一些其他的状态。

​		依照我超哥所说，这不显然 $dp[i][j][k]$ 么？所以开始定义状态 $dp$ 方程，定义 $i$ 代表在第 $i$ 天， $j$ 代表进行了 $j$ 次交易，$k$ 代表当前情况下手中是否有股票，$k$ 代表手中是否有股票，所以取值只有 $0$ 或者 $1$，$0$ 代表没有，$1$ 代表有。所以 $dp[i][j][0]$，代表在第 $i$ 天，进行了 $j$ 次交易，手中没有股票的情况下所获得的最大利润。$dp[i][j][1]$ 同理。所以最后我们返回 $dp[n][k][0]$，即第 $n$ 天，交易了 $k$ 次，手中没有股票的累计最大利润。为什么不返回$dp[n][k][1]$，那股票买了砸手里肯定比卖出去赚的少啊，所以最后手里肯定是不要剩股票最优。理解了上述状态开始定义状态转移方程。

情况定义如下：

- 当 $j = 0$ 时，代表当天手中没有股票，那么它可以从如下几种状态转移过来
  - 前一天手中没有股票，直接转移
  - 前一天手中有股票，今天卖了
- 当 $j = 1$ 时，代表当天手中有股票，那么它可以从如下几个状态转移过来
  - 前一天手中有股票，直接转移
  - 前一天手中没有股票，今天购买  

​        由于交易代表一次购买，一次出售，所以定义当购买时我们会花费一次交易，当出售时不会消耗交易次数。购买是将自己的钱给别人，出售则相反，所以定义购买时减去当前股票的价格，出售时增加当前股票的价格。

所以状态转移方程如下：
$$
dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + price[i])
$$

$$
dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i])
$$

理解到这里最难的部分已经解决了![](https://cdn.jsdelivr.net/gh/xzzai/static@master/uPic/138.png)，开始初始化一些状态，如下

为了方便计算，防止数组越界，让 $i$ 从 $1$，开始，同理交易次数 $j$ 也是从 $1$ 开始。

当 $i = 0$ 时做任何操作，即还没开始购买，如果此时手中有股票，那么一定是非法的即手中累计 $-INF$，有如下初始化

```cpp
for(int i = 0;i <= n;i++)
    dp[0][i][1] = INT_MIN;//在第 0 天 无论进行多少次购买，手中都不可能有股票
```

当 $j = 0$ 时，无论在那一天手中有股票也同样非法，有如下初始化

```cpp
for(int i = 0;i <= n;i++)
    dp[i][0][1] = INT_MIN;
```

其余状况都是 $0$. 

总结如下，按照题意进行改写即可

```cpp
for(int i = 0;i <= n;i++)
	dp[i][0][1] = INT_MIN;
for(int i = 0;i <= mk;i++)
	dp[0][i][1] = INT_MIN;
for(int i = 1;i <= n;i++) { 
	for(int j = 1;j <= mk;k++) {
		dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i-1]);
		dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i-1]);
	}
}
return dp[n][mk][0];
```

当 $k = INF$ 时，第二维可以取消，因为当 $k$ 无限大时 $k \approx k - 1$。 



#### 309. 最佳买卖股票时机含冷冻期

由于购买需要冷冻一天，那么当需要购买股票的时候应该从 $i - 2$ 那天转移过来，而非 $i - 1$，注意数组不要越界。

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = INT_MIN;
        for(int i = 1;i <= n;i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1]);
            if(i >= 2)	//特判一下，不要越界
                dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i-1]);
            else 
                dp[i][1] = max(dp[i-1][1], -prices[i-1]);
        }
        return dp[n][0];
    }
};
```



 #### 714. 买卖股票的最佳时机含手续费

只需要在购买的时候多花点钱就行了

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() == 0)
            return 0;
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = INT_MIN;
        for(int i = 1;i <= n;i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i-1] - fee);//减去手续费
        }
        return dp[n][0];
    }
};
```



####  188. 买卖股票的最佳时机 IV

这题有一个需要注意的点，就是当 $k$ 很大时，因为要开三维$dp$，会炸空间，所以进行一些特判。由于交易是一天买，一天卖，一次交易至少需要两天所以当 $k \geq \dfrac{n}{2}$ 可以认为 $k \approx INF$，进而转化为第二类问题求解。

```cpp
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int n = prices.size();
        const int mk = k;
        if(k >= n / 2) { //转为第二类问题
            return maxProfitK_INF(prices);
        }
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(mk + 1, vector<int>(2, 0)));
        for(int i = 0;i <= n;i++)
            dp[i][0][1] = INT_MIN;
        for(int i = 0;i <= mk;i++)
            dp[0][i][1] = INT_MIN;
        for(int i = 1;i <= n;i++) { 
            for(int k = 1;k <= mk;k++) {
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i-1]);
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i-1]);
            }
        }
        return dp[n][mk][0];
    }

    int maxProfitK_INF(vector<int>& prices) {
        int ans = 0;
        for(int i = 1;i < prices.size();i++) {
            ans +=  max(0, prices[i] - prices[i-1]);
        }
        return ans;
    }
};
```



 



 

