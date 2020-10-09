#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using ivec = std::vector<int>;

ivec GenerateRandVec(int numOfNums, int min, int max);

void printValues(const ivec &vector);

int main(int argc, char **argv){

    auto vecValues = GenerateRandVec(10,1,50);

    printValues(vecValues);

    std::sort(vecValues.begin(), vecValues.end(),
                [](int x, int y){ return x < y; } );

    printValues(vecValues);

    ivec evenVecValues;

    std::copy_if(vecValues.begin(), vecValues.end(), 
                std::back_inserter(evenVecValues),
                [](int x){ return (x % 2 == 0 ); } );


    printValues(evenVecValues);
    
    int sum = 0;
    std::for_each(vecValues.begin(), vecValues.end(), 
            [&](int x){ sum += x; } );
    std::cout << "Sum " << sum << std::endl;
    
    ivec doubleVec;

    std::for_each(vecValues.begin(), vecValues.end(), 
            [&](int x){ doubleVec.push_back(x * 2); } );

    printValues(doubleVec);

    ivec vec1 = {1,2,3,4,5};
    ivec vec2 = {1,2,3,4,5};
    ivec vec3(5);

    std::transform(vec1.begin(), vec1.end(),
            vec2.begin(), vec3.begin(), 
            [](int x, int y){ return x * y;} );
    
    printValues(vec3);

    // printValues(doubleVec);

    int age = 43;

    bool canIVote = (age >= 18) ? true : false;

    std::cout<<" Can derek vote: " << std::boolalpha << canIVote << std::endl;

    //Recursive lambda function
    std::function<int(int)>  Fib = 
    [&Fib](int n){ return n < 2 ? n : Fib(n-1) + Fib(n -2 ); };

    for(int i = 0; i < 100; ++i)
        std::cout << "Fib " << i << ": " << Fib(i) << std::endl;
    
    return 0;
}
void printValues(const ivec &vector){

    for(auto val: vector)   
        std::cout << val << std::endl;

    std::cout << "\n";
}

ivec GenerateRandVec(int numOfNums, int min, int max){

    ivec vecValues;
    srand(time(NULL));
    int i = 0, randVal = 0;
    
    while(i < numOfNums){
        randVal = min + std::rand() % ((max+1) - min);
        vecValues.push_back(randVal);
        ++i;
    }
    return vecValues;
}
