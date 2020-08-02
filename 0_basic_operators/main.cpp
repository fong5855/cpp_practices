#include <iostream>
#include <string>
#include <stdio.h>

// 定義常數
#define PI 3.14;

// 定義巨集
#define PRINT(x) std::cout << x << std::endl;

int main()
{
  // 單行註釋，宣告變數及assign value
  char c = 'y';

  /*
  多行註釋
  c style print function
  %c: Character ('c')
  %d: Decimal (10)
  %x: Hexadecimal (0xAA)
  %s: String ("string")
  */
  printf("%c", c);
  printf("%s", "\n");
  printf("%x", c);

  // c++ style print function (平常的時候可讀性不錯)，各有優缺點
  std::cout << "\n----------------" << std::endl;

  // printf 可以很好的控制要輸出的樣式 (這時候可讀性較好)
  printf("%c%s%x", c, "\n", c);

  std::cout << "----------------" << std::endl;

  // cout 稍微麻煩一點 (這時候可讀性就變差了)
  std::cout << c << "\n";
  std::cout << std::hex << (int)c << std::dec << std::endl;

  std::cout << "-----------------" << std::endl;
  PRINT("運算部分");

  int a = 10;
  int b = 3;

  PRINT(a + b); 
  PRINT(a - b); 
  PRINT(a * b); 
  PRINT(a / b); 

  PRINT(a % b); 

  PRINT(a++);   
  PRINT(a);     

  a = 10;
  PRINT(++a);   
  PRINT(a);     

  // 浮點數
  double a1 = 10.0;
  double a2 = 20.0;
  PRINT(a1 / a2); 
  
  // 除了 = 還有其他assign operators

  PRINT(a);   
  PRINT(b);   
  a += 1;     
  PRINT(a);   
  a -= 1;
  PRINT(a);   
  a *= 3;     
  PRINT(a);   
  a /= 3;
  PRINT(a);   

  PRINT("邏輯運算");
  if (0 || false) {   
    PRINT("0 is false");  
  }
  if (!0) { // ! is not
    PRINT("0 is false");  
  }
  if (-1 && 1 && true) {  // && is and
    PRINT("all the other value is true");   
  }
  else if (1) {
    PRINT("else if");
  }
  else {
    PRINT("else");
  }

  // ? operator
  PRINT(((a > b) ? a : b));

  // switch

  switch (c)
  {
  case 'y':
    PRINT("c is y");
  case 's':
    PRINT("don't forget break");
    break;
  default:
    PRINT("if above cases does not match");
    break;
  }

  // loop
  int i = 0;
  while (i < 3) {
    PRINT(std::to_string(i) + " in while loop" );
    i += 1;
  }

  for (i = 0; i < 3; i++) {
    PRINT(std::to_string(i) + " in for loop");
  }

  do
  {
    PRINT(std::to_string(i) + " in do while");
    i += 1;
  } while (i < 3);

  // for loop
  for (i = 1; i < 10; i++)
  {
    for (int j = 1; j < 10; j++)
    {
      std::cout << j << " x " << i << " = " << j * i << "\t";
    }
    std::cout << std::endl;
  }

  // break and continue
  for (i = 0; i < 10; i++)
  {
    if (i == 2) {
      PRINT("meet a \"continue\" in for loop");
      continue;
    }
    PRINT(std::to_string(i) + " in for loop");
    if (i == 3){
      PRINT("meet a \"break\" in for loop");
      break;
    }
  }

  // 暫停，不然程式會直接88
  system("pause");
  return 0;
}