#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;



void printCode(const vector<string>& lines){
   cout << endl;
   for(const auto& line : lines){
      cout << line;
      cout << endl;
   }
   cout << endl;
}

int main(){
   vector<string> lines(1);
   int line = 0;

   //Arrow < or >
   int arrowLeftRightcounter = 0;


   while(true){
      int c = _getch();
      // printf("%d\n", c);

      //CTRL + Q [Exit]
      if(c == 17) break;

      //add new element to lines vector
      if(c == 13){
         lines.push_back("");
         line++;
         cout << endl;
      }
      
      //Backspace [Text Deleting Handle]
      else if(c == 8){
         if(!lines[line].empty()){
            lines[line].pop_back();
            cout << "\b \b"; //move the cursor to back[left], replace space and then move cursor to back again
         }
      }

      //Cursor left or right
      else if(c == 224 || c == 0){
         int arrow = _getch();

         if(arrow == 75){
            arrowLeftRightcounter--;
            cout << "\b";
         }

      }
      
      //Print character Normally and add char to spesific line
      else{
         lines[line] += c;
         cout << (char)c;
      }
   }
   
   //Print Code
   printCode(lines);
   getchar();

   return 0;
}