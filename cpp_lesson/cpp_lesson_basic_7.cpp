/*新C++言語入門、林晴比古著、Chapter10*/
/*参照*/

#include <iostream>
using namespace std;

void gure(int &dt);

int main()
{
    int dt;
    int &rf=dt;//参照を宣言。&rfによって、rfの内容はdt変数を参照する。rfはdtの別名。
    int *pt=&dt;//ポインタを宣言。変数dtのアドレスを設定。
    //ポインタはアドレスをいつでも変更できるが、参照は初期化のときだけ設定できそれ以降アドレスは変更できない。

    dt=100;//dtの別名としてrfが機能
    cout << "dt = " << dt << "rf = " << rf << "*pt = " << *pt << endl;

    rf=200;//rfが参照している変数dtに200を設定する。
    cout << "dt = " << dt << "rf = " << rf << "*pt = " << *pt << endl;

    *pt=300;//ptの指すアドレスに300を代入する
    cout << "dt = " << dt << "rf = " << rf << "*pt = " << *pt << endl;

    gure(dt);//参照の呼び出し

    cout << "main_dt = " << dt << endl;

    /*
    ポインタはアドレスと値を操作できるが、参照は値を操作できるだけである。
    参照はアドレス設定の時&を付けなくてよい。
    参照は値操作のときに*を付ける必要がない。
    参照は初期化の時以外でアドレスの再設定はできない。
    */

    return 0;
}

void gure(int &dt)//参照を仮引数に使う
{
    cout << "gure_dt = " << dt << endl;
    dt = dt*5;
}