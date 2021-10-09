#include <iostream>

using namespace std;

class credit
{
public:
	string card_no;
	void type();
	void isValid();
};

void credit::type()
{
	if ((card_no.length() == 15) && (card_no[0] == '3') && (card_no[1] == '4' || '7'))
	{
		cout << "You are trying to validate American Express Card."
			 << "\n";
	}
	else if ((card_no.length() == 16) && (card_no[0] == '5') && (card_no[1] == '1' || '2' || '3' || '4' || '5'))
	{
		cout << "You are trying to validate Master Card"
			 << "\n";
	}
	else if ((card_no[0] == '4') && (card_no.length() == 13 || 16))
	{
		cout << "You are trying to evaluate Visa Cards"
			 << "\n";
	}

	else
	{
		cout << "Card Type Unknown!" << endl;
	}
}

void credit::isValid()
{
	int len = card_no.length();
	int TotalSum = 0;
	int SumOdd = 0, SumEven = 0;

	//double the even placed digits from the end and adding all.If it results in two digit number ,add the digits
	for (int i = len - 2; i >= 0; i = i - 2)
	{
		int twice = (((card_no[i]) - 48) * 2); //converting string array to integer array
		if (twice > 9)
		{
			twice = (twice / 10) + (twice % 10);
		}
		SumEven = SumEven + twice;
	}

	//adding all the odd digits number from the end
	for (int i = len - 1; i >= 0; i = i - 2)
	{
		SumOdd = SumOdd + (((card_no[i]) - 48));
	}

	TotalSum = SumEven + SumOdd;

	//checking if total sum of odd and even placed digits is a multiple of 10.
	//if yes,the number is valid.
	if (TotalSum % 10 == 0)
	{
		cout << "Entered Card Number " << card_no << " is valid" << endl;
	}
	else
	{
		cout << "Entered Card Number " << card_no << " is invalid" << endl;
	}
}

int main()
{

	credit ob1;
	int i = 0, ans;
	cout << "****************CREDIT CARD NUMBER VALIDATOR******************" << endl
		 << endl
		 << endl;
	cout << "**************************LUHN'S ALGORITHM************************" << endl
		 << endl;
	do
	{

		cout << "Enter the credit card number you want to check:";
		cin >> ob1.card_no;
		cout << "\n"
			 << "Your entered number is :" << ob1.card_no << "\n";
		ob1.type();
		ob1.isValid();
		cout << "do you want to continue?(1 for yes 2 for no)" << endl;
		cin >> ans;
		switch (ans)
		{
		case 1:
			cout << endl;
			break;
		case 2:
			i++;
		}

	} while (i == 0);

	return 0;
}
