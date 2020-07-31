#include <iostream>
#include <vector>
#include <string>

using namespace std;

//��������ַ����շ��Ž��зָ�
void SplitStringBySymbol(const string& iStr, const string& symbol, vector<string>& ioVecStr)
{
    if (iStr.empty())
    {
        return;
    }
    size_t iFindIndex = iStr.find(symbol, 0);
    if (iFindIndex == string::npos)
    {
        ioVecStr.emplace_back(iStr);
        return;
    }
    if (iFindIndex==0)
    {
        return;
    }
    ioVecStr.emplace_back(iStr.substr(0, iFindIndex));
    return SplitStringBySymbol(iStr.substr(iFindIndex + 1), symbol, ioVecStr);
}

//https://ac.nowcoder.com/acm/contest/320#question

//�����������������a, b(1 <= a, b <= 10 ^ 9), �������ݰ������顣
// int a, b;
//while (cin>>a>>b)
//{
//    cout << a + b;
//}

//�����һ�а���һ����������t(1 <= t <= 100)
//������ÿ�а�������������a, b(1 <= a, b <= 10 ^ 9)
//int length = 0;
//cin >> length;
//for (int i = 0; i < length; ++i)
//{
//    int a, b;
//    cin >> a >> b;
//    cout << a + b << "\n";
//}

//�����������������a, b(1 <= a, b <= 10 ^ 9), ���������ж���, �������Ϊ0 0���������
//while (true)
//{
//    int a, b;
//    cin >> a >> b;
//    if (a == 0 && b == 0)
//    {
//        break;
//    }
//    cout << a + b << "\n";
//}

//�������ݰ������顣
//ÿ������һ��, ÿ�еĵ�һ������Ϊ�����ĸ���n(1 <= n <= 100), nΪ0��ʱ��������롣
//������n��������, ����Ҫ��͵�ÿ����������
//while (true)
//{
//    int length;
//    cin >> length;
//    if (length == 0)
//    {
//        break;
//    }
//    int b = 0, sum = 0;
//    for (int i = 0; i < length; ++i)
//    {
//        cin >> b;
//        sum += b;
//    }
//    cout << sum << "\n";
//}


//����ĵ�һ�а���һ��������t(1 <= t <= 100), ��ʾ����������
//������t��, ÿ��һ�����ݡ�
//ÿ�еĵ�һ������Ϊ�����ĸ���n(1 <= n <= 100)��
//������n��������, ����Ҫ��͵�ÿ����������
//int tLine = 0;
//cin >> tLine;
//for (int i = 0; i < tLine; ++i)
//{
//    int n = 0;
//    cin >> n;
//    int sum = 0, b = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> b;
//        sum += b;
//    }
//    cout << sum << "\n";
//}

//���������ж���, ÿ�б�ʾһ���������ݡ�
//ÿ�еĵ�һ������Ϊ�����ĸ���n(1 <= n <= 100)��
//������n��������, ����Ҫ��͵�ÿ����������
//int n = 0;
//while (cin >> n)
//{
//    int sum = 0, b = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> b;
//        sum += b;
//    }
//    cout << sum << "\n";
//}

//���������ж���, ÿ�б�ʾһ���������ݡ�
//ÿ�в�����n���������ո������(1 <= n <= 100)��
//int sum = 0;
//int nu = 0;
//while (cin >> nu)
//{
//    sum += nu;
//    if (getchar() == '\n')
//    {
//        cout << sum << "\n";
//        sum = 0;
//    }
//}

//���������У���һ��n
//�ڶ�����n���ո�������ַ���
//int line = 0;
//cin >> line;
//string str;
//vector<string> vecOu;
//for (int i = 0; i < line; ++i)
//{
//    cin >> str;
//    vecOu.push_back(str);
//}

//�������������ÿ����������һ�С�
//ÿ��ͨ���ո��������n���ַ���n��100
//string str;
//vector<string> vecOu;
//while (cin >> str)
//{
//    vecOu.emplace_back(str);
//    if (getchar() == '\n')
//    {
//        sort(vecOu.begin(), vecOu.end());
//        for (auto& it : vecOu)
//        {
//            cout << it << " ";
//        }
//        cout << "\n";
//        vecOu.clear();
//        continue;
//    }
//}

//�������������ÿ����������һ�С�
//ÿ��ͨ��','��������n���ַ���n��100   a, c, bb
//string str;
//while (cin >> str)
//{
//    if (getchar() == '\n')
//    {
//        vector<string> vecOu;
//        SplitStringBySymbol(str, ",", vecOu);
//        cout << vecOu.back();
//        cout << "\n";
//    }
//}