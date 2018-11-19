#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int val=1,sum=0;
    while(val<=10 && (sum+=val,++val))
    {}          //empty block, same as null statement ;

    cout<<"null statement & empty block: "<<sum<<endl;

    const vector<string> score{"F","D","C","B","A","A++"};
    cout<<"Enter a grade: ";
    unsigned grade=0;
    while(cin>>grade && grade<=100)
    {
        string letters;
        if(grade<60)
        {
            letters=score[0];
        }
        else
        {
            letters=score[grade/10-5];          //choose the letter

            if(grade%10>7)                      //choose the +/- tail
            {
                letters+="+";
            }
            else if(grade%10<3)
            {
                letters+="-";
            }
        }

        letters=grade<60?score[0]:score[grade/10-5];                            //choose the letter
        letters+=grade==100||grade<60?"":grade%10>7?"+":grade%10<3?"-":"";      //choose the +/- tail

        cout<<letters<<" ";
    }
    cout<<endl;

    unsigned a_c,e_c,i_c,o_c,u_c,vowel_c,blank_c,ff_c,fl_c,fi_c;
    a_c=e_c=i_c=o_c=u_c=vowel_c=blank_c=ff_c=fl_c=fi_c=0;

    cout<<"Enter a sentence: ";
    char ch=0;
    while(cin>>ch)
    {
        //        if('a'==ch)
        //            ++a_c;
        //        else if('e'==ch)
        //            ++e_c;
        //        else if('i'==ch)
        //            ++i_c;
        //        else if('o'==ch)
        //            ++o_c;
        //        else if('u'==ch)
        //            ++u_c;


        switch(ch)
        {
            case 'a': case 'A': ++a_c; break;
            case 'e': case 'E': ++e_c; break;
            case 'i': case 'I': ++i_c; break;
            case 'o': case 'O': ++o_c; break;
            case 'u': case 'U': ++u_c; break;

            case '\n': case '\t': case ' ': ++blank_c; break;

            default: break;
        }
    }

    cout<<endl<<"we have "<<a_c<<" letters of 'a'"<<endl
        <<"we have "<<e_c<<" letters of 'e'"<<endl
        <<"we have "<<i_c<<" letters of 'i'"<<endl
        <<"we have "<<o_c<<" letters of 'o'"<<endl
        <<"we have "<<u_c<<" letters of 'u'"<<endl
        <<"we have "<<blank_c<<" blanks"<<endl;

    //definition inside case
    switch(ch)
    {
        case 'a':
            int test1;              //Don't provide initializer if there are following cases/default
            test1=0;
            ++test1;
            break;
        case 'b':
            {
                int test2=10;       //Or define objects with initializer in a block
                ++test2;
            }
            break;
        default:
            int test3=100;          //The last case/default can define objects with initializer because it won't jump to any case/default
            ++test3;
            break;
    }

    return 0;
}
