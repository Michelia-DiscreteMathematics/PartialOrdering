#include "Poset.h"
using namespace std;

int main()
{
    Poset set;
    set.get_number();
    set.get_factor();
    set.get_cover();
    set.print_factor();
    set.print_cover();
    set.get_complement();
    return 0;
}