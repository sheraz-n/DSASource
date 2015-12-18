#include <iostream>
#include <bitset>
using namespace std;

int main(){

cout<<"Let there be light :\n";

int n = sizeof(long);

cout<<"Size of long is :" <<n;

bitset<8> y(n);
cout<<"Size of long is :" <<y;
return 0;
}
