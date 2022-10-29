#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int c_n_fib(int n, int *cache);
void i_n_fib(int n);
int r_n_fib(int n);

int main(int argc, char *argv[]){
   
   int changed_int = atoi(argv[1]);
   int CACHE_SIZE = 60;

   FILE *f;
   char ch;
   int num;
   f = fopen(argv[3], "r");
   ch = fgetc(f);
   num = atoi(&ch);
   fclose(f);
   
   char *buff = argv[2];
   int result = changed_int + num;
   if(!strcmp(buff, "i")){
       i_n_fib(result);
   }else if(!strcmp(buff, "r")){
       result--;
       printf("%d\n", r_n_fib(result));
   }else if(!strcmp(buff, "c")){
      result--;
      int cache[CACHE_SIZE];
      for(int i = 0; i < CACHE_SIZE; i++){
         cache[i] = -1;
      }
      int nth = c_n_fib(result, cache);
      printf("%d\n", nth);
   }
    return 0;
}

int r_n_fib(int n){
   if(n <= 1){
      return n;
   }
   return r_n_fib(n - 1) + r_n_fib(n - 2);
}

void i_n_fib(int n){
   int first = 0;
   int second = 1;
   int result = 0;

   for(int i = 0; i < n; i++){
      if(i <= 1){
         result = i;
      }else{
         result = first + second;
         first = second;
         second = result;
      }
   }
    printf("%d\n", result);
}

int c_n_fib(int n, int *cache){
   if(n <= 1){
      return n;
   }
   if(cache[n] != -1){
      return cache[n];
   }
   cache[n] =  c_n_fib(n - 1, cache) + c_n_fib(n - 2, cache);
   return cache[n];
}
