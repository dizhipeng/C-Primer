#include "Other_test.h"
#include <vector>
#include <cstdlib>

using std::vector;

int main()
{
    //NoDefault can't be default initialized
    //It must has an initial value
    vector<NoDefault> v1(10,0);

    //object of C can be default initialized
    vector<C> v2(10);

    return EXIT_SUCCESS;
}
