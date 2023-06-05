#include <iostream>

int sum(int array[], int from, int to)
{
   int sum = 0;
   for(int i = from; i <= to; i++)
       sum += array[i];
   return sum;
}

void max_sum(int array[], int size)
{
   int max_sum = array[0];
   int min = 0;
   int max = 0;
   for(int i = 0; i < size; i++)
   {
       for(int j = i ; j < size; j++)
       {
           int current_sum = sum(array, i, j);
           if(current_sum > max_sum)
           {
               max_sum = current_sum;
               min = i;
               max = j;
           }
       }
   }
   std::cout << max_sum << " i: " << min << " j: " << max << std::endl;
}

int main(){
   int a[] = {1,2,3,-3,-2,-1};
   max_sum(a,9);
   return 0;
}