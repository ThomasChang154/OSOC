/*1.1.1
解释执行的语言相比编译执行的语言有什么优缺点?
答：
解释执行语言能给出即时反馈，开发速度更快，其编写的源代码文件（文本格式）只需配合
对应平台的解释器即可运行，无需为不同平台重新编译，因而具备良好的源码级跨平台性（前提
是目标平台已安装相应的解释环境）；编译执行语言则需针对不同操作系统和硬件平台，通过重
新编译（及链接）生成对应的二进制可执行文件，才能正常运行。  
在运行机制上，解释执行语言通常不生成持久化的独立目标文件，而是由解释器动态读取并执行
源码（或中间字节码）；编译执行语言则通过一次编译生成目标文件，机器可直接识别并快速执
行。因此，在传统的纯解释模式下，解释执行语言由于每次执行都需重复解释，其启动速度（冷
启动）和响应速度通常慢于编译型语言。  
不过，随着即时编译（JIT）技术的成熟与普及（如Java的HotSpot、Python的PyPy等），解
释型语言在执行过程中会将高频运行的“热点代码”动态编译为本地机器码并缓存。这使得其在长
期运行或高并发场景下的峰值计算性能已大幅逼近编译型语言。*/

/*2.2.1
如何在printf的格式化字符串中表示百分号%?
答：
printf("%%");
*/

/*2.5.1
如何实现向上取整?
答：
#include<stdio.h>

int main()
{
	int x = 16, n = 4, result;
	result = (x % n == 0) ? (x / n) : (x / n + 1);      // 判断语句
	printf("the ceiling value is %d", result);
	return 0;
}

*/

/*3.3.1
定义一个函数increment,它的作用是将传进来的参数加1,然后在main函数中用increment函数
来增加变量的值，代码能否实现目标功能?
答：
不能，main函数在调用increment函数后，操作结果并没有返回至main函数中，
执行自定义函数后局部变量的存储空间会被释放，因此不能奏效。
应对程序作如下修改：
#include<stdio.h>

int increment(int x)
{
	x = x + 1;
    return x;                           // 返回值
}

int main(void)
{
	int i = 1, j = 2;
	i = increment(i); 
	j = increment(j); 
    printf("i = %d, j = %d", i, j);
	return 0;
}

*/

/*3.3.2
如果在一个程序中调用了printf函数却不包含头文件，
例如int main(void) { printf("\n"); }，
编译时会报警告：
warning: incompatible implicit declaration of built-in function ‘printf’
请分析错误原因?
答：
这是没有包含头文件导致的“隐式定义”问题。编译器根据获得的格式推测出隐式函数原型为
int printf(char*)，而printf的真实函数原型是int printf(const char*, ...)
二者格式不匹配，因此如此报错。
*/

/*4.1.1
以下程序段编译能通过，执行也不出错，但是执行结果不正确，请分析一下哪里错了。还有，既然
错了为什么编译能通过呢？
答：
不应该用分号将if语句的判断条件和分支语句分开。使用分号分开后，if语句成为了单独的语句，
并没有语法错误，没有实际执行效果；分支语句则变成了无条件执行的语句，因此编译可通过，
并且执行结果错误。
*/

/*4.2.1
写两个表达式，分别取整型变量x的个位和十位。
答：
#include<stdio.h>

int main(void)
{
    int x, x_2, x_1;
    if (x >= 0)
    {
        x_2 = (x / 10) % 10;        // 取十位
        x_1 = x % 10;	            // 取个位		
    }
    else
    {
        x_2 = -(x / 10) % 10;
        x_1 = -x % 10;
    }
    printf("x_2 = %d, x_1 = %d\n", x_2, x_1);
}

*/

/*4.2.2
写一个函数，参数是整型变量x，功能是打印x的个位和十位。
答：
#include<stdio.h>

void print(int x)
{
    int x_2, x_1;
    if (x >= 0)
    {
        x_2 = (x / 10) % 10;
        x_1 = x % 10;
    }
    else
    {
        x_2 = -(x / 10) % 10;
        x_1 = -x % 10;
    }
    printf("x_2 = %d, x_1 = %d\n", x_2, x_1);
}

int main(void)
{
    int a = -255, b = 512;
    print(a);
    print(b);
    return 0;
}

*/

/*4.3.1
if (x > 0 && x < 10)；
else
	printf("x is out of range.\n");
可以改写成：
if (x <= 0 || x >= 10)
	printf("x is out of range.\n");
*/

/*4.3.2
if (x > 0)
	printf("Test OK!\n");
else if (x <= 0 && y > 0)
	printf("Test OK!\n");
else
	printf("Test failed!\n");
可以改写成：
if (x <= 0 && y <= 0)
	printf("Test failed!\n");
else
	printf("Test OK!\n");
*/

/*4.3.3
if (x > 1 && y != 1) {
	...
} else if (x < 1 && y != 1) {
	...
} else {
	...
}
进入最后一个else，x和y需要满足x == 1 || y == 1
*/

/*4.3.4
if (x < 3 && y > 3)
	printf("Test OK!\n");
else if (x >= 3 && y >= 3)    <---冗余
	printf("Test OK!\n");     <---冗余
else if (z > 3 && x >= 3)
	printf("Test OK!\n");
else if (z <= 3 && y >= 3)
	printf("Test OK!\n");
else
	printf("Test failed!\n");
*/

/*5.1.1
编写一个布尔函数int is_leap_year(int year)，判断参数year是不是闰年。
如果某年份能被4整除，但不能被100整除，那么这一年就是闰年，
此外，能被400整除的年份也是闰年。
答：
#include<stdio.h>
#include<math.h>

int is_leap_year(int year)
{
    if(year % 400 == 0)
        return 1;               // 注意，“400年才闰”这一规则应当优先
    else if(year % 4 == 0)      // 如果“4年一闰”和“100年不闰”这一规则优先
    {                           // 则诸如“1600年”“2000年”这样的年份会被判定为平年
        if(year % 100 == 0)     // 从而导致错误
            return 0;
        else
            return 1;
    }
    else
        return 0;
}

int main(void)
{
    int input_year = 2024;
    if(is_leap_year(input_year))
        printf("%d is leap year.\n", input_year);
    else
        printf("%d is not leap year.\n", input_year);
    return 0;
}

*/

/*5.1.2
编写一个函数double myround(double x)，输入一个小数，将它四舍五入。
例如myround(-3.51)的值是-4.0，myround(4.49)的值是4.0。
可以调用math.h中的库函数ceil和floor实现这个函数。
答：
#include<stdio.h>
#include<math.h>

double myround(double x)
{
    int mod;
    double x_round;
    if(x > 0.0)
    {
        mod = ((int)(x * 10)) % 10;
        if(mod < 5)
            x_round = floor(x);
        else
            x_round = ceil(x);
    }
    else if(x < 0.0)
    {
        mod = ((int)(-x * 10)) % 10;
        if(mod < 5)
            x_round = -floor(-x);
        else
            x_round = -ceil(-x);
    }
    else
        x_round = x;
    return x_round;
}

int main(void)
{
    double result;
    result = myround(-2.35);
    printf("result: %f", result);
    return 0;
}

// 正数： mod = (x * 10) % 10  <   5 ---> floor(x);
         mod = (x * 10) % 10  >=  5 ---> ceil(x);
   负数： mod = (-x * 10) % 10 <   5 ---> -floor(-x);
         mod = (-x * 10) % 10 >=  5 ---> -ceil(-x);
    0：  0
    
*/

/*5.3.1
编写递归函数求两个正整数a和b的最大公约数（GCD，Greatest Common Divisor），
使用Euclid算法：
如果a除以b能整除，则最大公约数是b。
否则，最大公约数等于b和a%b的最大公约数。
Euclid算法是很容易证明的，请读者自己证明一下为什么这么算就能算出最大公约数。
最后，修改你的程序使之适用于所有整数，而不仅仅是正整数。
答：
辗转相除法：
#include<stdio.h>

int GCD(int x, int y)
{
    int GCD_x_y;
    if(x > 0 && y > 0)
    {
        if(x % y == 0)
            GCD_x_y = y;
        else
            GCD_x_y = GCD(y, x % y);
        return GCD_x_y;
    }
    else
    {
        printf("ERROR!\n");
        return -1;
    }    
}

int main(void)
{
    int test;
    test = GCD(44, 3);
    printf("test = %d\n", test);
    return 0;
}

适用于所有整数的版本：
#include<stdio.h>

int abs(int num)
{
    unsigned int num_abs;
    if(num >= 0)
        num_abs = num;
    else
        num_abs = -num;
    return num_abs;
}

int GCD(int x, int y)
{
    int GCD_x_y;
    unsigned int x_abs = abs(x);
    unsigned int y_abs = abs(y);
    if(x_abs > 0 && y_abs > 0)
    {
        if(x_abs % y_abs == 0)
          GCD_x_y = y_abs;
        else
            GCD_x_y = GCD(y_abs, x_abs % y_abs);
        return GCD_x_y;
    }
    else if(x_abs == 0 && y_abs > 0)
        return y_abs;
    else if(x_abs == 0 && y_abs == 0)
    {
        printf("ERROR!\n");
        return -1;
    }
    else
        return x_abs;
}

int main(void)
{
    int test;
    test = GCD(44, 0);
    printf("test = %d\n", test);
    return 0;
}

*/

/*5.3.2
编写递归函数求Fibonacci数列的第n项，这个数列是这样定义的：
fib(0)=1
fib(1)=1
fib(n)=fib(n-1)+fib(n-2)
答：
#include<stdio.h>

unsigned int fibo(unsigned int x)
{
    if(x == 0)
        return 1;
    else if(x == 1)
        return 1;
    else
    {
        unsigned int result;
        result = fibo(x - 1) + fibo(x - 2);
        return result;
    }
}

int main(void)
{
    int test;
    test = fibo(6);
    printf("test = %d\n", test);
    return 0;
}

*/

/*6.1.1
将程序从递归方式改为循环方式实现：
答（1）：
#include<stdio.h>

int abs(int num)
{
    unsigned int num_abs;
    if(num >= 0)
        num_abs = num;
    else
        num_abs = -num;
    return num_abs;
}

int GCD(int x, int y)
{
    unsigned int x_abs = abs(x);
    unsigned int y_abs = abs(y);
    if(x_abs == 0 && y_abs > 0)
        return y_abs;
    else if(x_abs > 0 && y_abs == 0)
        return x_abs;
    else if (x_abs == 0 && y_abs == 0)
    {
        printf("ERROR!\n");
        return -1;
    }
    else
    {
        unsigned int mod = x_abs % y_abs;   // 初始化余数
        while(mod != 0)                     
        {
            x_abs = y_abs;                  // 辗转相除法的实现
            y_abs = mod;                    // 原除数作为新被除数，余数作为新除数
            mod = x_abs % y_abs;            // 再求余数
        }
        return y_abs;
    }
}

int main(void)
{
    int test;
    test = GCD(146, 42);
    printf("test = %d\n", test);
    return 0;
}

答（2）：
#include<stdio.h>

unsigned int fibo(unsigned int x)
{ 
    if(x == 0)
        return 1;
    else if(x == 1)
        return 1;
    else
    {
        unsigned int n = 1;             // 起步为fibo(1)
        unsigned int num_front = 1;     // 为获得fibo(2)，初始好fibo(0)
        unsigned int num_behind = 1;    // 初始好fibo(1)
        unsigned int result;
        while(n != x)
        {
            result = num_front + num_behind;    // 得到fibo(2)
            num_front = num_behind;             // 原本第二个加数用作新的第一个加数
            num_behind = result;                // 得到的加和用作新的第二个加数
            n = n + 1;                          // 不断靠近目标项
        }
        return result;
    }
}

int main(void)
{
    int test;
    test = fibo(2);
    printf("test = %d\n", test);
    return 0;
}

*/

/*6.1.2
编写程序数一下1到100的所有整数中出现多少次数字9。
答：
#include<stdio.h>

int main(void)
{
    int n = 1;
    int times_9 = 0;
    while(n <= 100)
    {
        if(n % 10 == 9)
            times_9 = times_9 + 1;
        else
            times_9 = times_9;
        if((n / 10) % 10 == 9)
            times_9 = times_9 + 1;
        else
            times_9 = times_9;
        n = n + 1;
    }
    printf("times_9: %d\n", times_9);
    return 0;
}

*/

/*6.4.1
求素数这个程序只是为了说明break和continue的用法才这么写的，
其实完全可以不用break和continue，
请读者修改一下控制流程，去掉break和continue而保持功能不变。
答：
#include<stdio.h>

int is_prime(unsigned int n)
{
	int i;
	for (i = 2; i < n; i++)
	{
        if(n % i == 0)
            return 0;       // 在这个循环内部终止结束，说明不是质数
    }
    if(n == 1)
        return 0;           // 1不是质数
    else
        return 1;           // 跳出循环体的数是质数
}

int main(void)
{
	int i;
	for (i = 1; i <= 100; i++) 
		if (is_prime(i))
		    printf("%d\n", i);
	return 0;
}

*/

/*6.4.2
上一节讲过怎样把for循环改写成等价的while循环，
但也提到如果循环体中有continue语句这两种形式就不等价了，想一想为什么不等价了？
答：
对于while循环和do/while循环，执行continue语句之后测试控制表达式，
如果值为真则继续执行下一次循环；
对于for循环，执行continue语句之后首先计算控制表达式3，然后测试控制表达式2，
如果值为真则继续执行下一次循环。
这会导致结果不同。
*/

/*6.5.1
上面打印的小九九有一半数据是重复的，因为8*9和9*8的结果一样。
请修改程序打印这样的小九九：
答：
#include<stdio.h>

int main(void)
{
	int i, j;
	for (i = 1; i <= 9; i++) 
    {
		for (j = 1; j <= i; j++)    // 关键控制条件j <= i
			printf("%d\t", i * j);
		printf("\n");
	}
	return 0;
}

*/

/*6.5.2
编写函数diamond打印一个菱形,如果用偶数做参数则打印错误提示。
答：
#include<stdio.h>

int is_odd(unsigned int x)
{
    if(x % 2 == 0)
        return 0;
    else
        return 1;
}

void diamond(unsigned int num, char print_char)
{
    int i, j, k;            // i为打印图形总数，j为打印第几个，k为打印制表符总数
    if(!is_odd(num))
        printf("ERROR!\n");
    else
    {   
        for(i = 1; i <= num; i = i + 2)         // 打印上半
        {
            for(k = (num - i) / 2; k >= 1; k--) // 打印制表符
                printf("\t");
            for(j = 1; j <= i; j++)             // 打印符号
                printf("%c\t", print_char);
            printf("\n");
        }
        for(i = num - 2; i >= 1; i = i - 2)     // 打印下半
        {
            for(k = 1; k <= (num - i) / 2; k++) // 打印制表符
                printf("\t");
            for(j = 1; j <= i; j++)             // 打印符号
                printf("%c\t", print_char);
            printf("\n");
        }
    }
}

int main(void)
{
	diamond(11, '#');
	return 0;
}

*/

/*7.2.1
在本节的基础上实现一个打印复数的函数，打印的格式是x+yi，如果实部或虚部为0则省略，
例如：1.0、-2.0i、-1.0+2.0i、1.0-2.0i。最后编写一个main函数测试本节的所有代码。
想一想这个打印函数应该属于上图中的哪一层？
答：
#include<stdio.h>
#include<math.h>

struct complex_number 
{
    double x;
    double y;
};

double real_part(struct complex_number z)
{
    return z.x;     // 取实部
}

double img_part(struct complex_number z)
{
    return z.y;     // 取虚部
}

double mag_part(struct complex_number z)
{
    return sqrt(z.x * z.x + z.y * z.y);     // 取幅值
}

double ang_part(struct complex_number z)
{
    return atan2(z.y, z.x);     // 取幅角
}

struct complex_number make_from_real_img(double x, double y)
{
    struct complex_number z;    // 运算后重组
    z.x = x;
    z.y = y;
    return z;
}

struct complex_number make_from_mag_ang(double r, double A)
{
    struct complex_number z;    // 运算后重组
    z.x = r * cos(A);
    z.y = r * sin(A);
    return z;
}

struct complex_number add_complex(struct complex_number z1, struct complex_number z2)
{
    return make_from_real_img(real_part(z1) + real_part(z2), img_part(z1) + img_part(z2));
}

struct complex_number sub_complex(struct complex_number z1, struct complex_number z2)
{
    return make_from_real_img(real_part(z1) - real_part(z2), img_part(z1) - img_part(z2));
}

struct complex_number multi_complex(struct complex_number z1, struct complex_number z2)
{
    return make_from_mag_ang(mag_part(z1) * mag_part(z2), ang_part(z1) + ang_part(z2));
}

struct complex_number div_complex(struct complex_number z1, struct complex_number z2)
{
    return make_from_mag_ang(mag_part(z1) / mag_part(z2), ang_part(z1) - ang_part(z2));
}

void print_complex_number(struct complex_number result)
{
    double result_real = real_part(result);
    double result_img = img_part(result);
    if(result_real == 0 && result_img != 0)
        printf("%fi", result_img);
    else if(result_real != 0 && result_img == 0)
        printf("%f", result_real);
    else if(result_real == 0 && result_img == 0)
        printf("0");
    else
        printf("%f + %fi", result_real, result_img);
}

int main(void)
{
	struct complex_number z1 = {3.2, 6.4};
    struct complex_number z2 = {2.3, 0.7};
    print_complex_number(add_complex(z1, z2));
    print_complex_number(sub_complex(z1, z2));
    print_complex_number(multi_complex(z1, z2));
    print_complex_number(div_complex(z1, z2));
    return 0;
}

*/

/*7.2.2
实现一个用分子分母的格式来表示有理数的结构体rational以及相关的函数，
rational结构体之间可以做加减乘除运算，运算的结果仍然是rational。
注意要约分为最简分数，例如1/8和-1/8相减的打印结果应该是1/4而不是2/8，
可以利用第3节“递归”练习题中的Euclid算法来约分。
在动手编程之前先思考一下这个问题实现了什么样的数据抽象，抽象层应该由哪些函数组成。
答： 
#include<stdio.h>
#include<math.h>

int abs(int num)        // 绝对值函数
{
    unsigned int num_abs;
    if(num >= 0)
        num_abs = num;
    else
        num_abs = -num;
    return num_abs;
}

int GCD(int x, int y)   // 适用于所有整数的最大公约数计算
{
    int GCD_x_y;
    unsigned int x_abs = abs(x);
    unsigned int y_abs = abs(y);
    if(x_abs > 0 && y_abs > 0)
    {
        if(x_abs % y_abs == 0)
          GCD_x_y = y_abs;
        else
            GCD_x_y = GCD(y_abs, x_abs % y_abs);
        return GCD_x_y;
    }
    else if(x_abs == 0 && y_abs > 0)
        return y_abs;
    else if(x_abs == 0 && y_abs == 0)
    {
        printf("ERROR!\n");
        return -1;
    }
    else
        return x_abs;
}

struct rational     // 有理数结构体，分子num和分母den
{
    int num;
    int den;
};

struct rational make_rational(int num, int den)
{                   // 计算后重组函数
    struct rational x;
    x.num = num;
    x.den = den;
    return x;
}

struct rational GCD_result(int num, int den)
{                   // 约分函数
    int GCD_number = GCD(num, den);
    num = num / GCD_number;
    den = den / GCD_number;
    return make_rational(num, den);
}

struct rational add_rational(struct rational x1, struct rational x2)
{                   // 加法计算
    if(x2.den == 0 || x1.den == 0)
    {
        printf("ERROR INPUT!\n");
        return make_rational(0, 0);
    }
    else
    {
        int x1_common, x2_common;
        x1_common = x1.num * x2.den;
        x2_common = x2.num * x1.den;
        return GCD_result(x1_common + x2_common, x1.den * x2.den);
    }
}

struct rational sub_rational(struct rational x1, struct rational x2)
{                   // 减法计算
    if(x2.den == 0 || x1.den == 0)
    {
        printf("ERROR INPUT!\n");
        return make_rational(0, 0);
    }
    else
    {
        int x1_common, x2_common;
        x1_common = x1.num * x2.den;
        x2_common = x2.num * x1.den;
        return GCD_result(x1_common - x2_common, x1.den * x2.den);
    }
}

struct rational multi_rational(struct rational x1, struct rational x2)
{                   // 乘法计算
    if(x2.den == 0 || x1.den == 0)
    {
        printf("ERROR INPUT!\n");
        return make_rational(0, 0);
    }
    else
        return GCD_result(x1.num * x2.num, x1.den * x2.den);
}

struct rational div_rational(struct rational x1, struct rational x2)
{                   // 除法计算
    if(x2.num == 0 || x2.den == 0 || x1.den == 0)
    {
        printf("ERROR INPUT!\n");
        return make_rational(0, 0);
    }
    else
        return GCD_result(x1.num * x2.den, x1.den * x2.num);
}

void print_rational(struct rational x)
{
    if(x.den == 0)
        printf("ERROR!\n");
    else 
    {
        if(x.num == 0)
            printf("0\n");
        else if((x.num > 0 && x.den > 0) || (x.num < 0 && x.den < 0))
        {
            if(abs(x.den) == 1)
                printf("%d\n", abs(x.num));
            else
                printf("%d/%d\n", abs(x.num), abs(x.den));
        }
        else
        {
            if(abs(x.den) == 1)
                printf("-%d\n", abs(x.num));
            else
                printf("-%d/%d\n", abs(x.num), abs(x.den));
        } 
    }
}

int main(void)
{
	struct rational a = make_rational(1, 8); 
	struct rational b = make_rational(-1, 8); 
	print_rational(add_rational(a, b));
	print_rational(sub_rational(a, b));
	print_rational(multi_rational(a, b));
	print_rational(div_rational(a, b));
	return 0;
}

*/

/*7.3.1
本节只给出了make_from_real_img和make_from_mag_ang函数的实现，
请读者自己实现real_part、img_part、magnitude、angle这些函数。
答：
#include<stdio.h>
#include<math.h>

enum coordinate_type 
{
    RECTANGULAR, POLAR              // 默认前者从0开始自动赋值，后者自动递增
};

struct complex_number
{
    enum coordinate_type type;      // type是枚举变量，有RECTANGULAR和POLAR两种常量赋值选择
    double a;
    double b;
};

struct complex_number make_from_real_img(double x, double y)
{
	struct complex_number z;
	z.type = RECTANGULAR;
	z.a = x;
	z.b = y;
	return z;
}

struct complex_number make_from_mag_ang(double r, double A)
{
	struct complex_number z;
	z.type = POLAR;
	z.a = r;
	z.b = A;
	return z;
}

double real_part(struct complex_number z)
{
    if(z.type == RECTANGULAR)
        return z.a;
    else
        return z.a * cos(z.b);
}

double img_part(struct complex_number z)
{
    if(z.type == RECTANGULAR)
        return z.b;
    else
        return z.a * sin(z.b);
}

double magnitude(struct complex_number z)
{
    if(z.type == RECTANGULAR)
        return sqrt(z.a * z.a + z.b * z.b);
    else
        return z.a;
}

double angle(struct complex_number z)
{
    if(z.type == RECTANGULAR)
        return atan2(z.b, z.a);
    else
        return z.b;
}

*/

/*7.3.2
编译运行下面这段程序，结果是什么？并解释一下为什么是这样的结果。
#include <stdio.h>

enum coordinate_type { RECTANGULAR = 1, POLAR };

int main(void)
{
	int RECTANGULAR;
	printf("%d %d\n", RECTANGULAR, POLAR);
	return 0;
}
答：
RECTANGULAR的值是不定值，POLAR的值是2。
RECTANGULAR在main函数内被局部声明了，没有赋值，因此输出不确定；
POLAR在枚举类型enum中被全局枚举定义为2，因此输出为2。
特别注意，enum定义的成员名称不可与局部变量名称重复，二者所在的命名空间相同，因此会发生冲突，不合法
*/

/*8.1.1
编写一个程序，定义两个类型和长度都相同的数组，将其中一个数组的所有元素拷贝给另一个。
既然数组不能直接赋值，想想应该怎么实现。
答：
#include <stdio.h>

int main(void)
{
	int num_1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num_2[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int trans;      // 中转变量
    int i;
    for(i = 0; i <= 9; i++)
    {
        trans = num_1[i];
        num_2[i] = trans;
    }
    for(i = 0; i <= 9; i++)
        printf("num_2[%d] = %d\n", i, num_2[i]);
	return 0;
}
// 特别注意，数组类型变量不可以互相赋值，但结构体类型变量可以
// 此外，数组类型做右值使用时，自动转换成指向数组首元素的指针

*/

/*8.2.1
用rand函数生成[10, 20]之间的随机整数，表达式应该怎么写？
答：
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num[10];
    int i;
    for(i = 0; i < 10; i++)
    {
        num[i] = rand() % 11 + 10;              // 任意区间随机数的构造：rand() % x + y表示的区间范围是[y, x + y -1]
        printf("num[%d] = %d\n", i, num[i]);
    }
	return 0;
}
或者可以这样写，封装成一个函数：
#include <stdio.h>
#include <stdlib.h>

int random_gen(int x, int y)
{
    return rand() % x + y;      // 随机数生成范围[y, x + y - 1]
}

int main(void)
{
	int num[10];
    int i;
    for(i = 0; i < 10; i++)
    {
        num[i] = random_gen(11, 10);
        printf("num[%d] = %d\n", i, num[i]);
    }
	return 0;
}

*/

/*8.3.1
补完本节直方图程序的main函数，以可视化的形式打印直方图。
答：
#include <stdio.h>
#include <stdlib.h>
#define N 40

int random_gen(int x, int y)
{
    return rand() % x + y;      // 随机数生成范围[y, x + y - 1]
}

int main(void)
{
	int num[N];
    int histogram[10] = {0};
    int i, j;
    int times = 0;

    for(i = 0; i < N; i++)
    {
        num[i] = random_gen(10, 0);
        printf("num[%d] = %d\n", i, num[i]);        // 验证生成随机数结果
        histogram[num[i]]++;
    }
    
    for(i = 0; i < 10; i++)
        printf("%d\t", i);
    printf("\n");
    // 接下来处理直方图打印的思路：
    // i = 1 until N                                i表示第i行，同时也表示某个数出现了i次，极端条件下，一个数最多出现N次
    // j = 0 until 9                                j表示每个随机数0~9
    // histogram[j] >= i                            判断条件：随机数j出现的次数是否大于或等于当前第i次
    // printf("*\t") && times++; else printf("\t"); 如果大于或等于，则打印标志符，同时标志符打印次数加1；否则不打印，单纯打印制表符
    for(i = 1; i <= N; i++)
    {
        for(j = 0; j < 10; j++)
        {
            if(histogram[j] >= i)
            {
                printf("*\t");
                times++;
                if(j == 9)
                    printf("\n");       // 换行 
            }
            else
            {
                printf("\t");
                if(j == 9)
                    printf("\n");       // 换行
            }
        }
        if(times == N)                  // 途中如果发现标志符的数量已经达到N，则跳出循环，避免冗余操作
            break;
    }
	return 0;
}

*/

/*8.3.2
定义一个数组，编程打印它的全排列。
程序的主要思路是：
把第1个数换到最前面来（本来就在最前面），准备打印1xx，再对后两个数2和3做全排列。
把第2个数换到最前面来，准备打印2xx，再对后两个数1和3做全排列。
把第3个数换到最前面来，准备打印3xx，再对后两个数1和2做全排列。
可见这是一个递归的过程，把对整个序列做全排列的问题归结为对它的子序列做全排列的问题，
注意我没有描述Base Case怎么处理，你需要自己想。
你的程序要具有通用性，如果改变了N和数组a的定义（比如改成4个数的数组），
其它代码不需要修改就可以做4个数的全排列（共24种排列）。
答：
#include <stdio.h>
#include <stdlib.h>
#define N 4

int num[N] = {1, 2, 3, 4};

// 递归生成全排列（回溯法）
// 思路：固定前step个位置，然后对后面的元素进行交换递归
// 参数step：当前要确定的位置索引（从0开始） 

void permute(int step)
{     
    if (step < N)   // 还未处理完所有位置，需要继续递归
    {
        int i;
        int temp;   // 用于交换的临时变量
                    // 循环从step开始，只考虑当前位置及之后的元素
                    // 因为step之前的元素已经固定，不能再动
        for (i = step; i < N; i++)   
        {
            // ----交换操作：将num[i]放到当前step位置----
            temp = num[i];          
            num[i] = num[step];    
            num[step] = temp;        

            // ----递归：处理下一个位置step + 1----
            permute(step + 1);         

            // ----回溯操作：交换回来，恢复数组原状----
            // 目的是为了不影响下一次循环（i变化时，数组应保持原始顺序）
            temp = num[i];          
            num[i] = num[step];     
            num[step] = temp;       
        }
            // 当for循环结束后，该层递归返回上一层
    }
    else    // step == N表示所有位置都已填好，得到一个完整排列
    {
        int i;
            // 输出当前数组中的排列
        for (i = 0; i < N; i++)
            printf("%d\t", num[i]);
        printf("\n");
            // 打印后返回上一层，继续尝试其他交换
    }
}

int main(void)
{
    permute(0);   // 从第0个位置开始生成全排列
    return 0;
}

*/

/*8.3.3
完成了上述要求之后再考虑第二个问题：
如果再定义一个常量M表示从N个数中取几个数做排列（N == M时表示全排列），
原来的程序应该怎么改？
答：
#include <stdio.h>
#include <stdlib.h>
#define N 5
#define M 4

int num[N] = {1, 2, 3, 4, 5};
int num_select[M];

// 递归生成全排列（回溯法）
// 思路：固定前step个位置，然后对后面的元素进行交换递归
// 参数step：当前要确定的位置索引（从0开始）

void permute(int step)
{     
    if (step < M)   // 还未处理完所有位置，需要继续递归
    {
        int i;
        int temp;   // 用于交换的临时变量
                    // 循环从step开始，只考虑当前位置及之后的元素
                    // 因为step之前的元素已经固定，不能再动
        for (i = step; i < M; i++)   
        {
            // ----交换操作：将num[i]放到当前step位置----
            temp = num_select[i];          
            num_select[i] = num_select[step];    
            num_select[step] = temp;        

            // ----递归：处理下一个位置step + 1----
            permute(step + 1);         

            // ----回溯操作：交换回来，恢复数组原状----
            // 目的是为了不影响下一次循环（i变化时，数组应保持原始顺序）
            temp = num_select[i];          
            num_select[i] = num_select[step];     
            num_select[step] = temp;       
        }
            // 当for循环结束后，该层递归返回上一层
    }
    else    // step == N表示所有位置都已填好，得到一个完整排列
    {
        int i;
            // 输出当前数组中的排列
        for (i = 0; i < M; i++)
            printf("%d\t", num_select[i]);
        printf("\n");
            // 打印后返回上一层，继续尝试其他交换
    }
}

int main(void)
{
    int j;
    for(j = 0; j < M; j++)
        num_select[j] = num[j];
    permute(0);   // 从第0个位置开始生成全排列
    return 0;
}

*/

/*8.3.4
最后再考虑第三个问题：如果要求从N个数中取M个数做组合而不是做排列，
就不能用原来的递归过程了，想想组合的递归过程应该怎么描述，编程实现它。
答：
#include <stdio.h>
#include <stdlib.h>
#define N 7
#define M 3

int num[N] = {1, 2, 3, 4, 5, 6, 7};
int num_select[M];

// 递归生成组合
// 一共N个数，选取M个数，
// 第0个位置可选元素范围：从第0个元素到第N - M个元素（pos = 0）
// 第1个位置可选元素范围取决于第0个位置的元素：
// 如果选择第0个元素，范围：从第1个元素到第N - M + 1个元素
// 如果选择第1个元素，范围：从第2个元素到第N - M + 1个元素（pos = 1）
// 如果选择第2个元素，范围：从第3个元素到第N - M + 1个元素
// ......
// 如果选择第N - M个元素：范围：只有第N - M + 1个元素
// 第2个位置可选元素范围取决于第1个位置的元素：
// 如果选择第1个元素，范围：从第2个元素到第N - M + 2个元素
// 如果选择第2个元素，范围：从第3个元素到第N - M + 2个元素（pos = 2）
// 如果选择第3个元素，范围：从第4个元素到第N - M + 2个元素
// ......
// 如果选择第N - M + 1个元素：范围：只有第N - M + 2个元素
// ......
// 第3个位置可选元素范围取决于第2个位置的元素：
// 如果选择第2个元素，范围：从第3个元素到第N - M + 3个元素
// 如果选择第3个元素，范围：从第3个元素到第N - M + 3个元素（pos = 3）
// 如果选择第4个元素，范围：从第4个元素到第N - M + 3个元素
// ......
// 如果选择第N - M + 2个元素：范围：只有第N - M + 3个元素
// ......
// 于是可以总结出：
// 第M - 1个位置可选元素范围取决于第M - 2个位置的元素：
// 如果选择第M - 2个元素，范围：从第M - 1个元素到第N - 1个元素
// 如果选择第M - 1个元素，范围：从第M个元素到第N - 1个元素（pos = M - 1）
// 如果选择第M个元素，范围：从第M + 1个元素到第N - 1个元素
// ......
// 如果选择第N - 2个元素：范围：只有第N - 1个元素

// 参数start：取值范围起始值（从0到M - 1）
// 参数pos：当前的位置（从0到M - 1）
  
void combine(int pos, int start)
{     
    if (pos < M)   // 还未处理完所有位置，需要继续递归
    {
        int range;       // range表示取值范围
        for(range = start; range <= N - M + pos; range++)
        {
            num_select[pos] = num[range];
            combine(pos + 1, range + 1);
            // 特别注意，第二个递归参数是range + 1，
            // 确保下一层的起始下标比当前选择的下标大
        }
    }
    else    // pos == M表示所有位置都已填好，得到一个完整组合
    {
        int i;
            // 输出当前数组中的组合
        for (i = 0; i < M; i++)
            printf("%d\t", num_select[i]);
        printf("\n");
            // 打印后返回上一层，继续组合
    }
}

int main(void)
{
    combine(0, 0);   // 从第0个位置开始生成组合
    return 0;
}

*/

/*11.4.1
快速排序是另外一种采用分而治之策略的排序算法，
在平均情况下的时间复杂度也是Θ(nlgn)，但比归并排序有更小的时间常数。
请补完partition函数，这个函数有多种写法，请选择时间常数尽可能小的实现方法。
想想快速排序在最好和最坏情况下的时间复杂度是多少？
快速排序在平均情况下的时间复杂度分析起来比较复杂，有兴趣的读者可以参考算法导论。
答：
快速排序（Quick Sort）是一种高效的排序算法，
基于分治法（Divide and Conquer）的思想。
它的核心是通过选择一个基准元素（pivot），将列表分为两部分：
一部分小于基准元素，另一部分大于基准元素，然后递归地对这两部分进行排序。
快速排序的平均时间复杂度为 O(n log n)，在实际应用中性能优异。
快速排序是由托尼·霍尔发展的一种排序算法。
在平均状况下，排序 n 个项目要 Ο(n log n) 次比较。
在最坏状况下则需要 Ο(n ^ 2) 次比较，但这种状况并不常见。
事实上，快速排序通常明显比其他 Ο(n log n) 算法更快，
因为它的内部循环（inner loop）可以在大部分的架构上很有效率地被实现出来。

算法步骤如下：

1. 选择基准元素：从列表中选择一个元素作为基准（pivot）。
   选择方式可以是第一个元素、最后一个元素、中间元素或随机元素。
2. 分区：将列表重新排列，使得所有小于基准元素的元素都在基准的左侧，
   所有大于基准元素的元素都在基准的右侧。基准元素的位置在分区完成后确定。
3. 递归排序：对基准元素左侧和右侧的子列表分别递归地进行快速排序。
4. 合并：由于分区操作是原地进行的，递归结束后整个列表已经有序。

#include <stdio.h>

#define LEN 6
int a[LEN] = { 10, 8, 11, 4, 15, 16 };

int partition(int start, int end)
{
	int mid;                // 排列后基准值角标
    int pivot = a[start];   // 以起始元素为基准值
    int i;                  // 待排序数组a的角标
    int j = 0;              // 比基准值小的数组b的角标
    int k = 0;              // 比基准值大的数组c的角标
    int b[end - start + 1], c[end - start + 1];     // 初始化数组b、c，数组长度为end - start + 1
    for(i = start + 1; i <= end; i++)       // 对基准值以外的元素进行分配
    {
        if(a[i] <= pivot)
        {
            b[j] = a[i];     
            j++;
        }
        else
        {
            c[k] = a[i];    
            k++;           
        }
    }
    b[j] = pivot;           // 将其他元素都分配完之后，基准值应放置在数组b中
    mid = start + j;        // 返回排列后基准值的角标，注意，应在j的基础上加上偏移量start
    j++;                    // 准备将数组c的元素放入数组b，数组b是排序后的数组结果
    k = 0;                  // 重置k的值
    while(j < end - start + 1)  // 将数组c的元素放入数组b
    {
        b[j] = c[k];    
        j++;
        k++;
    }
    j = 0;                  // 重置j的值
    while(start <= end)     // 将数组a更新成数组b的值
    {
        a[start] = b[j];
        start++;
        j++;
    }
	return mid;             // 返回排列后基准值角标
}

void quicksort(int start, int end)
{
	int mid;
	if (end > start) 
    {
		mid = partition(start, end);    // 得到排列后基准值角标
		quicksort(start, mid - 1);      // 对基准值以左的数组继续递归排序，直至排序完成
		quicksort(mid + 1, end);        // 对基准值以右的数组继续递归排序，直至排序完成
	}
}

int main(void)
{
    quicksort(0, LEN - 1);
    int i;
    for(i = 0; i < LEN; i++)
        printf("%d\t", a[i]);
    return 0;
}

*/

/*11.5.1
实现一个算法，在一组随机排列的数中找出最小的一个。
你能想到的最直观的算法一定是Θ(n)的，想想有没有比Θ(n)更快的算法？
答：
#include <stdio.h>

#define LEN 8
int a[LEN] = { 10, 5, 11, 4, 15, 16, 2, 3 };

int min_of(int start, int end)
{
    int pivot;
    int i;
    if(start <= end)
    {
        pivot = a[start];
        for(i = start + 1; i <= end; i++)
        {
            if(pivot > a[i])
                pivot = a[i];
        }
        return pivot;
    }
    else
        return -1;
}

int main(void)
{
    int min;
    printf("%d\n", min_of(0, LEN - 1));
    return 0;
}

*/

/*11.5.2
在一组随机排列的数中找出第二小的，这个问题比上一个稍复杂，你能不能想出Θ(n)的算法？
答：
#include <stdio.h>

#define LEN 8

int a[LEN] = { 3, 2, 4, 1, 5, 0, 6, 8 };

int min_of(int start, int end)
{
    int pivot;
    int i;
    if(start <= end)
    {
        pivot = a[start];
        for(i = start + 1; i <= end; i++)
        {
            if(pivot > a[i])
                pivot = a[i];
        }
        return pivot;
    }
    else  
        return -1;
}

int second_min(int start, int end, int delete)
{
    int i;
    int j = 0;
    int num = 0;                                // 和待剔除元素相同的元素数
    if(start <= end)
    {
        for(i = start; i <= end; i++)           // 记录和待剔除元素相同的元素数
        {
            if(delete == a[i])
                num++;
        }
        int count = (end - start + 1) - num;    // 剔除后临时数组的长度
        if(count == 0 || num == 0)              // 发现原数组所有元素都相同或输入的待剔除元素不存在
            return -1;                          // 返回-1
        else
        {
            int b[count];
            for(i = start; i <= end; i++)       // 生成剔除后临时数组
            {
                if(delete != a[i])
                {
                    b[j] = a[i];
                    j++;
                }
            }
            int pivot;                          // 从临时数组中找最小值
            j = 0;
            pivot = b[j];
            for(j = 1; j < count; j++)
            {
                if(pivot > b[j])
                    pivot = b[j];
            }
            return pivot;                       // 即原数组第二小的值
        }
    }
    else
        return -1;
}

int main(void)
{
    int min = min_of(0, LEN - 1);
    printf("%d\t", second_min(0, LEN - 1, min));
    return 0;
}

*/

/*11.5.3
进一步泛化，在一组随机排列的数中找出第k小的，这个元素称为k-th Order Statistic。
能想到的最直观的算法肯定是先把这些数排序然后取第k个，时间复杂度和排序算法相同，
可以是Θ(nlgn)。这个问题虽然比前两个问题复杂，
但它也有平均情况下时间复杂度是Θ(n)的算法，
将上一节习题1的快速排序算法稍加修改就可以解决这个问题：
---------------------------------------------------------------
int order_statistic(int start, int end, int k)
{
	用partition函数把序列分成两半，中间的pivot元素是序列中的第i个;
	if (k == i)
		返回找到的元素;
	else if (k > i)
		从后半部分找出第k-i小的元素并返回;
	else
		从前半部分找出第k小的元素并返回;
}
---------------------------------------------------------------
请编程实现这个算法。
答：
#include <stdio.h>

#define LEN 6
int a[LEN] = { 10, 8, 11, 4, 15, 16 };
// 8 4 10 11 15 16 mid = 2
// k = 3 相当于在后半序列中寻找第0小的 
// k - mid - 1 = 3 - 2 - 1 = 0

int partition(int start, int end)
{
	int mid;                // 排列后基准值角标
    int pivot = a[start];   // 以起始元素为基准值
    int i;                  // 待排序数组a的角标
    int j = 0;              // 比基准值小的数组b的角标
    int k = 0;              // 比基准值大的数组c的角标
    int b[end - start + 1], c[end - start + 1];     // 初始化数组b、c，数组长度为end - start + 1
    for(i = start + 1; i <= end; i++)       // 对基准值以外的元素进行分配
    {
        if(a[i] <= pivot)
        {
            b[j] = a[i];     
            j++;
        }
        else
        {
            c[k] = a[i];    
            k++;           
        }
    }
    b[j] = pivot;           // 将其他元素都分配完之后，基准值应放置在数组b中
    mid = start + j;        // 返回排列后基准值的角标，注意，应在j的基础上加上偏移量start
    j++;                    // 准备将数组c的元素放入数组b，数组b是排序后的数组结果
    k = 0;                  // 重置k的值
    while(j < end - start + 1)  // 将数组c的元素放入数组b
    {
        b[j] = c[k];    
        j++;
        k++;
    }
    j = 0;                  // 重置j的值
    while(start <= end)     // 将数组a更新成数组b的值
    {
        a[start] = b[j];
        start++;
        j++;
    }
	return mid;             // 返回排列后基准值角标
}

int order_statistic(int start, int end, int k)
{
    int mid;
    if(end >= start)
    {
        mid = partition(start, end);                                // 用partition函数把序列分成两半，中间的pivot元素是序列中的第mid个
        if(k == mid)                                                // 分成两半之后，如果要找的第k小的元素和pivot（即a[mid]）相同，则直接返回该元素
            return a[mid];
        else if(k > mid)                                            // 如果要找的第k小的元素在pivot之后，则对后半序列递归应用order_statistic函数
            return order_statistic(mid + 1, end, k - mid - 1);      // 注意，需要在后半序列中寻找第k - mid - 1小的数，因为需要排除前半序列的元素
        else                                                        // 如果要找的第k小的元素在pivot之后，则对前半序列递归应用order_statistic函数
            return order_statistic(start, mid - 1, k);              // 在前半序列中依然寻找第k小的数
    }
}

int main(void)
{
    printf("%d\n", order_statistic(0, LEN - 1, 0));
    return 0;
}

*/

/*11.6.1
本节的折半查找算法有一个特点：如果待查找的元素在数组中有多个则返回其中任意一个，
以本节定义的数组int a[8] = { 1, 2, 2, 2, 5, 6, 8, 9 };为例，
如果调用binarysearch(2)则返回3，即a[3]，而有些场合下要求这样的查找返回a[1]，
也就是说，如果待查找的元素在数组中有多个则返回第一个。
请修改折半查找算法实现这一特性。
答：
#include <stdio.h>

#define LEN 8
int a[LEN] = { 1, 2, 2, 2, 5, 6, 8, 9 };

int binarysearch(int number)
{
	int mid, start = 0, end = LEN - 1;

	while (start <= end) 
    {
		mid = (start + end) / 2;
		if (a[mid] < number)
			start = mid + 1;
		else if (a[mid] > number)
			end = mid - 1;
		else
		{
            int i = start;          // 找到目标元素之后，从start角标位置开始向右扫描
            while(a[mid] != a[i])   // 没找到第一个目标元素则递增
                i++;
            return i;               // 直至找到第一个目标元素，返回其角标位置
        }
	}
	return -1;
}

int main(void)
{
	printf("%d\n", binarysearch(2));
	return 0;
}

*/

/*11.6.2
编写一个函数double mysqrt(double y);求y的正平方根，参数y是正实数。
我们用折半查找来找这个平方根，在从0到y之间必定有一个取值是y的平方根，
如果我们查找的数x比y的平方根小，则x^2<y，如果我们查找的数x比y的平方根大，则x^2>y，
我们可以据此缩小查找范围，当我们查找的数足够准确时（比如满足|x^2-y|<0.001），
就可以认为找到了y的平方根。思考一下这个算法需要迭代多少次？
迭代次数的多少由什么因素决定？
答：
#include <stdio.h>

double mysqrt(double y)
{
    double x, start = 0.0, end = y;
    while(start < end)
    {
        x = (start + end) / 2;
        if(x * x - y >= 0.001 || x * x - y <= -0.001)
        {
            if(x * x < y)
                start = x;
            else
                end = x;
        }
        else
            return x;
    }
    if(start == end)
        return 0.0;
    else
        return -1.0;
}

int main(void)
{
	double result;
    printf("%f\t", mysqrt(3));
    return 0;
}

*/

/*11.6.3
编写一个函数double mypow(double x, int n);求x的n次方，参数n是正整数。
第一次循环算出x·x=x2，第二次循环算出x2·x2=x4，第三次循环算出x4·x4=x8。
这样只需要三次循环，时间复杂度是Θ(lgn)。思考一下如果n不是2的整数次幂应该怎么处理。
请分别用递归和循环实现这个算法。
递归实现：
#include <stdio.h>

double mypower(double x, int n)
{
    int mid;
    if(n == 0)
        return 1;
    if(n % 2 == 0)                          // n为偶数时，将求x的n次幂转换成求x^2的n/2次幂，不断递归
        return mypower(x * x, n / 2);
    else
    { 
        if(n == 1)                          // 递归到最后，n必定为1，并且x为最终结果
            return x;
        else
            return x * mypower(x, n - 1);   // n为奇数时，将求x的n次幂转换成求x * x的n-1次幂，使得n-1为偶数，不断递归
    }
}

int main(void)
{
    printf("%f\n", mypower(3, 9));
    return 0;
}

循环实现：
#include <stdio.h>

double mypower(double x, int n)
{
    double result = 1.0;                    // 初始将result设成1，这是为了应对n = 0以及n为奇数的情况
    double base = x;
    while(n > 0)
    {
        if(n % 2 == 1)                      // 如果n一开始是奇数，则首先将1和x相乘
            result = result * base;         // 后续与x相乘的都是x的偶数次幂，从而计算出x的奇数次幂
        base = base * base;                 // 如果n一开始就是偶数，则后续就是1和x的偶数次幂相乘，从而计算出x的偶数次幂
        n = n / 2;
    }
    return result;                          // 返回计算结果，如果n = 0则返回result的初始值1
}

int main(void)
{
    printf("%f\n", mypower(2, 4));
    return 0;
}

*/

/*12.3.1
修改本节的程序，要求从起点到终点正向打印路线。
答：
#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

struct point { int row, col; } stack[512];
int top = 0;

void push(struct point p)
{
	stack[top++] = p;
}

struct point pop(void)
{
	return stack[--top];
}

int is_empty(void)
{
	return top == 0;
}

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

void print_maze(void)
{
	int i, j;
	for (i = 0; i < MAX_ROW; i++) {
		for (j = 0; j < MAX_COL; j++)
			printf("%d ", maze[i][j]);
		putchar('\n');
	}
	printf("*********\n");
}

struct point predecessor[MAX_ROW][MAX_COL] = {
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
};

void visit(int row, int col, struct point pre)
{
	struct point visit_point = { row, col };
	maze[row][col] = 2;
	predecessor[row][col] = pre;
	push(visit_point);
}

int main(void)
{
	struct point p = { 0, 0 };
    int num = 1;
    struct point route_end_to_start[25];        // 存储结构体数组

	maze[p.row][p.col] = 2;
	push(p);	
	
	while (!is_empty()) {
		p = pop();
		if (p.row == MAX_ROW - 1  // goal 
		    && p.col == MAX_COL - 1)
			break;
		if (p.col+1 < MAX_COL     // right 
		    && maze[p.row][p.col+1] == 0)
			visit(p.row, p.col+1, p);
		if (p.row+1 < MAX_ROW     // down
		    && maze[p.row+1][p.col] == 0)
			visit(p.row+1, p.col, p);
		if (p.col-1 >= 0          // left
		    && maze[p.row][p.col-1] == 0)
			visit(p.row, p.col-1, p);
		if (p.row-1 >= 0          // up 
		    && maze[p.row-1][p.col] == 0)
			visit(p.row-1, p.col, p);
		print_maze();
	}
	if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
		route_end_to_start[0] = p;
		while (predecessor[p.row][p.col].row != -1) {
			p = predecessor[p.row][p.col];
			route_end_to_start[num++] = p;
		}
        int i;
        for(i = num - 1; i >= 0; i--)
            printf("(%d, %d)\n", route_end_to_start[i].row, route_end_to_start[i].col);     // 正序输出
	} else
		printf("No path!\n");

	return 0;
}

*/

/*12.3.2
本节程序中predecessor这个数据结构占用的存储空间太多了，
改变它的存储方式可以节省空间，想想该怎么改？
优化后倒序打印路线：
#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

// 将predecessor定义成具有MAX_ROW * MAX_COL个元素的一维数组
// 数组的下标为移动后的位置，下标对应存储的内容为移动前的位置
// 将行和列转换成一个数字，之后在打印行和列时再根据这个数字转换回去
// 例：移动前的位置是“第2行第2列”，移动后的位置是“第2行第3列”
// 则以2 * MAX_COL + 3 = 13作为predecessor的下标
// 以2 * MAX_COL + 2 = 12作为predecessor的下标存储内容
// 转换成行数只需“除以MAX_COL”；转换成列数只需“取余MAX_COL”

struct point { int row, col; } stack[512];
int predecessor[MAX_ROW * MAX_COL];             
int top = 0;                                    

void push(struct point p)                       
{
	stack[top++] = p;
}

struct point pop(void)
{
	return stack[--top];
}

int is_empty(void)
{
	return top == 0;
}

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

void print_maze(void)
{
	int i, j;
	for (i = 0; i < MAX_ROW; i++) {
		for (j = 0; j < MAX_COL; j++)
			printf("%d ", maze[i][j]);
		putchar('\n');
	}
	printf("*********\n");
}

void visit(int row, int col, struct point pre)
{
	struct point visit_point = { row, col };
	maze[row][col] = 2;
	predecessor[row * MAX_COL + col] = pre.row * MAX_COL + pre.col;
	push(visit_point);
}

int main(void)
{
	struct point p = { 0, 0 };

	maze[p.row][p.col] = 2;
	push(p);	
	
    int i;
    for(i = 0; i < MAX_ROW * MAX_COL; i++)
        predecessor[i] = -1;                    // predecessor数组初始化

	while (!is_empty()) {
		p = pop();
		if (p.row == MAX_ROW - 1  // goal
		    && p.col == MAX_COL - 1)
			break;
		if (p.col+1 < MAX_COL     // right 
		    && maze[p.row][p.col+1] == 0)
			visit(p.row, p.col+1, p);
		if (p.row+1 < MAX_ROW     // down 
		    && maze[p.row+1][p.col] == 0)
			visit(p.row+1, p.col, p);
		if (p.col-1 >= 0          // left 
		    && maze[p.row][p.col-1] == 0)
			visit(p.row, p.col-1, p);
		if (p.row-1 >= 0          // up 
		    && maze[p.row-1][p.col] == 0)
			visit(p.row-1, p.col, p);
		print_maze();
	}
	if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
		printf("(%d, %d)\n", p.row, p.col);
		while(p.row != 0 || p.col != 0){        // 注意，循环的判断条件是当p的行和列不同时为0，如果同时为0则退出循环，打印完成
			int p_row_trans = p.row;            // 注意，需要使用中间变量保护，如果不使用，则下面的代码在更新p.row的值后，在更新p.col的值时会发生错误，因为p.row的值已经被更新，不再是原本的值
            int p_col_trans = p.col;            // 注意，需要使用中间变量保护
            p.row = predecessor[p_row_trans * MAX_COL + p_col_trans] / MAX_COL;
            p.col = predecessor[p_row_trans * MAX_COL + p_col_trans] % MAX_COL;
			printf("(%d, %d)\n", p.row, p.col);
        }
	} else
		printf("No path!\n");

	return 0;
}

优化后正序打印路线：
#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

struct point { int row, col; } stack[512];
int predecessor[MAX_ROW * MAX_COL];
int route_end_to_start[MAX_ROW * MAX_COL];      // 存储数组
int top = 0;

void push(struct point p)
{
	stack[top++] = p;
}

struct point pop(void)
{
	return stack[--top];
}

int is_empty(void)
{
	return top == 0;
}

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

void print_maze(void)
{
	int i, j;
	for (i = 0; i < MAX_ROW; i++) {
		for (j = 0; j < MAX_COL; j++)
			printf("%d ", maze[i][j]);
		putchar('\n');
	}
	printf("*********\n");
}

void visit(int row, int col, struct point pre)
{
	struct point visit_point = { row, col };
	maze[row][col] = 2;
	predecessor[row * MAX_COL + col] = pre.row * MAX_COL + pre.col;
	push(visit_point);
}

int main(void)
{
	struct point p = { 0, 0 };
    int num = 1;

	maze[p.row][p.col] = 2;
	push(p);	
	
    int i;
    for(i = 0; i < MAX_ROW * MAX_COL; i++)
        predecessor[i] = -1;                    // predecessor数组初始化

	while (!is_empty()) {
		p = pop();
		if (p.row == MAX_ROW - 1  // goal
		    && p.col == MAX_COL - 1)
			break;
		if (p.col+1 < MAX_COL     // right 
		    && maze[p.row][p.col+1] == 0)
			visit(p.row, p.col+1, p);
		if (p.row+1 < MAX_ROW     // down 
		    && maze[p.row+1][p.col] == 0)
			visit(p.row+1, p.col, p);
		if (p.col-1 >= 0          // left 
		    && maze[p.row][p.col-1] == 0)
			visit(p.row, p.col-1, p);
		if (p.row-1 >= 0          // up 
		    && maze[p.row-1][p.col] == 0)
			visit(p.row-1, p.col, p);
		print_maze();
	}
	if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
		route_end_to_start[0] = p.row * MAX_COL + p.col;
		while(p.row != 0 || p.col != 0){
			int p_row_trans = p.row;
            int p_col_trans = p.col;
            p.row = predecessor[p_row_trans * MAX_COL + p_col_trans] / MAX_COL;
            p.col = predecessor[p_row_trans * MAX_COL + p_col_trans] % MAX_COL;
			route_end_to_start[num++] = p.row * MAX_COL + p.col;        // 将更新后的行和列转换成数字进行存储
        }
        for(i = num - 1; i >= 0; i--)
            printf("(%d, %d)\n", route_end_to_start[i] / MAX_COL, route_end_to_start[i] % MAX_COL);     // 正序输出
	} else
		printf("No path!\n");

	return 0;
}

*/

/*12.3.3
上一节我们实现了一个基于堆栈的程序，然后改写成递归程序，
用函数调用的栈帧替代自己实现的堆栈。本节的DFS算法也是基于堆栈的，
请把它改写成递归程序，这样改写可以避免使用predecessor数据结构，想想该怎么做。
深度优先搜索的递归实现：
#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

struct point { int row, col; };
int record[512];                        // 实时路径记录数组
int flag = 0;                           // 走到终点标志                

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 1, 0, 0,
};

void explore(int row, int col, int step)            // 走访函数
{
    struct point p = { row, col };                  

	maze[p.row][p.col] = 2;                         // 每次走访一个坐标，就对这个坐标标注为2，防止走访混乱
	record[step++] = p.row * MAX_COL + p.col;       // 记录这个坐标，之后step递增，为递归调用做准备

    if(p.row == 4 && p.col == 4)                    // 如果走到终点了，更新标志并跳出函数
    {
        flag = 1;
        return;
    }

	if(p.col+1 < MAX_COL                            // right
		&& maze[p.row][p.col+1] == 0)
	{	
        explore(p.row, p.col+1, step);              // 发现可以向右移动，则递归
        if(flag == 1)                               // 跳出函数后，只要标志不为1就继续尝试其他方向
            return;                                 // 发现标志为1就跳出函数，不需要再尝试其他方向
    }
	if(p.row+1 < MAX_ROW                            // down
		&& maze[p.row+1][p.col] == 0)
	{	
        explore(p.row+1, p.col, step);
        if(flag == 1)
            return;
    }
	if(p.col-1 >= 0                                 // left 
		&& maze[p.row][p.col-1] == 0)
    {
        explore(p.row, p.col-1, step);
        if(flag == 1)
            return;
    }
	if(p.row-1 >= 0                                 // up 
		&& maze[p.row-1][p.col] == 0)
	{
        explore(p.row-1, p.col, step);
        if(flag == 1)
            return;
    }

    if(flag == 0)                                   // 尝试尽所有方向后（走到死路），检查标志，如果标志为0，说明尚未找到通往终点的路线
    {                                               // 那么此时进行回溯，将作出改动的部分还原：还原位置标注、还原位置记录，之后跳出函数继续尝试
        maze[p.row][p.col] = 0;                     // 如果标志为1，则已经找到通往终点的路线，不执行回溯操作
        record[--step] = -1;
        return;
    }
}

int main(void)
{
	int i;
    for(i = 0; i < 512; i++)
        record[i] = -1;
    explore(0, 0, 0);
    int j;
    for(j = 0; record[j] != -1; j++)            // 如果根本没有通往重点的路线，则explore函数会不断回溯，record数组中均为无效记录，不会打印任何数据
        printf("(%d, %d)\n", record[j] / MAX_COL, record[j] % MAX_COL);
	return 0;
}

*/

/*12.4.1
本节的例子直接在队列元素中加一个指针成员表示前趋，
想一想为什么上一节的例12.3“用深度优先搜索解迷宫问题”不能采用这种方法表示前趋？
答：
这是因为前趋指针所指的那块内存，在深度优先搜索（DFS）的“栈”弹出后可能被覆盖，
导致指针悬垂，因此必须创建全局前趋存储数组，避免这种情况；
而在广度优先搜索（BFS）的“队列”（线性队列）中，被弹出后的内存依然稳定有效，
因此不需要创建全局前趋存储数组，只需要在队列元素中加一个指针成员表示前趋。
*/

/*12.4.2
本节例子中给队列分配的存储空间是512个元素，其实没必要这么多，
那么解决这个问题至少要分配多少个元素的队列空间呢？跟什么因素有关？
答：
线性队列至少需要分配18个队列空间，这与迷宫的可行格子数目有关。
*/

/*12.5.1
现在把迷宫问题的要求改一下，只要求程序给出最后结论就可以了，
回答“有路能到达终点”或者“没有路能到达终点”，而不需要把路径打印出来。
请把例 12.4 “用广度优先搜索解迷宫问题”改用环形队列实现，
然后试验一下解决这个问题至少需要分配多少个元素的队列空间。
答：
循环队列的长度是由迷宫的拓扑结构决定的，具体来说是每个节点的最大层数。
#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5
#define MAX_QUEUE 5             // 这个循环队列的长度至少需要为5

struct point { int row, col; } queue[MAX_QUEUE];
int head = 0, tail = 0;

void enqueue(struct point p)
{
	if(tail == MAX_QUEUE)       // tail到达队列终点时再次回到队列起点开始入队
        tail = 0;
    queue[tail++] = p;
}

struct point dequeue(void)
{
	if(head == MAX_QUEUE)       // head到达队列终点时再次回到队列起点开始出队
        head = 0;
    return queue[head++];
}

int is_empty(void)
{
	return head == tail;
}

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

void print_maze(void)
{
	int i, j;
	for (i = 0; i < MAX_ROW; i++) {
		for (j = 0; j < MAX_COL; j++)
			printf("%d ", maze[i][j]);
		putchar('\n');
	}
	printf("*********\n");
}

void visit(int row, int col)
{
	struct point visit_point = { row, col };
	maze[row][col] = 2;
	enqueue(visit_point);
}

int main(void)
{
	struct point p = { 0, 0 };

	maze[p.row][p.col] = 2;
	enqueue(p);
	
	while (!is_empty()) {
		p = dequeue();
		if (p.row == MAX_ROW - 1  // goal 
		    && p.col == MAX_COL - 1)
			break;
		if (p.col+1 < MAX_COL     // right 
		    && maze[p.row][p.col+1] == 0)
			visit(p.row, p.col+1);
		if (p.row+1 < MAX_ROW     // down 
		    && maze[p.row+1][p.col] == 0)
			visit(p.row+1, p.col);
		if (p.col-1 >= 0          // left 
		    && maze[p.row][p.col-1] == 0)
			visit(p.row, p.col-1);
		if (p.row-1 >= 0          // up 
		    && maze[p.row-1][p.col] == 0)
			visit(p.row-1, p.col);
		print_maze();
	}
	if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1)
		printf("Path existing!\n");
	else
		printf("No path existing!\n");

	return 0;
}

*/
