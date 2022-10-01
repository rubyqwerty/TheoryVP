
#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
	string a;
	vector<pair<string, string>>p = { {"bAI" , "I"}, {"dAI" , "I"}, {"bA" , "I"},{"dA" , "I"}, {"+" , "A"}, {"-" , "A"} };
	vector<int> answerRules;
	vector<string> printLine;

	cin >> a;
	string copyA = a;
	regex rules("([b|d][+|-]){" + to_string(a.length() / 2) + "}");

	if (regex_match(a, rules))
	{
		cout << "Line correct\n";
		
		while (a != "I")
		{
			int max=-1;
			int index = -1;
			for (int i = 0; i < p.size(); ++i)
			{
				int h = a.rfind(p[i].first);
				if (h > max)
				{
					max = h;
					index = i;
				}
			}
			a.replace(max, p[index].first.size(), p[index].second);
			printLine.insert(printLine.begin(), a);
			answerRules.insert(answerRules.begin(), index + 1);
		}
		cout << endl;
		for (int i = 0; i < printLine.size(); ++i) cout << printLine[i] << " -"<< answerRules[i] <<"-> ";
		cout << copyA;
		printf(R"(

1. I -> bAI
2. I -> dAI
3. I -> bA
4. I -> dA
5. A -> +
6. A -> - 
			)");
	}
	else cout << "Line not correct";

}