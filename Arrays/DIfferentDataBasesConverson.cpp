#include<iostream>
#include<bitset>
using namespace std;
void Binary(int a)
{
  if(a==0)
  {
    return;
  }
  Binary(a/2);
  cout<<a%2;
    
}
int main()
{
    int a=19;
    // cout<<"HEX = "<<hex<<a<<endl;
    // cout<<"DEC = "<<dec<<a<<endl;
    // cout<<"OCT = "<<oct<<a<<endl;
    // cout<<"BIN = "<<bitset<4>(a)<<endl;
    Binary(a);
    return 0;
}