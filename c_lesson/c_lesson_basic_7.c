/*すぐわかるC/C++、塚越一雄著、1.12節*/
/*ポインタ*/

//ポインタを理解するには、変数のサイズとアドレスを知る必要がある。

/*★1 変数のサイズを調べる*/
//1つ1つのメモリは1バイトの大きさを持っており、通常1つの変数で数バイトのメモリを使う。
#include <stdio.h>//入出力などが行える基本ライブラリ
#include <string.h>//strlenという文字列をコピーする関数に必要

volga()
{
    int a[3];
    printf("char          :%d\n",sizeof(char));//[mynote:全角文字はchar型2つ分使う。]
    printf("int           :%d\n",sizeof(int));
    printf("long          :%d\n",sizeof(long));
    printf("long int      :%d\n",sizeof(int));
    printf("float         :%d\n",sizeof(float));
    printf("sizeof (a[0]) :%d\n",sizeof (a[0]));//配列要素1つ分のサイズ
    printf("sizeof (a)    :%d\n",sizeof (a));//全要素分のサイズ

    return 0;
}

/*★2 変数のアドレスを調べる*/
// メモリのアドレス(住所)が分からなければ、コンピュータがメモリを特定できない。
talgo()
{
    char s[3];
    float f;
    int b;
    char c;

    printf("&s[0] :%u\n",&s[0]);//アドレス演算子&を付けると、変数の値ではなく変数の先頭番地を意味する。
                                //今回は、s[0]~s[2]までの3バイトの内[0]が先頭番地、次のsも先頭番地を表す。
    printf("&s    :%u\n",&s);   //kyotest_3.cで配列のsの[]内を書かない理由は、sを書くだけで先頭アドレスを渡すことができ、
    printf("&f    :%u\n",&f);   //s[20]ではsの20番目を渡すことになるからである。また、s[0]~s[19]のためs[20]は存在しない。
    printf("&b    :%u\n",&b);   //厳密にはアドレスを%uで出力できるのはnearポインタである。
    printf("&c    :%u\n",&c);

    return 0;
}

/*★3 ポインタ*/
//変数の数や文字といったデータではなく、変数のアドレスを記憶するための変数をポインタという。
pilga()
{
    int d =100;
    int *pd;//pdはint型変数のアドレスを記憶できる

//ポインタの型とポインタに代入する変数型は同じである必要がある。
    long int *jk;
    long int price[]={7589, 658, 34};

    printf("&d  :%4u\n",&d);//変数の前に&を付けるとアドレスを指定できる。
    printf("&pd :%4u\n",&pd);//ポインタpdのアドレスを指定

    pd=&d;//代入。ポインタpdに変数dのアドレスを記憶。変数のアドレスを代入する時はポインタに*を付けてはいけない。

    printf("pd  :%4u\n",pd);//ポインタpdが記憶している変数のアドレスを出力。今回は変数dのアドレスが出力される。
    printf("*pd :%4u\n",*pd);//ポインタの前に*を付けるとポインタが記憶している変数dの値(今回はd=100)を取り出すことができる。

//ポインタに*を付けると、アドレスを代入した変数に記憶してある値を示す。
//つまり、ポインタはある変数のアドレスを代入するもので、*を付けるとその変数の値を示す。
    *pd=200;//ポインタの前に*を付けると変数dに値(今回は200)を代入できる。
    printf("*pd :%4u\n",*pd);//代入後の値

    jk=&price[0];
    printf("*jk :%4u\n",*jk);

    return 0;
}

/*★4 ポインタを使った引数の参照渡し*/
//引数にポインタを使うと、呼び出し側の実引数の値を変更させることができる。
void change_1(int x, int y)//x,yは仮引数
{
    int temp;

    if(x<y){
        temp=x;
        x=y;
        y=temp;
    }
}

void change_2(int *x, int *y)//引数の参照渡し[mynote:参照とはアドレスを参照するということ]
{
    int temp;

    if(*x<*y){//ポインタを使って実引数n1,n2そのものの値を変化させる。
        temp=*x;//*を付けずに値を変換するとアドレスのみが変換される。
        *x=*y;
        *y=temp;
    }
}

moneypenny()
{
    int n1=100, n2=200;
    printf("n1,n2の初期値      : %d, %d\n",n1,n2);
    change_1(n1, n2);//n1,n2は実引数
    printf("ポインタ無しの変換 : %d, %d\n",n1,n2);
    change_2(&n1, &n2);//n1,n2のアドレスを仮引数*x,*yに渡す。
    printf("ポインタ有りの変換 : %d, %d\n",n1,n2);

    return 0;
}

/*★5 ポインタを使った文字列引数と文字列の戻り値*/
//文字列の引数
void dec_str(char *z)
{
    int last=strlen(z);//strlenは引数の文字列の長さを調べる。string.hのインクルードが必要。
    if(last>0)
    //''はchar型、""は文字列型
        z[last-1]='\0';//文字列の最後の要素にNull文字を代入。今回はConmputerのrの配列要素にNull文字を入れ文字列の終わりを示す。
}

nolga()
{
    char name[]="Computer";//[]内が空白なのは、文字列の引数に使えるのが配列の先頭アドレスだけだからである。指定すると先頭アドレスではなくなる。
    int i;

    for(i=0; i<8; i++){
        printf("%s\n",name);
        dec_str(name);
    }

    return 0;
}

//文字列の戻り値(理解仕切れていない)
// char *func(void)
// {
//     //char name_2[]="Brother";
//     return "Brother";
// }
// ulgo()
// {
//     char *k=NULL;
//     k=func();
//     printf(k);
    
//     return 0;
// }

//関数呼び出し
main()
{
    volga();
    talgo();
    pilga();
    moneypenny();
    nolga();
    //ulgo();

    return 0;
}