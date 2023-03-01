/*新C++言語入門、林晴比古著、Chapter3*/
/*変数宣言*/

/*
変数には型がある。
char        文字型          1   -128~127
int(16 bit) 整数型          2   -32768~32767
int(32 bit) 整数型          4   -2147483648~2147483647
long int    倍長整数型      4   -2147483648~2147483647
float       単精度浮動小数点 4   10^-38~10^38
double      倍精度浮動小数点 8   10^-308~10^308
bool        論理型          1   True or False

unsigned char       符号なし文字型      1   0~255
unsigned int(16 bit)符号なし整数型      2   0~65535
unsigned int(32 bit)符号なし整数型      4   0~4294967295
unsigned long       符号なし倍長整数型  4   0~4294967295
*/

#include <iostream>
#include <iomanip>
using namespace std;

main()
{
    bool m1,m2,m3,m4;
    m2=true;
    m3=0;
    m4=480;

    cout << "bool型m1= " << m1 << endl;//bool型m1に値を何も設定しないとてきとうな値が出力される
    cout << "bool型m2= " << m2 << endl;//1
    cout << "bool型m3= " << m3 << endl;//0
    cout << "bool型m4= " << m4 << endl;//0以外の値が設定されると1になる

    float f;
    double d;

    f=100.0/3.0;
    d=100.0/3.0;

    cout << "\nfloat型とdouble型の精度は同じか？\n";
    cout << "float  = " << f << endl;
    cout << "double = " << d << endl;
    cout << "これだけでは同じに見える。\n";
    cout << "coutの表示幅はデフォルトで6桁になっているので\nマニピュレータ機能で表示幅を変更すると\n";
    cout << "float  = " << setprecision(15) << f << endl;
    cout << "double = " << setprecision(15) << d << endl; 
    cout << "以上からfloat型とdouble型の精度は違うことがわかる。\n";

    int i(200/5);
    d=200/5;

    cout << "変数の初期化\n";
    cout << "int 　    = " << i << endl;
    cout << "新double  = " << d << endl;

    return 0;
}