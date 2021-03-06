
作業上傳「線上課程系統」平台 http://140.124.181.3/exam/Login

助教時間：星期三 18：10～19：30，科技大樓 1223。
助教：呂紹清 paul789012@gmail.com、許聖泉。

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

一、程式作業繳交注意事項
1. 作業遲交不計分。
2. 程式碼有抄襲者，任何一次抄襲，學期成績不及格。

二、程式作業撰寫規則，違反規則該次作業不予計分
1. 程式碼不得使用全域變數，亦即，宣告在 main外面的變數！
2. 程式碼不得使用 goto 指令。
3. 程式碼不得使用 system("pause") 功能。
4. 程式碼不得使用 非 C 語言的功能，如 C++ for (int i=0; i<x, i++) {}。
5. 作業上傳請繳交.c 檔，不得繳交 .cdp .zip .rar .7z .exe等不合法檔案！ 

三、課程注意事項
1. 跟助教、卓越小老師預約課後輔導時間，請準時，學校會派人來簽到。
2. 作業要跟助教討論除錯問題，請跟助教約時間，當面討論比較有效果。
3. 作業等相關問題可寄至助教信箱詢問。
4. 下列網站提供很好的查詢資源請同學使用。
    http://www.cplusplus.com/reference/clibrary/

============================================================================================

Week 1

001. 計算總成績、平均

某一學生修國文、計算機概論、計算機程式設計三科，使用者輸入名字（一個char）、學號（int）、三科成績(int)。
(1) 計算學生總成績、平均。
(2) 印出名字、學號、總成績、平均。

Input

K
905067
100
100
100

Output

Name:K
Id:905067
Total:300
Average:100

============================================================================================

Week 1

002. 一元二次方程式

一元二次方程式，aX^2 + bx + c = 0，輸入a, b, c, 求 方程式的兩個實根。


-------------
輸入說明

第一個數 a
第二個數 b
第三個數 c

---------------
輸出說明

第一個實根， x1 = ((-b)+sqrt(b*b-4*a*c))/(2*a)
第二個實根， x2 = ((-b)-sqrt(b*b-4*a*c))/(2*a)

須 #include <math.h>
x1, x2 輸出到小數點第一位  printf("%.1f",x1);

---------------
Input
1
-2
1

Output
1.0
1.0

------------------------------------------------------------------------

Week 1

003. 數值運算

分別輸入 num1 num2 求出兩數的 Sum,Difference,Product,Quotient。

Difference結果取絕對值，使用 double fabs(double);

須 #include <math.h>

結果須輸出到小數點第二位  printf("%.2f",x1);

輸入: 
25 
2 

輸出:
Sum:27.00
Difference:23.00
Product:50.00
Quotient:12.50

=====================================================================================
Week 2

004 判斷何種三角形

當三個邊長能構成三角形時，再判斷該三角形是否為正三角形，若否，則判斷是否為等腰三角形：
1. 不能成為三角形：任兩邊和不大於第三邊，或任一邊長不大於 0。
2. 正三角形：三個邊相等。
3. 等腰三角形：任兩邊相等，平方和大於第三邊的平方。
4. 一般三角形：非正三角形與等腰三角形。

此題必須寫一個運算的function
int getTriangle(int a, int b, int c);


輸入說明
----------------
輸入三個整數


輸出說明
---------------
1. 不能成為三角形：輸出 1。
2. 正三角形：輸出 2。
3. 等腰三角形：輸出 3。
4. 一般三角形：輸出 4。


測試案例(Test Case)資料：

input
4 1 1

output
1
-------------------
input
3 3 3

output
2
-------------------
input
3 2 3

output
3

-------------------
input
7 8 9

output
4

====================================================================================

Week 2

005

請輸入五個數字，分別計算出平均數、變異數、標準差，
並精確到小數點後第二位(註，之後的小數捨去)。


平均數參考公式
μ=Σ(Xi)/N
變異數參考公式
Σ(Xi-μ)^2/N
標準差參考公式
(Σ(Xi-μ)^2/N)^(0.5)


例如：1 2 8 9 10
平均值:6.00  (1+2+8+9+10)/5.0 = 6.00
變異數:14.00 Σ(Xi-μ)^2=(1-6)^2+(2-6)^2+(8-6)^2+(9-6)^2+(10-6)^2
                        =25+16+4+9+16=70 
             700./5.0=14.00
標準差14^(0.5) = 3.74165 
               取兩位小數 = 3.74


輸入說明
----------------
輸入五個整數


輸出說明
---------------
平均值
變異數
標準差


輸出到小數點第二位  printf("%.2f",x);



測試案例(Test Case)資料：

input
1 2  8 9 10

output
6.00
14.00
3.74
-------------------
============================================================================================

Week 2

006. 一元二次方程式

一元二次方程式，aX^2 + bx + c = 0，輸入a, b, c, 求 方程式的兩個實/虛根。
T = sqrt(b*b-4*a*c)
第一個根， x1 = (-b+T)/(2*a)
第二個根， x2 = (-b-T)/(2*a)

本題須 #include <math.h>。

--------------------------
輸入說明

第一個數 a
第二個數 b
第三個數 c

--------------------------
輸出說明

當 T>=0
輸出x1, x2為實根，輸出到小數點第一位  printf("%.1f",x1);

當 T<0
輸出x1 , x2為虛根，輸出到小數點第一位  
printf("%.1f+%.1fi",x11, x12);
printf("%.1f-%.1fi",x21, x22);

---------------
Input
1
-2
1

Output
1.0
1.0


---------------
Input
1
2
2

Output
-1.0+1.0i
-1.0-1.0i

========================================================================================================

Week 2

007

A、B、C三本書價格及折扣表如下：      
       定價   1~10本   11~20本   21~30本   31本以上      
A      380    原價     打9折     打8.5折   打8折      
B      1200   原價     打9.5折   打8.5折   打8折      
C      180    原價     打8.5折   打8  折   打7折      
有一顧客欲購買A:ｘ本、B:ｙ本、C:ｚ本（ｘ、ｙ、ｚ為使用者輸入），請計算需花費多少錢？

例如: 
A購買6本 B購買12本 C購買30本 
6*380+12*1200*0.95+30*180*0.8 
=20280 

輸入說明: 
------------
A書本數量，整數
B書本數量，整數
C書本數量，整數


輸出說明: 
-------------
費用，整數
printf("%d", x);


input
6 
12 
30 


output
20280

==========================================================================================
Week 3

008. 最佳資費選擇


輸入每月網內、網外、市話、通話時間(秒)及網內、網外簡訊則數，求最佳資費。

費率如下表:

資費類型        183型     383型     983型  
月租費          183元     383元     983元  
優惠內容        月 租 費 可 抵 等 額 通 信 費
語音費率 網內   0.08      0.07      0.06
(元/秒)  網外   0.139     0.130     0.108
市話            0.135     0.121     0.101
(元/秒)
簡訊費率 網內   1.128     1.128     1.128
(元/則)  網外   1.483     1.483     1.483

---------------------------------
輸入說明
---------------
網內語音(秒)，整數
網外語音(秒)，整數
市話    (秒)，整數
網內簡訊數，整數
網內簡訊數，整數

---------------------------------
輸入說明
---------------------------------
最佳資費類型，(183, 383, 983)
最佳資費，整數


---------------------------------
測試資料：(Test Case)

input
120
150
20
10
5

output
183
183


input
3000
4000
200
5
5

output
383
767

=========================================================================================

Week 3

009 判斷何種三角形

當三個邊長能夠構成三角形時，再判斷該三角形為鈍角、銳角或是直角三角形，其判別方法如下：
1. 直角三角形：其中有兩個邊的平方和等於第三邊的平方。
2. 鈍角三角形：其中有兩個邊的平方和小於第三邊的平方。
3. 銳角三角形：任兩邊的平方和大於第三邊的平方。
輸入三個整數

輸出：顯示直角三角形(Right Triangle)、鈍角三角形(Obtuse Triangle)、
銳角三角形(Acute Triangle)或無法構成三角形(Not Triangle)。

此題必須寫一個運算的function

int compute(int a, int b, int c);
a, b, b 為三角形三個邊
回傳值
0:Not Triangle
1:Right Triangle
2:Obtuse Triangle
3:Acute Triangle

測試資料：

input
5 12 13

output
Right Triangle

input
5 3 4

output
Right Triangle

input
1 2 3

output
Not Triangle

================================================================================================

Week 3

010.


請檢查輸入的三門課程是否衝堂。

依序輸入
課程編號 (4位數字)、
上課小時數 (1-2小時)、
上課時間 (依小時數輸入上課時間, 星期1-5, 第1-8節)。

輸入任何錯誤，輸出 -1。

---------------------------------
輸入說明
---------------------------------
1002 (第一門課課程編號)
2    (2 小時)
33   (星期 3 第 3 節課)
59   (星期 5 第 9 節課)
1003 (第二門課課程編號)
2    (2 小時)
11   (星期 1 第 1 節課)
33   (星期 3 第 3 節課)
3003 (第三門課課程編號)
2    (2 小時)
11   (星期 1 第 1 節課)
33   (星期 3 第 3 節課)

(上課時間輸入順序為星期 1~5，第 1 節 ~ 第 8 節)
(課程編號輸入順序為編號大小)
---------------------------------
輸出說明
---------------------------------
1002,1003,33
1002,3003,33
1003,3003,11
1003,3003,33

輸出 - 課程編號,課程編號,衝突時間

若沒有衝突則輸出 correct

若有錯誤輸入則輸出 -1

(每次列出兩個衝突課程編號，一個衝突時間，所有倆倆課程衝突均要列出)
(衝突輸出順序，課程 1-2, 1-3, 2-3, 第 1 節 ~ 第 2 節)


---------------------------------
測試資料：
---------------------------------

input

1001
2
12
13
1002
2
13
21
1003
2
21
25
---------
output

1001,1002,13
1002,1003,21

---------------------------------
input

1001
1
21
1002
2
32
33
1003
2
45
46
---------
output

correct


---------------------------------
input

101
3
99
1002
2
32
33
1003
2
45
46
---------
output

-1


================================================================================================

Week 4

011.

請算出a,b,c三條線在x軸上所涵蓋的長度 
例如:a(x1,x2)表示a為在x軸上x1到x2的線 

------------------ 
輸入說明: 
------------------ 
-1 (a的x1座標為 -1) 
1 (a的x2座標為 1) 
0 (b的x1座標為 0) 
2 (b的x2座標為 2) 
1 (c的x1座標為 1) 
3 (c的x2座標為 3) 
---------------- 
輸出說明: 
---------------- 
4


================================================================================================

Week 4

013.

小明到保齡球館打保齡球，一輪有十局，假設小明一到八局都拿零分，剩下最後兩局 
每局有十瓶保齡球瓶，倒一瓶保齡瓶得一分，每一局最多為十分， 
每一局可以打兩次，若在第十局打出strike，可以再多打一局，但當局只能打一次，試算出總得分 
------------------ 
輸入說明: 
------------------ 
2 
5 
7 
1 
---------------- 
輸出說明: 
---------------- 
15



================================================================================================

Week 5

014. 

數線上有n條線段，n小於10 
L1(X11,X12)、L2(X21,X22)、...、Ln(Xn1,Xn2)，Xn1表示線段n起點(整數)，Xn2表示線段n終點(整數) 
計算這n條線段覆蓋的長度總和，重疊的區段只計算1次 

例如:線段L1(1,3)、線段L2(2,4)、線段L3(5,6) 
覆蓋的長度總和= (A的長度2) + (B的長度2) - (A和B重疊1) + (C的長度1) 

------------------ 
輸入說明: 
------------------ 
輸入2n+1個整數，分別為 
線段數量n 
L1的x11座標 
L1的x12座標 
L2的x21座標 
L2的x22座標 
L3的x31座標 
L3的x32座標 
------------------ 
3 
-1 
1 
0 
2 
1 
3 
---------------- 

輸出說明: 
覆蓋的長度總和，整數 
printf("%d", x); 
---------------- 
4 

---------------- 
測試資料: 
---------------- 
input 

3 
-2 
-1 
-2 
-1 
-1 
0 
------------- 
output 

2 


================================================================================================

Week 5

015. 

小明到保齡球館打保齡球，保齡球規則如下 

1.每局有十瓶保齡球瓶，倒一瓶保齡瓶得一分，全倒表示十個瓶子都被打倒 
2.每一局最多為十分，每一局最多可打兩次 
3.1-9局時，一局內一次全倒稱為strike，可額外多加計後兩球分數 
4.1-9局時，一局內兩次才全倒稱為spare，可額外多加計後一球分數 
5.若在第10局打出strike，可以再多打兩球算分數 
6.若在第10局打出spare，可以再多打一球算分數 
7.僅有1-9局strike或spare可額外多加計後兩球或一球分數，第10局則否 
8.計分板總共有21格，1-9局各有2格，第10局有3格 

輸入1-10局所有球分數，試算出總得分 。 
------------------ 
輸入說明: 
------------------ 
輸入21個整數，除第十局有3格分數，其餘每局2格分數 
------------------ 
10 
0 
9 
1 
10 
0 
7 
3 
10 
0 
2 
8 
10 
0 
5 
5 
10 
0 
1 
9 
10 
---------------- 
輸出說明: 
分數總和，整數 
printf("%d", x); 
---------------- 
200 

---------------- 
測試資料: 
---------------- 
input: 

5 
5 
8 
2 
6 
4 
7 
3 
7 
3 
9 
1 
5 
5 
8 
2 
9 
1 
9 
1 
10 
---------------- 
output: 

178

================================================================================================

Week 6

016. 

輸入第一個整數，決定輸出圖形種類， 
1 三角形方尖方面向右邊 
2 三角形方尖方面向左邊 

輸入第二個整數，決定輸出的行數。 
(奇數，範圍為 3,5,7,9,....,21) 
若三角形方尖方面向左邊，則空白以「.」輸出。 

三角形本身每行以數字表示 
若是第1種則由左而右遞增(例如1234) 
若是第2種則由左而右遞減(例如4321) 
------------------ 

輸入說明: 
------------------ 
輸入兩個整數a和b 
第一個整數a=1,2 
第二個整數b=奇數，範圍為 3,5,7,9,....,21 
------------------ 
2 (第二種圖形，三角形尖方面向左邊) 
5 (共 5 行) 
------------------ 

輸出說明: 
------------------ 
將三角形畫出 
若三角形方尖方面向左邊，則空白以「.」輸出 
------------------ 
..1 
.21 
321 
.21 
..1 
---------------- 

測試資料: 
---------------- 
input 
1 
9 

output 
1 
12 
123 
1234 
12345 
1234 
123 
12 
1 
---------------------------- 
input 
2 
5 

output 
..1 
.21 
321 
.21 
..1



================================================================================================

Week 6

017. 

輸入一個整數n，決定輸出的菱形高度。 
(n=奇數，範圍為 3,5,7,9,....,21) 
菱形本身用「*」表示 
空白部分以「.」表示 
輸出的每一行「*」和「.」總數也等於n 
------------------ 

輸入說明: 
------------------ 
輸入一個整數n，n=奇數，範圍為 3,5,7,9,....,21 
---------------- 

輸出說明: 
---------------- 
根據n將菱形畫出來 
菱形本身用「*」表示 
空白部分以「.」表示 
---------------- 

測試資料: 
---------------- 
input: 
7 
---------------- 
output: 
...*... 
..***.. 
.*****. 
******* 
.*****. 
..***.. 
...*...


================================================================================================

Week 7

018. 

***請注意，double強制轉成int有時候會有問題 
***例如pow(10,2)得出100.00 
***但強制轉成int會變成99 


進位制轉換 

輸入說明：輸入指定進制數B (2<=B<=9)與十進位數N(0<=N<=10,000,000)。 
輸出說明：N經進位制B轉換後的數字，錯誤輸入則輸出-1 

input 
9 
1234 

output 
1621


-----------------------------------------------------------------------------------------------

Week 7

019. 牛頓法解方程式 (Newton's method) 

***請注意，double強制轉成int有時候會有問題 
***例如pow(10,2)得出100.00 
***但強制轉成int會變成99 

應用牛頓法解以下兩個方程式的根。 
(Apply Newton's method) to solve the two equations). 

x_(j+1) = x_j – f(x_j)/f'(x_j), (其中 f'(x) 是 f(x) 的一次微分) 

f1(x) = x^n - cx^(n-2) – d, and (n>2), ( f1'(x) = nx^(n-1) – (n-2)cx^(n-3) ) 

f2(x) = x^n - cx – d, and (n>2), ( f2'(x) = nx^(n-1) – c。 

(Hint: let x0 = d/2) 

輸入說明: 
第一個輸入 1 代表 f1，2 代表 f2。 
第二個輸入代表 n。 
第三個輸入代表 c。 
第四個輸入代表 d。 
第五個輸入代表 err，精確小數位數，例如err=6， 
即兩次疊代差小於0.000001。 
也就是說 x_(j+1) 與 x_j 相減小於 0.000001，10 的負6次方。 

輸出說明: 
一個方程式的根，顯示到小數點 err+1 位。 
亦即，若err=6，則要顯示到小數點第七位。 
使用去尾法，不需要四捨五入。 

---------------- 
Input: 
1 
4 
5 
5 
2 

Output: 
2.419

-----------------------------------------------------------------------------------------------

Week 7

020.切割面積加總法公式 

***請注意，double強制轉成int有時候會有問題 
***例如pow(10,2)得出100.00 
***但強制轉成int會變成99 

使用切割面積加總法公式， 

T = (h/2)(f(p) + f(q) + 2 Σ(i=1,n-1)f(xi)) , 

h = (q-p)/n，h 是 double。 

計算 f(x) 的面積，到小數點第五位四捨五入。 

x 值從區間起始 p 到區間終點 q 的面積， 

n 為 切割數，初始設定 n_(0)=2，每次 n_(j+1) = n_(j) + 1。 

err為精確小數位數，例如 err=6，即 n_(j+1) 和 n_(j)兩次切割， 

計算出的面積值的差小於 10 的負6次方，亦即小於 0.000001。 

f1(x) =((a-x^2))^(1/2), a 為常數。 f2(x) = (ax^3 + 7x)/(a+x)^(1/2), a 為常數。 

輸入說明： 
輸入 1 代表計算 f1(x) 面積，輸入 2 代表計算 f2(x)面積， 
接著依序，輸入 a, p, q, err，輸入0為停止輸入。 

此題測試資料為連續輸入一至多筆資料。 

--------------- 
Input: 
1,4,-2,1,9,0 

Output: 
5.05481 

HINT 

方程式可能會跑到 y<0的地方，此時要算面積，必須將y取絕對值。 

若 err=3, Area_(j+1) 跟 Area_(j)的差小於 10負3次方 
fabs(Area_(j+1)-Area_(j))*10*10*10<1 
若以整數比較會好一點 

int k=fabs(Area_(j+1)-Area_(j))*10*10*10*10; 
if (k>10) {….} 

面積差，為兩次計算出面積的差值(相減)。 
數值分析的誤差是兩次面積計算的差值除以，前一次的面積值。


================================================================================================


Week 8

021 

費氏數列 Fibonacci number 

請用迴圈撰寫。 
輸入一個整數n，輸出 Fibonacci number。 

F(1) = 1 ; F(2) = 1; 
F( n ) = F(n-1) + F(n-2) ;n > 2 

並請檢查使用者輸入是否符合規定 
不能使用遞迴和陣列 

輸入說明： 

每一組一個正整數，輸入-1結束所有輸入。 
數字代表第幾個數列的數字 1~100 
不合法的輸入則輸出Error。 

輸出說明： 

費氏數列的值。 

--------------------- 

Sample Input: 

31 
39 
-1 

Sample Output: 

1346269 
63245986 

--------------------- 

Sample Input: 

31 
1.101 
-1 

Sample Output: 

1346269 
Error 

--------------------- 

Sample Input: 

.11$ 
1.- 
31 
-1 

Sample Output: 

Error 
Error 
1346269 

-----------------------------------------------------------------------------------------------

Week 8

022

神奇寶貝進化計算器 

在pokemon go遊戲中，傳送一隻神奇寶貝給博士可以得到 1.5 公升進化藥水，每完成一隻神奇寶貝的進化也可以得到 1.5 公升進化藥水。 

現在玩家想要在最短時間內完成最多次的進化，請幫助玩家最多可以進化幾隻神奇寶貝 

已進化和未進化的神奇寶貝都可以被傳送走，傳送走該神奇寶貝即消失 

每隻神奇寶貝只能進化一次，已進化的神奇寶貝不能再進化，僅能留下來或被傳送，傳送一樣可以拿 1.5 公升進化藥水 

輸入說明 ： 

一次測試會輸入三個數字 
第一個數為神奇寶貝進化需要消耗的進化藥水 N (-100 < N < 0)，必須為負小數，顯示到小數點後一位，例如:-12.3或-99.0 
第二個數為玩家所擁有的進化藥水 C (0 ? C ? 30000)，必須為正小數，顯示到小數點後一位，例如:3255.6或553.0 
第三個數為玩家所擁有的神奇寶貝數量 W (0 ? W ? 10000)，必須為正整數，例如:5。 


不合法的輸入如下，遇到不合法輸入則輸出Error 
(1)當需輸入小數但小數格式輸入錯誤時，例如:1.-6或1.1.1 
(2)當需輸入正數，但使用者輸入負數時 
(3)當需輸入負數，但使用者輸入正數時 
(4)當需輸入小數，但使用者輸入的小數，小數點後超過一位，例如:-1.6667 
(5)當需輸入整數，但使用者輸入小數時 


輸出說明 ： 
輸出進化次數。 

--------------------- 

範例輸入1： 
-12.3 22.5 5 

範例輸出: 
2 

--------------------- 

範例輸入2： 
%56 22.5 5 

範例輸出: 
Error 

--------------------- 

範例輸入3： 
-12.3 -22.5 5 

範例輸出: 
Error 

--------------------- 

範例輸入1說明： 
1. 先進化1隻神奇寶貝，用掉 12.3 公升進化藥水，進化後再得1.5公升進化藥水，剩 11.7 公升進化藥水和 4 隻未進化神奇寶貝和 1 隻已進化神奇寶貝。 

2. 把 1 隻已進化神奇寶貝傳送給博士換取 1.5 公升進化藥水，剩 13.2 公升進化藥水和 4 隻未進化神奇寶貝。 

3. 再進化 1 隻神奇寶貝，得1.5公升進化藥水，最後剩 2.4 公升進化藥水及 3 隻未進化神奇寶貝和 1 隻已進化神奇寶貝。 

4. 因為剩下的 4 隻神奇寶貝即使傳送給博士，得到的進化藥水也不夠進化的量，所以總共只能進化2次。

================================================================================================

Week 9

023

最大質數

輸入一個數 x ，根據以下規則得到 k ，並找出 2 到 k 之間最大的質數。
處理輸入請使用有限狀態機，不要使用陣列

規則:
1. 若 x 為正整數，且 2 <= x <= 1000，則 k = x
2. 若 x = 0 或 x = 1，則 k = 1000
3. 若 x 為負整數，則 k = x * -11
4. 若 x 為正小數，則 k = 小數點前面的數
5. 若 x 為負小數，則 k = 小數點後面的數
6. 若 x 不包含在以上 5 種規則，則為錯誤輸入，程式輸出error

規則範例:
1. x = 50， k = 50
2. x = 0， k = 1000
3. x = -90， k = 990
4. x = 66.22， k = 66
5. x = -33.44， k = 44
6. 錯誤輸入的類型包含以下例子，直接輸出error
%1.1
.11$
011
001.1
1.-
1%.1
1.1.1
-001.1
-0-0.256
-1.3-1
-0.1.1
-0.e
2.
00000
0.3-
0.23$
1..7
-$23.5
$2235
$.1
00.1
-0.
0.
-0
123456789123456789

-----------------------------------------

輸入說明： 
輸入一個數字。

輸出說明： 
根據規則找出 k ，輸出 2 到 k 之間最大的質數。

-----------------------------------------
輸入範例:
50

輸出範例:
47
-----------------------------------------
輸入範例:
0

輸出範例:
997
-----------------------------------------
輸入範例:
-90

輸出範例:
983
-----------------------------------------
輸入範例:
66.22

輸出範例:
61
-----------------------------------------
輸入範例:
-33.44

輸出範例:
43
-----------------------------------------




================================================================================================

Week 10

024.方程式計算 

(此題不使用陣列) 

寫一個 function 輸入 XY 座標系統的兩個座標 (x1, y1), (x2, y2)； 
輸出兩個座標經過的 XY 方程式 y=mx+b; 

m=(y1-y2)/(x1-x2) 
b=(x2y1-x1y2)/(x2-x1) 
void f1(int x1, int y1, int x2, int y2, double *m, double *b); 

寫一個 function 輸入 XY 座標系統的兩個座標 (x1, y1), (x2, y2)； 
輸出兩個座標經過的 XY 方程式 y=m1/m2x+b1/b2; 

m1=(y1-y2), m2=(x1-x2), 
b1=(x2y1-x1y2), b2=(x2-x1), 
void f2(int x1, int y1, int x2, int y2, int *m1, int *m2, int *b1, int *b2); 

------------- 
輸入說明: 
XY的兩個座標 x1, y1, x2, y2，均為整數。 

輸出說明: 
(1) y=mx+b, 
m, b 計算至小數第二位。 

(2) y=mx+b 
m, b 以分數表達。 

=>方程式有可能沒有 x 項，或沒有 y 項。 
=>沒有 x 項則 y=b，沒有 y 項則 x = -b/m。 
=>若m,b為整數，則使用整數表達。 

------------- 
輸入範例: 
3 4 -3 0 

輸出範例: 
y=0.67x+2 
y=2/3x+2

-------------------------------------------------------

025 
求最大周長和面積 

寫一個 function 輸入 N 組矩形 XY 座標中的兩個點，輸出 N 組矩形中的最大的周長和最大的面積。 

程式中必須使用以下 function 定義，計算一個矩形的周長與面積。 

--------------------------------------- 
void compute(int x1, int y1, int x2, int y2, int *perimeter, int *area); 

第一個點 (x1, y1) 
第二個點 (x2, y2) 
計算周長結果 *perimeter 
計算面積結果 *area 

輸入幾組矩形的兩個點，輸入-1停止輸入。 
輸出最大的面積和最大的周長。 

------------------ 
輸入說明： 

分別輸入幾組矩形的兩個點， 
第一筆輸入第一個矩形兩個點，x1, y1, x2, y2， 

換行再輸入第一個矩形兩個點，直到輸入 -1 停止。 

輸出說明： 

輸出所有矩形中最大的面積和最大的周長。 

--------------------- 
輸入範例: 
-10 -10 20 60 
52 52 2 2 
85 8 5 38 
-1 

輸出範例: 
2500 
220

-----------------------------------------------------------------------------------

026 
分數計算 

(此題不使用陣列，必須使用指標) 

程式碼必須使用以下 function 定義，計算兩個分數的相加。 

void add(int n1, int d1, int n2, int d2, int *numerator, int *denominator); 

n1: 第一個數的分子 
n1: 第一個數的分母 
n1: 第二個數的分子 
n1: 第二個數的分母 
*numerator: 相加結果的分子 
*deniminator: 相加結果的分母 

程式碼必須使用以下 function 定義，計算兩個分數的相乘。 

void mul(); 

int multiply(int n1, int d1, int n2, int d2, int *numerator, int *denominator); 

n1: 第一個數的分子 
n1: 第一個數的分母 
n1: 第二個數的分子 
n1: 第二個數的分母 
*numerator: 相乘結果的分子 
*deniminator: 相乘結果的分母 

-------------------- 

輸入說明: 

輸入二行，每一行代表一個分數 

---------------- 
輸出說明: 

輸出分數相加結果 
輸出分數相乘結果 

若有輸入分數的分母或分子為0，則輸出ERROR。 
若分數大於1，則分數部分要加括號。 
若為負數，負號在最前面。 

---------------- 
範例輸入: 
1/2 
2/3 

範例輸出: 
1(1/6) 
1/3 

---------------- 
範例輸入: 
0/2 
2/3 

範例輸出: 
ERROR 
ERROR

================================================================================================

Week 11

027.整數的交集聯集

請設計程式，利用兩個一維整數陣列儲存兩個正整數集合 A, B ，
兩個集合 A, B 的陣列大小為 20，正整數 1~100；
程式功能為：
(1) 新增集合元素：輸入一集合與一正整數，若新增的元素與該集合內元素有重複，
則無法新增。
(2) 刪除集合元素：輸入一集合與一正整數，若集合中無該元素，無法刪除。
(3) 計算集合是否空集合。
(4) 計算兩個集合的交集。
(5) 計算兩個集合的聯集。
(6) 計算集合是否為另一個集合的子集合。

------------------------------ 
輸入說明:

每一行第一數字輸入整數指令選項，意義如下:
0: 結束exit 
1: 清空 A，輸出 A 和 B 的內容。
2: 清空 B，輸出 A 和 B 的內容。
3: 新增元素到 A，後面接一個正整數為要插入的元素，
輸出 A 和 B 的內容。
4: 新增元素到 B，後面接一個正整數為要新增的元素，
輸出 A 和 B 的內容。
5: 從 A 刪除一個元素，後面接一個正整數為要刪除的元素，
輸出 A 和 B 的內容。
6: 從 B 刪除一個元素，後面接一個正整數為要刪除的元素。
輸出 A 和 B 的內容。
7: 輸出 A, B 聯集。
8: 輸出 A, B 交集。
9: 輸出 A 是否為 B 的子集合，若是則輸出 1 ，否則輸出 0。


輸出說明:

輸出集合格式
集合名稱:[集合元素,集合元素,...]，中間沒有空白，
元素順序依照輸入先後順序。
交集與聯集的元素順序，先以A的元素順序再以B的元素順序。
每一指令輸出一行。


---------------- 
輸入範例: 
3 4
3 7
4 8
4 9
5 4
6 8
3 8
7
8
9
0

輸出範例: 
A:[4,]B:[]
A:[4,7,]B:[]
A:[4,7,]B:[8,]
A:[4,7,]B:[8,9,]
A:[7,]B:[8,9,] 
A:[7,]B:[9,]
A:[7,8,]B:[9,]
[7,8,9,]
[]
0

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
028. 撲克牌

撲克牌四種花色分別是黑桃、紅心、磚塊、梅花，定義 0~3。

撲克牌數字1~13，與四種花色共有52張牌。

編碼規則為數字+花色，例如 10 表示黑桃 A、72 表示磚塊 7，123 表示梅花 3。


撲克牌遊戲把單一張牌命名為單張，沒有任何花色牌型，編號 0。

兩張數字一樣的命名為 Pair，編號 1。

2 組 pair 的牌稱為 Two pair，編號 2。

三張一樣的稱為 Three of a Kind，編號 3。

Three of a Kind 加一個 Pair 稱為 Full House，編號 4。

四張一樣稱為 Four Of A Kind，編號 5。

數字連續的5張牌稱為 Straight，包括 13 ,1, 2, 3, 4也是，編號 6。

數字連續的5張且花色一樣稱為 Straight Flush，編號 7。



輸入5張撲克牌，判斷哪一類型的牌形編號(1~7)。

程式必須有以下function。

void judge(int data[], int *r);

data[0]~data[4]為輸入 5 張撲克牌，r 為哪一類型的牌形編號(1~7)。


輸入說明 ：

第一列輸入為5個整數分別由空格分開，表示5張撲克牌。

輸出說明 ：

輸出為一個1~7的整數，代表牌型編號，以指標變數傳出。

---------------------- 
輸入範例

90 82 83 81 92

輸出範例

4

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
029.多項式相加減 

讓使用者輸入兩個一元多項式,程式輸出相加減乘的結果 

一元多項式 就是只有一個變數(例如x)的多項式 最高次方不限 不一定所有次方項都會出現 
各項的: 係數都當作整數(可正可負) 和 次方數都當作正整數 即可 
多項式加法 就是將兩個多項式中 變數的次方相同的項的係數相加 
多項式減法 就是將兩個多項式中 變數的次方相同的項的係數相減 
多項式乘法 就是將兩個多項式中 每一個項數與另一個多項式的每一個項數相乘 
使用者依序(高次項->低次項)輸入各項 
係數為0(不出現)的項目當然不需輸入 
輸出時請依序(高次項->低次項)輸出各項，係數為零者不需輸出，係數為一者請省略1直接輸出未知數(EX: X,X^2等) 
多項式的各項與運算符號請用空白隔開如輸出範例 

例如： 
2乘以(x的3次方) 寫作 2x^3 
x的1次方 寫作 x 

則 
4x^3 - 2x + 3 <-最高項為3次方項 
+) -2x^5 - x^3 + 3x^2 - x - 1 <-最高項為5次方項 
________________________________________ 
-2x^5 + 3x^3 + 3x^2 - 3x + 2 

(PS:若首項有負號,負號後不須空格,如上方例子結果的-2x^5) 
--------------- 

輸入說明： 
輸入第一行 符號 + - * 判斷多項式的運算模式 
輸入第二行 運算多項式1 (多項式的各項與運算符號請用空白隔開，0次項不顯示) 
輸入第三行 運算多項式2 (多項式的各項與運算符號請用空白隔開，0次項不顯示) 

輸出範例： 
輸出運算結果的多項式，依序(高次項->低次項)輸出各項，係數為零者不需輸出，係數為一者請省略係數直接輸出未知數(EX: X,X^2等)，多項式的各項與運算符號請用空白隔開如輸出範例 

[範例輸入] 
+ 
4x^3 - 2x + 3 
-2x^5 - x^3 + 3x^2 - x - 1 

[範例輸出] 
-2x^5 + 3x^3 + 3x^2 - 3x + 2 

[範例輸出] 
- 
5x^3 + 4x^2 + 3 
3x^2 + x + 9 

[範例輸出] 
5x^3 + x^2 - x - 6 

[範例輸出] 
* 
5x + 3 
3x + 9 

[範例輸出] 
15x^2 + 54x + 27

================================================================================================

Week 12

030. 以陣列實做長整數的運算 

將長整數儲存於一維陣列，長度為60位。 
計算兩數的相加、相減、相乘。 

輸入說明: 
兩個小於60位數的數字 

輸出說明 
兩數的相加、相減、相乘結果 
------------------------------------------ 
輸入範例: 
74678186416540450856046456406565453745354346846 
42541264516146186481412634534534535674461 
輸出範例: 
74678228957804967002232937819199988279890021307 
74678143875275934709859974993930919210818672385 
3176904481932122418791481787372835129458102253511598206541415533747989064100764738100006


---------------------------------------------------------------------------------------------------
\	



Week 12

031. 以陣列實做長小數的運算 

將長小數(包含整數部位與小數部位)，整數位數不超過60位，小數位數也不超過60位。 
計算兩小數的相加、相減、相乘。 

輸入說明: 
輸入兩個小數數字 
輸入N，表示兩小數計算後結果顯示到小數點後第N位 
例如:N=15，表示2小數計算後的結果只需顯示到小數點後第15位 

輸出說明: 
輸出兩小數的相加、相減、相乘結果到小數點後第N位 
--------------------------------------------------- 
輸入範例: 
65343418641654045085604645640656546846.556486456415648646887416 
214626641264516146186481412635674461.941874911456152601406410561641 
12 
輸出範例: 
65558045282918561231791127053292221308.498361367871 
65128792000389528939418164228020872384.614611544959 
14024438471799379658526098633943699458449060884862983183352754662019100618.818644674529


-------------------------------------------------------------------------------------------------


Week 12

032.計算全班成績以及畫出長條圖 

首先先輸入全班的學號(全班人數最多90人，學號為整數)、以及每個人的CS和PG成績(成績為整數，分數最高為100分)， 


程式可以執行的功能分成7大類: 
1: 查某人成績。 
2: 查最高分。 
3: 查最低分。 
4: 查不及格。 
5: 查及格。 
6: 查前3名。 
7: 統計。 

每類又有2~3個小功能 

第1大類(透過學號查某人成績): 
1:查詢某人平均成績 
2:查詢某人CS成績 
3:查詢某人PG成績 

第2大類(查最高分): 
1:查詢最高分平均成績 
2:查詢CS最高成績 
3:查詢PG最高成績 

第3大類(查最低分): 
1:查詢最低分平均成績 
2:查詢CS最低成績 
3:查詢PG最低成績 

第4大類(查不及格):此部分需顯示學號和成績，輸出方式為學號由小到大 
1:查詢平均成績不及格 
2:查詢CS成績不及格 
3:查詢PG成績不及格 

第5大類(查及格):此部分需顯示學號和成績，輸出方式為學號由小到大 
1:查詢平均成績及格 
2:查詢CS成績及格 
3:查詢PG成績及格 

第6大類(查前3名):此部分需顯示學號和成績，輸出方式為按照名次由小到大 
1:查詢平均成績前三名 
2:查詢CS成績前三名 
3:查詢PG成績前三名 

第7大類(統計): 
1:統計全班平均成績的中位數 
2:畫出全班平均成績的長條圖 


輸入說明: 

首先先輸入全班的學號、每個人的CS和PG成績，輸入-1表示全班成績輸入完畢。 

所有的成績計算，小數部分都無條件捨去。 

接著輸入2個整數指令選項，第1個整數表示執行哪一大類，第2個整數表示要執行該大類哪一個功能: 


輸出說明: 

印出程式執行的結果 
------------------------------ 
輸入範例: 
104233555 85 96 
103233555 56 66 
102233555 38 5 
101233555 21 12 
100233555 68 76 
-1 
1 
1 
103233555 
輸出範例: 
61 
------------------------------- 
輸入範例: 
104233555 85 96 
103233555 56 66 
102233555 38 5 
101233555 21 12 
100233555 68 76 
-1 
2 
2 
輸出範例: 
85 
------------------------------- 
輸入範例: 
104233555 85 96 
103233555 56 66 
102233555 38 5 
101233555 21 12 
100233555 68 76 
-1 
3 
3 
輸出範例: 
5 
------------------------------- 
輸入範例: 
104233555 85 96 
103233555 56 66 
102233555 38 5 
101233555 21 12 
100233555 68 76 
-1 
4 
1 
輸出範例: 
101233555:16 
102233555:21 
------------------------------- 
輸入範例: 
104233555 85 96 
103233555 56 66 
102233555 38 5 
101233555 21 12 
100233555 68 76 
-1 
5 
2 
輸出範例: 
100233555:68 
104233555:85 
------------------------------- 
輸入範例: 
104233555 85 96 
103233555 56 66 
102233555 38 5 
101233555 21 12 
100233555 68 76 
-1 
6 
3 
輸出範例: 
1st:104233555 96 
2nd:100233555 76 
3rd:103233555 66 
------------------------------- 
輸入範例: 
104233555 85 96 
103233555 56 66 
102233555 38 5 
101233555 21 12 
100233555 68 76 
-1 
7 
1 
輸出範例: 
61 
------------------------------- 
輸入範例: 
104233555 85 96 
103233555 56 66 
102233555 38 5 
101233555 21 12 
100233555 68 76 
-1 
7 
2 
輸出範例: 
0-10: 
11-20:* 
21-30:* 
31-40: 
41-50: 
51-60: 
61-70:* 
71-80:* 
81-90:* 
91-100:


================================================================================================

Week 13


033.判斷N個三角形有幾個三角形相交 

讓使用者輸入N個三角形的座標,程式輸出N個三角形中有幾個三角形相交 

輸入說明: 
先輸入一個正整數N代表之後要輸入多少個三角形 
再輸入每個三角形的三個點座標 
座標都是整數 

輸出說明: 
印出有幾個三角形相交 

input: 
4 
2 2 
4 2 
4 4 
2 1 
3 1 
3 3 
3 3 
6 3 
3 7 
1 5 
7 5 
4 13 

output: 
4

-------------------------------------------------------------------------

Week 13

034.判斷N個三角形相交於幾點 

讓使用者輸入N個三角形的座標,程式輸出N個三角形中相交於幾點 
輸入說明: 
先輸入一個正整數N代表之後要輸入多少個三角形 
再輸入每個三角形的三個點座標 
座標都是整數 

輸出說明: 
印出相交於幾點 

input: 
4 
2 2 
4 2 
4 4 
2 1 
3 1 
3 3 
3 3 
6 3 
3 7 
1 5 
7 5 
4 13 

output: 
6




-------------------------------------------------------------------------

Week 13

035. 一個有括號的多項式 +, -, *,判斷括號是否有對稱，若有對稱， 
把最底層的括號的運算式與運算值印出 

輸入說明: 
輸入有括號的多項式，例如:(((2+5)+2)*3) 

輸出說明: 
若括號有對稱，印出最底層的括號的運算式與運算值 

若括號沒有對稱，則印出ERROR INPUT 

input: 
(((2+5)+2)*3) 

output: 
2+5 
7 

input: 
(((2+5)+2)*3 

output: 
ERROR INPUT



================================================================================================

Week 14

036 求N個三角形相交座標 

讓使用者輸入N個三角形的座標,程式輸出N個三角形中相交座標 
輸入說明: 
先輸入一個正整數N代表之後要輸入多少個三角形 
再輸入每個三角形的三個點座標 
座標都是整數 

輸出說明: 
印出相交的座標，座標先從x的值判斷由小到大印出 
若x值一樣，則再根據y的值判斷由小到大印出 

input: 
2 
-2 2 
-2 0 
0 2 
-3 1 
-1 1 
-3 2 

output: 
(-2,1) 
(-2,3/2) 
(-1,1)


-------------------------------------------------------------------------

Week 14

037 三種排序法比較
 
輸入說明 
輸入一串未經排序的整數數字，數量小於20，結束時輸入-999 
接著輸入數字0代表由小到大排序，輸入1代表由大到小排序。 

輸出說明 
利用Bubble Sort, Insertion Sort, Selection Sortn三種排序方法， 
輸出排序完成的數字與三種排序所執行的交換次數。 

input: 
1 781 848 7 4 99 11 44 88 90 111 11 54 12 55 -999 
0 

output: 
1 4 7 11 11 12 44 54 55 88 90 99 111 781 848 
Bubble Sort change times = 48 
Insertion Sort change times = 48 
Selection Sort change times = 12 

---------------------------------- 
input: 
1 3 5 7 9 11 13 15 17 -999 
1 

output: 
17 15 13 11 9 7 5 3 1 
Bubble Sort change times = 36 
Insertion Sort change times = 36 
Selection Sort change times = 4

---------------------------------------------------------

Week 14.

038 實作stack和circular queue 
輸入說明: 
首先先輸入要實作stack還是circular queue: 
1表示實作stack 
2表示實作circular queue 
接著輸入想要執行的功能: 
1表示新增整數數字到stack或circular queue 
2表示想要刪除stack或circular queue裡面的數字 
3表示印出目前stack或circular queue裡面的所有數字 

stack和circular queue的MAX為5 
如果沒有辦法新增數字到stack或circular queue則需顯示"FULL" 
如果stack或circular queue為空導致沒有辦法刪除數字，則需顯示"EMPTY" 

輸出說明: 
印出程式執行結果。 

--------------------------------------------------------------- 
input: 
1 
1 2 
1 6 
1 8 
1 5 
1 9 
1 7 

output: 
FULL 

input: 
1 
1 2 
1 6 
1 8 
1 5 
1 9 
2 
2 
2 
3 
output: 
2 6 

input: 
2 
1 2 
1 6 
1 8 
1 5 
1 9 
output: 
FULL 

input: 
2 
1 2 
1 6 
1 8 
1 5 
2 
2 
2 
1 3 
3 
output: 
5 3 

input: 
2 
1 2 
1 6 
1 8 
1 5 
2 
2 
2 
2 
2 
output: 
EMPTY

================================================================================================

Week 15

039 中序轉後序 

給予一個由變數加上+-*/四則運算與冪次^運算的數學式，變數用一個小寫英文字母表示。 
運算優先次序是：冪次大於乘除大於加減。中序表示法是運算符號在兩運算子中間，可藉括號表示優先運算次序。 
請將用中序表示的運算式改成後序表示。後序表示法不需藉由括號區分運算的先後次序。 

輸出說明 
一行長度在512個字母內的字串，用中序表示法表達的算式。 

輸出說明：後序表示的算式。 
-------------------------------- 
input: 
a+b*(c-d)^e 

output: 
abcd-e^*+ 

input: 
(a-b)^c+(d-e)^f 

output: 
ab-c^de-f^+


--------------------------------------------------------

Week 15.

040 

設一個 nxn 的矩陣，由左而右，由上而下標示自1到 nxn 的數，如下圖為 4x4的。 
1 2 3 4 
5 6 7 8 
9 10 11 12 
13 14 15 16 
讀入旋轉序列後，將該矩陣的資料輸出。 
下圖中，表示向右旋轉一次。 
13 9 5 1 
14 10 6 2 
15 11 7 3 
16 12 8 4 
下圖表示將圖向左旋轉一次， 
4 8 12 16 
3 7 11 15 
2 6 10 14 
1 5 9 13 
下圖表示將圖上下對翻一次。 
13 14 15 16 
9 10 11 12 
5 6 7 8 
1 2 3 4 
------------------------------ 
輸入說明 ： 
首先輸入一個正整數 n, n<10，表示一個 nxn 的矩陣。 
接著輸入一串矩陣想要執行的功能的參數，參數的數量不超過80，參數輸入完畢時輸入F 
R:表示矩陣向右旋轉 
L:表示矩陣向左旋轉 
N:表示矩陣上下對翻 
------------------------------ 
輸出說明 ： 
由左而右，由上而下，輸出經過旋轉後的排列。每筆測試資料共輸出 n 行，每行 n 個整數， 
每筆資料間以空行隔開。 
------------------------------ 
Sample Input: 
3 
R R N R L L R L N R L L L F 

Sample output: 
7 4 1 
8 5 2 
9 6 3 
------------------------------ 
Sample Input: 
2 
R L L R N N F 

Sample output: 
1 2 
3 4

--------------------------------------------------------

Week 15.


041 數獨的規則 
輸入一個9*9的數字矩陣，其中每個元素均為0～9，其中0代表該格尚未填入數字。 
請撰寫一支程式判斷該矩陣中，0 應該出現甚麼數字。數獨的規則如下： 
(1)矩陣中的每一列（9個元素）只能出現1~9至多各一次。 
(2)矩陣中的每一行（9個元素）只能出現1~9至多各一次。 
(3)9個3*3的小矩陣（9個元素），亦分別只能出現1~9至多各一次。 
----------------------------------- 
輸入說明 ： 
9*9的數字矩陣，其中每個元素均為0～9, 0代表該格尚未填入數字. 
----------------------------------- 
輸出說明 ： 
從上到下，從左到右，輸出 0 的位置與數字。 
----------------------------------- 
Sample Input: 
023456789 
456789123 
789123456 
231564897 
564897231 
897231564 
312605978 
645978312 
908312645 

Sample Output: 
0 0 1 
6 4 4 
8 1 7

================================================================================================

Week 16





















