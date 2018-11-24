#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::exception;
using std::runtime_error;
using std::range_error;
using std::overflow_error;
using std::underflow_error;
using std::logic_error;
using std::domain_error;
using std::invalid_argument;
using std::length_error;
using std::out_of_range;
using std::bad_alloc;
//using std::bad_cast;

int main()
{

    cout<<"choose a exception to throw(0~10): "<<endl;
    unsigned num=0;
    while(cin>>num)
    {
        try
        {
            switch(num)
            {
                case 0:
                    throw exception();
                    break;
                case 1: 
                    throw runtime_error("information string runtime_error");
                    break;
                case 2:
                    throw range_error("information string range_error");
                    break;
                case 3: 
                    throw overflow_error("information string overflow_error");
                    break;
                case 4:
                    throw underflow_error("information string underflow_error");
                    break;
                case 5:
                    throw logic_error("information string logic_error");
                    break;
                case 6:
                    throw domain_error("information string domain_error");
                    break;
                case 7:
                    throw invalid_argument("information string invalid_argument");
                    break;
                case 8:
                    throw length_error("information string length_error");
                    break;
                case 9:
                    throw out_of_range("information string out_of_range");
                    break;
                case 10:
                    throw bad_alloc();
                    break;
                    //                case 11:
                    //                    throw bad_cast();
                    //                    break;
                default:
                    break;
            }
        }
        catch(range_error e)
        {
            cout<<e.what()<<endl;
        }
        catch(overflow_error e)
        {
            cout<<e.what()<<endl;
        }
        catch(underflow_error e)
        {
            cout<<e.what()<<endl;
        }
        catch(domain_error e)
        {
            cout<<e.what()<<endl;
        }
        catch(invalid_argument e)
        {
            cout<<e.what()<<endl;
        }
        catch(length_error e)
        {
            cout<<e.what()<<endl;
        }
        catch(out_of_range e)
        {
            cout<<e.what()<<endl;
        }
        catch(bad_alloc e)
        {
            cout<<e.what()<<endl;
        }
        //        catch(bad_cast e)
        //        {
        //            cout<<e.what()<<endl;
        //        }
        catch(runtime_error e)
        {
            cout<<e.what()<<endl;
        }
        catch(logic_error e)
        {
            cout<<e.what()<<endl;
        }
        catch(exception e)
        {
            cout<<e.what()<<endl;
        }

    }

    cin.clear();
    int a1=0,a2=0;
    cout<<"Enter two integers: ";

    while(cin>>a1>>a2)
    {
        try
        {
            if(a2==0)
            {
                throw runtime_error("Exception: Divided by 0");     //throw a divided by 0 excption
            }

            cout<<a1<<"/"<<a2<<"="<<a1/a2<<endl;                    //No exception, output result
            break;
        }
        catch(runtime_error e)
        {
            cout<<e.what()<<endl;
            cout<<"Try again?(Y/n): ";
            char confirm='n';
            cin>>confirm;
            if('Y'!=confirm&&'y'!=confirm)                          //Ask whether try again, if not, terminate
            {
                break;
            } 
            cout<<"Enter two integers: ";
        }
    }

    return 0; 
}
