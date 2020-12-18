#include <iostream>
#include <thread>
#include <fstream>

#include <EditingPad.h>

int main()
{
    std::ifstream boardFile;
    boardFile.open("Board1.txt");
    auto pad = EditingPad(); //creat editing pad
    int width, height; // integers for the size of the board

    //case if file exist
    if (boardFile.is_open())
        pad.loadFile(boardFile);
    //case file don't exist 
    //and we need to edit our board
    else {
        pad.information(); //****************************************************** Matara function ?
        std::cout << "Please enter the size of the board:" << std::endl;
        std::cout << "Enter the width size :" << std::endl;
        std::cin >> width;
        std::cout << "Enter the height size :" << std::endl;
        std::cin >> height;
        std::cout << "Thank you, now you can build your personal board :)" << std::endl;
        pad.setPad(width, height);
    }

    pad.drawPad();

    return 0;
 }
