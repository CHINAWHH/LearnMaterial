#include "AutumnMove.h"

int AutumnMove::maxProfit1(vector<int>& prices)
{
    if (prices.empty())
    {
        return 0;
    }
    int ret = 0;
    int preMin = INT_MAX;
    for (auto &it:prices)
    {
        ret = max(ret, it - preMin);
        preMin = min(preMin, it);
    }
    return ret;
}

int AutumnMove::maxProfit2(vector<int>& prices)
{
    if (prices.empty())
    {
        return 0;
    }
    vector<vector<int>> dp(prices.size() + 1, vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = INT_MIN;
    for (int i=1;i<=prices.size();++i)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i-1]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i - 1]);
    }
    return dp.back()[0];
}

int AutumnMove::maxProfit3(vector<int>& prices)
{
    if (prices.empty())
    {
        return 0;
    }
    vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(3, vector<int>(2)));
    dp[0][1][0] = 0;
    dp[0][1][1] = -prices[0];
    dp[0][2][0] = 0;
    dp[0][2][1] = -prices[0];
    for (int i = 1; i < prices.size(); ++i)
    {
        dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][1][1] + prices[i]);
        dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][0][0] - prices[i]);
        dp[i][2][0] = max(dp[i - 1][2][0], dp[i - 1][2][1] + prices[i]);
        dp[i][2][1] = max(dp[i - 1][2][1], dp[i - 1][1][0] - prices[i]);
    }
    return dp[prices.size() - 1][2][0];
}

int AutumnMove::maxProfit4(int k, vector<int>& prices)
{
    if (k<=0)
    {
        return 0;
    }
    if (k>=prices.size()/2)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = INT_MIN;
        for (int i = 1; i <= prices.size(); ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i - 1]);
        }
        return dp.back()[0];
    }
    vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(k + 1, vector<int>(2)));
    for (int i=0;i<=k;++i)
    {
        dp[0][i][1] = INT_MIN;
    }
    for (int i=1;i<=prices.size();++i)
    {
        for (int j=1;j<=k;++j)
        {
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i-1]);
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j-1][0] - prices[i-1]);
        }
    }
    return dp[prices.size()][k][0];
}

int AutumnMove::maxProfit5(vector<int>& prices)
{
    if (prices.size()<2)
    {
        return 0;
    }
    vector<vector<int>> dp(prices.size() + 1, vector<int>(2));
    dp[0][1] = INT_MIN;
    for (int i=1;i<=prices.size();++i)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
        if (i>=2)
        {
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i - 1]);
        }
        else
        {
            dp[i][1] = max(dp[i - 1][1], -prices[i - 1]);
        }
    }
    return dp[prices.size()][0];
}

int AutumnMove::maxProfit6(vector<int>& prices, int fee)
{
    if (prices.empty())
    {
        return 0;
    }
    vector<vector<int>> dp(prices.size() + 1, vector<int>(2));
    dp[0][1] = INT_MIN;
    for (int i=1;i<=prices.size();++i)
    {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i - 1]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i - 1] - fee);
    }
    return dp[prices.size()][0];
}

std::vector<int> AutumnMove::smallestRange(vector<vector<int>>& nums)
{
    multimap<int, int> numstomap;//Ԫ��ֵ-��������ţ�Ĭ�ϰ�ֵ����
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[i].size(); j++)
        {
            numstomap.insert(pair<int, int>(nums[i][j], i));
        }
    }
    multimap<int, int>::iterator left = numstomap.begin();//��ָ�룬����ָ���ʼ��λ�����
    multimap<int, int>::iterator right = numstomap.begin();//��ָ��
    int res = INT_MAX;//����һ����������ʼֵ
    int leftv = 0;//���ؽ��������Ԫ��ֵ
    int rightv = 0;//
    int k = nums.size();//�����
    unordered_map<int, int> curmap;//�����-����
    while (right != numstomap.end())//��ֹ����
    {
        curmap[right->second] ++;//���������������Ԫ��
        while (curmap.size() == k)//�Ѿ��ҵ���һ�����н⡢�Ż���
        {
            if (right->first - left->first < res)//��¼���н�
            {
                res = right->first - left->first;
                leftv = left->first;
                rightv = right->first;
            }
            curmap[left->second] --;//��������
            if (curmap[left->second] == 0)
            {
                curmap.erase(left->second);
            }
            left++;
        }
        right++;
    }
    if (res == INT_MAX) 
        return {};
    else 
        return { leftv,rightv };
}

std::string AutumnMove::addStrings(string num1, string num2)
{
    if (num1.empty())
    {
        return num2;
    }
    if (num2.empty())
    {
        return num1;
    }
    string ret(max(num1.size(), num2.size()) + 1,0);
    int left = num1.size()-1, right = num2.size()-1;
    int index = 0,add=0,sum=0;
    while (left>=0&&right>=0)
    {
        sum = num1[left--] + num2[right--] + add-2*'0';
        ret[index++] = sum % 10+'0';
        add = sum / 10;
    }
    while (left>=0)
    {
        sum = num1[left--]  + add - '0';
        ret[index++] = sum % 10+'0';
        add = sum / 10;
    }
    while (right >= 0)
    {
        sum = num2[right--] + add - '0';
        ret[index++] = sum % 10+'0';
        add = sum / 10;
    }
    if (add!=0)
    {
        ret[index] = add+'0';
    }
    else
    {
        ret.pop_back();
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

bool AutumnMove::canJump(vector<int>& nums)
{
    if (nums.empty())
    {
        return false;
    }
    int nextIndex = 0;
    for (int i=0;i<nums.size();++i)
    {
        if (nextIndex<i)
        {
            return false;
        }
        nextIndex = max(nextIndex, i + nums[i]);
        if (nextIndex>=nums.size()-1)
        {
            return true;
        }
    }
    return false;
}

void AutumnMove::mergeVector(vector<int>& A, int m, vector<int>& B, int n)
{
    if (A.empty()||B.empty())
    {
        return;
    }
    int index = A.size()-1;
    --m;
    --n;
    while (m>=0&&n>=0)
    {
        if (A[m]>B[n])
        {
            A[index--] = A[m--];
        }
        else
        {
            A[index--] = B[n--];
        }
    }
    while (n>=0)
    {
        A[index--] = B[n--];
    }
}

int AutumnMove::cuttingRope(int n)
{
    if (n<=2)
    {
        return 1;
    }
    if (n==3)
    {
        return 2;
    }
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for (int i=4;i<=n;++i)
    {
        for (int j=1;2*j<=i;++j)
        {
            dp[i] = max(dp[i], dp[j] * dp[i - j]);
        }
    }
    return dp.back();
}

ListNode* AutumnMove::getIntersectionNode(ListNode* headA, ListNode* headB)
{
    if (nullptr ==headA||nullptr==headB)
    {
        return nullptr;
    }
    ListNode* newHeadA = headA;
    ListNode* newHeadB = headB;
    int countA = 0, countB = 0;
    while (newHeadA)
    {
        ++countA;
        newHeadA = newHeadA->next;
    }
    while (newHeadB)
    {
        ++countB;
        newHeadB = newHeadB->next;
    }
    int diff = countA - countB;
    newHeadA = headA;
    newHeadB = headB;
    if (diff<0)
    {
        while (diff)
        {
            ++diff;
            newHeadB = newHeadB->next;
        }
    }
    else
    {
        while (diff)
        {
            --diff;
            newHeadA = newHeadA->next;
        }
    }
    while (NULL != newHeadA&&NULL!=newHeadB)
    {
        if (newHeadA==newHeadB)
        {
            return newHeadA;
        }
        newHeadA = newHeadA->next;
        newHeadB = newHeadB->next;
    }
    return NULL;
}

double AutumnMove::Sqrt(double target, double diff)
{
    if (target<=0)
    {
        return 0;
    }
    double C = target, x0 = target;
    while (true) 
    {
        double xi = 0.5 * (x0 + C / x0);
        if (fabs(x0 - xi) < diff)
        {
            break;
        }
        x0 = xi;
    }
    return x0;
}

bool AutumnMove::canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    if (prerequisites.empty())
    {
        return true;
    }
    vector<int> inVec(numCourses);
    vector<vector<int>> ouVec(numCourses);
    for (int i=0;i<prerequisites.size();++i)
    {
        inVec[prerequisites[i][0]] += prerequisites[i].size()-1;
        for (int j=1;j<prerequisites[i].size();++j)
        {
            ouVec[prerequisites[i][j]].emplace_back(prerequisites[i][0]);
        }
    }
    queue<int> que;
    for (int i=0;i<inVec.size();++i)
    {
        if (inVec[i]==0)
        {
            que.push(i);
        }
    }
    int count = 0;
    while (!que.empty())
    {
        int node = que.front();
        que.pop();
        ++count;
        for (auto &it:ouVec[node])
        {
            --inVec[it];
            if (inVec[it]==0)
            {
                que.push(it);
            }
        }
    }
    return count == numCourses;
}

ListNode* AutumnMove::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    if (nullptr==l1)
    {
        return l2;
    }
    if (nullptr==l2)
    {
        return l1;
    }
    ListNode* newHead = new ListNode(0);
    ListNode* curNode = newHead;
    int add = 0,sum=0;
    while (l1&&l2)
    {
        sum = l1->val + l2->val + add;
        curNode->next = new ListNode(sum % 10);
        add = sum / 10;
        l1 = l1->next;
        l2 = l2->next;
        curNode = curNode->next;
    }
    while (l1)
    {
        sum = l1->val + add;
        curNode->next = new ListNode(sum % 10);
        add = sum / 10;
        l1 = l1->next;
        curNode = curNode->next;
    }
    while (l2)
    {
        sum = l2->val + add;
        curNode->next = new ListNode(sum % 10);
        add = sum / 10;
        l2 = l2->next;
        curNode = curNode->next;
    }
    if (add!=0)
    {
        curNode->next= new ListNode(add);
    }
    curNode = newHead->next;
    delete newHead;
    return curNode;
}

TreeNode* AutumnMove::lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    //LCA����
    if (nullptr==root|| p == root || q == root)
    {
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (nullptr!=left&&nullptr!=right)
    {
        return root;
    }
    else if (nullptr==left&&nullptr==right)
    {
        return nullptr;
    }
    return nullptr == left ? right : left;
}

int dfsPathSum(TreeNode* root, int& ret)
{
    if (nullptr==root)
    {
        return 0;
    }
    int leftMax = max(dfsPathSum(root->left, ret), 0);
    int rightMax = max(dfsPathSum(root->right, ret), 0);
    ret = max(leftMax + rightMax + root->val, ret);
    return max(root->val+max(leftMax, rightMax),0);
}

int AutumnMove::maxPathSum(TreeNode* root)
{
    if (nullptr==root)
    {
        return 0;
    }
    int ret = INT_MIN;
    dfsPathSum(root, ret);
    return ret;
}

void partion(vector<int>& nums, int left, int right)
{
    if (left>=right)
    {
        return;
    }
    int leftCur = left;
    int rightCur = right + 1;
    int prio = nums[leftCur];
    while (leftCur < rightCur)
    {
        do 
        {
            ++leftCur;
        } while (leftCur<rightCur&&nums[leftCur]<prio);
        do 
        {
            --rightCur;
        } while (nums[rightCur]>prio);
        if (leftCur>=rightCur)
        {
            //Ҫ��д>=��������
            break;
        }
        swap(nums[leftCur], nums[rightCur]);
    }
    swap(nums[left], nums[rightCur]);
    partion(nums, left, rightCur - 1);
    partion(nums, rightCur+1, right);
}

void AutumnMove::QuickSort(vector<int>& nums)
{
    if (nums.size()<2)
    {
        return;
    }
    partion(nums,0,nums.size()-1);
}

std::vector<int> AutumnMove::preorderTraversal(TreeNode* root)
{
    if (nullptr==root)
    {
        return {};
    }
    stack<TreeNode*> stac;
    vector<int> ret;
    stac.push(root);
    while (!stac.empty())
    {
        TreeNode* node = stac.top();
        stac.pop();
        ret.emplace_back(node->val);
        if (node->right)
        {
            stac.push(node->right);
        }
        if (node->left)
        {
            stac.push(node->left);
        }
    }
    return ret;
}

std::vector<int> AutumnMove::postorderTraversal(TreeNode* root)
{
    if (nullptr==root)
    {
        return {};
    }
    stack<TreeNode*> stac;
    vector<int> ret;
    stac.push(root);
    while (!stac.empty())
    {
        TreeNode* node = stac.top();
        stac.pop();
        ret.emplace_back(node->val);
        if (node->left)
        {
            stac.push(node->left);
        }
        if (node->right)
        {
            stac.push(node->right);
        }
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int AutumnMove::longestConsecutive(vector<int>& nums)
{
    if (nums.empty())
    {
        return 0;
    }
    unordered_set<int> hashSet(nums.begin(), nums.end());
    int ret = 0;
    for (auto &it:hashSet)
    {
        if (hashSet.count(it+1)==0)
        {
            int temp = it;
            int count = 0;
            while (hashSet.count(temp))
            {
                --temp;
                ++count;
            }
            ret = max(count, ret);
        }
    }
    return ret;
}

int AutumnMove::trap(vector<int>& height)
{
    if (height.empty())
    {
        return 0;
    }
    vector<int> leftVec(height.size()+1);
    vector<int> rightVec(height.size()+1);
    for (int i=1;i<=height.size();++i)
    {
        leftVec[i] = max(leftVec[i - 1], height[i-1]);
    }
    for (int i=height.size()-2;i>=0;--i)
    {
        rightVec[i] = max(height[i+1], rightVec[i + 1]);
    }
    int ret = 0;
    for (int i=0;i<height.size();++i)
    {
        ret += max(min(leftVec[i], rightVec[i]) - height[i], 0);
    }
    return ret;
}

unordered_map<TreeNode*,int> hashM;
int dfsRob3(TreeNode* root)
{
    if (nullptr==root)
    {
        return 0;
    }
    if (hashM.count(root))
    {
        return hashM[root];
    }
    int ret1 = root->val;
    if (root->left)
    {
        ret1 += dfsRob3(root->left->left) + dfsRob3(root->left->right);
    }
    if (root->right)
    {
        ret1+= dfsRob3(root->right->left) + dfsRob3(root->right->right);
    }
    int ret2 = dfsRob3(root->left) + dfsRob3(root->right);
    hashM[root] = max(ret1, ret2);
    return hashM[root];
}

int AutumnMove::rob(TreeNode* root)
{
    if (NULL==root)
    {
        return 0;
    }
    return dfsRob3(root);
}

void Merge(vector<int>& nums, vector<int>& helpNums, int start, int end)
{
    if (start>=end)
    {
        helpNums[end] = nums[end];
        return;
    }
    const int len = (end-start)/2;
    Merge(nums, helpNums, start, start + len);
    Merge(nums, helpNums, start + len + 1, end);
    int startIndex = start + len;
    int endIndex = end;
    int curIndex = end;
    while (startIndex >=start&&endIndex>=start+len+1)
    {
        if (nums[startIndex]<nums[endIndex])
        {
            helpNums[curIndex--] = nums[endIndex--];
        }
        else
        {
            helpNums[curIndex--] = nums[startIndex--];
        }
    }
    while (startIndex >= start)
    {
        helpNums[curIndex--] = nums[startIndex--];
    }
    while (endIndex >= start + len + 1)
    {
        helpNums[curIndex--] = nums[endIndex--];
    }
    for (int i=start;i<=end;++i)
    {
        nums[i] = helpNums[i];
    }
}

void AutumnMove::MergeSort(vector<int>& nums)
{
    if (nums.size()<2)
    {
        return;
    }
    vector<int> helpNums(nums.size());
    Merge(nums, helpNums, 0, nums.size() - 1);
}

bool AutumnMove::isSameTree(TreeNode* p, TreeNode* q)
{
    if (nullptr==p&&nullptr==q)
    {
        return true;
    }
    if (nullptr==p||nullptr==q)
    {
        return false;
    }
    if (p->val!=q->val)
    {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

ListNode* AutumnMove::reverseList(ListNode* head)
{
    if (nullptr==head)
    {
        return head;
    }
    ListNode* pre = nullptr;
    ListNode* pTemp = nullptr;
    while (head)
    {
        pTemp = head->next;
        head->next = pre;
        pre = head;
        head = pTemp;
    }
    return pre;
}

std::pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail)
{
    ListNode* pre = tail->next;
    ListNode* p = head;
    while (pre !=tail)
    {
        ListNode* nex = p->next;
        p->next = pre;
        pre = p;
        p = nex;
    }
    return { tail,head };
}

ListNode* AutumnMove::reverseKGroup(ListNode* head, int k)
{
    if (nullptr==head||k<2)
    {
        return head;
    }
    ListNode* newHead = new ListNode(0);
    newHead->next = head;
    ListNode* pre = newHead;
    while (head)
    {
        ListNode* tail = pre;
        for (int i=0;i<k;++i)
        {
            tail = tail->next;
            if (!tail)
            {
                return newHead->next;
            }
        }
        ListNode* nex = tail->next;
        std::pair<ListNode*, ListNode*> res = myReverse(head, tail);
        head = res.first;
        tail = res.second;
        // �����������½ӻ�ԭ����
        pre->next = head;
        tail->next = nex;
        pre = tail;
        head = tail->next;
    }
    return newHead->next;
}

std::vector<std::vector<int>> AutumnMove::generateMatrix(int n)
{
    if (n<1)
    {
        return {};
    }
    vector<vector<int>> ret(n, vector<int>(n));
    int leftNum = 0, rightNum = n-1, top = 0, low = n-1;
    int number = 1;
    while (true)
    {
        for (int i=leftNum;i<= rightNum;++i)
        {
            ret[top][i] = number++;
        }
        ++top;
        if (top>low)
        {
            break;
        }
        for (int i=top;i<=low;++i)
        {
            ret[i][rightNum] = number++;
        }
        --rightNum;
        if (rightNum<leftNum)
        {
            break;
        }
        for (int i=rightNum;i>=leftNum;--i)
        {
            ret[low][i] = number++;
        }
        --low;
        if (low<top)
        {
            break;
        }
        for (int i=low;i>=top;--i)
        {
            ret[i][leftNum] = number++;
        }
        ++leftNum;
        if (leftNum>rightNum)
        {
            break;
        }
    }
    return ret;
}

int AutumnMove::countBinarySubstrings(string s)
{
    if (s.size()<2)
    {
        return 0;
    }
    int preCount = 0;
    int ret = 0;
    int left = 0;
    while (left<s.size())
    {
        int curCount = 0;
        int preIndex = left;
        while (left<s.size()&&s[left]==s[preIndex])
        {
            ++left;
            ++curCount;
        }
        ret += min(curCount, preCount);
        preCount = curCount;
    }
    return ret;
}

const int block = 4;

void BackIpAddresses(const string& str, int piece, int start, vector<int>& path, vector<string>& ret)
{
    if (start>str.size())
    {
        return;
    }
    if (piece==block)
    {
        if (start==str.size())
        {
            string strTemp;
            for (int i = 0; i < path.size(); ++i)
            {
                strTemp += to_string(path[i]);
                if (i != path.size() - 1)
                {
                    strTemp.push_back(',');
                }
            }
            ret.emplace_back(strTemp);
        }
        return;
    }
    if (str[start]=='0')
    {
        path.emplace_back(0);
        BackIpAddresses(str, piece + 1, start + 1, path, ret);
        path.pop_back();
        return;
    }
    int num=0;
    for (int i=0;i<3;++i)
    {
        num = str[start+i] - '0' + num * 10;
        if (num>255)
        {
            break;
        }
        path.emplace_back(num);
        BackIpAddresses(str, piece + 1, start + i+1, path, ret);
        path.pop_back();
    }
}

std::vector<std::string> AutumnMove::restoreIpAddresses(string s)
{
    if (s.size()<2)
    {
        return {};
    }
    vector<int> path;
    vector<string> ret;
    BackIpAddresses(s, 0, 0, path, ret);
    return ret;
}

void HeapHelp(vector<int>& nums, int start,const int len)
{
    int nextIndex = 2 * start + 1;
    int tempNode = nums[start];
    while (nextIndex<len)
    {
        if (nextIndex+1<len&&nums[nextIndex]<nums[nextIndex+1])
        {
            ++nextIndex;
        }
        if (tempNode>nums[nextIndex])
        {
            break;
        }
        nums[start] = nums[nextIndex];
        start =nextIndex;
        nextIndex = 2 * start + 1;
    }
    nums[start] = tempNode;
}

void AutumnMove::HeapSort(vector<int>& nums)
{
    if (nums.size()<2)
    {
        return;
    }
    const int len = nums.size();
    for (int i=len/2-1;i>=0;--i)
    {
        HeapHelp(nums, i, len);
    }
    for (int i=len-1;i>=0;--i)
    {
        std::swap(nums[i], nums[0]);
        HeapHelp(nums, 0, i);
    }
}

TreeNode* AutumnMove::buildTree(vector<int>& preorder, vector<int>& inorder)
{
    if (preorder.size()!=inorder.size())
    {
        return nullptr;
    }
    if (preorder.empty())
    {
        return nullptr;
    }
    if (preorder.size()==1)
    {
        return new TreeNode(preorder.front());
    }
    TreeNode* root = new TreeNode(preorder.front());
    auto node = find(inorder.begin(), inorder.end(), root->val);
    int len = node - inorder.begin();
    vector<int> preLeft(preorder.begin() + 1, preorder.begin() + len+1);
    vector<int> preRight(preorder.begin() + len + 1, preorder.end());
    vector<int> inorLeft(inorder.begin(), node);
    vector<int> inorRight(node + 1, inorder.end());
    root->left = buildTree(preLeft, inorLeft);
    root->right = buildTree(preRight, inorRight);
    return root;
}

int dirSolve[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
void dfsSolve(vector<vector<char>>& board, int curX, int curY)
{
    if (board[curX][curY]!='O')
    {
        return;
    }
    board[curX][curY] = 'F';
    for (int i=0;i<4;++i)
    {
        int newX = curX + dirSolve[i][0];
        int newY = curY + dirSolve[i][1];
        if (newX>=0&&newX<board.size()&&newY>=0&&newY<board[0].size()&&board[newX][newY]=='O')
        {
            dfsSolve(board, newX, newY);
        }
    }
}

void AutumnMove::solve(vector<vector<char>>& board)
{
    if (board.empty())
    {
        return;
    }
    const int raw = board.size();
    const int col = board[0].size();
    for (int i=0;i< raw;++i)
    {
        if (board[i][0]=='O')
        {
            dfsSolve(board,i, 0);
        }
        if (board[i][col -1]=='O')
        {
            dfsSolve(board, i, col-1);
        }
    }
    for (int i=0;i<col;++i)
    {
        if (board[0][i] == 'O')
        {
            dfsSolve(board, 0, i);
        }
        if (board[raw - 1][i] == 'O')
        {
            dfsSolve(board, raw-1,i);
        }
    }
    for (auto &it:board)
    {
        for (auto &itsec:it)
        {
            if (itsec=='F')
            {
                itsec = 'O';
            }
            else if(itsec=='O')
            {
                itsec = 'X';
            }
        }
    }
}

bool dfsHasPathSum(TreeNode* root, int sum, const int& target)
{
    if (nullptr==root)
    {
        return false;
    }
    sum += root->val;
    if (nullptr==root->left&&nullptr==root->right)
    {
        if (target==sum)
        {
            return true;
        }
    }
    if (dfsHasPathSum(root->left,sum,target))
    {
        return true;
    }
    if (dfsHasPathSum(root->right,sum,target))
    {
        return true;
    }
    return false;
}

bool AutumnMove::hasPathSum(TreeNode* root, int sum)
{
    if (nullptr==root)
    {
        return false;
    }
    return dfsHasPathSum(root, 0, sum);
}

void dfsPathSumVec(TreeNode* root, const int& target, vector<int>& path, vector<vector<int>>& ret, int add)
{
    if (nullptr==root)
    {
        return;
    }
    add += root->val;
    path.emplace_back(root->val);
    if (nullptr==root->left&&nullptr==root->right)
    {
        if (target==add)
        {
            ret.emplace_back(path);
        }
        path.pop_back();
        return;
    }
    dfsPathSumVec(root->left, target, path, ret, add);
    dfsPathSumVec(root->right, target, path, ret, add);
    path.pop_back();
}

std::vector<std::vector<int>> AutumnMove::pathSum(TreeNode* root, int sum)
{
    if (nullptr==root)
    {
        return {};
    }
    vector<int> path;
    vector<vector<int>> ret;
    dfsPathSumVec(root, sum,path,ret, 0);
    return ret;
}

std::string AutumnMove::multiply(string num1, string num2)
{
    if (num1.empty()||num2.empty())
    {
        return "0";
    }
    vector<int> nums(num1.size() + num2.size() + 1);
    int index = 0;
    for (int i=num1.size()-1;i>=0;--i)
    {
        int curIndex = index++;
        for (int j= num2.size()-1;j>=0;--j)
        {
            nums[curIndex++] += (num1[i] - '0') * (num2[j] - '0');
        }
    }
    string ret(nums.size(),'0');
    int add = 0;
    for (int i=0;i<nums.size();++i)
    {
        int sum = nums[i] + add;
        add = sum / 10;
        ret[i] = sum % 10 + '0';
    }
    for (int j=ret.size()-1;j>=1;--j)
    {
        if (ret[j]=='0')
        {
            ret.pop_back();
        }
        else
        {
            break;
        }
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

std::vector<std::vector<int>> AutumnMove::merge(vector<vector<int>>& intervals)
{
    if (intervals.empty())
    {
        return {};
    }
    sort(intervals.begin(), intervals.end(), [](const vector<int>& leftVec, const vector<int>& rightVec)
        {
            if (leftVec.front()!=rightVec.front())
            {
                return leftVec.front() < rightVec.front();
            }
            return leftVec.back() < rightVec.back();
        });
    int left = intervals[0].front(), right = intervals[0].back();
    vector<vector<int>> ret;
    for (int i=1;i<intervals.size();++i)
    {
        if (right<intervals[i].front())
        {
            vector<int> temp = { left,right };
            ret.emplace_back(temp);
            left = intervals[i].front();
            right = intervals[i].back();
        }
        else
        {
            right = max(right, intervals[i].back());
        }
    }
    vector<int> temp = { left,right };
    ret.emplace_back(temp);
    return ret;
}

std::string AutumnMove::reverseWords(string s)
{
    if (s.empty())
    {
        return s;
    }
    reverse(s.begin(),s.end());
    int index = 0;
    string ret;
    while (index<s.size()&& s[index] == ' ')
    {
        ++index;
    }
    while (index<s.size())
    {
        int curIndex = index;
        while (curIndex<s.size()&&s[curIndex]!=' ')
        {
            ++curIndex;
        }
        for (int j=curIndex-1;j>=index;--j)
        {
            ret.push_back(s[j]);
        }
        if (curIndex!=index)
        {
            ret += " ";
        }
        index = curIndex + 1;
    }
    if (!ret.empty())
    {
        ret.pop_back();
    }
    return ret;
}

std::unordered_map<TreeNode*, int> depthMap;
int GetTreeDepth(TreeNode* root)
{
    if (nullptr==root)
    {
        return 0;
    }
    if (depthMap.count(root))
    {
        return depthMap[root];
    }
    int leftDepth = GetTreeDepth(root->left);
    int rightDepth = GetTreeDepth(root->right);
    depthMap[root] = 1 + max(leftDepth, rightDepth);
    return depthMap[root];
}

bool AutumnMove::isBalanced(TreeNode* root)
{
    if (nullptr==root)
    {
        return true;
    }
    if (abs(GetTreeDepth(root->left)-GetTreeDepth(root->right))>1)
    {
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}

