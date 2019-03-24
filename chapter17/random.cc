#include <iostream>
#include <random>

using std::cout;
using std::endl;
using std::default_random_engine;
using std::uniform_int_distribution;

unsigned get_random_unsigned(long seed,long min=1,long max=100)
{
    //random engine and distribution must be static
    //in order to get a different number at each call
    static default_random_engine e(seed);
    static uniform_int_distribution<unsigned> u(min,max);

    return u(e);
}

int main(int argc,char **argv)
{
    default_random_engine e;
    cout<<"rand()'s range: [0,"<<RAND_MAX<<"]"<<endl; 
    cout<<"default_random_engine's range: ["
        <<e.min()<<","<<e.max()<<"]"<<endl;

    for(size_t i=0;i!=10;++i)
        cout<<get_random_unsigned(time(0),1,100)<<" ";

}
