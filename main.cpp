#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <map>
#include <numeric>

using std::cout;
using std::cin;
using std::endl;


/*Створити клас "Банківський рахунок" з полями: номер рахунку, баланс, дата відкриття.
* 
Реалізувати методи для отримання та зміни цих полів, 

а також методи для внесення та зняття грошей з рахунку. 

Створити масив об'єктів цього класу та знайти рахунки з найбільшим та найменшим балансом.*/


class KVFinder
{
private:
	std::map<std::string, int> user;
	std::string KEY; int VALUE{};

public:
	
	void InputData()
	{

		do
		{
			cout << "\nEnter key: "; cin >> KEY;
			cout << "Enter value: "; cin >> VALUE;
			user.insert({ KEY,VALUE });
		} while (user.size() != 3);

		cout << endl;
		for (const auto& x : user)
		{
			cout << x.first << " = " << x.second << endl;
		}
	}
	void FindKey()
	{
		std::string findKey;
		cout << "\nEnter for finding key: "; cin >> findKey;
		auto ITk = user.find(findKey);

		if (ITk != user.end())
		{
			cout << "\nKey has found.\n" << ITk->first;
		}
		else
		{
			cout << "\nKey " << findKey << " not found.\n";
		}
	}
	void FindValue()
	{
		int findValue{};
		bool found{ false };

		cout << "\nEnter for finding value: "; cin >> findValue;

		for (auto& ITv : user)
		{
			if (ITv.second == findValue)
			{
				cout << "\nValue has found: " << ITv.second << " [ " << ITv.first << " ]";
				found = true;
				break;
			}
			else
			{
				cout << "\nValue " << findValue << " not found.\n";
			}
		}
	}
};

int main()
{
	KVFinder lookfor;
	lookfor.InputData();
	lookfor.FindValue();
	
	cout << "\n\n"; return 0;
}
