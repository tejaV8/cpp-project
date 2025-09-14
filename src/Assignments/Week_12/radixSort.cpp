#include<iostream>
using namespace std;

void radixSort(int a[], int n){
   int max = a[0], pass = 0, b[10][n], div = 1;
   
   for(int i = 1; i < n; i++){
      if(max < a[i]){
         max = a[i];
      }
   }
   
   while(max > 0){
      pass++;
      max = max/10;
   }
      
   for(int x = 1; x <= pass; x++){
      for(int br = 0; br < 10; br++){
         for(int bc = 0; bc < n; bc++){
            b[br][bc] = 0;
         }
      }
         
      for(int i = 0; i < n; i++){
         int j = 0;
         int rem = (a[i]/div)%10;
         
         while(b[rem][j] != 0)
            j++;
            
         b[rem][j] = a[i];
      }
      int k =0;
         
      for(int br = 0; br < 10; br++){
         for(int bc = 0; bc < n; bc++){
            if(b[br][bc] != 0){
               a[k] = b[br][bc];
               k++;
            }
         }
      }
      div = div*10;
   }
}


int main(){
   int size;
   cout << "Enter the size: ";
   cin >> size;

   int arr[size];

   cout << "Enter " << size << " elements: ";
   for(int i  = 0; i < size; i++){
      cin >> arr[i];
   }cout << endl;

   cout << "Initiating Radix Sort Technique!" << endl;
   radixSort(arr, size);

   cout << "Sorted Array: ";
   for(int i  = 0; i < size; i++){
      cout << arr[i] << " ";
   }cout << endl;
   
   return 0;
}