#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

void renderLines(const vector<string>& lines){
    system("cls");
    for(int i = 0; i < lines.size(); i++){
        cout << lines[i];
        if(i < lines.size() - 1){
            cout << "\n";
        }
    }
}

void fileWrite(string fileName, const vector<string>& lines){
    ofstream file;
    file.open(fileName);
    for(const auto& line : lines){
        file << line << "\n";
    }
    file.close();
}

int main(int argc, char* argv[]){

    string fileName = "";
    //Command Line Argument Handle
    if(argc > 1 && string(argv[1]) != ""){
        fileName = argv[1];
    }
    


    vector<string> lines = {""};
    int cursorX = 0;
    int cursorY = 0;

    // INITIAL
    renderLines(lines);

    while(true){
        int characterInput = _getch();

        //1. EXIT (CTRL+Q)
        if(characterInput == 17){
            if(fileName == ""){
                cout << "File Name: ";
                cin >> fileName;
            }
            break;
        }

        //2. Enter
        else if(characterInput == 13){
            lines.push_back("");
            cursorY++;
            cursorX = 0;
            cout << endl;
        }

        //3. Backspace
        else if(characterInput == 8){
            if(cursorX > 0){
                lines[cursorY].erase(cursorX - 1, 1);
                cursorX--;
            }
            else if(cursorY > 0){ //logika kalau buat ngapus baris di atasnya
                cursorX = lines[cursorY - 1].length();
                lines[cursorY - 1] += lines[cursorY];
                lines.erase(lines.begin() + cursorY);
                cursorY--; 
            }
        }

        // Normal Character (Line Input)
        else if(characterInput >= 32 && characterInput <= 126){
            lines[cursorY].insert(cursorX, 1, (char)characterInput);
            cursorX++;
            cout << (char)characterInput;
        }

        // LAST EXUCITON
        renderLines(lines);
    }
    cout << fileName << endl;
    fileWrite(fileName, lines);
    
    return 0;
}