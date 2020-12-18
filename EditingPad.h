#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

#include <vector>
#include <Tile.h>
#include <Button.h>
#include <Graphics.h>

class EditingPad
{
public:
    EditingPad();

    void loadFile(std::ifstream& boardFile);
    void setButtons(int width); //sets button locations and textures.

    void setPad(int width, int height);//sets basic map.
    void drawPad(); //draws the graphic map.

private:
    std::vector<std::vector<Tile>> m_board;
    std::vector<Button> m_blanks;
    std::vector<Button> m_buttons;

    Graphics graphics_type;
 
    bool firstClick = false;
};


//
//bool clicked(sf::Window& window, sf::Sprite sprite);//checks if a tile was clicked.
//void saveBoard();//saves the board to a text file.
//void clearBoard(sf::RenderWindow& window);//clears the board and creates a new one.
//bool checkDoorRobot(char id);//checks if door or robot are placed.
//void information();//displays information to the user.
//~Controller();