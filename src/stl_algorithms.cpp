#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <random>

template<typename T>
inline void printContainer(const T &cont, const std::string &name){
    
    std::cout << name << ": ";
    for(auto it: cont)
        std::cout << it << " ";
    
    std::cout << "\n";
}
int main(int argc, char **argv){

    //We will start plating by default with a container of numbers from o to 30
    int size = 30;

    if(argc >= 2){
        try
        {
            size = std::stoi(argv[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << "First argument should be a number" << '\n';
        }
    }

    std::vector<int> v1(size),v2;
    
    /*Instead of doing
    
    for(int i = 0; i < size; ++i)    
        v1.push_back(i);
    
    We can use std::iota :)
    */
    std::iota(v1.begin(), v1.end(), 0);

    std::sample(v1.begin(), v1.end(), std::back_inserter(v2), v1.size()/2, std::mt19937{std::random_device{}()});
    printContainer(v1, "Initial vector");
    printContainer(v2, "Half vector of random numbers");

    //Lets create a heap from this vector(A heap is a tree structure in which the parent is always bigger than his children)

    std::make_heap(v1.begin(), v1.end());
    printContainer(v1, "After applying make heap");
    
    return 0;
}