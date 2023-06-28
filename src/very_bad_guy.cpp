#include <cstdint>
#include <cstdlib>

void f()
{
    char arr[5];

    arr[10] = 0; // This should be detected
}

void g() // This is not called from the main intentionally, to see if the analyzer also detects it
{
    char another[23];

    another[24] = 1;
}

int main(int argc, char** argv){

    f();

    int* blabla = new int; // We will omit the delete

    char* bloblo;

    char deref = *bloblo; // nullptr derefencing!!

    return 0;
}