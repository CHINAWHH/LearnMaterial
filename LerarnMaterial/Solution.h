#ifndef SOLUTION_H
#define SOLUTION_H
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <stack>
#include <iostream>
#include <set>
#include <map>
#include <bitset>
#include "math.h"
#include <queue>
#include <memory>
#include <list>
#include <unordered_set>
#include "Common.h"
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();
	/******************************************************************************
	 �������ƣ� longestPalindrome
	 ����˵���� �ҵ���Ļ������ַ���,���м���2�߿��������㷨
	 ��    ���� string s 
	 �� �� ֵ�� std::string
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/10/26
	******************************************************************************/
	string longestPalindrome(string s);
	void DfsParent(vector<string> &istrVec,string istr,int l,int r);
	/******************************************************************************
	 �������ƣ� generateParenthesis
	 ����˵���� ���ɿ��ܵ�n�����ŵ���ȷ���
	 ��    ���� int n 
	 �� �� ֵ�� std::vector<std::string>
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/10/28
	******************************************************************************/
	vector<string> generateParenthesis(int n);
	/******************************************************************************
	 �������ƣ� swapPairs
	 ����˵���� ��������2�����ڵĽڵ�
	 ��    ���� ListNode * head 
	 �� �� ֵ�� ListNode*
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/10/28
	******************************************************************************/
	ListNode* swapPairs(ListNode* head);
	/******************************************************************************
	 �������ƣ� divide
	 ����˵���� ����2��������Ҫ��ʹ�ó˷�������mod���㣬���ؽ��
	 ��    ���� int dividend 
	 ��    ���� int divisor 
	 �� �� ֵ�� int
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/10/28
	******************************************************************************/
	int divide(int dividend, int divisor);
	/******************************************************************************
	 �������ƣ� nextPermutation
	 ����˵���� ������һ������ұ����������������û�а���������
	 ��    ���� vector<int> & nums 
	 �� �� ֵ�� void
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/10/30
	******************************************************************************/
	void nextPermutation(vector<int>& nums);
	/******************************************************************************
	 �������ƣ� search
	 ����˵���� ��һ��δ֪����ת�����������У��ҵ�ĳ��Ŀ��ֵ��Ҫlogn
	 ��    ���� vector<int> & nums 
	 ��    ���� int target 
	 �� �� ֵ�� int
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/10/30
	******************************************************************************/
	int search(vector<int>& nums, int target);
	/******************************************************************************
	 �������ƣ� searchRange
	 ����˵���� ��һ�������������ҵ����������Ϊtarget����
	 ��    ���� vector<int> & nums 
	 ��    ���� int target 
	 �� �� ֵ�� std::vector<int>
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/10/31
	******************************************************************************/
	vector<int> searchRange(vector<int>& nums, int target);
	/******************************************************************************
	 �������ƣ� isValidSudoku
	 ����˵���� �ж��Ƿ���һ����Ч������������ÿһ�к�ÿһ��1-9ֻ�ܳ���һ��,��3*3�ķ�����Ҳֻ�ܳ���һ��
	 ��    ���� vector<vector<char>> & board 
	 �� �� ֵ�� bool
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/10/31
	******************************************************************************/
	bool isValidSudoku(vector<vector<char>>& board);
	void DFSSum(int start, int target);
	/******************************************************************************
	 �������ƣ� combinationSum
	 ����˵���� ����һ�����ظ������Ŀ��ֵ��ʹ�������е�ֵҪ����target�������е�ֵ��������ѡ��,���û����㷨
	 ��    ���� vector<int> & candidates 
	 ��    ���� int target 
	 �� �� ֵ�� std::vector<std::vector<int>>
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/10/31
	******************************************************************************/
	vector<vector<int>> combinationSum(vector<int>& candidates, int target);
	void DFSSum2(int start, int target);
	/******************************************************************************
	 �������ƣ� combinationSum2
	 ����˵���� ����һ�������Ŀ��ֵ��ʹ�������е�ֵҪ����target�������е�ֵֻ��ʹ��һ��,Ԫ�����ظ�
	 ��    ���� vector<int> & candidates 
	 ��    ���� int target 
	 �� �� ֵ�� std::vector<std::vector<int>>
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/11/01
	******************************************************************************/
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
	/******************************************************************************
	 �������ƣ� multiply
	 ����˵���� ������ˣ������ַ����ĳ˻�
	 ��    ���� string num1 
	 ��    ���� string num2 
	 �� �� ֵ�� std::string
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/11/01
	******************************************************************************/
	string multiply(string num1, string num2);
	void DFSpermute(vector<int> path, int i,unordered_map<int,bool> &hashM);
	/******************************************************************************
	 �������ƣ� permute
	 ����˵���� ���ظ����ֵ���������ȫ����
	 ��    ���� vector<int> & nums 
	 �� �� ֵ�� std::vector<std::vector<int>>
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/11/02
	******************************************************************************/
	vector<vector<int>> permute(vector<int>& nums);
	void DFSpermuteUnique(vector<int> path, int i, vector<pair<int, int>> &iInt);
	/******************************************************************************
	 �������ƣ� permuteUnique
	 ����˵���� ���ظ���������ȫ���У����в����ظ�
	 ��    ���� vector<int> & nums 
	 �� �� ֵ�� std::vector<std::vector<int>>
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/11/02
	******************************************************************************/
	vector<vector<int>> permuteUnique(vector<int>& nums);
	/******************************************************************************
	 �������ƣ� Select
	 ����˵���� Ѱ�ҵ�kС��Ԫ��
	 ��    ���� T a[] 
	 ��    ���� int n 
	 ��    ���� int k 
	 �� �� ֵ�� T
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/11/01
	******************************************************************************/
	template<typename T>
	T Select(T a[], int n, int k);
	/******************************************************************************
	 �������ƣ� rotate
	 ����˵���� һ��n*n�ľ���˳ʱ����ת90��
	 ��    ���� vector<vector<int>> & matrix 
	 �� �� ֵ�� void
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/11/02
	******************************************************************************/
	void rotate(vector<vector<int>>& matrix);
	/******************************************************************************
	 �������ƣ� groupAnagrams
	 ����˵���� ����ĸ��λ�ʷ���һ����ĸ�����ͬ��λ�ò�ͬ
	 ��    ���� vector<string> & strs 
	 �� �� ֵ�� std::vector<std::vector<std::string>>
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/11/02
	******************************************************************************/
	vector<vector<string>> groupAnagrams(vector<string>& strs);
	/******************************************************************************
	 �������ƣ� myPow
	 ����˵���� ����X���ݼ���
	 ��    ���� double x 
	 ��    ���� int n 
	 �� �� ֵ�� double
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/11/02
	******************************************************************************/
	double myPow(double x, int n);
	/******************************************************************************
	 �������ƣ� spiralOrder
	 ����˵���� �������������ֵ
	 ��    ���� vector<vector<int>> & matrix 
	 �� �� ֵ�� std::vector<int>
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/11/02
	******************************************************************************/
	vector<int> spiralOrder(vector<vector<int>>& matrix);
	/******************************************************************************
	 �������ƣ� canJump
	 ����˵���� �ж��ܷ��������һ��
	 ��    ���� vector<int> & nums 
	 �� �� ֵ�� bool
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/11/04
	******************************************************************************/
	bool canJump(vector<int>& nums);
	/******************************************************************************
	 �������ƣ� merge
	 ����˵���� �ϲ����ص�������
	 ��    ���� vector<vector<int>> & intervals 
	 �� �� ֵ�� std::vector<std::vector<int>>
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/11/04
	******************************************************************************/
	vector<vector<int>> merge(vector<vector<int>>& intervals);
	/******************************************************************************
	 �������ƣ� generateMatrix
	 ����˵���� ����һ��������������һ������1��n2������Ԫ�أ�����˳ʱ��������������
	 ��    ���� int n 
	 �� �� ֵ�� std::vector<std::vector<int>>
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/11/04
	******************************************************************************/
	vector<vector<int>> generateMatrix(int n);
	/******************************************************************************
	 �������ƣ� getPermutation
	 ����˵���� ����Ԫ�ص��������У��ҵ��Ӵ�С�ŵĵ�k��
	 ��    ���� int n 
	 ��    ���� int k 
	 �� �� ֵ�� std::string
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/11/04
	******************************************************************************/
	string getPermutation(int n, int k);
	/******************************************************************************
	 �������ƣ� rotateRight
	 ����˵���� ��ת����
	 ��    ���� ListNode * head 
	 ��    ���� int k 
	 �� �� ֵ�� ListNode*
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/11/05
	******************************************************************************/
	ListNode* rotateRight(ListNode* head, int k);
	/******************************************************************************
	 �������ƣ� uniquePaths
	 ����˵���� �жϻ������ߵ�·��,������ֻ�����һ���������һ��
	 ��    ���� int m 
	 ��    ���� int n 
	 �� �� ֵ�� int
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/11/05
	******************************************************************************/
	int uniquePaths(int m, int n);
	/******************************************************************************
	 �������ƣ� minPathSum
	 ����˵���� �ҵ���С·����
	 ��    ���� vector<vector<int>> & grid 
	 �� �� ֵ�� int
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/11/05
	******************************************************************************/
	int minPathSum(vector<vector<int>>& grid);
	/******************************************************************************
	 �������ƣ� simplifyPath
	 ����˵���� ��ȡ�򻯺��·������UNIX�µķ��
	 ��    ���� string path 
	 �� �� ֵ�� std::string
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/11/06
	******************************************************************************/
	string simplifyPath(string path);
	/******************************************************************************
	 �������ƣ� setZeroes
	 ����˵���� ������0�������һ��0�����ڵ��к��ж�Ϊ0
	 ��    ���� vector<vector<int>> & matrix 
	 �� �� ֵ�� void
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/11/06
	******************************************************************************/
	void setZeroes(vector<vector<int>>& matrix);
private:
	int expandAroundCenter(const string &s, int left, int right);
	template<typename T>
	T Select(T a[], int leftEnd, int rightEnd, int k);
};

template<typename T>
T Solution::Select(T a[], int n, int k)
{
	if (k<1||k>n)
	{
		return T[0];
	}
	int maxPos = 0;
	for (int i = 1; i < n;++i)
	{
		if (a[i]>a[maxPos])
		{
			maxPos = i;
		}
	}
	swap(a[n - 1], a[maxPos]);
	return Select(a, 0, n - 1, k);
}

template<typename T>
T Solution::Select(T a[], int leftEnd, int rightEnd, int k)
{
	if (leftEnd>=rightEnd)
	{
		return a[leftEnd];
	}
	int leftCur = leftEnd;
	int rightCur = rightEnd + 1;
	T privot = a[leftEnd];
	while (true)
	{
		do 
		{
			++leftCur;
		} while (a[leftCur]<privot);
		do 
		{
			--rightCur;
		} while (a[rightCur]>privot);
		if (leftCur>=rightCur)
		{
			break;
		}
		swap(a[leftCur], a[rightCur]);
	}
	if (rightCur-leftEnd+1==k)
	{
		return privot;
	}
	a[leftEnd] = a[rightCur];
	a[rightCur] = privot;
	if (rightCur-leftEnd+1<k)
	{
		return Select(a, rightCur + 1, rightEnd, k - rightEnd + leftEnd -1);
	}
	return Select(a,leftEnd,rightCur-1,k);
}

#endif 
