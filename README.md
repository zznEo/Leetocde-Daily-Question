&emsp;&emsp;感觉打过 ACM 之后，不写题总感觉学习的时候少了点什么。不希望把这份手艺拉下，但是因为疫情导致原定的省赛，区域赛都遥遥无期，曾经一起熬夜打 CF(Codeforces) 的乐趣也都没了。专业知识继续补足，项目这个暑假不打算写了，搭环境属实让我绝望。准备捡起祖传的手艺每日坚持一更 `Leecode`，不过当天如果题太难，我就换一个，难度的话基本保证在中等以上，如上。

### 2020/09/01
[486. 预测赢家](https://leetcode-cn.com/problems/predict-the-winner/)月初的第一题我就不会写，上来直接整懵了，看了题解 "零和博弈"，我只理解了暴搜的解法， $DP$，是在没看太懂。对于暴搜而言，只看局部(当前问题)，在当前的 $[L, R]$ 内，当前选手的最优解是什么，判断二者的差值，即为答案。
```cpp
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return check(0, nums.size() - 1, nums, 1) >= 0;
    }
private:
    int check(int l, int r, vector<int>& nums, int trun){
        if(l == r)
            return nums[l]*trun;
    
        int score_l = nums[l]*trun + check(l+1, r, nums, -trun);
        int score_r = nums[r]*trun + check(l, r-1, nums, -trun);

        return max(score_l*trun, score_r*trun)*trun;
    }
};
```


---
### 2020/08/31
&emsp;&emsp;最近几天都在忙着返校相关的章程，没有时间继续每日一题，但是把中间空上的已经补上了，后续慢慢继续写了
[841. 钥匙和房间](https://leetcode-cn.com/problems/keys-and-rooms/)，$BFS$ 遍历一下图联通即可
```cpp
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if(rooms.empty())
            return true;
        n = rooms.size(); m = rooms[0].size();
        queue<int> que;
        while(!que.empty())
            que.pop();
        que.push(0);
        while(!que.empty()){
            int x = que.front(); que.pop();
            vis[x] = 1;
            for(auto& i:rooms[x])
                if(vis[i] == 0)
                    que.push(i);
        }

        for(int i = 0;i < rooms.size();i++)
            for(int j = 0;j < rooms[i].size();j++)
                if(vis[rooms[i][j]] == 0)
                    return false;


        return true;
    }
private:
    int n, m;
    int vis[5000] = {0};
};
```
**复杂度分析**
- 时间复杂度：$O(n+m)$，其中 $n$ 是房间的数量，$m$ 是所有房间中的钥匙数量的总数。
- 空间复杂度：$O(n)$，其中 $n$ 是房间的数量。主要为队列的开销。

---
### 2020/08/26
[17. 电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)，中等题怎么全是搜索。。。。这跟全排列差不多
```cpp
class Solution {
public:
	void Init() {
		Mp[2] = { "abc" };
		Mp[3] = { "def" };
		Mp[4] = { "ghi" };
		Mp[5] = { "jkl" };
		Mp[6] = { "mno" };
		Mp[7] = { "pqrs" };
		Mp[8] = { "tuv" };
		Mp[9] = { "wxyz" };
	}

	void dfs(int pos) {
		if (pos == digits.size()){
            ans.push_back(tmp);
            return ;
        }
			
        int t = digits[pos] - '0';
		for (int i = 0; i < Mp[t].size(); i++) {
            int t = digits[pos] - '0';
			tmp.push_back(Mp[t][i]);
			dfs(pos + 1);
			tmp.pop_back();
		}
	}

	vector<string>& letterCombinations(string digits) {
        if(digits.size() == 0)
            return ans;
		Init();
		this->digits = digits;
		dfs(0);
		return ans;
	}
private:
	vector<string> ans;
	string digits;
	string Mp[1000];
	string tmp = "";
};
```
**复杂度分析**
![dRcRW8.png](https://s1.ax1x.com/2020/08/26/dRcRW8.png)

---
### 2020/08/25
[491. 递增子序列](https://leetcode-cn.com/problems/increasing-subsequences/)，二进制枚举或者 $DFS$，去重
```cpp
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
            dfs(0, nums, INT_MIN);
            return ans;
    }

    void dfs(int pos, vector<int>& nums, int last){
        if(pos == nums.size()){
            if(tmp.size() >= 2)
                ans.push_back(tmp);
            return ;    
        }
        
        if(nums[pos] >= last){	//如果当前的值大于等于上一次的优先放进去
            tmp.push_back(nums[pos]);
            dfs(pos+1, nums, nums[pos]);
            tmp.pop_back();
        }
        if(nums[pos] != last){	//放进去后，不选择当前的值，直接跳过选下一个
            dfs(pos+1, nums, last);
        }
    }

private:
    vector<int> tmp;
    vector<vector<int>> ans;
};
```
**复杂度分析**
- 时间复杂度：$O(2^n \cdot n)$。仍然需要对子序列做二进制枚举，枚举出的序列虽然省去了判断合法性和哈希的过程，但是仍然需要 $O(n)$ 的时间添加到答案中。
- 空间复杂度：$O(n)$。这里临时数组的空间代价是 $O(n)$，递归使用的栈空间的空间代价也是 $O(n)$。


---
### 2020/08/24
[459. 重复的子字符串](https://leetcode-cn.com/problems/repeated-substring-pattern/)，直接暴力也可以用 $KMP$，好久没用发现已经忘了 $KMP$ 算法了，记得当初学的时候一连学了几天才明白 $next$ 数组的作用，打比赛的时候也很少去写字符串处理的题，只记得 $KMP$ 是处理模式串匹配的，剩下的全忘了，就会大力出奇迹了。
```cpp
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i = 1;i <= s.size()-1;i++){	//枚举子字符串长度
            if(s.size()%i != 0)
                continue;
            bool flag = true;
            for(int j = 0,k = 0;j < s.size();j++,k = (k+1)%i){
                if(s[j] != s[k]){
                    flag  = false;
                    break;
                }
            }
            if(flag)
                return flag;
        }
        return false;
    }
};
```
**复杂度分析**
- 时间复杂度：$O(n^2)$ 其中 $n$ 是字符串 $s$ 的长度。枚举 $i$ 的时间复杂度为 $O(n)$，遍历 $s$ 的时间复杂度为 $O(n)$，相乘即为总时间复杂度。
- 空间复杂度：$O(1)$。

##### 第二题
[42. 接雨水](https://leetcode-cn.com/problems/trapping-rain-water/)，看到这个样例的图片第一反应单调栈，果不其然，~~我忘了单调栈怎么写了~~，单调栈可以在 $O(n)$ 的时间复杂度内处理出每个点左右两边第一个比它大值，针对本题而言，保证单调栈内高度递增，当出现比当前栈顶元素高的柱子时，代表从该柱子往右，不可能再用以栈顶元素为边界接水，直接出栈即可，建议看题解，比较清楚
```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        for(int i = 0;i < height.size();i++){
            while(!s.empty() && height[s.top()] < height[i]){	//当 i 柱子高于栈顶柱子，把它前面的都算上，就单调栈把
                int cur = s.top(); s.pop();
                if(s.empty())
                    break;
                int l = s.top();
                int h = min(height[i], height[l]) - height[cur];
                ans += (i - l - 1)*h;
            }
            s.push(i);
        }
        return ans;
    }
private:
    stack<int> s;
    int ans = 0;
};
```
**复杂性分析**
- 时间复杂度：$O(n)$
  - 单次遍历 $O(n)$，每个条形块最多访问两次（由于栈的弹入和弹出），并且弹入和弹出栈都是 $O(1)$ 的。
- 空间复杂度：$O(n)$。 栈最多在阶梯型或平坦型条形块结构中占用 $O(n)$ 的空间。
---
### 2020/08/21
[201. 数字范围按位与](https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/)，第一时间没想到求二进制下的最长公共子串，位运算这方面一点也不行，还是脑子不够用转不过来。大概描述一下。
既然要找所有数字的二进制位按位 & 后的结果，那么最后的结果中有 $1$ 的那一位必须是所有位置都为 $1$， $[m, n]$中有一位不为 $1$，那么该位为 $0$（&，类似于二进制乘法）。分情况讨论
- $m == n$ 时，这直接返回就行不用多说
- $m < n$ 时，前缀和肯定是以 $m$ 的第一个二进制下 $1$ 的位置，因为比该位置更靠前的一定都是 $0$。例如 $[1, 4]$， $4$ 的二进制为 $100$，那么在 $1$ 的第一个二进制位之前都会被 & 为 $0$，都是无意义的，主要看 $1$ 之后的位置。当右边界缩小为 $m$ 时，此时后面的所有位置都填充 $0$，即为答案。为何要填充为 $0$？ 因为假设从第 $i$ 个位置结束最长公共子串，前 $i$ 位均相同，第 $i+1$ 位开始不同，由于 $[m,n]$ 连续，所以第 $i+1$ 位在 $[m,n]$ 的数字范围从小到大列举出来一定是前面全部是 $0$，后面全部是 $1$，具体的证明看官方题解把
```cpp
class Solution {
public:
    int& rangeBitwiseAnd(int &m, int &n) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
        while(m < n){
            n = n & (n-1);	//每次消掉最后一位
        }
        return n;
    }
};
```

---
### 2020/08/22
[679. 24 点游戏](https://leetcode-cn.com/problems/24-game/) $DFS$ 全排列进行暴搜，每次选择两个数字进行加、减、乘、除 $4$ 操作，当进行到最后一位时判断是否为 $24$，即可。一共有 $4$ 个数字 $4$ 种操作运算符
&emsp;&emsp;首先，从 $4$ 个元素中选择两个共有  $6$ 种选择，并选择加、减、乘、除 $4$ 种运算操作之一，用得到的结果取代选出的 $2$ 个数字，剩下 $3$ 个数字。
&emsp;&emsp;然后在剩下的 $3$ 个数字中有序地选出 $2$ 个数字，共有 $3$ 种选法，并选择 $4$ 种运算操作之一，用得到的结果取代选出的 $2$ 个数字，剩下 $2$ 个数字。
&emsp;&emsp;最后剩下 $2$ 个数字，有 $2$ 种不同的顺序，并选择 $4$ 种运算操作之一。
&emsp;&emsp;因此，一共有 
```math
$$(6*2 \times 4) \times (3*2 \times 4) \times (1*2 \times 4) = 9216$$
```
种不同的可能性。（每个都 $*2$，因为每种运算都有两种循序 a+b、 b+a）。

实现时，有一些细节需要注意
- 除法运算为实数除法，因此结果为浮点数，列表中存储的数字也都是浮点数。在判断结果是否等于 $24$ 时应考虑精度误差，这道题中，误差小于 $10^{-6}$ 可以认为是相等。
- 进行除法运算时，除数不能为 $0$，如果遇到除数为 $0$ 的情况，则这种可能性可以直接排除。由于列表中存储的数字是浮点数，因此判断除数是否为 $0$ 时应考虑精度误差，这道题中，当一个数字的绝对值小于 $10^{-6}$时，可以认为该数字等于 $0$。

```cpp
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> num;
        for(int i = 0;i < nums.size();i++){	//全都转化为 double
            num.push_back(nums[i]*1.0);
        }
        solve(num);
        return flag;
    }

    void solve(vector<double>& nums){
        if(flag)	//如果已经有一个情况为 true，直接一直返回即可
            return ;
        if(nums.size() < 0)		//如数组长队为0，直接返回
            return ;
        if(nums.size() == 1){		。。如果只剩一个数字，判断该点是不是24
            if(fabs(nums[0] - TARGET) < EPS){
                flag = true;
                return ;
            }
        }

        for(int i = 0;i < nums.size();i++){	//选取第一个数字
            for(int j = 0;j < nums.size();j++){	//选取第二个数字
                if(i == j)
                    continue;
                vector<double> residual;	//存放剩余的数字
                residual.clear();
                double a = nums[i], b = nums[j];
                for(int k = 0;k < nums.size();k++){	//把没选到的数字放在另一个数组内，于选中的数组拼成新的数组
                    if(i != k && k != j)
                        residual.push_back(nums[k]);
                }
                //a+b
                residual.push_back(a+b);
                solve(residual);
                residual.pop_back();

                //a-b
                residual.push_back(a-b);
                solve(residual);
                residual.pop_back();

                //b-a
                residual.push_back(b-a);
                solve(residual);
                residual.pop_back();

                //a*b
                residual.push_back(a*b);
                solve(residual);
                residual.pop_back();

                //a/b
                if(b != 0){
                    residual.push_back(a/b);
                    solve(residual);
                    residual.pop_back();
                }

                //b/a
                if(a != 0){
                    residual.push_back(b/a);
                    solve(residual);
                    residual.pop_back();
                }
            }
        }
    }
private:
    static constexpr int TARGET = 24;
    static constexpr double EPS = 1e-6;
    bool flag = false;
};
```
**复杂度分析**
- 时间复杂度：$O(1)$。一共有 $9216$ 种可能性，对于每种可能性，各项操作的时间复杂度都是 $O(1)$，因此总时间复杂度是 $O(1)$，~~听起来挺离谱的~~。

- 空间复杂度：$O(1)$。空间复杂度取决于递归调用层数与存储中间状态的列表，因为一共有 $4$ 个数，所以递归调用的层数最多为 $4$，存储中间状态的列表最多包含 $4$ 个元素，因此空间复杂度为常数。

---
### 2020/08/21
[111. 二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)，$DFS$左右子树的大小，然后取 $min$
```cpp
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        int min_depth = INT_MAX;
        if (root->left != nullptr) {
            min_depth = min(minDepth(root->left), min_depth);
        }
        if (root->right != nullptr) {
            min_depth = min(minDepth(root->right), min_depth);
        }

        return min_depth + 1;
    }
};
```
**复杂度分析**
- 时间复杂度：$O(N)$，其中 $N$ 是树的节点数。对每个节点访问一次。

- 空间复杂度：$O(H)$，其中 $H$ 是树的高度。空间复杂度主要取决于递归时栈空间的开销，最坏情况下，树呈现链状，空间复杂度为 $O(N)$。平均情况下树的高度与节点数的对数正相关，空间复杂度为 $O(\log N)$。

[29. 两数相除](https://leetcode-cn.com/problems/divide-two-integers/)，要求不使用乘法、除法和 mod 运算符。那就只能用加减法了，举例说明，例如当前的除数是 $11$，被除数 $3$，那么首先看 $3$ 能是小于 $11$，的那么让 $3$翻倍得到 $6$，也是小于 $11$ 的，那么证明 $11 \div 3 > 2$，再让 $6$ 翻倍得到 $12 > 11$，那么 $2 < 11 \div 3 < 4$，此时让 $11 - 6 -> 5$，再让 $5$ 去进行如上计算，递归得到答案，为什么要拆成 $11 - (3*2)$，因为 $11 = 3*2 + 3*1 + 2$，上述过程就是实现这个等式。对于例如 $0, 1, -1$的特殊情况(越界)进行特判即可
```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == 1) return dividend;
        if(divisor == -1){
            if(dividend > INT_MIN)
                return -dividend;
            return INT_MAX;
        }

        long long divd = dividend, divr = divisor; //确定符号，并且全都转化为正数运算
        int flag = 1;
        if((divd < 0 && divr > 0) || (divd > 0 && divr < 0))
            flag = -1;
        divd = abs(divd);
        divr = abs(divr);

        long long res = div(divd, divr);
        if(flag > 0)
            return res > INT_MAX?INT_MAX:res;
        return -res;
    }

    int div(long long a, long long b){
        if(a < b)	//如果 a < b，那么代表 a 里面没有一个 b
            return 0;
        int cnt = 1;
        long long tb = b;
        while((tb + tb) < a){//模拟上述过程，不断让被除数翻倍
            tb += tb;
            cnt += cnt;
        }
        return cnt + div(a - tb, b);
    }
};
```
**复杂度分析**
- 时间复杂度：好难算啊，针对每次翻倍的操作是 $log$，但是递归里面又是一个 $log$
- 空间复杂度：$O(1)$，维护了几个变量

---
### 2020/08/20
[529. 扫雷游戏](https://leetcode-cn.com/problems/minesweeper/)，这题读题真的累，但是就是 $DFS/BFS$ 一遍就行，好像 $Leecode$ 中等题搜索偏多啊。
```cpp
class Solution {
public:
    int dir_x[8] = {0, 1, 0, -1, 1, 1, -1, -1};
    int dir_y[8] = {1, 0, -1, 0, 1, -1, 1, -1};

    void dfs(vector<vector<char>>& board, int x, int y) {
        int cnt = 0;
        for (int i = 0; i < 8; ++i) {
            int tx = x + dir_x[i];
            int ty = y + dir_y[i];
            if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size()) {
                continue;
            }
            cnt += board[tx][ty] == 'M';
        }
        if (cnt > 0) {
            board[x][y] = cnt + '0';
        } else {
            board[x][y] = 'B';
            for (int i = 0; i < 8; ++i) {
                int tx = x + dir_x[i];
                int ty = y + dir_y[i];
                if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size() || board[tx][ty] != 'E') {
                    continue;
                }
                dfs(board, tx, ty);
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
        } else {
            dfs(board, x, y);
        }
        return board;
    }
};
```
**复杂度分析**
- 时间复杂度：$O(nm)$，其中 $n$ 和 $m$ 分别代表面板的宽和高。最坏情况下会遍历整个面板。
空间复杂度：$O(nm)$。空间复杂度取决于递归的栈深度，而递归栈深度在最坏情况下有可能遍历整个面板而达到 $O(nm)$。

#### 第二题
[19. 删除链表的倒数第N个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)两种解法，一种是先统计这个链表有多少的节点，假设链表有 $cnt$ 个节点，那么要删除倒数第 $N$ 个节点，就是删除正数第 $cnt - N + 1$ 个节点，但是开开始前要先添加一个哑节点， $dummy$，用于防止出现删除头节点的情况。
```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);	//哑节点
        dummy->next = head;
        ListNode* tmp = head;
        int cnt = 0, delval = 0;
        while(tmp != nullptr){
            cnt++;
            tmp = tmp->next;
        }
        //cout << cnt << endl;
        int delpos = cnt - n;	//要删除的是 cnt - n + 1，那么该节点的前一个就是 cnt - n
        tmp = dummy;
        while(delpos > 0) {
            delpos--;
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
        return dummy->next;
    }
};
```

双指针方法，定义两个指针，始终保持两个指针的间隔距离为 $N$，当一个指针指到结尾时，另一个指针就是待删除的点，和上面的时间复杂度差不多。
```cpp
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *firstNode = dummyNode, *secondNode = dummyNode;

        for (int i = 1; i <= n; ++i) {
            secondNode = secondNode->next;
        }
        
        while (secondNode->next != nullptr) {
            secondNode = secondNode->next;
            firstNode = firstNode->next;
        }

        firstNode->next = firstNode->next->next;

        return dummyNode->next;
    }
};
```
**复杂度分析**
- 时间复杂度：$O(L)$，该算法对列表进行了两次遍历，首先计算了列表的长度 $L$ 其次找到第 $(L−n)$ 个结点。 操作执行了 $2L - n$ 步，时间复杂度为 $O(L)$。
- 空间复杂度：$O(1)$，就多开了一个哑节点。

---
### 2020/08/19
[647. 回文子串](https://leetcode-cn.com/problems/palindromic-substrings/solution/)，$Manacher$板子，在 $Manacher$ 算法中，处理出来的 $p[i]$ 数组表示，以 $i$ 为对称中心能延展的最长回文串长度。例如如下字符串 $aba$，经过转化后变成 $@#a#b#a#$，可以发现，每个字符的 $p[i]$ 至少为 $2$，例如字符 $a$。而 $b$ 的 $p[i] = 4$，那么以 $b$ 为中心构成的回文字符串有$4$个， 其中有一半是 $#$开头的，所以以 $b$ 为中心实际的回文串长度为 $p[i] \div 2$
```cpp
class Solution {
public:
    int countSubstrings(string s) {
        return Manacher(s);
    }

    void Init(string s){
        tmp[0] = '@';
        tmp[1] = '#';
        len1 = s.size();
        for(int i = 0;i < len1;i++){
            tmp[i*2 + 2] = s[i];
            tmp[i*2 + 3] = '#';
        }
        len2 = strlen(tmp);
    }

    int Manacher(string s){
        Init(s);
        for(int i = 1;i < len2;i++){
            if(i < mx)
                p[i] = min(mx - i, p[2*id - i]);
            else 
                p[i] = 1;
            while(tmp[i + p[i]] == tmp[i - p[i]])
                p[i]++;
            if(i + p[i] > mx){
                mx = i+p[i];
                id = i;
            }
            ans += (p[i] / 2);
        }
        return ans;
    }
private:
    int mx = 0, id = 0, p[2005] = {0}, len1, len2;
    char tmp[2005];
    int ans = 0;
};
```
**复杂度分析**
- 时间复杂度：$O(n)$。即 $Manacher$ 算法的时间复杂度.
空间复杂度：$O(n)$。

---
### 2020/08/18
[109. 有序链表转换二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/)，很容易想到，从中位数建树，因为链表有序，中位数建树一定能满足两边平衡，然后递归建树即可。
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	ListNode* Find(ListNode* left, ListNode* right) {
		ListNode* l = left;
		ListNode* mid = left;
		while (l != right && l->next != right) {
			l = l->next; //每次跳两位，中位数跳一位，算是一个规律吧，自己画一下就知道了
			l = l->next;
			mid = mid->next;
		}
		return mid;
	}

	TreeNode* Build(ListNode* left, ListNode* right) {
		if (left == right)
			return nullptr;
		ListNode* mid = Find(left, right);
		TreeNode* root = new TreeNode(mid->val);
		root->left = Build(left, mid);
		root->right = Build(mid->next, right);
		return root;
	}

	TreeNode* sortedListToBST(ListNode* head) {
		return Build(head, nullptr);
	}
};
```
**复杂度分析**
- 时间复杂度：$O(n \log n)$，其中 $n$ 是链表的长度。
- 空间复杂度：$O(\log n)$，这里只计算除了返回答案之外的空间。平衡二叉树的高度为 $O(\log n)$，即为递归过程中栈的最大深度，也就是需要的空间。
---
### 2020/08/17
[110. 平衡二叉树](https://leetcode-cn.com/problems/balanced-binary-tree/)，就 $DFS$ 统计树高可解，也可以通过判断子树是否为平衡二叉树递归求解
```cpp
class Solution {
public:
	int Hight(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int lchildHight = Hight(root->left);//一直向下递归，到根节点返回 0
		int rchildHight = Hight(root->right);
		if (lchildHight == -1 || rchildHight == -1 || abs(lchildHight - rchildHight) > 1)
			return -1;  //只要有一个子树不符合，那么该树即不是平衡二叉树
		else
			return max(lchildHight, rchildHight) + 1;
	}
	bool isBalanced(TreeNode* root) {
		return Hight(root) >= 0;
	}
};
```
**复杂度分析**
- 时间复杂度：$O(n)$，其中 $n$ 是二叉树中的节点个数。使用自底向上的递归，每个节点的计算高度和判断是否平衡都只需要处理一次，最坏情况下需要遍历二叉树中的所有节点，因此时间复杂度是 $O(n)$。
- 空间复杂度：$O(n)$，其中 $n$ 是二叉树中的节点个数。空间复杂度主要取决于递归调用的层数，递归调用的层数不会超过 $n$。

##### 第二题

[5. 最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)，$Manacher$ 马拉车算法板子，看到学长在腾讯一面的时候被问到，来复习一下，推荐一个讲解的链接[Manacher（马拉车）————O(n)回文子串](https://www.cnblogs.com/fan1-happy/p/11166182.html)
```cpp
class Solution {
public:
	string longestPalindrome(string s) {
		init(s);
		len1 = s.size(); len2 = strlen(t);
		Manacher();
		int pos = 0, cnt = -1;
		for (int i = 0; i < len2; i++) {
			if (cnt < p[i] - 1) {
				cnt = p[i]- 1;
				pos = i;
			}
		}
		string ans = "";
		for (int i = pos - cnt; i < pos+cnt; i++) {
			if (t[i] != '#')
				ans.push_back(t[i]);
		}
		return ans;
	}
private:
	void init(string s) {
		t[0] = '@';
		t[1] = '#';
		for (int i = 0; i < s.size(); i++) {
			t[i * 2 + 2] = s[i];
			t[i * 2 + 3] = '#';
		}
	}
	void Manacher() {
		for (int i = 1; i < len2; i++) {
			if (i < mx)
				p[i] = min(p[2 * id - i], mx - i);
			else
				p[i] = 1;
			while (t[i + p[i]] == t[i - p[i]])
				p[i]++;
			if (p[i] + i > mx) {
				mx = p[i] + i;
				id = i;
			}
		}
	}
private:
	char t[3005];
	int id = 0, mx = 0, p[3005] = {0}, len1, len2;
	/*
	*	t:		翻倍处理后的字符串
	*	id:		当前的对称中心
	*	mx:		以id为对称中心，半径为 p[id] 的边界
	*	p:		记录以 i 为中心，的会问长度
	*	len1:	s的长度
	*	len2:	t的长度 = s*2 + 2
	*/
};
```
**复杂度分析：**
- 时间复杂度：$O(N)$，$Manacher$ 算法只有在遇到还未匹配的位置时才进行匹配，已经匹配过的位置不再匹配，因此对于字符串 $S$ 的每一个位置，都只进行一次匹配，算法的复杂度为 $O(N)$。
- 空间复杂度：$O(N)$，只维护了几个变量，一个翻倍的字符串，一个记录答案的数组。


---
### 2020/08/16
[733. 图像渲染](https://leetcode-cn.com/problems/flood-fill/)，就简单搜索找连通块，没什么东西
```cpp
class Solution {
public:
    const int dx[4] = {1, 0, 0, -1};
    const int dy[4] = {0, 1, -1, 0};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int currColor = image[sr][sc];
        if (currColor == newColor) return image;
        int n = image.size(), m = image[0].size();
        queue<pair<int, int>> que;
        que.emplace(sr, sc);
        image[sr][sc] = newColor;
        while (!que.empty()) {
            int x = que.front().first, y = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++) {
                int mx = x + dx[i], my = y + dy[i];
                if (mx >= 0 && mx < n && my >= 0 && my < m && image[mx][my] == currColor) {
                    que.emplace(mx, my);
                    image[mx][my] = newColor;
                }
            }
        }
        return image;
    }
};
```
**复杂度分析**
- 时间复杂度：$O(n\times m)$，其中 $n$ 和 $m$ 分别是二维数组的行数和列数。最坏情况下需要遍历所有的方格一次。
- 空间复杂度：$O(n\times m)$，其中 $n$ 和 $m$ 分别是二维数组的行数和列数。主要为队列的开销。

##### 第二题
[2. 两数相加](https://leetcode-cn.com/problems/add-two-numbers/)，直接模拟加法，然后进行一个链表反转。理论上可以优化，直接在 $l1$ 于 $l2$ 的基础上进行修改，将加和后的值直接存入其中一个，实现差不多，我写的比较麻烦，正好也训练一下我链表的操作。
```cpp
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(0);
		while (l1 != nullptr && l2 != nullptr) {
			int x = l1->val;
			int y = l2->val;
			int ans = x + y + add;
			ListNode* tmp = new ListNode(0);
			tmp->val = ans % 10;
			add = ans / 10;
			tmp->next = head->next;
			head->next = tmp;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1 != nullptr) {
			int x = l1->val;
			ListNode* tmp = new ListNode(0);
			tmp->val = add + x;
			add = tmp->val / 10;
			tmp->val %= 10;

			tmp->next = head->next;
			head->next = tmp;
			l1 = l1->next;
		}
		while (l2 != nullptr) {
			int x = l2->val;
			ListNode* tmp = new ListNode(0);
			tmp->val = add + x;
			add = tmp->val / 10;
			tmp->val %= 10;
			
			tmp->next = head->next;
			head->next = tmp;
			l2 = l2->next;
		}
		if (add != 0) {
			ListNode* tmp = new ListNode(add);
			tmp->next = head->next;
			head->next = tmp;
		}
		head = head->next;
		ListNode* rever = nullptr, * next = nullptr;
		while (head) {
			next = head->next;
			head->next = rever;
			rever = head;
			head = next;
		}

		return rever;
	}
private:
	int add;
};
```
**复杂度分析**
- 时间复杂度：$O(\max(m, n))$，假设 $m$ 和 $n$ 分别表示 $l1$ 和 $l2$ 的长度，上面的算法最多重复 $\max(m, n)$次，翻转链表最多需要 $\max(m, n) + 1$次。
- 空间复杂度：空间复杂度：$O(\max(m, n))$， 新列表的长度最多为 $\max(m,n) + 1$。

##### 第三题
[5489. 两球之间的磁力](https://leetcode-cn.com/problems/magnetic-force-between-two-balls/)二分板子，最大化最小值，也没什么好说的
```cpp
class Solution {
public:
	bool check(vector<int>& position, int mid, int m) {
		int cnt = 1,pos = position[0];
		while (true) {
			int tpos = lower_bound(position.begin(), position.end(), pos + mid) - position.begin();
			if (tpos != position.size()) {
				pos = position[tpos];
				cnt++;
			}
			else
				break;
		}
		return cnt >= m;
	}
	int maxDistance(vector<int>& position, int m) {
		sort(position.begin(), position.end());
		int n = position.size();
		int l = 1, r = position[n - 1];
		int ans = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (check(position, mid, m)) {
				ans = mid;
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		return ans;
	}
};
```
**复杂度分析**
- 时间复杂度：总时间复杂度 $O(n * log n)$，首先对于数组的排序，$sort$， 时间复杂度 $O(n * log n)$，二分答案 $O(log n)$，$check$ 函数 $O(log n)$
- 空间复杂度：$O(1)$，只维护了几个变量
---
### 2020/08/15
[546. 移除盒子](https://leetcode-cn.com/problems/remove-boxes/)好难的 DP 啊，看题解看了好久才明白。建议去查看[这个题解](https://leetcode-cn.com/problems/remove-boxes/solution/tu-jie-dong-tai-gui-hua-di-gui-zhuang-tai-zhuan-yi/)讲的比较清楚
```cpp
class Solution {
public:
	int removeBoxes(vector<int>& boxes) {
		box = boxes;
		return solve(0, boxes.size() - 1, 0);
	}
	int solve(int i, int j, int k) {
		if (i > j)
			return 0;

		if (dp[i][j][k] != 0)
			return dp[i][j][k];

		while (i < j && box[j] == box[j - 1]) {
			j--;
			k++;
		}

		dp[i][j][k] = solve(i, j-1, 0) + (k+1)*(k+1);

		for (int p = i; p < j; p++) {
            if (box[p] == box[j]) {
                dp[i][j][k] = max(dp[i][j][k], solve(p + 1, j - 1, 0) + solve(i, p, k + 1));
            }
        }
        printf("%d %d %d %d\n", i, j, k, dp[i][j][k]);
		return dp[i][j][k];
	}
public:
	vector<int> box;
	int dp[101][101][101] = { 0 };
};
```
---
### 2020/08/14
#### 第一题

今天的每日一题比较简单，[括号匹配](https://leetcode-cn.com/problems/valid-parentheses/)，所以更新两题
```cpp
class Solution {
public:
    bool isValid(string s) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				sta.push(s[i]);
			else {
				if (sta.empty())
					return false;
				char tmp = sta.top(); sta.pop();
				if (s[i] == ')' && tmp == '(')
					continue;
				else if (s[i] == ']' && tmp == '[')
					continue;
				else if (s[i] == '}' && tmp == '{')
					continue;
				return false;
			}
		}
		if (!sta.empty())
			return false;
		return true;
    }
public:
	stack<char> sta;
};
```
**复杂度分析**
- 时间复杂度：$O(n)$，其中 $n$ 是字符串 $s$ 的长度。
- 空间复杂度：$O(n + |\Sigma|)$，其中 $\Sigma$ 表示字符集，本题中字符串只包含 $6$ 种括号，$|\Sigma| = 6$。栈中的字符数量为 $O(n)$，而哈希映射使用的空间为$ O(|\Sigma|)$，相加即可得到总空间复杂度。

#### 第二题
[3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)
给定一个字符串，请你找出其中不含有重复字符的 **最长子串** 的长度。

类似滑动窗口。由于它需要寻找的是一个**最长字串**，只需要从左到右遍历一下，对于每一个出现的字符记录一个 `vis` 数组，用于标记出现的位置，当 `vis` 数组不为 $0$ 时，代表该字母以前出现过，那么只需要用当前的位置 $i$ 减去曾经这个字符出现的位置 $vis[s[i]]$，就能得出中间的序列是能用的，但是会出现 $abba$，这种，所以在记录一个 $lastpos$ 用于记录，如果这个点上一次出现的位置比我更新的位置要早，那么上次的点的位置就是无意义的。例如 `abba`，过程如下

```
规定 i 从 1开始，那么，s[i-1]，即可获取原串
i = 1 时，
	s[i-1] = a
	vis[s[i-1]] = 0 -> visvis[s[i-1]] = 1
	cnt = 1
	lastpos = 0
	ans = 1
i = 2 时
	s[i-1] = b
	vis[s[i-1]] = 0 -> vis[s[i-1]] = 2
	cnt = 2
	lastpos = 0
	ans = 2
i = 3 时
	s[i-1] = b
	vis[s[i-1]] = 2
	cnt = i - vis[s[i-1]]  -> cnt = 1
	lastpos = vis[s[i-1]] -> lastpos = 2 //在2号位置更新过了，代表2号以前的位置都不是可取的了
	vis[s[i-1]] = 3
	ans = 2
i = 4 时
	s[i-1] = a
	vis[s[i-1]] = 1，此时出现的点小于上次更新的点，所以该次记录无效
	cnt = 2
	lastpos = 2
	ans = 2
```

感觉说的不清，但是意思很对，剩下的看注释把
```cpp
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ans = 0, cnt = 0, lastpos = 0;
		for (int i = 1; i <= s.size(); i++) {
			if (vis[s[i-1]] != 0 && lastpos < vis[s[i-1]]) {  //当字符串上一次出现的位置
				cnt = i - vis[s[i-1]];
				lastpos = vis[s[i - 1]]; //记录当前更新的节点，该节点以前都是非法的
			}
			else {
				cnt++;
			}
			vis[s[i-1]] = i;
			ans = max(ans, cnt);
		}
		return ans;
	}
public:
	int vis[200] = {0};  //用于记录字符出现的位置
};
```
**时间复杂度分析：**
- 时间复杂度：$O(N)$，其中 $N$ 是字符串的长度。左指针和右指针分别会遍历整个字符串一次。
- 空间复杂度：$O(|\Sigma|)$，其中 $\Sigma$ 表示字符集（即字符串中可以出现的字符），$|\Sigma|$ 表示字符集的大小。在本题中没有明确说明字符集，因此可以默认为所有 $ASCII$ 码在 $[0, 128)$ 内的字符，即 $|\Sigma| = 128$。我们需要用到哈希集合来存储出现过的字符，而字符最多有 $|\Sigma|$ 个，因此空间复杂度为 $O(|\Sigma|)$。


### 2020/08/13
[43. 字符串相乘](https://leetcode-cn.com/problems/multiply-strings/)
就大数乘法，我直接暴力做的，模拟乘法 + 大数加法就行了，好像还可以优化竖式，数学大佬 `FFT` 优化属实牛逼
下面是偷题解的图片
![大数乘法.png](https://s1.ax1x.com/2020/08/13/dS8RFP.png)
这个直接模拟就行，不过比我之前学的大数模板简单的多，记得刚学C语言内会，一个大数80多行写几个小时还要疯狂 DeBug。
```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        string ans = "0";
        int len1 = num1.size(), len2 = num2.size();
        for (int i = len1 - 1; i >= 0; i--) {
            string curr = "";
            int add = 0;
            for (int j = len1 - 1; j > i; j--)
                curr.push_back('0');

            int x = num1[i] - '0';
            for (int j = len2 - 1; j >= 0; j--) {
                int y = num2[j] - '0';
                int ret = x * y + add;
                curr.push_back((ret % 10) + '0');
                add = ret / 10;
            }
            if (add != 0)
                curr.push_back(add + '0');
            reverse(curr.begin(), curr.end());
            ans = AddString(ans, curr);
        }
        return ans;
    }

    string AddString(string& num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || add != 0) {
            int x = (i >= 0) ? (num1[i] - '0') : 0;
            int y = (j >= 0) ? (num2[j] - '0') : 0;
            int ret = x + y + add;
            ans.push_back((ret % 10)+'0');
            add = ret / 10;
            i--; j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
**时间复杂度分析：**
- 时间复杂度：$O(nm + m^{2})$ ，其中 $n$ 和 $m$ 分别代表 $num1$ 于 $num2$ 的长度。需要从右往左遍历 $num2$，对于 $num2$ 的每一位都需要和 $num1$ 进行相乘，因此计算乘积的总次数为 $nm$。字符串相加一共会有 $n$ 次操作，相加的字符串长度最大为 $n + m$，因此字符串相加的时间复杂度为$O(n(n+m))$
- 空间复杂度：$O(n + m)$，空间的大小取决于中间存储的字符串大小，最大长度 $m+n$。

优化解法，舒适思路清奇，感觉看官方的题解比较清楚，就不过多赘述，类似找规律
```cpp
class Solution {
public:
	string multiply(string num1, string num2) {
        cin.tie(nullptr);
        cout.tie(nullptr);
		if (num1 == "0" || num2 == "0")
			return "0";
		int len1 = num1.size(), len2 = num2.size();
		vector<int> ans(len1 + len2);
		for (int i = len1 - 1; i >= 0; i--) {
			int x = num1[i] - '0';
			for (int j = len2 - 1; j >= 0; j--) {
				int y = num2[j] - '0';
				int ret = x * y;
				ans[i + j + 1] += x * y;
			}
		}

		for (int i = len1 + len2 - 1; i >= 0; i--) {
			if (ans[i] > 9) {
				ans[i - 1] += ans[i] / 10;
				ans[i] = ans[i] % 10;
			}
		}

		string ret = "";
		for (int i = 0; i < len1 + len2; i++) {
			if (i == 0 && ans[i] == 0)
				continue;
			ret.push_back(ans[i] + '0');
		}
		return ret;
	}
};
```
---
### 2020/08/12
[133. 克隆图](https://leetcode-cn.com/problems/clone-graph/)
给你无向连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。

#### 题解
怎么感觉中等题好多搜索，这个就是直接裸的BFS/DFS就行，开个`map`，映射一下即可
#### 代码示例
```cpp
class Solution {
public:
    map<Node*, Node*> mp;
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return node;
        if (mp[node] != nullptr) //如果这个点已经被访问过，直接返回就行
            return mp[node];
        Node* clonenode = new Node(node->val);
        mp[node] = clonenode;
        for (auto it = node->neighbors.begin(); it != node->neighbors.end(); it++) {
            clonenode->neighbors.emplace_back(cloneGraph(*it));
        }
        return clonenode;
    }
};
```
#### 复杂度分析
- 时间复杂度：$O(N)$，其中 $N$ 表示节点数量。深度优先搜索遍历图的过程中每个节点只会被访问一次。
- 空间复杂度：$O(N)$,存储克隆节点和原节点的哈希表需要 $O(N)$ 的空间，递归调用栈需要 $O(H)$ 的空间，其中 $H$ 是图的深度，经过放缩可以得到 $O(H)=O(N)$，因此总体空间复杂度为 $O(N)$。

---
### 2020/08/11
[130. 被围绕的区域](https://leetcode-cn.com/problems/surrounded-regions/)
给定一个二维矩阵，让把所有被 $X$ 包围 $O$ ，变成 $X$，不包括边界的 $O$。

#### 题解
&emsp;&emsp;第一眼看过去类似于找联通块，想到了从一个 $O$ 开始 $BFS$ 去探寻找到的点，然后如果这个点能联通的所有点有一个不符合条件(里面有边界点)那么这一串都不符合。又想到添加一个 `map` 去标记那些被搜过的点，防止第二次遇到又搜一边，然后添加了一堆东西，空间开销巨大。后来反过来想，可以从边界点往内部搜效果是一样的，一边搜一边修改原数组中的值，例如从边界 $O$ 开始搜，所有能到达的点都设置为 $A$，那么最后遍历原数组时，所有是 $A$ 的都变回 $O$，所有是 $O$ 的都是 $X$，即可
#### 代码示例
```cpp
class Solution {
public:
	using P = pair<int, int>;
	queue<P> que;
	int n, m;
	int nextstep[4][2] = { {0,1},{0,-1},{1,0},{-1,0} }; //四个方向

	void solve(vector<vector<char>>& board) {
		n = board.size();
		if (n == 0)
			return;
		m = board[0].size();
		//取出边界的店
		for (int i = 0; i < n; i++) {
			if (board[i][0] == 'O')
				que.push(P(i, 0));
			if (board[i][m - 1] == 'O')
				que.push(P(i, m - 1));
		}
		for (int i = 1; i < m - 1; i++) {
			if(board[0][i] == 'O')
				que.push(P(0, i));
			if (board[n - 1][i] == 'O')
				que.push(P(n - 1, i));
		}

		while (!que.empty()) {
			P now = que.front(); que.pop();
			board[now.first][now.second] = 'T';//替换成不合格的点
			for (int i = 0; i < 4; i++) {
				int tx = now.first + nextstep[i][0];
				int ty = now.second + nextstep[i][1];
				if (tx < 0 || ty < 0 || tx >= n || ty >= m || board[tx][ty] != 'O')
					continue;
				que.push(P(tx, ty));
			}
		}

        for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board[i][j] = (board[i][j] == 'T') ? 'O' : 'X';//修改回去
			}
		}
	}
};
```
#### 复杂度分析
- 时间复杂度：$O(n\times m)$，其中 $n$ 和 $m$ 分别为矩阵的行数和列数。广度优先搜索过程中，每一个点至多只会被标记一次。
- 空间复杂度：$O(n\times m)$，其中 $n$ 和 $m$ 分别为矩阵的行数和列数。主要为广度优先搜索的队列的开销。
