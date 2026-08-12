/*14.2.1
二进制小数可以这样定义：
(0.A1A2A3...)2 = A1 × 2 ^ -1 + A2 × 2 ^ -2 + A3 × 2 ^ -3 + ...
这个定义同时也是从二进制小数到十进制小数的换算公式。
从本节讲的十进制转二进制的推导过程出发类比一下，十进制小数换算成二进制小数应该怎么算？
答：
每次都对十进制小数部分乘2，
如果得到的整数部分小于1，则取0并继续对小数部分乘2；
如果得到的整数部分大于1，则取1并继续对剩余的小数部分乘2；
如果得到的整数部分正好等于1，则取1后完成转换。
*/

/*14.2.2
再类比一下，八进制（或十六进制）与十进制之间如何相互换算？
答：
将八进制数或十六进制数先转换成二进制数，之后转换成十进制数；
将十进制数转换成二进制数，之后转换成八进制数或十六进制数。
*/

/*16.1.1
下面两行printf打印的结果有何不同？请读者比较分析一下。
------------------------------------------------
int i = 0xcffffff3;
printf("%x\n", 0xcffffff3 >> 2);
printf("%x\n", i >> 2);
------------------------------------------------
答：
这里的“%x”表示取unsigned int型参数格式化成无符号十六进制数，
此处的0xcffffff3转换成无符号十进制数是3,489,660,915，
大于int型正值最大值2,147,483,647，但小于unsigned int型最大值4,294,967,295。
对于第一句打印语句，编译器会将无后缀整型0xcffffff3解释成无符号整数
（编译器对十六进制数按int、unsigned int、long int、unsigned long int、
long long int、unsigned long long int的顺序匹配无后缀整型），
于是右移两位最高位补0，得到0x33fffffc；
对于第二句打印语句，编译器会将0xcffffff3解释成负数补码（对应-805,306,381）赋给整型int，
于是右移两位最高位补1（implementation-defined），得到0xf3fffffc。
之后，“%x”会将右移结果（整型负数）直接当作无符号整型解释出来。
*/

/*16.1.2
统计一个无符号整数的二进制表示中1的个数，函数原型是int countbit(unsigned int x);。
答：
#include <stdio.h>

int countbit(unsigned int x)
{
    int count = 0;
    while(x != 0)               // 辗转相除法
    {
        if(x % 2 != 0)
        {
            count++;
            x = x >> 1;
        }
        else
            x = x >> 1;
    }
    return count;
}

int main(void)
{
    printf("the number of 1 is %d.\n", countbit(0x1234));
    return 0;
}

*/

/*16.1.3
用位操作实现无符号整数的乘法运算，
函数原型是unsigned int multiply(unsigned int x, unsigned int y);。
例如：(11011)2×(10010)2=((11011)2<<1)+((11011)2<<4)。
答：
#include <stdio.h>

unsigned int multiply(unsigned int x, unsigned int y)
{
    unsigned int pointer = 0;           // 指示y的数位为1的位置，从最低位（第0位）递增到最高位
    unsigned int result = 0;            // 初始累计求和结果为0
    while(y != 0)
    {
        if(y % 2 != 0)                  // 指针所指数位为1
        {
            result = result + (x << pointer);   // 进行累计求和，特别注意，加和运算符“+”的运算优先级比移位运算符“<<”“>>”的运算优先级高，因此需要把x << pointer用括号括住
            y = y >> 1;                         // 更新y
            pointer++;                          // 更新指针
        }
        else                            // 指针所指数位不是1
        {  
            y = y >> 1;                         // 更新y
            pointer++;                          // 更新指针
        }
    }
    return result;
}

int main(void)
{
    unsigned int x = 0x1B;
    unsigned int y = 0x12;
    printf("the result of %u * %u is %u.\n", x, y, multiply(x, y));
    return 0;
}

*/

/*16.1.4
对一个32位无符号整数做循环右移，
函数原型是unsigned int rotate_right(unsigned int x);。
所谓循环右移就是把低位移出去的部分再补到高位上去，
例如rotate_right(0xdeadbeef, 16)的值应该是0xbeefdead。
答：
#include <stdio.h>

unsigned int rotate_right(unsigned int x, unsigned int times)
{
    unsigned int i;
    unsigned int result = x;
    for(i = 0; i < times; i++)
    {
        if(result % 2 != 0)                         // 最低位为1
            result = (result >> 1) + 0x80000000;    // 先右移，再在最高位加1
        else                                        // 最低位为0
            result = result >> 1;                   // 直接右移
    }
    return result;
}

int main(void)
{
    unsigned int x = 0xdeadbeef;
    unsigned int times = 16;
    printf("result: %x\n", rotate_right(x, times));
    return 0;
}

*/

/*16.1.5
请在网上查找有关独立磁盘冗余阵列的资料，理解其实现原理，其实就是利用了本节的性质3和4。
答:
RAID（独立磁盘冗余阵列）通过组合多个物理磁盘实现性能与容错的提升，
其核心机制依赖于数据条带化、镜像和校验。
其中，RAID 5/6的容错能力正是建立在异或（XOR）运算的可逆性之上：
对一组数据块进行异或得到校验块，当任意一个数据块丢失时，可利用剩余数据与校验块再次异或还原。
例如，在四盘阵列中，若D2丢失，则通过D1 ^ D3 ^ D4 ^ P = D2即可恢复，
这正是异或运算“A ^ B = C => A ^ C = B”性质的工程化应用。
*/

/*16.1.6
交换两个变量的值，不得借助额外的存储空间，除了本节讲的方法之外你还能想出什么方法？
本节讲的方法不能把同一个变量自己跟自己交换，你的方法有没有什么局限性？
答：
交换两变量值若不借助额外空间，常用算术法（加减）与异或法（位运算）。
算术法通过a = a + b; b = a - b; a = a - b实现，但存在溢出风险；
异或法则利用a = a ^ b; b = a ^ b; a = a ^ b完成交换，无溢出问题且适用于整数类型。
两者均存在局限性：算术法仅适用于数值类型，异或法不能用于同一变量自交换
（a ^ a = 0导致数据丢失）。在现实编程中，为兼顾安全性、可读性和通用性，
仍建议采用临时变量法。
*/

/*16.4.1
以下代码得到的sum是0xffff，对吗？
-------------------------------------------------------
#include <stdio.h>

int main(void)
{
    int i = 0;
    unsigned int sum = 0;
    for (; i < 16; i++)
	    sum = sum + 1U << i;
    printf("sum = %x\n", sum);
    return 0;
}
-------------------------------------------------------
答：
不是，移位运算符的优先级比加和运算符的优先级低，如果想得到预期结果，应改成：
#include <stdio.h>

int main(void)
{
    int i = 0;
    unsigned int sum = 0;
    for (; i < 16; i++)
	    sum = sum + (1U << i);
    printf("sum = %x\n", sum);
    return 0;
}

*/

