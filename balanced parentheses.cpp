#include "pch.h"
#include <iostream>
#include <stack>
#include <string>
#include <queue>
using namespace std;

bool isBalanced(string Parentheses)
{
	stack <char> openParentheses; 
	queue <char> closedParentheses; 

	for (int i = 0; i < Parentheses.length(); i++)
	{
		if (Parentheses[i] == '[' || Parentheses[i] == '{' || Parentheses[i] == '(')
		{
			openParentheses.push(Parentheses[i]);
		}
		if (openParentheses.empty())
			return false;

		if (Parentheses[i] == ']' || Parentheses[i] == '}' || Parentheses[i] == ')')
		{
			closedParentheses.push(Parentheses[i]);
		}
		if (closedParentheses.size() > 0)
		{
			if ((openParentheses.top() == '{' && closedParentheses.front() == '}')
				|| (openParentheses.top() == '(' && closedParentheses.front() == ')')
				|| (openParentheses.top() == '[' && closedParentheses.front() == ']'))
			{
				openParentheses.pop();
				closedParentheses.pop();
			}

			else
			{
				return false;
				break;
			}
		}
	}
	int stackSize = openParentheses.size();
	int queueSize = closedParentheses.size();
	if (stackSize != queueSize)
		return false;
}

void main()
{
	string parentheses = ")[({)}{}]";
	bool flag = isBalanced(parentheses);
	if (flag)
		cout << parentheses << " is balanced\n";
	else
		cout << parentheses << " is not balanced\n";
}

