class Solution {
public:
    
    string intToRoman2(int num) {
    String M[] = {"", "M", "MM", "MMM"};
    String C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    String X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    String I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }

    string intToRoman(int num) {
        int length  = log10(num) +1 ;
        string output="";
        //cout << length <<endl;
        int tmp = num;
        if(length > 0)
        {
            for(int i = length ; i > 0 ; i --)
            {
                int power = pow(10,i -1) ;
                int digit = tmp / power;
               // cout <<"digit = " <<digit <<endl;
               
                if((digit >= 1 && digit < 4 ) )
                {
                    for(int  j = 0 ; j < digit ; j ++)
                    {
                        switch(i)
                        {
                            case 4:
                                 output += 'M';
                                break;
                            case 3:
                                 output += 'C';
                                break;
                            case 2:
                                 output += 'X';
                                break;
                            case 1:
                                 output += 'I';
                                break;
                        }
                       
                    }
                }
                if(digit > 5 && digit < 9 )
                {
                    switch(i)
                    {
                        case 3:
                             output += 'D';
                            break;
                        case 2:
                             output += 'L';
                            break;
                        case 1:
                             output += 'V';
                            break;
                    }
                    int reminder = digit - 5;
                    for(int  j = 0 ; j < reminder ; j ++)
                    {
                        switch(i)
                        {
                            case 4:
                                 output += 'M';
                                break;
                            case 3:
                                 output += 'C';
                                break;
                            case 2:
                                 output += 'X';
                                break;
                            case 1:
                                 output += 'I';
                                break;
                        }
                       
                    }
                    
                }
                if(digit == 4)
                {
                    switch(i)
                    {
                        case 3:
                             output += "CD";
                            break;
                        case 2:
                             output += "XL";
                            break;
                        case 1:
                             output += "IV";
                            break;
                    }
                }
                if(digit == 5)
                {
                    switch(i)
                    {
                        case 3:
                             output += 'D';
                            break;
                        case 2:
                             output += 'L';
                            break;
                        case 1:
                             output += 'V';
                            break;
                    }
                }
                if(digit == 9)
                {
                    switch(i)
                    {
                        case 3:
                             output += "CM";
                            break;
                        case 2:
                             output += "XC";
                            break;
                        case 1:
                             output += "IX";
                            break;
                    }
                }
                       
                
                tmp = tmp % power;
                //cout << "tmp = " << tmp <<endl;
            }
        }
        
        return output;

        
    }
};
