#include <string>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

 int myAtoi(string str) {
        bool negativeNum = false;
        bool firstIntegralDigit = false;
        bool sign = false;
        int output = 0;
        int digit = 0;
        unordered_set<int> numberDigits;
        for(int i = 0 ; i < str.length() ; i ++)
        {
            char strChar = str[i];
            if(strChar == '-' || strChar == '+')
            {
                if(strChar == '+' && !sign && !firstIntegralDigit)
                {
                    sign = true;
                    continue;
                }
                else if (strChar == '-' && !sign && !firstIntegralDigit)
                {
                    negativeNum = true;
                    sign = true;
                }
                else
                    break;
                    
            }
            else if(strChar == ' ' )
            {
                if(firstIntegralDigit || sign)
                    break;
                else
                    continue;
            }
            else if(!isdigit(str[i]) && !firstIntegralDigit)
            {
                return 0;
            }
            else if(!isdigit(str[i]) && firstIntegralDigit)
            {
                break;;
            }
            else if(isdigit(str[i]))
            {
                firstIntegralDigit = true;
                digit =  str[i]- '0';
                if(output  <= (INT_MAX - digit) / 10)
                {
                    output *= 10;
                    
                    output += digit;
                }
                else
                {
                    if(negativeNum)
                        return INT_MIN;
                    else
                        return INT_MAX ;
                }
               
            }
        }
        
        
        if(negativeNum)
            return (-1)  * output;
        else
            return output;
        
    }

int myAtoi2(string str) {
	//remove_if(str.begin(), str.end(), isspace);
	enum SIGN { POSITIVE, NEGATIVE, NOSIGN };
	SIGN numberSign = NOSIGN;
	int length = str.length();
	const char * strArr = str.c_str();
	int intNumber = 0;
	double count = 0;
	bool whiteSpace = false;
	//bool positiveNum = true;
	for (int i = length - 1; i >= 0; i--)
	{	
		if (strArr[i] != '-' && strArr[i] != '+' && !isspace(strArr[i]))
		{
			if (isdigit(strArr[i]))
			{
			    int digit = strArr[i] - '0';
				intNumber += digit * pow(10, count);
				count++;
			}
			else
			{
				intNumber = 0;
				count = 0;
			}
		}
		else if(strArr[i] == '-')
		{
			if (numberSign == NEGATIVE || numberSign == POSITIVE)
				return 0;
			else if (numberSign == NOSIGN)
			{
				numberSign = NEGATIVE;
				intNumber *= -1;
			}
			if (numberSign == NEGATIVE && i == 0)
				return intNumber;
			else if (numberSign == POSITIVE)
				return 0;
			else if (i > 0 && (strArr[i - 1] == ' '))
				continue;
			else if (i > 0 && isdigit(strArr[i - 1]))
			{
				intNumber = 0;
				count = 0;
				numberSign = NOSIGN;
			}
			
		}
		else if (strArr[i] == '+')
		{
			if (numberSign == NEGATIVE || numberSign == POSITIVE)
				return 0;
			else if (numberSign == NOSIGN)
				numberSign = POSITIVE;
			if (numberSign == POSITIVE && i == 0)
				if ((numberSign == POSITIVE || numberSign == NOSIGN) && intNumber < 0)
					return (intNumber + 1) * -1;
				else
					return intNumber;
			else if (i > 0 && (strArr[i - 1] == ' '))
				continue;
			else if (i > 0 && isdigit(strArr[i - 1]))
			{
				intNumber = 0;
				count = 0;
				numberSign = NOSIGN;
			}

		}
		else if (strArr[i] == ' ')
		{
			if (i == 0)
				break;
			if (i > 0 && strArr[i - 1] == ' ')
				continue;
			else
			{
				intNumber = 0;
				count = 0;
				numberSign = NOSIGN;
			}
		}
	}

	if ((numberSign == POSITIVE || numberSign == NOSIGN) && intNumber < 0)
		return (intNumber + 1) * -1;
	return intNumber;
}


/*void main()
{
	cout << myAtoi("+11586828692") << endl;
	cout << myAtoi("    +11191657170") << endl;
	cout << myAtoi("-2") << endl;
	cout << myAtoi("-+2") << endl;
	cout << myAtoi("++2") << endl;
	cout << myAtoi("--2") << endl;
	cout << myAtoi("-524+00134") << endl;
	cout << myAtoi("  +00134") << endl;
	cout << myAtoi("  -00134") << endl;
	cout << myAtoi("12345678910") << endl;
	cout << myAtoi("-12345678910") << endl;
	cout << myAtoi("123  910") << endl;
	
	

}*/
