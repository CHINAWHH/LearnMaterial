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
private:
	int expandAroundCenter(const string &s, int left, int right);
	
};

#endif 
