**1、**A+B问题

我直接一手 return a+b;

但是！先看答案

```c++
class Solution 
{
    /*
     * param a: The first integer
     * param b: The second integer
     * return: The sum of a and b
     */
public:
    int aplusb(int a, int b) 
    {
        // 主要利用异或运算来完成 
        // 异或运算有一个别名叫做：不进位加法
        // 那么a ^ b就是a和b相加之后，该进位的地方不进位的结果
        // 然后下面考虑哪些地方要进位，自然是a和b里都是1的地方
        // a & b就是a和b里都是1的那些位置，a & b << 1 就是进位
        // 之后的结果。所以：a + b = (a ^ b) + (a & b << 1)
        // 令a' = a ^ b, b' = (a & b) << 1
        // 可以知道，这个过程是在模拟加法的运算过程，进位不可能
        // 一直持续，所以b最终会变为0。因此重复做上述操作就可以
        // 求得a + b的值。
        while (b != 0) 
        {
            int _a = a ^ b;
            int _b = (a & b) << 1;
            a = _a;
            b = _b;
        }
        return a;
    }
};
```

so...?  why??...

不明白这么做在效率上有何提高，为何不直接a+b结束？

**2、**给定一个整型数组，找出主元素，它在数组中的出现次数大于数组元素个数的二分之一。

输入：

```
数组 = [1, 1, 1, 1, 2, 2, 2]
```

输出：

```
1
```

解释：

数组中1的个数大于数组元素的二分之一。

#### 方法：Boyer-MooreBoyer-Moore 投票算法

由于题目要求时间复杂度 **O*(*n)** 和空间复杂度 **O(1)**，因此符合要求的解法只有Boyer-Moore 投票算法。

Boyer-Moore 投票算法的基本思想是：在每一轮投票过程中，从数组中删除两个不同的元素，直到投票过程无法继续，此时数组为空或者数组中剩下的元素都相等。

- 如果数组为空，则数组中不存在主要元素；
- 如果数组中剩下的元素都相等，则数组中剩下的元素可能为主要元素。

Boyer-Moore 投票算法的步骤如下：

1. 维护一个候选主要元素 **candidate** 和候选主要元素的出现次数 **count**，初始时 candidate 为任意值，count=0；
2. 遍历数组 nums 中的所有元素，遍历到元素 **x** 时，进行如下操作：
   1. 如果 count=0，则将 **x** 的值赋给 candidate，否则不更新 candidate 的值；
   2. 如果 **x**=**candidate**，则将 count加 1，否则将 count 减 1。
3. 遍历结束之后，如果数组 nums 中存在主要元素，则 candidate 即为主要元素，否则candidate可能为数组中的任意一个元素。

由于不一定存在主要元素，因此需要第二次遍历数组，验证 candidate是否为主要元素。第二次遍历时，统计 candidate 在数组中的出现次数，如果出现次数大于数组长度的一半，则 candidate是主要元素，返回 candidate，否则数组中不存在主要元素，返回 −1。

为什么当数组中存在主要元素时，Boyer-Moore 投票算法可以确保得到主要元素？

在 Boyer-Moore 投票算法中，遇到相同的数则将 count加 1，遇到不同的数则将 count减 1。根据主要元素的定义，主要元素的出现次数大于其他元素的出现次数之和，因此在遍历过程中，主要元素和其他元素两两抵消，最后一定剩下至少一个主要元素，此时 candidate 为主要元素，且 count≥1。

```c++
class Solution {
public:
    int  majorityNumber(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (int& num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        count = 0;
        int length = nums.size();
        for (int& num : nums) {
            if (num == candidate) {
                count++;
            }
        }
        return count * 2 > length ? candidate : -1;
    }
}
```

**3、**给定一个整数数组`A`。
定义B*[*i*]=*A*[0]∗...∗*A*[*i*−1]∗*A*[*i*+1]∗...∗*A*[*n*−1]， 计算`B`的时候请不要使用除法。请输出`B`。

**样例 1：**

输入：

```
A = [1,2,3]
```

输出：

```
[6,3,2]
```

解释：

B[0] = A[1] * A[2] = 6; B[1] = A[0] * A[2] = 3; B[2] = A[0] * A[1] = 2

#### 方法：空间复杂度 O*(1) 的方法

**思路**

由于输出数组不算在空间复杂度内，那么我们可以将 `L` 或 `R` 数组用输出数组来计算。先把输出数组当作 `L` 数组来计算，然后再动态构造 `R` 数组得到结果。让我们来看看基于这个思想的算法。

**算法**

1. 初始化 `answer` 数组，对于给定索引 `i`，`answer[i]` 代表的是 `i` 左侧所有数字的乘积。
2. 构造方式与之前相同，只是我们试图节省空间，先把 `answer` 作为方法一的 `L` 数组。
3. 这种方法的唯一变化就是我们没有构造 `R` 数组。而是用一个遍历来跟踪右边元素的乘积。并更新数组 an**s**w**er*[*i*]=*an**s**w**er*[*i*]∗*R*。然后 R* 更新为R*=*R*∗*n**u**m**s*[*i*]，其中变量 R* 表示的就是索引右侧数字的乘积。

```c++
class Solution {
public:
    vector<long long> productExcludeItself(vector<int>& nums) {
        long length = nums.size();
        vector<long long> answer(length);

        // answer[i] 表示索引 i 左侧所有元素的乘积
        // 因为索引为 '0' 的元素左侧没有元素， 所以 answer[0] = 1
        answer[0] = 1;
        for (int i = 1; i < length; i++) {
            answer[i] = nums[i - 1] * answer[i - 1];
        }

        // R 为右侧所有元素的乘积
        // 刚开始右边没有元素，所以 R = 1
        long R = 1;
        for (int i = length - 1; i >= 0; i--) {
            // 对于索引 i，左边的乘积为 answer[i]，右边的乘积为 R
            answer[i] = answer[i] * R;
            // R 需要包含右边所有的乘积，所以计算下一个结果时需要将当前值乘到 R 上
            R *= nums[i];
        }
        return answer;
    }
};
```

**4、**旋转数组

描述

给定一个数组，将数组向右移动k步，其中k为非负数。

样例

**样例 1:**

```
输入: [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转1步: [7,1,2,3,4,5,6]
向右旋转2步: [6,7,1,2,3,4,5]
向右旋转3步: [5,6,7,1,2,3,4]
```

**样例 2:**

```
输入: [-1,-100,3,99], k = 2
输出: [3,99,-1,-100]
解释: 
向右旋转1步: [99,-1,-100,3]
向右旋转2步: [3,99,-1,-100]
```

自己的答案的写法

```c++
/*大致想法是让旋转几次就循环几次，然后每次让末尾的数插入到最前面去，然后重置数组大小删掉末尾的数
但是这样时间就用的太长了，显然不行*/
	vector<int> rotate(vector<int>& nums, int k) 
    {
        // Write your code here
        for (int i = 0; i < k; i++)
        {
            int temp = nums[nums.size() - 1];
            nums.insert(nums.begin(), temp);
            nums.resize(nums.size() - 1);
        }
        return nums;
    }
```

然后我们来看看答案的几种写法：

```c++
/*
首先是一个简单的写法：使用额外的数组
*/
class Solution {
public:
    vector<int> rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> newArr(n);
        for (int i = 0; i < n; ++i) {
            newArr[(i + k) % n] = nums[i];
        }
        return newArr;
    }
};
```

```c++
/*
或者，也可以这样
Example：nums = [1,2,3,4,5,6,7] k = 3
Step1:划分成[1,2,3,4], [5,6,7]
Step2:分别reverse，[4,3,2,1], [7,6,5]
Step3:合并reverse，[5,6,7,1,2,3,4]
*/
class Solution {
public:
    vector<int> rotate(vector<int> &nums, int k) {
        // Write your code here
        if(k == 0 ||nums.size() < 2) return nums;
        
        k = k%nums.size();
        reverse(nums.begin(), nums.begin() + nums.size() - k);
        reverse(nums.begin() + nums.size() - k, nums.end());
        reverse(nums.begin(), nums.end());
        return nums;
    }
};
```

```c++
/*
亦或者，这个数学推理，不过这个比较难看懂
*/
class Solution {
public:
    vector<int> rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = __gcd(k, n);
        for (int start = 0; start < count; ++start) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                swap(nums[next], prev);
                current = next;
            } while (start != current);
        }
        return nums;
    }
};
```

![image-20230405234233451](C:\Users\Accel\AppData\Roaming\Typora\typora-user-images\image-20230405234233451.png)

--

**5、**KMP模式匹配法

眼睛：我看会了

脑子：我理解了

手：啊？

```c++
//这是答案
class Solution {
public:
    /**
     * @param source: 
     * @param target: 
     * @return: return the index
     */
    int strStr(string &source, string &target) {
        // Write your code here
        int n = source.size(), m = target.size();
        if (m == 0) {
            return 0;
        }
        vector<int> pi(m);
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && target[i] != target[j]) {
                j = pi[j - 1];
            }
            if (target[i] == target[j]) {
                j++;
            }
            pi[i] = j;
        }
        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && source[i] != target[j]) {
                j = pi[j - 1];
            }
            if (source[i] == target[j]) {
                j++;
            }
            if (j == m) {
                return i - m + 1;
            }
        }
        return -1;
    }
};
```

**6、**给定字符串S，找到一个字母字符，其大写和小写字母均出现在S中，则返回此字母的大写，若存在多个答案，返回最大的字母，不存在则返回"NO"。

```c++
输入: S = "admeDCAB"
输出: "D"

输入: S = "adme"
输出: "NO"
```

眼前一黑的题解：

```c++
class Solution {
public:
    /**
     * @param s: a string
     * @return: a string
     */
    int key(char c) {
        if (c >= 'a' && c <= 'z'){
            return c - 'a';
        } else {
            return 26 + c - 'A';
        }
    }
    string largestLetter(string &s) {
        // write your code here
        int num[60];
        memset(num, 0, sizeof num);
        for (auto i : s) {
            int k = key(i);
            num[k]++;
        }
        string ans = "NO";
        for (int i = 25 ;i >= 0; i--) {
            if (num[i] && num[i + 26]) {
                ans = ('A'+i);
                break;
            }
        }
        return ans;
    }
};
```

```c++
class Solution {
public:
    /**
     * @param s: a string
     * @return: a string
     */
    string largestLetter(string &s) {
        // write your code here
        for(char c='Z';c>='A';c--){
            if(s.find(c)!=s.npos&&s.find(c+'a'-'A')!=s.npos) return string(1,c);
        }
        return "NO";
    }
};
```

**7、**树的前序中序后续遍历----非递归的形式

​	**前序遍历**

## Morris 遍历

### 思路与算法

有一种巧妙的方法可以在线性时间内，只占用常数空间来实现前序遍历。这种方法由 J. H. Morris 在 1979 年的论文「Traversing Binary Trees Simply and Cheaply」中首次提出，因此被称为 Morris 遍历。

Morris 遍历的核心思想是利用树的大量空闲指针，实现空间开销的极限缩减。其前序遍历规则总结如下：

1. 新建临时节点，令该节点为 `root`；
2. 如果当前节点的左子节点为空，将当前节点加入答案，并遍历当前节点的右子节点；
3. 如果当前节点的左子节点不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点：
   - 如果前驱节点的右子节点为空，将前驱节点的右子节点设置为当前节点。然后将当前节点加入答案，并将前驱节点的右子节点更新为当前节点。当前节点更新为当前节点的左子节点。
   - 如果前驱节点的右子节点为当前节点，将它的右子节点重新设为空。当前节点更新为当前节点的右子节点。
4. 重复步骤 2 和步骤 3，直到遍历结束。

这样我们利用 Morris 遍历的方法，前序遍历该二叉树，即可实现线性时间与常数空间的遍历。

```c++
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        TreeNode *p1 = root, *p2 = nullptr;

        while (p1 != nullptr) {
            p2 = p1->left;
            if (p2 != nullptr) {
                while (p2->right != nullptr && p2->right != p1) {
                    p2 = p2->right;
                }
                if (p2->right == nullptr) {
                    res.emplace_back(p1->val);
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                } else {
                    p2->right = nullptr;
                }
            } else {
                res.emplace_back(p1->val);
            }
            p1 = p1->right;
        }
        return res;
    }
};
```

​	**中序遍历**

## Morris 中序遍历

### 解题思路

**Morris 遍历算法**是另一种遍历二叉树的方法，它能将非递归的中序遍历空间复杂度降为 O(1)。

**Morris 遍历算法**整体步骤如下（假设当前遍历到的节点为 *x*）：

1. 如果 x 无左孩子，先将 x的值加入答案数组，再访问 x 的右孩子，即 x*=*x*.*right。
2. 如果*x*有左孩子，则找到左子树上最右的节点（即左子树中序遍历的最后一个节点，x 在中序遍历中的前驱节点），我们记为predecessor。根据predecessor的右孩子是否为空，进行如下操作。
   - 如果*predecessor* 的右孩子为空，则将其右孩子指向 *x*，然后访问 x*的左孩子，即 x*=*x*.*left*。
   - 如果 predecessor的右孩子不为空，则此时其右孩子指向 x*，说明我们已经遍历完 x* 的左子树，我们将 predecessor 的右孩子置空，将 x 的值加入答案数组，然后访问 x的右孩子，即 x*=*x*.*right。
3. 重复上述操作，直至访问完整棵树。

其实整个过程我们就多做一步：假设当前遍历到的节点为 x*，将 x* 的左子树中最右边的节点的右孩子指向 x*，这样在左子树遍历完成后我们通过这个指向走回了 x*，且能通过这个指向知晓我们已经遍历完成了左子树，而不用再通过栈来维护，省去了栈的空间复杂度。

```c++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *predecessor = nullptr;

        while (root != nullptr) {
            if (root->left != nullptr) {
                // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
                predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }
                
                // 让 predecessor 的右指针指向 root，继续遍历左子树
                if (predecessor->right == nullptr) {
                    predecessor->right = root;
                    root = root->left;
                }
                // 说明左子树已经访问完了，我们需要断开链接
                else {
                    res.push_back(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                }
            }
            // 如果没有左孩子，则直接访问右孩子
            else {
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};
```

​	**后序遍历**

## Morris 遍历

### 解题思路

有一种巧妙的方法可以在线性时间内，只占用常数空间来实现后序遍历。这种方法由 J. H. Morris 在 1979 年的论文「Traversing Binary Trees Simply and Cheaply」中首次提出，因此被称为 Morris 遍历。

Morris 遍历的核心思想是利用树的大量空闲指针，实现空间开销的极限缩减。其后序遍历规则总结如下：

1. 新建临时节点，令该节点为 `root`；
2. 如果当前节点的左子节点为空，则遍历当前节点的右子节点；
3. 如果当前节点的左子节点不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点；
   - 如果前驱节点的右子节点为空，将前驱节点的右子节点设置为当前节点，当前节点更新为当前节点的左子节点。
   - 如果前驱节点的右子节点为当前节点，将它的右子节点重新设为空。倒序输出从当前节点的左子节点到该前驱节点这条路径上的所有节点。当前节点更新为当前节点的右子节点。
4. 重复步骤 2 和步骤 3，直到遍历结束。

这样我们利用 Morris 遍历的方法，后序遍历该二叉搜索树，即可实现线性时间与常数空间的遍历。

```c++
class Solution {
public:
    void addPath(vector<int> &vec, TreeNode *node) {
        int count = 0;
        while (node != nullptr) {
            ++count;
            vec.emplace_back(node->val);
            node = node->right;
        }
        reverse(vec.end() - count, vec.end());
    }

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        TreeNode *p1 = root, *p2 = nullptr;

        while (p1 != nullptr) {
            p2 = p1->left;
            if (p2 != nullptr) {
                while (p2->right != nullptr && p2->right != p1) {
                    p2 = p2->right;
                }
                if (p2->right == nullptr) {
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                } else {
                    p2->right = nullptr;
                    addPath(res, p1->left);
                }
            }
            p1 = p1->right;
        }
        addPath(res, root);
        return res;
    }
};
```

-----------------------------------------------------------------------------------------------------------------------------------------------------------

至此，此项结束。
