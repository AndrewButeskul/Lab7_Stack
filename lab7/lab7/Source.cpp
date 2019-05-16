#include <string>
#include <map>
#include <stack>
#include<iostream>

using namespace std;

int main()
{
	string str;
	cout << "Enter string:" << "\n";
	cin >> str;
	map<char, char> mp{ { '(', ')' }, { '[', ']' }, { '{', '}'} };
	stack<char> stk;
	int i = 0;
	for (i = 0; i < str.size(); ++i)
	{
		if ('(' == str[i] || '[' == str[i] || '{' == str[i])
		{
			stk.push(str[i]);
		}
		else if (!stk.empty())
		{
			char c = stk.top();
			stk.pop();
			if (mp[c] != str[i])
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
	cout << (i == str.size() && stk.empty() ? "Right" : "Wrong") << "\n";

	system("pause");
	return 0;
}