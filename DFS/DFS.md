# DFS

也是进入到了我最头痛的DFS

刷了一点简单题（其实是其他的不会），重点考虑是不是全排列，全排列的可以考虑搜索一下



这里是我跟着大佬刷题的时候为了方便搞的题单

**[DFS - 题单 - 洛谷 | 计算机科学教育新生态](https://www.luogu.com.cn/training/730031#problems)**





## 1.P1706 全排列问题

**[P1706 全排列问题 - 洛谷](https://www.luogu.com.cn/problem/P1706)**

### 题目描述

按照字典序输出自然数 $1$ 到 $n$ 所有不重复的排列，即 $n$ 的全排列，要求所产生的任一数字序列中不允许出现重复的数字。

### 输入格式

一个整数 $n$。

### 输出格式

由 $1 \sim n$ 组成的所有不重复的数字序列，每行一个序列。

每个数字保留 $5$ 个场宽。

### 输入输出样例 #1

#### 输入 #1

```
3
```

#### 输出 #1

```
	1    2    3
    1    3    2
    2    1    3
    2    3    1
    3    1    2
    3    2    1
```

#### 说明/提示

$1 \leq n \leq 9$。



### AC代码

这个很简单，没什么要记录的

不懂的可以在社区里找找画递归树的，我本来画了，但是忘记放哪里了

~~~cpp
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=10;

int n;
bool st[N];//记录状态
int arr[N];//记录答案

//x是枚举的位置
void dfs(int x){
    if(x > n){
        for(int i = 1;i <= n;i++){
            printf("    %d",arr[i]);
        }
        printf("\n");
        return ;
    }

    for(int i = 1;i <= n;i++){
        if(!st[i]){
            st[i] = true;
            arr[x] = i;
            dfs(x+1);
            st[i] = false;
            arr[x] = 0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    dfs(1);
    return 0;
}
~~~

---



## 2.P1157 组合的输出

**[P1157 组合的输出 - 洛谷](https://www.luogu.com.cn/problem/P1157)**

### 题目描述

排列与组合是常用的数学方法，其中组合就是从 $n$ 个元素中抽出 $r$ 个元素（不分顺序且 $r \le n$），我们可以简单地将 $n$ 个元素理解为自然数 $1,2,\dots,n$，从中任取 $r$ 个数。

现要求你输出所有组合。

例如 $n=5,r=3$，所有组合为：

$123,124,125,134,135,145,234,235,245,345$。

### 输入格式

一行两个自然数 $n,r(1<n<21,0 \le r \le n)$。

### 输出格式

所有的组合，每一个组合占一行且其中的元素按由小到大的顺序排列，每个元素占三个字符的位置，所有的组合也按字典顺序。

**注意哦！输出时，每个数字需要 $3$ 个场宽。以 C++ 为例，你可以使用下列代码：**

```cpp
cout << setw(3) << x;
```

输出占 $3$ 个场宽的数 $x$。注意你需要头文件 `iomanip`。

### 输入输出样例 #1

#### 输入 #1

```
5 3
```

#### 输出 #1

```
  1  2  3
  1  2  4
  1  2  5
  1  3  4
  1  3  5
  1  4  5
  2  3  4
  2  3  5
  2  4  5
  3  4  5
```



### AC代码

同样直接给代码

~~~cpp
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 21;
int n,r;//总数，选出r个
int arr[N];

void dfs(int x,int start){
    if((x-1) + (n - start + 1) < r)    return;
    
    if(x > r){
        for(int i = 1;i <= r;i++)
            printf("%3d",arr[i]);
        printf("\n");
        return;
    }
    
    for(int i = start;i <= n;i++){
        arr[x] = i;
        dfs(x+1,i+1);
        arr[i] = 0;
    }
}

int main()
{
    cin >> n >> r;
    dfs(1,1);//位置，从数字几开始放
    return 0;
}
~~~

---



## 3.P2089 烤鸡

**[P2089 烤鸡 - 洛谷](https://www.luogu.com.cn/problem/P2089)**

### 题目背景

猪猪 Hanke 得到了一只鸡。

### 题目描述

猪猪 Hanke 特别喜欢吃烤鸡（本是同畜牲，相煎何太急！）Hanke 吃鸡很特别，为什么特别呢？因为他有 $10$ 种配料（芥末、孜然等），每种配料可以放 $1$ 到 $3$ 克，任意烤鸡的美味程度为所有配料质量之和。

现在， Hanke 想要知道，如果给你一个美味程度 $n$ ，请输出这 $10$ 种配料的所有搭配方案。

### 输入格式

一个正整数 $n$，表示美味程度。

### 输出格式

第一行，方案总数。

第二行至结束，$10$ 个数，表示每种配料所放的质量，按字典序排列。

如果没有符合要求的方法，就只要在第一行输出一个 $0$。

### 输入输出样例 #1

#### 输入 #1

```
11
```

#### 输出 #1

```
10
1 1 1 1 1 1 1 1 1 2 
1 1 1 1 1 1 1 1 2 1 
1 1 1 1 1 1 1 2 1 1 
1 1 1 1 1 1 2 1 1 1 
1 1 1 1 1 2 1 1 1 1 
1 1 1 1 2 1 1 1 1 1 
1 1 1 2 1 1 1 1 1 1 
1 1 2 1 1 1 1 1 1 1 
1 2 1 1 1 1 1 1 1 1 
2 1 1 1 1 1 1 1 1 1
```

#### 说明/提示

对于 $100\%$ 的数据，$n \leq 5000$。



### AC代码

前几题相对简单一点，我就懒得记录思考过程

~~~cpp
#include<iostream>
#include<algorithm>
#define read(x) scanf("%d",&x)
using namespace std;

const int N = 59050;//3^10大概
int n;
int res = 0;//方案数
int a[20];//枚举可能方案
int ans[N][20];//存放答案

void dfs(int x,int sum){
    if(sum > n)  return;
    
    if(x > 10){
        if(sum == n){
            res++;
            for(int i = 1; i <= 10; i++){
                ans[res][i] = a[i];
            }
        }
        return;
    }
    
    for(int i = 1; i <= 3; i++){
        a[x] = i;
        dfs(x+1,sum+i);
        a[x] = 0;
    }
}

int main(){
    read(n);
    dfs(1,0);//枚举到的位置，调料总数
    printf("%d\n",res);

    for(int i = 1; i <= res; i++){
        for(int j = 1; j <= 10; j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
~~~



这里还有一个极具优雅的超级暴力（纯整活，别学）

~~~cpp
#include<iostream>
using namespace std;

const int N = 1e8;
int ans[N];

int main(){
	int n;cin >> n;
	int res = 0,x = 1;
	
	for(int a = 1;a <= 3;a++)
		for(int b = 1;b <= 3;b++)
			for(int c = 1;c <= 3;c++)
				for(int d = 1;d <= 3;d++)
					for(int e = 1;e <= 3;e++)
						for(int f = 1;f <= 3;f++)
							for(int g = 1;g <= 3;g++)
								for(int h = 1;h <= 3;h++)
									for(int i = 1;i <= 3;i++)
										for(int j = 1;j <= 3;j++)
											if(a+b+c+d+e+f+g+h+i+j == n){
												res++;//方案数加一
												ans[x++] = a;
												ans[x++] = b;
												ans[x++] = c;
												ans[x++] = d;
												ans[x++] = e;
												ans[x++] = f;
												ans[x++] = g;
												ans[x++] = h;
												ans[x++] = i;
												ans[x++] = j;
												}
	cout << res << endl;
	for(int i = 1;i < x;i++)
		i%10 ? cout << ans[i] << ' ' : cout << ans[i] << endl;
	return 0;								
}
~~~

---



## 4.P1149 [NOIP 2008 提高组] 火柴棒等式

**[P1149 NOIP 2008 提高组\] 火柴棒等式 - 洛谷](https://www.luogu.com.cn/problem/P1149)**

### 题目描述

给你 $n$ 根火柴棍，你可以拼出多少个形如 $A+B=C$ 的等式？等式中的 $A$、$B$、$C$ 是用火柴棍拼出的整数（若该数非零，则最高位不能是 $0$）。用火柴棍拼数字 $0\sim9$ 的拼法如图所示：

![](https://cdn.luogu.com.cn/upload/image_hosting/p5hsawt2.png)

注意：

1. 加号与等号各自需要两根火柴棍；
2. 如果 $A\neq B$，则 $A+B=C$ 与 $B+A=C$ 视为不同的等式（$A,B,C\geq0$）；
3. $n$ 根火柴棍必须全部用上。

### 输入格式

一个整数 $n(1 \leq n\leq 24)$。

### 输出格式

一个整数，能拼成的不同等式的数目。

### 输入输出样例 #1

#### 输入 #1

```
14
```

#### 输出 #1

```
2
```

### 输入输出样例 #2

#### 输入 #2

```
18
```

#### 输出 #2

```
9
```

#### 说明/提示

【输入输出样例 1 解释】

$2$ 个等式为 $0+1=1$ 和 $1+0=1$。

【输入输出样例 2 解释】

$9$ 个等式为

$0+4=4$、$0+11=11$、$1+10=11$、$2+2=4$、$2+7=9$、$4+0=4$、$7+2=9$、$10+1=11$、$11+0=11$。

noip2008 提高第二题



### AC代码

显然能看到加号和等号用掉4根，所以数量先减4

大佬说最大的合法加数是711，但我看不出来，数组直接开的很大



搜索思路很直白，就是找到三个数，满足**等式成立**，

然后算每个数的火柴数，**火柴要正好用完**

~~~cpp
#include<iostream>
#include<algorithm>
#define r(x) scanf("%d",&x)

using namespace std;

const int N = 1010;

int n;
int res = 0,sum = 0;
int arr[N];
int nums[N] = {6,2,5,5,4,5,6,3,7,6};

int f(int x){
    if(nums[x])    return nums[x];
    else{
        int thissum = 0;
        while(x){
            thissum += nums[x%10];
            x /= 10;
        }
        return thissum;
    }
}

void dfs(int x,int sum){
    if(sum > n)    return;

    if(x > 3){
        if(arr[1] + arr[2] == arr[3] && sum == n){
            res++;
        }
        return;
    }
    
    for(int i = 0; i <= N; i++){
        arr[x] = i;
        dfs(x+1,sum + f(i));
        arr[x] = 0;
    }
}

int main(){
    r(n);
    n -= 4;
    dfs(1,0);
    
    printf("%d\n",res);
    return 0;
}
~~~



上面的代码也是能过的，下面是加了记忆化，就是将算过的答案记录下来，下次使用到就直接出结果。

类比一下斐波那契数列

~~~cpp
#include<iostream>
#include<algorithm>
#define r(x) scanf("%d",&x)

using namespace std;

const int N = 1010;

int n;
int res = 0,sum = 0;
int arr[N];
int nums[N] = {6,2,5,5,4,5,6,3,7,6};

void dfs(int x,int sum){
    if(sum > n)    return;

    if(x > 3){
        if(arr[1] + arr[2] == arr[3] && sum == n){
            res++;
        }
        return;
    }
    
    for(int i = 0; i <= N; i++){
        arr[x] = i;
        dfs(x+1,sum + nums[i]);//记忆化
        arr[x] = 0;
    }
}

int main(){
    r(n);
    n -= 4;
    
    for(int i = 10; i <= N; i++)//记忆化
        nums[i] = nums[i%10] + nums[i/10];
    
    dfs(1,0);
    
    printf("%d\n",res);
    return 0;
}
~~~

---



## 5.P1036 [NOIP 2002 普及组] 选数

**[P1036 NOIP 2002 普及组\] 选数 - 洛谷](https://www.luogu.com.cn/problem/P1036)**

### 题目描述

已知 $n$ 个整数 $x_1,x_2,\cdots,x_n$，以及 $1$ 个整数 $k$（$k<n$）。从 $n$ 个整数中任选 $k$ 个整数相加，可分别得到一系列的和。例如当 $n=4$，$k=3$，$4$ 个整数分别为 $3,7,12,19$ 时，可得全部的组合与它们的和为：

$3+7+12=22$

$3+7+19=29$

$7+12+19=38$

$3+12+19=34$

现在，要求你计算出和为素数共有多少种。

例如上例，只有一种的和为素数：$3+7+19=29$。

### 输入格式

第一行两个空格隔开的整数 $n,k$（$1 \le n \le 20$，$k<n$）。

第二行 $n$ 个整数，分别为 $x_1,x_2,\cdots,x_n$（$1 \le x_i \le 5\times 10^6$）。

### 输出格式

输出一个整数，表示种类数。

### 输入输出样例 #1

#### 输入 #1

```
4 3
3 7 12 19
```

#### 输出 #1

```
1
```

#### 说明/提示

**【题目来源】**

NOIP 2002 普及组第二题



### AC代码

这个题目就是组合，然后加个素数判断

数据范围还挺宽的感觉，没有用到素数筛

~~~cpp
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 36;
int n,k,sum=0,ans=0;
int arr[N],num[N];

bool isPrime(int sum){
    if(sum < 2) return false;
    for(int i = 2;i <= sum/i;i++)
        if(sum%i==0)    return false;
    
    return true;
}

void dfs(int x,int start){//当前枚举位置，和被枚举数组的开始位置
    //加上剪枝，看数据范围
    //已经选择的数字的数量 + 可以选择的数字的数量 >= k
    if((x-1) + (n - start + 1) < k)    return;
    //此时已经选择了x-1个，start的位置在x，所以可以选择的数量是 n - start + 1

    if(x > k){
        sum = 0;
        for(int i = 1;i <= k;i++)
            sum += arr[i];
    
        if(isPrime(sum))    ans++;
        return;
    }

    for(int i = start;i <= n;i++){
        arr[x] = num[i];
        dfs(x+1,i+1);
        arr[x] = 0;
    }
}

int main()
{
    scanf("%d %d",&n,&k);
    for(int i = 1;i <= n;i++){
        scanf("%d",&num[i]);
    }
    dfs(1,1);
    printf("%d\n",ans);
    return 0;
}
~~~

---



## 6.P1088 [NOIP 2004 普及组] 火星人

**[P1088 NOIP 2004 普及组\] 火星人 - 洛谷](https://www.luogu.com.cn/problem/P1088)**

### 题目描述

人类终于登上了火星的土地并且见到了神秘的火星人。人类和火星人都无法理解对方的语言，但是我们的科学家发明了一种用数字交流的方法。这种交流方法是这样的，首先，火星人把一个非常大的数字告诉人类科学家，科学家破解这个数字的含义后，再把一个很小的数字加到这个大数上面，把结果告诉火星人，作为人类的回答。

火星人用一种非常简单的方式来表示数字――掰手指。火星人只有一只手，但这只手上有成千上万的手指，这些手指排成一列，分别编号为 $1,2,3,\cdots$。火星人的任意两根手指都能随意交换位置，他们就是通过这方法计数的。

一个火星人用一个人类的手演示了如何用手指计数。如果把五根手指――拇指、食指、中指、无名指和小指分别编号为 $1,2,3,4$ 和 $5$，当它们按正常顺序排列时，形成了 $5$ 位数 $12345$，当你交换无名指和小指的位置时，会形成 $5$ 位数 $12354$，当你把五个手指的顺序完全颠倒时，会形成 $54321$，在所有能够形成的 $120$ 个 $5$ 位数中，$12345$ 最小，它表示 $1$；$12354$ 第二小，它表示 $2$；$54321$ 最大，它表示 $120$。下表展示了只有 $3$ 根手指时能够形成的 $6$ 个 $3$ 位数和它们代表的数字：


| 三进制数 | 代表的数字 |
| :------: | :--------: |
|  $123$   |    $1$     |
|  $132$   |    $2$     |
|  $213$   |    $3$     |
|  $231$   |    $4$     |
|  $312$   |    $5$     |
|  $321$   |    $6$     |

现在你有幸成为了第一个和火星人交流的地球人。一个火星人会让你看他的手指，科学家会告诉你要加上去的很小的数。你的任务是，把火星人用手指表示的数与科学家告诉你的数相加，并根据相加的结果改变火星人手指的排列顺序。输入数据保证这个结果不会超出火星人手指能表示的范围。

### 输入格式

共三行。  
第一行一个正整数 $N$，表示火星人手指的数目（$1 \le N \le 10000$）。  
第二行是一个正整数 $M$，表示要加上去的小整数（$1  \le  M  \le  100$）。  
下一行是 $1$ 到 $N$ 这 $N$ 个整数的一个排列，用空格隔开，表示火星人手指的排列顺序。

### 输出格式

$N$ 个整数，表示改变后的火星人手指的排列顺序。每两个相邻的数中间用一个空格分开，不能有多余的空格。

### 输入输出样例 #1

#### 输入 #1

```
5
3
1 2 3 4 5
```

#### 输出 #1

```
1 2 4 5 3
```

#### 说明/提示

对于 $30\%$ 的数据，$N \le 15$。

对于 $60\%$ 的数据，$N \le 50$。

对于 $100\%$ 的数据，$N \le 10000$。

noip2004 普及组第 4 题



### AC代码

全排列是按字典序来枚举的，这一点要记住
要注意到，如果只是老实得从第一个方案（也就是火星人的1）开始枚举，等到找到起始数字，
可能还没加上一个 M ，就超时了
所以要从火星人给的数字开始往后枚举

其他的注意点就放在注释里了

~~~cpp
#include<iostream>
#include<algorithm>
#define r(x) scanf("%d",&x)

using namespace std;

const int N = 10010;

int n,m;
int arr[N];//记录方案
int stast[N];//记录火星人的起始排列
bool st[N];//该数字是否已经在该排列方案里
int res = 0;//从开始位置，一共枚举了多少方案数
bool finish = false;

void dfs(int x){
    if(finish)    return;//剪枝。找到了就别继续找了
    
    if(x > n){
        res++;
        if(res == m+1){//火星人表示出来的第一个数字是1，所以要加上
            finish = true;
            for(int i = 1; i <= n; i++){
                printf("%d ",arr[i]);
            }
        }
        return;
    }
    
    for(int i = 1; i <= n; i++){
        if(!res)    i = stast[x];
        
        if(!st[i]){
            st[i] = true;
            arr[x] = i;
            dfs(x+1);
            st[i] = false;
            arr[x] = 0;
        }
    }
}

int main(){
    r(n);r(m);
    for(int i = 1; i <= n; i++)
        r(stast[i]);
        
    dfs(1);
    return 0;
}
~~~

---



## 7.P2036 [COCI 2008/2009 #2] PERKET

### 题目描述

Perket 是一种流行的美食。为了做好 Perket，厨师必须谨慎选择食材，以在保持传统风味的同时尽可能获得最全面的味道。你有 $n$ 种可支配的配料。对于每一种配料，我们知道它们各自的酸度 $s$ 和苦度 $b$。当我们添加配料时，总的酸度为每一种配料的酸度总乘积；总的苦度为每一种配料的苦度的总和。

众所周知，美食应该做到口感适中，所以我们希望选取配料，以使得酸度和苦度的绝对差最小。

另外，我们必须添加至少一种配料，因为没有任何食物以水为配料的。

### 输入格式

第一行一个整数 $n$，表示可供选用的食材种类数。

接下来 $n$ 行，每行 $2$ 个整数 $s_i$ 和 $b_i$，表示第 $i$ 种食材的酸度和苦度。

### 输出格式

一行一个整数，表示可能的总酸度和总苦度的最小绝对差。

### 输入输出样例 #1

#### 输入 #1

```
1
3 10
```

#### 输出 #1

```
7
```

### 输入输出样例 #2

#### 输入 #2

```
2
3 8
5 8
```

#### 输出 #2

```
1
```

### 输入输出样例 #3

#### 输入 #3

```
4
1 7
2 6
3 8
4 9
```

#### 输出 #3

```
1
```

### 说明/提示

#### 数据规模与约定

对于 $100\%$ 的数据，有 $1 \leq n \leq 10$，且将所有可用食材全部使用产生的总酸度和总苦度小于 $1 \times 10^9$，酸度和苦度不同时为 $1$ 和 $0$。

#### 说明

- 本题满分 $70$ 分。
- 题目译自 [COCI2008-2009](https://hsin.hr/coci/archive/2008_2009/) [CONTEST #2](https://hsin.hr/coci/archive/2008_2009/contest2_tasks.pdf) PERKET，译者 @[mnesia](https://www.luogu.com.cn/user/115711)。



### AC代码

我的想法是求这堆调料的组合，然后记录最小的差值，但题解不是这么写的。
但题解并不是这样的，我想可能是，如果是组合，还退出递归的条件还需要考虑选了1种，2种…………，不好写（可能，不懂）

大佬的想法是**每种调料有三种状态**，
0.还没枚举到
1.选了
2.不选

然后对所有情况全排列
**特别注意**，需要把**flag放在递归退出条件里**，因为我们是先从选调料开始枚举的，所以一开始就会把 flag 改为 true ，而最后会枚举到全部不选，所以会计算错误的答案

需要注意的写在了注释里

~~~cpp
#include<iostream>
#include<algorithm>
#define r(x) scanf("%d",&x)
using namespace std;
const int N = 20;

int n,res=1e9;
int sour[N],bitter[N];
int st[N];

void dfs(int x){
    if(x>n){
        bool flag = false;//存在一种情况就是没有选任何一种调料，这时 res 是默认的 1
        int sum1 = 1,sum2 = 0;
        for(int i = 1; i <= n; i++){
            if(st[i] == 1){//选了该调料才计算酸度积，苦度和
                flag = true;//修改标志，说明选择了调料
                sum1 *= sour[i];
                sum2 += bitter[i];
            }
        }
        
        if(flag)//有选择调料的情况下才能计算差值
            res = min(res,abs(sum1-sum2));
        return;
    }
    
    //选
    st[x] = 1;
    dfs(x+1);
    st[x] = 0;
    
    //不选
    st[x] = 2;
    dfs(x+1);
    st[x] = 0;
}

int main(){
    r(n);
    for(int i = 1; i <= n; i++){
        r(sour[i]);
        r(bitter[i]);
    }
    
    dfs(1);
    printf("%d\n",res);

    return 0;
}
~~~



**也可以将flag放在全局变量里，但是要先枚举不选，这样就是从全部不选，慢慢枚举到全部都选**

~~~cpp
#include<iostream>
#include<algorithm>
#define r(x) scanf("%d",&x)
using namespace std;
const int N = 20;

int n,res=1e9;
int sour[N],bitter[N];
int st[N];
bool flag = false;//存在一种情况就是没有选任何一种调料，这时 res 是默认的 1

void dfs(int x){
    if(x>n){
        int sum1 = 1,sum2 = 0;
        for(int i = 1; i <= n; i++){
            if(st[i] == 1){//选了该调料才计算酸度积，苦度和
                flag = true;//修改标志，说明选择了调料
                sum1 *= sour[i];
                sum2 += bitter[i];
            }
        }
        
        if(flag)//有选择调料的情况下才能计算差值
            res = min(res,abs(sum1-sum2));
        return;
    }
    
    //差别在这里
    //不选
    st[x] = 2;
    dfs(x+1);
    st[x] = 0;
    
    //选
    st[x] = 1;
    dfs(x+1);
    st[x] = 0;
}

int main(){
    r(n);
    for(int i = 1; i <= n; i++){
        r(sour[i]);
        r(bitter[i]);
    }
    
    dfs(1);
    printf("%d\n",res);

    return 0;
}

~~~

---



## 8.P1135 奇怪的电梯

**[P1135 奇怪的电梯 - 洛谷](https://www.luogu.com.cn/problem/P1135)**

### 题目背景

感谢 @[yummy](https://www.luogu.com.cn/user/101694) 提供的一些数据。

### 题目描述

呵呵，有一天我做了一个梦，梦见了一种很奇怪的电梯。大楼的每一层楼都可以停电梯，而且第 $i$ 层楼（$1 \le i \le N$）上有一个数字 $K_i$（$0 \le K_i \le N$）。电梯只有四个按钮：开，关，上，下。上下的层数等于当前楼层上的那个数字。当然，如果不能满足要求，相应的按钮就会失灵。例如： $3, 3, 1, 2, 5$ 代表了 $K_i$（$K_1=3$，$K_2=3$，……），从 $1$ 楼开始。在 $1$ 楼，按“上”可以到 $4$ 楼，按“下”是不起作用的，因为没有 $-2$ 楼。那么，从 $A$ 楼到 $B$ 楼至少要按几次按钮呢？

### 输入格式

共二行。  

第一行为三个用空格隔开的正整数，表示 $N, A, B$（$1 \le N \le 200$，$1 \le A, B \le N$）。

第二行为 $N$ 个用空格隔开的非负整数，表示 $K_i$。

### 输出格式

一行，即最少按键次数，若无法到达，则输出 `-1`。

### 输入输出样例 #1

#### 输入 #1

```
5 1 5
3 3 1 2 5
```

#### 输出 #1

```
3
```

#### 说明/提示

对于 $100 \%$ 的数据，$1 \le N \le 200$，$1 \le A, B \le N$，$0 \le K_i \le N$。

本题共 $16$ 个测试点，前 $15$ 个每个测试点 $6$ 分，最后一个测试点 $10$ 分。



### AC代码

这个题目异常坎坷，题解里有些DFS代码也过不了了，应该是后来出了专门的数据卡掉DFS了

后续刷BFS再说吧



这个只能拿20分，我们从理性上知道一个楼层只被经过一次和被经过多次相比，肯定是前者的更优（因为后者中间多走了很多不必要的步数）。可能wa的部分就在这里。

~~~cpp
#include<iostream>
#include<algorithm>
#define r(x) scanf("%d",&x)
using namespace std;

const int N = 10010;
int n,a,b;
int arr[N];
int res = 1e9;

void dfs(int x,int cnt){
    if(cnt > res)    return;

    if(x == b){
        res = min(res,cnt);
        return;
    }

    //上
    if(x+arr[x] <= n){
        //printf("x+arr[x] = %d\n",x+arr[x]);
        dfs(x+arr[x],cnt+1);
    }

    //下
    if(x-arr[x] > 1){
        //printf("x-arr[x] = %d\n",x-arr[x]);
        dfs(x-arr[x],cnt+1);
    }
}

int main(){
    r(n);r(a);r(b);
    for(int i = 1; i <= n; i++)
        r(arr[i]);

    dfs(a,0);
    printf("%d\n",res);
    return 0;
}
~~~

而剩下的有超时的，有超内存的,那就要继续剪枝了。每个楼层只用了一次，选与不选，联想全排列吧。
这个题目的测试数据应该是优化了，应该是卡了dfs，多出了很多测试数据，单dfs应该是极限了。

**58分**

~~~cpp
#include<iostream>
#include<algorithm>
#define r(x) scanf("%d",&x)
using namespace std;

const int N = 1010;
int n,a,b;
int arr[N];
bool st[N];
int res = 1e9;

void dfs(int x,int cnt){
    if(cnt > res)    return;
    if(x < 0 || x > n)    return;

    if(x == b){
        res = min(res,cnt);
        return;
    }

    //上
    if(x+arr[x] <= n && !st[x+arr[x]]){
        //printf("x+arr[x] = %d\n",x+arr[x]);
        st[x+arr[x]] = true;
        dfs(x+arr[x],cnt+1);
        st[x+arr[x]] = false;
    }

    //下
    if(x-arr[x] > 1 && !st[x-arr[x]]){
        //printf("x-arr[x] = %d\n",x-arr[x]);
        st[x-arr[x]] = true;
        dfs(x-arr[x],cnt+1);
        st[x-arr[x]] = false;
    }
}

int main(){
    r(n);r(a);r(b);
    for(int i = 1; i <= n; i++)
        r(arr[i]);

    dfs(a,0);

    if(res == 1e9)
        printf("-1\n");
    else
        printf("%d\n",res);
    return 0;
}
~~~

---



## 9.P1451 求细胞数量

**[P1451 求细胞数量 - 洛谷](https://www.luogu.com.cn/problem/P1451)**

### 题目描述

一矩形阵列由数字 $0$ 到 $9$ 组成，数字 $1$ 到 $9$ 代表细胞，细胞的定义为沿细胞数字上下左右若还是细胞数字则为同一细胞，求给定矩形阵列的细胞个数。

### 输入格式

第一行两个整数代表矩阵大小 $n$ 和 $m$。

接下来 $n$ 行，每行一个长度为 $m$ 的只含字符 `0` 到 `9` 的字符串，代表这个 $n \times m$ 的矩阵。

### 输出格式

一行一个整数代表细胞个数。

### 输入输出样例 #1

#### 输入 #1

```
4 10
0234500067
1034560500
2045600671
0000000089
```

#### 输出 #1

```
4
```

#### 说明/提示

##### 数据规模与约定

对于 $100\%$ 的数据，保证 $1 \le n,m \le 100$。



### AC代码

那也是成功熬过了全排列，现在是地图搜索之类的，应该会好想象一点

题目也说得很清楚了，就找第一个非0的点，然后在规则里（上下左右）找到这个细胞的边界，然后计数+1，**记得一边找一边把对应的点改成0，表示搜索过了**



还是比较经典的一道题

~~~cpp
#include<iostream>
#include<algorithm>
#define read(x) scanf("%1d",&x)
using namespace std;

int n,m,ans = 0;
int a[110][110];

void dfs(int x,int y){
    if(x>n || x<1 || y>m || y<1 || a[x][y]==0)  return;
    a[x][y] = 0;
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}

int main(){
    cin >> n >> m;
    for(int i = 1; i<= n; i++)
        for(int j = 1; j <= m; j++)
            read(a[i][j]);

    for(int i = 1; i <= n; i++)
        for(int j = 1;j <= m; j++){
            if(a[i][j]){
                ans++;
                dfs(i,j);
            }
        }
    printf("%d\n",ans);
    return 0;
}
~~~

---



## 10.P1683 入门

**[P1683 入门 - 洛谷](https://www.luogu.com.cn/problem/P1683)**

### 题目描述

不是任何人都可以进入桃花岛的，黄药师最讨厌像郭靖一样呆头呆脑的人。所以，他在桃花岛的唯一入口处修了一条小路，这条小路全部用正方形瓷砖铺设而成。有的瓷砖可以踩，我们认为是安全的，而有的瓷砖一踩上去就会有喷出要命的毒气，那你就死翘翘了，我们认为是不安全的。你只能从一块安全的瓷砖上走到与他相邻的四块瓷砖中的任何一个上，但它也必须是安全的才行。

由于你是黄蓉的朋友，她事先告诉你哪些砖是安全的、哪些砖是不安全的，并且她会指引你飞到第一块砖上（第一块砖可能在任意安全位置），现在她告诉你进入桃花岛的秘密就是：如果你能走过最多的瓷砖并且没有死，那么桃花岛的大门就会自动打开了，你就可以从当前位置直接飞进大门了。

注意：瓷砖可以重复走过，但不能重复计数。

### 输入格式

第一行两个正整数 $W$ 和 $H$，分别表示小路的宽度和长度。

以下 $H$ 行为一个 $H\times W$ 的字符矩阵。每一个字符代表一块瓷砖。其中，`.` 代表安全的砖，`#` 代表不安全的砖，`@` 代表第一块砖。

### 输出格式

输出一行，只包括一个数，即你从第一块砖开始所能安全走过的最多的砖块个数（包括第一块砖）。

### 输入输出样例 #1

#### 输入 #1

```
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
```

#### 输出 #1

```
59
```

#### 说明/提示

##### 数据规模与约定

对于全部的测试点，保证 $1 \leq W,H\le 20$。



### AC代码

和上道题思路大差不差，就是找到起点，然后上下左右都跑一遍，

记得标注走过的瓷砖的状态，避免重复记录次数。

然后就是起点那一步也算数的（样例数一下就知道了）

~~~cpp
#include<iostream>
#include<algorithm>
#define r(x) scanf("%d",&x)
using namespace std;

const int N = 30;
char g[N][N];
int n,m;
int res = 1;
bool st[N][N];//瓷砖是否走过

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
void dfs(int x,int y){
    //写四个dfs调用也行

    for(int i = 0; i < 4; i++){
        int a = x+dx[i];
        int b = y+dy[i];

        if(a < 0 || a >= n || b < 0 || b >= m)  continue;
        if(g[a][b] != '.')    continue;
        if(st[a][b])    continue;

        st[a][b] = true;
        res++;
        dfs(a,b);
    }
}

int main(){
    scanf("%d %d",&m,&n);
    for(int i = 0; i < n; i++)
        scanf("%s",g[i]);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(g[i][j] == '@'){
                st[i][j] = true;
                dfs(i,j);
            }
    
    printf("%d\n",res);
    return 0;
}
~~~

---



## 11.P1025 [NOIP 2001 提高组] 数的划分

**[P1025 NOIP 2001 提高组\] 数的划分 - 洛谷](https://www.luogu.com.cn/problem/P1025)**

### 题目描述

将整数 $n$ 分成 $k$ 份，且每份不能为空，任意两个方案不相同（不考虑顺序）。

例如：$n=7$，$k=3$，下面三种分法被认为是相同的。

$1,1,5$;   
$1,5,1$;   
$5,1,1$.

问有多少种不同的分法。

### 输入格式

$n,k$ （$6<n \le 200$，$2  \le k  \le  6$）

### 输出格式

$1$ 个整数，即不同的分法。

### 输入输出样例 #1

#### 输入 #1

```
7 3
```

#### 输出 #1

```
4
```

#### 说明/提示

四种分法为：  
$1,1,5$;  
$1,2,4$;  
$1,3,3$;  
$2,2,3$.

**【题目来源】**

NOIP 2001 提高组第二题



### AC代码

可以看出题目的方案枚举是一种可以出现重复数的排列，

意思是不断地枚举可能的数，且后一个数不会小于前一个数，由此得到一个剪枝策略就是，我们枚举了这个数，后面最小的枚举数总和也就出来了，如果超过了我们要的和，那就不需要继续枚举下去了。

> 例如：我们先枚举了1  2  3，后面还可以枚举N个数，那总和的最小值就是3*N + 6

所以在start的递归上没有像排列题那样+1，

没有考虑到这点

T-T

~~~cpp
#include<iostream>
#include<algorithm>
#include<cstring>
#define r(x) scanf("%d",&x)

using namespace std;

const int N = 10;

int n,k;
int res = 0;//方案数
int arr[N];//记录方案

void dfs(int x, int start, int nowsum){//枚举的位置，从哪个数开始枚举，目前的总和
    if(nowsum > n)  return;

    if(x > k){
        if(nowsum == n)    res++;
        return;
    }
    
    // for(int i = start; i <= n; i++){//不剪枝
    //     arr[x] = i;
    //     dfs(x+1,i,nowsum+i);
    //     arr[x] = 0;
    // }
    
    for(int i = start; nowsum + i*(k-x+1) <= n; i++){//剪枝,后续的选数如果会让总和超过就不要枚举了
        arr[x] = i;
        dfs(x+1,i,nowsum+i);
        arr[x] = 0;
    }
}

int main(){
    r(n);r(k);
    dfs(1,1,0);
    printf("%d\n",res);
    return 0;
}
~~~

---



## 12.P1019 [NOIP 2000 提高组] 单词接龙

**[P1019 NOIP 2000 提高组\] 单词接龙 - 洛谷](https://www.luogu.com.cn/problem/P1019)**

### 题目背景

注意：本题为上古 NOIP 原题，不保证存在靠谱的做法能通过该数据范围下的所有数据。

本题为搜索题，本题不接受 hack 数据。[关于此类题目的详细内容](https://www.luogu.com.cn/paste/isdgwj5l)

NOIP2000 提高组 T3

### 题目描述

单词接龙是一个与我们经常玩的成语接龙相类似的游戏，现在我们已知一组单词，且给定一个开头的字母，要求出以这个字母开头的最长的“龙”（每个单词都最多在“龙”中出现两次），在两个单词相连时，其重合部分合为一部分，例如 `beast` 和 `astonish`，如果接成一条龙则变为 `beastonish`，另外相邻的两部分不能存在包含关系，例如 `at` 和 `atide` 间不能相连。

### 输入格式

输入的第一行为一个单独的整数 $n$ 表示单词数，以下 $n$ 行每行有一个单词，输入的最后一行为一个单个字符，表示“龙”开头的字母。你可以假定以此字母开头的“龙”一定存在。

### 输出格式

只需输出以此字母开头的最长的“龙”的长度。

### 输入输出样例 #1

#### 输入 #1

```
5
at
touch
cheat
choose
tact
a
```

#### 输出 #1

```
23
```

#### 说明/提示

样例解释：连成的“龙”为 `atoucheatactactouchoose`。

$n \le 20$。



### AC代码

题目比较短，2000年的陈年老题，

我们可以关注到两个问题：

> 1.怎么判断这个单词能接到另一个单词的后面
>
> 2.怎么去记录每个单词的使用次数

其实第二个问题很好解决对吧，那我们看第二个问题。

要让两个单词接在一起，就要让第一个单词的后面部分和第二个单词的前面部分有相同（不能是包含），

所以要想办法预处理一下。

用一个二维数组，存储两个单词是否能那个接在一起，

`g[i][j]`表示第`i`个单词能否接在第`j`个单词后面，数值表示重合的长度



这里我们用到`string`的函数`substr`

> `substr(a,b)`表示从下标a开始，取b个数
>
> 如果只有一个参数，表示从起始位置一直取到完



OK啊，插曲结束，我们考虑一个问题啊，

就是两个单词接在了一起，那么是重合部分越长越好，还是越短越好。

那我们很容易想出来对吧，我们要的是长度最长的龙，所以当然是让重合部分越短越好啦，

所以我们在用`k`枚举取的字母的长度时，从少开始取，一旦找到了`a`、`b`两个单词的重合部分，就证明这是他们俩最短的重合部分，然后直接`break`。



这个题真的忒难

彩笔快做哭了

~~~cpp
#include<iostream>
#include<algorithm>
#include<cstring>
#define r(x) scanf("%d",&x)
using namespace std;

const int N = 30;

int n;
string words[N];//存单词
int used[N];//每个单词的使用次数
int g[N][N];//预处理数组，记录两个单词的重合长度
int res = 0;

void dfs(string dragon,int x){//龙，和此时接上去的单词(就是现在的尾巴单词)
    res = max(res,(int)dragon.size());//确保两个参数是同类型

    used[x]++;
    for(int i = 0; i < n; i++){
        if(g[x][i] && used[i] < 2){
            dfs(dragon + words[i].substr(g[x][i]),i);
        }
    }
    used[x]--;//回溯
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> words[i];
        
    char start;
    cin >> start;//龙头
    
    //预处理
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            string a = words[i],b = words[j];
            for(int k = 1; k < min(a.size(),b.size()); k++){//取k个字母
                if(a.substr(a.size() - k, k) == b.substr(0,k)){
                    g[i][j] = k;
                    break;
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        if(words[i][0] == start){//找到做龙头的那个单词
            dfs(words[i],i);
        }
    }
    
    printf("%d\n",res);
    
    return 0;
}
~~~

---



## 13.P1596 [USACO10OCT] Lake Counting S

**[P1596 USACO10OCT\] Lake Counting S - 洛谷](https://www.luogu.com.cn/problem/P1596)**

### 题目描述

Due to recent rains, water has pooled in various places in Farmer John's field, which is represented by a rectangle of N x M (1 <= N <= 100; 1 <= M <= 100) squares. Each square contains either water ('W') or dry land ('.'). Farmer John would like to figure out how many ponds have formed in his field. A pond is a connected set of squares with water in them, where a square is considered adjacent to all eight of its neighbors. Given a diagram of Farmer John's field, determine how many ponds he has.

### 输入格式

Line 1: Two space-separated integers: N and M \* Lines 2..N+1: M characters per line representing one row of Farmer John's field. Each character is either 'W' or '.'. The characters do not have spaces between them.

### 输出格式

Line 1: The number of ponds in Farmer John's field.

### 题意翻译

由于近期的降雨，雨水汇集在农民约翰的田地不同的地方。我们用一个 *N*×*M*(1≤*N*≤100,1≤*M*≤100) 的网格图表示。每个网格中有水（`W`） 或是旱地（`.`）。一个网格与其周围的八个网格相连，而一组相连的网格视为一个水坑。约翰想弄清楚他的田地已经形成了多少水坑。给出约翰田地的示意图，确定当中有多少水坑。

输入第 1 行：两个空格隔开的整数：*N* 和 *M*。

第 2 行到第 *N*+1 行：每行 *M* 个字符，每个字符是 `W` 或 `.`，它们表示网格图中的一排。字符之间没有空格。

输出一行，表示水坑的数量。

### 输入输出样例 #1

#### 输入 #1

```
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
```

#### 输出 #1

```
3
```

#### 说明/提示

OUTPUT DETAILS: There are three ponds: one in the upper left, one in the lower left, and one along the right side.



### AC代码

其实看到这里这道题也不用讲了，这个题目是我忘记记录的，和求细胞数量的那个题完全没差别，我相信各位大佬手拿把掐。

~~~cpp
#include<iostream>
#include<algorithm>
#define r(x) scanf("%d",&x)
using namespace std;

const int N = 110;

int n,m;
char g[N][N];
bool st[N][N];
int res = 0;

int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {1,1,0,-1,-1,-1,0,1};
void dfs(int x,int y){
    for(int i = 0; i < 8; i++){
        int a = x+dx[i];
        int b = y+dy[i];
        
        if(a<0 || a>=n || b<0 || b>=m)  continue;
        if(g[a][b] != 'W')  continue;
        if(st[a][b])    continue;
        
        st[a][b] = 'true';
        dfs(a,b);
    }
}

int main(){
    r(n);r(m);
    for(int i = 0; i < n; i++)
        scanf("%s",g[i]);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == 'W' && !st[i][j]){
                dfs(i,j);
                res++;
            }
        }
    }
    printf("%d\n",res);
    
    return 0;
}
~~~

---



那么在这个知识点的最后还是要感谢一下小破站的大佬up主`一只会code的小金鱼`
