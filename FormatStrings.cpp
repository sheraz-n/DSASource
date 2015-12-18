#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
cout<<"Vulnerability 1:  100%dave"<<endl;
printf("100% dave");
cout<<endl;
cout<<endl;
cout<<"Vulnerability 2:  %s"<<endl;
char buff[] = "%d %d %x Let the buffer overflow";
printf(buff);

//printf("%s%s",buff);
cout<<endl;
cout<<endl;
cout<<"Vulnerability 3:  Cascaded %d"<<endl;
printf("%d %d %d %d %d  ");
cout<<endl;
cout<<endl;
cout<<"Vulnerability 4:  Cascaded %08x"<<endl;
printf("%08x %08x %08x %08x %08x  ");
cout<<endl;
cout<<endl;
return 0;
}
