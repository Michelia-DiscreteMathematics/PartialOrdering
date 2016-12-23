#ifndef _POSET_H
#define _POSET_H

#include <iostream>
#include <string>
#include <vector>

class Poset
{
private:
    int integer;
    std::vector<int> factor;
    std::vector<std::vector<int> > relation;
    
public:
    void get_number();
    void get_factor();
    void get_cover();
    void print_factor();
    void print_cover();
    int euclid(int a,int b);
    int get_lcm(int a,int b,int g);
    void get_complement();
};

#endif