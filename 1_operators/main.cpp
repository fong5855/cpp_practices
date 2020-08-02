#include <iostream> 
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

// 定義巨集
#define PRINT(x) std::cout << x << std::endl;


// 有三隻小豬ABC，請分別輸入三隻小豬的體重，並且判斷哪隻小豬最重？
void three_pigs() {
  int a, b, c;
  PRINT("有三隻小豬ABC，請分別輸入三隻小豬的體重");
  std::cout << "A ";
  std::cin >> a;
  std::cout << "B ";
  std::cin >> b;
  std::cout << "C ";
  std::cin >> c;

  // solution 1:
  if (a > b) {
    if (a > c) {
      PRINT("A 最重");
    }
    else {
      PRINT("C 最重");
    }
  }
  else {
    if (b > c) {
      PRINT("B 最重");
    }
    else {
      PRINT("C 最重");
    }
  }

  // solution 2:
  if (a > b && a > c) {
    PRINT("A 最重");
  }
  else if (b > a && b > c) {
    PRINT("B 最重");
  }
  else {
    PRINT("C 最重");
  }
}

// 系統隨機生成一個1到100之間的數字，玩家進行猜測，如果猜錯，提示玩家數字過大或過小，如果猜對恭喜玩家勝利，並且退出遊戲。
void guess_num() {
  /* initialize random seed: */
  srand(time(NULL));

  int rand_num = rand() % 100 + 1;

  int usr_guess = 0;
  while (true)
  {
    PRINT("猜一個數");
    std::cin >> usr_guess;
    if (usr_guess < rand_num) {
      PRINT("太小");
    }
    else if (usr_guess > rand_num) {
      PRINT("太大");
    }
    else
    {
      PRINT("bingo");
      break;
    }
  }
}
// 水仙花數是指一個 3 位數，它的每個位上的數字的 3次方之和等於它本身
// 列出所有的水仙花數
void list_narcissistic_number() {
  for(int i=100; i<1000; i++) {
    // 百位數
    int k = i / 100;
    // 十位數
    int h = (i % 100) / 10;
    // 個位數
    int d = i % 10;
    // 三次方總和
    int tri_sum = pow(k, 3) + pow(h, 3) + pow(d, 3);
    if (i == tri_sum) {
      PRINT( pow(k, 3) << ", " << pow(h, 3) << ", " << pow(d, 3) << ", sum = " << i);
    }
  }
}

// 從1開始數到數字100， 如果數字個位含有7，或數字十位含有7，或該數字是7的倍數，輸出666，其餘數字直接輸出。
void check_7() {
  for (int i = 1; i <= 100; i++) {
    int d = i % 10; 
    int s = i % 7;

    if (d == 7 || (i >= 70 && i < 80) || s == 0) {
      PRINT(666);
    } else {
      PRINT(i);
    }
  }
}

// 99乘法表
void multiplication_table() {
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      std::cout << j << " x " << i << " = " << j*i << "\t";
    }
    PRINT(" ");
  }
}

// bubble sort
void bubble_sort() {
  int num_list[10] = {0};
  for (int i = 0; i < 10; i++) {
    num_list[i] = rand() % 100 + 1;
  }
  
  for (int i = 0; i < 10; i++)
  {
    for (int j = i; j < 10; j++)
    {
      if (num_list[j] < num_list[i]) {
        int tmp = num_list[i];
        num_list[i] = num_list[j];
        num_list[j] = tmp;
      }
    }
  }
  
  for (int i = 0; i < 10; i++) {
    std::cout << num_list[i] << ", ";
  }
  

}

int main(int argc, char** argv) {
    PRINT("有三隻小豬ABC，請分別輸入三隻小豬的體重，並且判斷哪隻小豬最重？");
    three_pigs();
    PRINT("");

    PRINT("系統隨機生成一個1到100之間的數字，玩家進行猜測，如果猜錯，提示玩家數字過大或過小，如果猜對恭喜玩家勝利，並且退出遊戲。");
    guess_num();
    PRINT("");

    PRINT("水仙花數是指一個 3 位數，它的每個位上的數字的 3次方之和等於它本身，列出所有的水仙花數")
    list_narcissistic_number();
    PRINT("");

    PRINT("從1開始數到數字100， 如果數字個位含有7，或數字十位含有7，或該數字是7的倍數，輸出666，其餘數字直接輸出。")
    check_7();
    PRINT("");

    PRINT("99乘法表");
    multiplication_table();
    PRINT("");

    PRINT("bubble sort");
    bubble_sort();

    return 0;
}