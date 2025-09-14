#include<iostream>
using namespace std;

int partition(int a[], int low, int high){

   int pivot = a[low], i = low +1, j = high;
   
   while(i <= j){
      while(a[i] < pivot){
         i++;
      }
      while(a[j] > pivot){
         j--;
      }
      if(i < j){
         swap(a[i], a[j]);
      }
   }
   
   swap(a[low] , a[j]);
   
   return j;
}

void quickSort(int a[], int low, int high){

   if(low < high){
   
      int p = partition(a, low, high);
      
      quickSort(a, low, p-1);
      quickSort(a, p+1, high);
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

   cout << "Initiating Quick Sort Technique!" << endl;
   quickSort(arr, 0, size);

   cout << "Sorted Array: ";
   for(int i  = 0; i < size; i++){
      cout << arr[i] << " ";
   }cout << endl;
   
   return 0;
}