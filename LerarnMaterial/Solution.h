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
	/******************************************************************************
	 �������ƣ� combinationSum
	 ����˵���� ����һ�������Ŀ��ֵ��ʹ�������е�ֵҪ����target�������е�ֵ��������ѡ��
	 ��    ���� vector<int> & candidates 
	 ��    ���� int target 
	 �� �� ֵ�� std::vector<std::vector<int>>
	 ��    �ߣ� Ru Long
	 ��    �ڣ� 2019/10/31
	******************************************************************************/
	vector<vector<int>> combinationSum(vector<int>& candidates, int target);
private:
	int expandAroundCenter(const string &s, int left, int right);
	
};

#endif 
