/*新C++言語入門、林晴比古著、Chapter1.9*/
/*定数*/

#include <iostream>
using namespace std;

int suuti()
{
    int i8, i10, i16;
    double ff, fe;

    i8=0123;
    i10=123;
    i16=0x123;
    ff=1.23;
    fe=1.23e2;

    cout << "8進数123  : " << i8  << endl;
    cout << "10進数123 : " << i10 << endl;
    cout << "16進数123 : " << i16 << endl;
    cout << "小数点    : " << ff  << endl;
    cout << "指数      : " << fe  << endl;

    return 0;
}

int escape()
{
    int a,t,n;
    a='\a';
    t='\t';//tab
    n='\n';
    //\a\t\nの文字コードを出力
    cout << "a: "<< a << endl;
    cout << "t: "<< t << endl;
    cout << "t: "<< n << endl;

    cout << "\a警報音\n";//ベルが鳴る
    cout << "AAA\tBBB\tCCC\nDDD\tEEE\tFFF\n";

    return 0;
}

main()
{
    suuti();
    escape();

    return 0;
}