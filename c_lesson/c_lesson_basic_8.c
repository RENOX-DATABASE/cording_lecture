/*すぐわかるC/C++、塚越一雄著、1.13節*/
/*内部変数と外部変数、記号定数の定義(define)、const定数とconst引数、関数プロトタイプ、ヘッダファイル*/

#include <stdio.h>//標準ヘッダファイルの取り込み
#include "headerfile.h"//ヘッダファイル(自作)の取り込み

//内部変数と外部変数＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
//関数の内部で宣言する変数のことを内部変数という。
//ある変数を複数の関数で共通に使いたい場合は関数の外で変数を宣言しなければならず、これを外部変数という。
int data;//外部変数

void put(int n)
{
    data=n;//put関数で外部変数dataを使う。
}

int get(void)
{
    return data;//get関数で外部変数dataを使う。
}

calgo()
{
    put(1024);
    printf("%d\n",get());

    return 0;
}

//記号定数＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
//ソースプログラムの名kでよく使う文字の列を別の記号(記号定数)に定義して、その文字の列の代わりに使うことができる。
//記号定数の利点は、途中で修正する可能性のある文字列や長い文字列などを使うときに使うと、#define部分を修正するだけで済むため安全性が高まる。
#define MAX 7    //記号定数の定義(今回は7をMAXという記号定数として定義)
#define ENDL '\n'

walgo()
{
    char c[MAX];
    char p[MAX];
    int k;

    for(k=0;k<MAX;k++)//[mynote:このforがないとセグメンテーション違反
                      //(アクセス禁止やルールに違反してメモリ上のエリアにアクセスしようとしたときなどに発生)になる。]
        c[k]='A';
    for(k=0;k<MAX;k++)
        putchar(c[k]);
    
    putchar(ENDL);

    return 0;
}

//const定数とconst引数＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
/*
const定数
＊const定数を付けるとその変数の値を変更できなくなる。
const int num=100;

＊また、defineを下記のように書き換えることもできる。
ただし、MAXは、配列宣言の[]内は定数でなければならないという規則があり、
char c[MAX]でエラーとなるためconst int MAX=7;はできない。
つまり、const定数は定数ではなく定数式(結果が整数の定数となる式)とみなされる。
＊しかし、C++では配列宣言の[]内に定数式を×のでエラーにはならない。
----------------------
#define BELL '\a'
#define ENDL '\n'
     _||_
     \  /
      \/
const char BELL='\a',
           ENDL='\n';
----------------------

const引数
＊引数の宣言の前にconstを付けると関数内部でその値を変更できなくなる。
つまり、const引数はうっかり引数の値を変更してしまうのを防ぐことができる。
----------------------
void func(char *s)
{
    s[0]='A';//文字列の先頭をAに変更
}
     _||_
     \  /
      \/
void func(const char *s)
{
    s[0]='A';//constによって変更できないのでエラーがでる。
}
----------------------
*/

//関数プロトタイプ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
/*
基本的にはmain関数の前に自作の関数を定義してからmainで呼び出す。そうしないとエラーがでる。
これはmainで自作の関数を使うため、使う前に定義する必要があるからだ。
もし定義がないと、mainの下にある自作の関数の引数や戻り値はint型として扱われてしまう。
しかし、mainの下に自作の関数を起きたいときもあるかもしれない。その際に関数プロトタイプを使う。
*/
void degol(void);//関数プロトタイプ

//関数呼び出し
main()
{
    calgo();
    walgo();
    degol();
    regol();//ヘッダファイル内の関数

    return 0;
}

void degol()//関数プロトタイプを使いmainの上で宣言
{
    printf("ABC\n");
}

//ヘッダファイル＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
/*ヘッダファイルを使うと別のソースファイルを取り込むことができる。
kyotest_8.cとheaderfile.hを使い説明する。以下のヘッダファイルはmainより上で定義している。
標準ヘッダファイルは<>で囲む。インクルードディレクトリだけを検索。
#include <stdio.h>
ヘッダファイル(自作)は""で囲む。まずカレントディレクトリを検索し見つからなければインクルードディレクトリを検索。
#include "headerfile.h"
main関数内のregol();で関数呼び出しをする。

!注意!
本サンプルではインクルードファイルの取り込み確認のため、関数定義の本体をヘッダファイルに書いたが、
実際は関数本体をヘッダファイルに定義するようなことはしない。
*/