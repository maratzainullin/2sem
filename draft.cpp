#include <iostream>





/*int f1(int a, int b){
    int c = a + b;
    return c;
};


int f2(int a, int b){
    int c = a*b;
    return c;
};


int f3(int a, int b){
    int c = a - b;
    return c;
};


int f4(int a, int b){
    int c =

};


int super_f(){



};
*/
using namespace std;
int xx (char *s, int a)
{
    cout <<"xx-args: "<<s<<", "<<a<<'\n';
    return a+a;
}

int yy (char *s, int a)
{
    cout <<"yy-args: "<<s<<", "<<a<<'\n';
    return a*a;
}

int call (char *s, int a, int (*f)(char *, int))
{
    cout <<"call "<<s<<" "<<a<<" f() = "<<f(s,a)<<'\n';
}



int main ()
{
    cout << 10/5 <<" "<<5/5;
}








