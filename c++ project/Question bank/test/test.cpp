#include <bits/stdc++.h>
using namespace std;

// 定位函数，找到from在src出现的位置，返回from起始位置的指针，暴力扫描
char* findstr(char* src, char* from){
   bool flag = false;
   for (int i = 0; i < strlen(src); ++i){
      if (src[i] == from[0]){
         flag = true;
         for (int j = 0; j < strlen(from); ++j){
            if (src[i + j] != from[j]){
               flag = false;
               break;
            }
         }
         if (flag){
            return src + i;
         }
      }
   }
   return nullptr;
}

// 替换函数，src起始位置就是需要替换的字符串
void replace(char* src, char* from, char* to){
   int lento = strlen(to);
   int lenfrom = strlen(from);
   char* tmp;
   if (lenfrom > lento){ //若to长度小于from，从前向后将src + lenfrom开始的字符串拷贝到src + lento处
      tmp = src + lenfrom; 
      while (*tmp != '\0'){
         *(tmp - (lenfrom - lento)) = *tmp; 
         ++tmp;
      }
      *(tmp - (lenfrom - lento)) = '\0'; 
   } else if (lenfrom < lento){//开始从后向前将src + strlen(src)即'\0'到strlen(src) + lenfrom拷贝至src + strlen(src) + (lento - lenfrom)到src + lento位置
      tmp = src;
      while(*tmp != '\0') tmp++;
      while(tmp >= src + lenfrom){
         *(tmp + (lento - lenfrom)) = *tmp;
         tmp--;
      }
   }
   memcpy(src, to, lento);
}

// 入口函数
void helper(char* src, char* from, char* to){
   char *ptr = findstr(src, from);
   while (ptr != nullptr){
      // ptr若不为空，则起始位置即为替换位置
      replace(ptr, from, to);
      // 跳到已替换to后的位置，避免重复查找子字符串
      ptr = ptr + strlen(to);
      // 迭代判断src剩余部分是否仍有from
      ptr = findstr(ptr, from);
   }
}

int main()
{
   char src[] = "aaa";
   char from[] = "a";
   char to[] = "bb";
   helper(src, from, to);
   cout << src << endl;
   return 0;
}
