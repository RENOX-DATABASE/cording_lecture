/*すぐわかるC/C++、塚越一雄著、1.5~1.6節*/
/*文字配列、キーボードから入力*/
#include <stdio.h>//入出力などが行える基本ライブラリ
#include <string.h>//strcpyという文字列をコピーする関数に必要
#include <stdlib.h>//文字列からint型への変換に必要

main()
{
    char s[20];//c言語には文字列定数("あいうえお")はあるが、文字列変数(例えばs="あいうえお")はない。
               //そこで、char型の配列を使う。sは配列変数名、[]内は記憶可能な最大文字数、ただし、実際に記憶できるのはn-1文字まで。

    s[0] = 'v';//配列は0から始まる
    s[1] = 'a';
    s[2] = 'l';
    s[3] = 'u';
    s[4] = 'e';
    s[5] = '\0';//\0(NULL文字)は文字列の最後を示す特別な文字。これがあることでvalueのeで文字列が終わることが分かる。

    printf("%s\n",s);//[]はいらない。その理由はkyotest_7.c。


/*文字配列へ文字を1文字ずつ代入するのは面倒であり、全角文字の場合、2つ文のchar型配列が必要。
その代わりに全角文字の代入にはstrcpyという文字列をコピーする関数を使う。
strcpyを使うにはstring.hが必要。
*/
    char x[20];//全角文字は20文字入れられない。全角文字は2つ分のchar型を使用するので2×(全角文字数)+1(\0)<=20である必要がある。
    strcpy(x,"あいうえお");
    printf("%s\n",x);

    //文字単位で初期化
    char y[]={'A','B','\0'};
    printf("%s\n",y);
    //文字列で初期化
    char z[]="かきくけこ";
    printf("%s\n",z);


    //キーボードから入力
    char v[50];
    printf("How old are you?\n=>");
    gets(v);//getsは文字列変数にしか入力ができないので、int型などには入力できない。int型などはscanf関数が使える。
    printf("%s\n",v);

    //文字列からint型への変換。使うにはstdlib.hが必要。
    int d;
    d=atoi(v);//atoi:文字列からint型へ変換。float型へはatof。
    printf("%d\n",d);

/*C++ ver. キーボードから入力
#include <iostream.h>
main()
{
    char v[50];
    cout << "How old are you?\n=>"
    cin >> v;
    cout << v << endl;
    return 0;
}
*/

    return 0;
}