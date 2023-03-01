/*すぐわかるC/C++、塚越一雄著、1.2~1.4節*/
/*変数、変換指示子*/
#include <stdio.h>//入出力などが行える基本ライブラリ

main()
{
    int x = 10;
    int y = 100;
    int z = 100;
    float weight, low, high;

    x= x+6;
    x+=4;
    weight = (178-100)* 0.9;
    low = weight*0.9;
    high = weight*1.1;

    printf("%dは%dよりも大きい\n",200,50); 
    printf("%d\n",5%2); //%d(変換指示子)を使うと四則演算ができる。剰余%:5%2=2余り1

    printf("%d\n",12);//int型
    printf("%ld\n",12345678);//long int型
    printf("%s\n","おいうえお");//string型

    printf("\n");//改行
    putchar('\n');//''で囲むとchar型、""は文字列型。このデータ型の違いはメモリの使われ方の違い。

    printf("%f\n",(178-100)*0.9);
    printf("%f\n",(178-100)*.9);//(178-100)×0.9の省略形
    printf("%.1f\n",(178-100)*.9);//%.1f:小数点以下の桁数指定(今回は少数第一位までを指定)
    
    printf("%.2f~%.2f\n",low,high);
    printf("%d\n",x);
    printf("++yは変数yを出力する前に演算したので%d、z++は変数zを出力した後に演算したので%d\n",++y,z++);
    
    return 0;
}


/*c++では演算子を再定義できるため、出力にデータ型(%d(int型)など)を指定する必要がなく、データ型は自動判定される。
#include <iostream.h>

main()
{
    cout << 12 << endl
         << 12345678 << endl;
         << "あいうえお";
    return 0;
}
*/