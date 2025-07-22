//Patterns 
#include <iostream>
using namespace std;

void rectanglePattern(int rows, int cols){
    
    for(int i = 0; i < rows; i++) {                                   // * * * * *
        for(int j = 0; j < cols; j++) {                               // * * * * *
            cout << "* ";                                             // * * * * *
        }                                                             // * * * * *
        cout << endl;                                                 // * * * * *
    }
}

void rightAngledTriangle(int rows) {
    for(int i = 1; i <= rows; i++) {                                  // *
        for(int j = 1; j <= i; j++) {                                 // * *
            cout << "* ";                                             // * * *
        }                                                             // * * * *
        cout << endl;                                                 // * * * * *
    }
}

void rightAngledNumberTriangle(int rows) {
    for(int i = 1; i <= rows; i++) {                                  // 1
        for(int j = 1; j <= i; j++) {                                 // 1 2
            cout << j << " ";                                         // 1 2 3
        }                                                             // 1 2 3 4
        cout << endl;                                                 // 1 2 3 4 5
    }
}
void rightAngledRepeatedNumberTriangle(int rows) {
    for(int i = 1; i <= rows; i++) {                                
        for(int j = 1; j <= i; j++) {                                 
            cout << i << " ";                                         
        }                                                             
        cout << endl;                                               
    }   
    //OUTPUT:
    // 1
    // 2 2
    // 3 3 3
    // 4 4 4 4
    // 5 5 5 5 5
}

void invertedRightAngledTriangle(int rows) {
    for(int i = rows; i >= 1; i--) {                                  // * * * * *
        for(int j = 1; j <= i; j++) {                                 // * * * *
            cout << "* ";                                             // * * *
        }                                                             // * * 
        cout << endl;                                                 // * 
    }
}

void invertedRightAngledNumberTriangle(int rows) {
    for(int i = rows; i >= 1; i--) {                                  // 1 2 3 4 5
        for(int j = 1; j <= i; j++) {                                 // 1 2 3 4
            cout << j << " ";                                         // 1 2 3
        }                                                             // 1 2 
        cout << endl;                                                 // 1 
    }
}

void triangle(int N){
    for (int i = 0; i < N; i++)                                        //     * 
    {                                                                  //    *** 
        for (int j =0; j<N-i-1; j++)                                   //   *****
        {                                                              //  *******
            cout <<" ";                                                // *********
        }
        for(int j=0;j< 2*i+1;j++){
            cout<<"*";
        }
        for (int j =0; j<N-i-1; j++)
        {
            cout <<" ";
        } 
        cout << endl;
    }
}

void invertedTriangle(int N){

    for (int i = 0; i < N; i++)                                        // *******
    {                                                                  //  *****
        for (int j = 0; j < i; j++)                                    //   ***    
        {         cout << " ";                                         //    *
            cout << " ";
        }
        for (int j = 0; j < 2 * (N - i) - 1; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

void diamondPattern(int N) {
    triangle(N);
    invertedTriangle(N);
    //OUTPUT:
    //     * 
    //    *** 
    //   ***** 
    //  ******* 
    // ********* 
    //  ******* 
    //   ***** 
    //    *** 
    //     *  
}

void leftPyramid(int N) {
    rightAngledTriangle(N);
    invertedRightAngledTriangle(N);
    //OUTPUT:
    // *
    // * *
    // * * *
    // * * * *
    // * * * * *
    // * * * *
    // * * *
    // * *
    // *
}

void binaryTrianglePattern(int rows) {

      int start =1;

      for(int i=0;i<rows;i++){

          if(i%2 ==0) start = 1;

          else start = 0;

          for(int j=0;j<=i;j++){
              cout<<start<<" ";
              start = 1-start;
          }
        cout<<endl;
      }
      //OUTPUT:
      // 1
      // 0 1
      // 1 0 1
      // 0 1 0 1
      // 1 0 1 0 1
}

void palindromicNumberTriangle(int rows){

      int spaces = 2*(rows-1);

      for(int i=1;i<=rows;i++){

          for(int j=1;j<=i;j++){
              cout<<j;
          }

          for(int j = 1;j<=spaces;j++){
              cout<<" ";
          }

          for(int j=i;j>=1;j--){
              cout<<j;
          }

          cout<<endl;

          spaces-=2;
      }
        //OUTPUT:
      // 1        1
      // 12      21
      // 123    321 
      // 1234  4321
      // 1234554321
}

void floydsTrianglePattern(int rows) {
    int num = 1;                                                 
    for (int i = 1; i <= rows; i++) {                        
        for (int j = 1; j <= i; j++) {                         
            cout << num << " ";                                  
            num++;                                              
        }
        cout << endl;
    }
    //OUTPUT: 
    // 1
    // 2 3
    // 4 5 6
    // 7 8 9 10
    // 11 12 13 14 15
}

void alphabetTrianglePattern(int rows) {
    for (int i = 0; i < rows; i++) {                                
        for (int j = 0; j <= i; j++) {                               
            cout << char('A' + j) << " ";
        }
        cout << endl;
    }
    //OUTPUT:
    // A 
    // A B 
    // A B C 
    // A B C D 
    // A B C D E 
}

void invertedAlphabetTrianglePattern(int rows) {
    for (int i = rows; i > 0; i--) {                                
        for (int j = 0; j < i; j++) {
            cout << char('A' + j) << " ";
        }
        cout << endl;
    }
    //OUTPUT:
    // A B C D E 
    // A B C D 
    // A B C 
    // A B 
    // A 
}

void repeatedAlphabetTrianglePattern(int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            cout << char('A' + i) << " ";
        }
        cout << endl;
    }
    //OUTPUT:
    // A 
    // B B 
    // C C C 
    // D D D D 
    // E E E E E 
}

void symmetricalAlphabetPyramid(int rows) {
    int spaces = rows - 1; 
    for (int i = 0; i < rows; i++) {
        // Print leading spaces
        for (int j = 0; j < spaces; j++) {
            cout << " ";
        }
        spaces--;
        
        for (int j = 0; j <= i; j++) {
            cout << char('A' + j);
        }
        for (int j = i - 1; j >= 0; j--) {
            cout << char('A' + j);
        }
        cout << endl;
    }
    //OUTPUT:
    //    A
    //   ABA
    //  ABCBA
    // ABCDCBA
}

void reverseAlphabetTriangle(int rows) {
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            cout << char('A' + j) << " ";
        }
        cout << endl;
    }
    //OUTPUT:
    // E 
    // D E 
    // C D E 
    // B C D E 
    // A B C D E 
}

void hollowDiamodBoxPattern(int N){

    int iniS = 0;
      for(int i=0;i< N;i++){

          for(int j=1;j<=N-i;j++){
              cout<<"*";
          }

          for(int j=0;j<iniS;j++){
              cout<<" ";
          }

          for(int j=1;j<=N-i;j++){
              cout<<"*";
          }

          iniS+=2;

          cout<<endl;
      }

      iniS = 2*N -2;
      for(int i=1;i<=N;i++){

          for(int j=1;j<=i;j++){
              cout<<"*";
          }
          for(int j=0;j<iniS;j++){
              cout<<" ";
          }

          for(int j=1;j<=i;j++){
              cout<<"*";
          }

          iniS-=2;

          cout<<endl;
        }
    //OUTPUT:
    // **********
    // ****  ****
    // ***    ***
    // **      **
    // *        *
    // **      **
    // ***    ***
    // ****  ****
    // **********
}

void symmetricButterflyPattern(int N) {

      int spaces = 2*N-2;

      for(int i = 1;i<=2*N-1;i++){

          int stars = i;

          if(i>N) stars = 2*N - i;

          for(int j=1;j<=stars;j++){
              cout<<"*";
          }

          for(int j = 1;j<=spaces;j++){
              cout<<" ";
          }

          for(int j = 1;j<=stars;j++){
              cout<<"*";
          }

          cout<<endl;
          if(i<N) spaces -=2;
          else spaces +=2;
      }
    //OUTPUT:
    // *        *
    // **      **
    // ***    ***
    // ****  ****
    // **********
    // ****  ****
    // ***    ***
    // **      **
    // *        *
}

void hollowRectangleBoxPattern(int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    //OUTPUT:
    // **********
    // *        *
    // *        *
    // *        *
    // **********
}

void concentricSquarePattern(int N) {

     for(int i=0;i<2*N-1;i++){

         for(int j=0;j<2*N-1;j++){

             int top = i;
             int bottom = j;
             int right = (2*N - 2) - j;
             int left = (2*N - 2) - i;

             cout<<(N- min(min(top,bottom), min(left,right)))<<" ";
         }
         cout<<endl;
     }
    //OUTPUT:
    // 4 4 4 4 4 4 4  
    // 4 3 3 3 3 3 4  
    // 4 3 2 2 2 3 4  
    // 4 3 2 1 2 3 4  
    // 4 3 2 2 2 3 4  
    // 4 3 3 3 3 3 4  
    // 4 4 4 4 4 4 4  
}

int main() {
    int choice, rows, cols, N;

    
        cout << "\n=========== Pattern Menu ===========\n";
        cout << "  1. Rectangle Pattern\n";
        cout << "  2. Right-Angled Triangle\n";
        cout << "  3. Right-Angled Number Triangle\n";
        cout << "  4. Right-Angled Repeated Number Triangle\n";
        cout << "  5. Inverted Right-Angled Triangle\n";
        cout << "  6. Inverted Right-Angled Number Triangle\n";
        cout << "  7. Pyramid (Centered Triangle)\n";
        cout << "  8. Inverted Pyramid\n";
        cout << "  9. Diamond Pattern\n";
        cout << " 10. Left Pyramid (Up + Down Triangles)\n";
        cout << " 11. Binary Triangle Pattern\n";
        cout << " 12. Palindromic Number Triangle\n";
        cout << " 13. Floyds Triangle\n";
        cout << " 14. Alphabet Triangle\n";
        cout << " 15. Inverted Alphabet Triangle\n";
        cout << " 16. Repeated Alphabet Triangle\n";
        cout << " 17. Symmetrical Alphabet Pyramid\n";
        cout << " 18. Reverse Alphabet Triangle\n";
        cout << " 19. Hollow Diamond Box Pattern\n";
        cout << " 20. Symmetric Butterfly Pattern\n";
        cout << " 21. Hollow Rectangle Box Pattern\n";
        cout << " 22. Concentric Square Pattern\n";
        cout << "  0. Exit\n";
        
        do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter rows and columns: ";
                cin >> rows >> cols;
                rectanglePattern(rows, cols);
                break;

            case 2:
                cout << "Enter number of rows: ";
                cin >> rows;
                rightAngledTriangle(rows);
                break;

            case 3:
                cout << "Enter number of rows: ";
                cin >> rows;
                rightAngledNumberTriangle(rows);
                break;

            case 4:
                cout << "Enter number of rows: ";
                cin >> rows;
                rightAngledRepeatedNumberTriangle(rows);
                break;

            case 5:
                cout << "Enter number of rows: ";
                cin >> rows;
                invertedRightAngledTriangle(rows);
                break;

            case 6:
                cout << "Enter number of rows: ";
                cin >> rows;
                invertedRightAngledNumberTriangle(rows);
                break;

            case 7:
                cout << "Enter value of N (height): ";
                cin >> N;
                triangle(N);
                break;

            case 8:
                cout << "Enter value of N (height): ";
                cin >> N;
                invertedTriangle(N);
                break;

            case 9:
                cout << "Enter value of N (height): ";
                cin >> N;
                diamondPattern(N);
                break;

            case 10:
                cout << "Enter number of rows: ";
                cin >> rows;
                leftPyramid(rows);
                break;

            case 11:
                cout << "Enter number of rows: ";
                cin >> rows;
                binaryTrianglePattern(rows);
                break;

            case 12:
                cout << "Enter number of rows: ";
                cin >> rows;
                palindromicNumberTriangle(rows);
                break;

            case 13:
                cout << "Enter number of rows: ";
                cin >> rows;
                floydsTrianglePattern(rows);
                break;

            case 14:
                cout << "Enter number of rows: ";
                cin >> rows;
                alphabetTrianglePattern(rows);
                break;

            case 15:
                cout << "Enter number of rows: ";
                cin >> rows;
                invertedAlphabetTrianglePattern(rows);
                break;

            case 16:
                cout << "Enter number of rows: ";
                cin >> rows;
                repeatedAlphabetTrianglePattern(rows);
                break;

            case 17:
                cout << "Enter number of rows: ";
                cin >> rows;
                symmetricalAlphabetPyramid(rows);
                break;

            case 18:
                cout << "Enter number of rows: ";
                cin >> rows;
                reverseAlphabetTriangle(rows);
                break;

            case 19:
                cout << "Enter value of N: ";
                cin >> N;
                hollowDiamodBoxPattern(N);
                break;

            case 20:
                cout << "Enter value of N: ";
                cin >> N;
                symmetricButterflyPattern(N);
                break;

            case 21:
                cout << "Enter rows and columns: ";
                cin >> rows >> cols;
                hollowRectangleBoxPattern(rows, cols);
                break;

            case 22:
                cout << "Enter value of N: ";
                cin >> N;
                concentricSquarePattern(N);
                break;

            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    
    return 0;
}