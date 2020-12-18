#include "EditingPad.h"

EditingPad::EditingPad()
{
	/*auto Pad = sf::RenderWindow(sf::VideoMode(600, 600), "Editing Pad");

    while (Pad.isOpen())
    {
        Pad.clear();
        m_board.draw(Pad);
        Pad.display();

        if (auto event = sf::Event{}; Pad.waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                Pad.close();
                break;
            }
        }  
    }*/
}

//This function will load ,from the text file,
//the board we will use in our game.
void EditingPad::loadFile(std::ifstream& boardFile)
{

    std::vector<std::string> txtBoard; //data structure to save the txt file
    size_t i = 0;
    std::string line; 

    //we get all the borad from the file 
    //line by line in our data structure
    while (!boardFile.eof()) {
        std::getline(boardFile, line);
        txtBoard.push_back(line);
    }

    m_board.resize(txtBoard.size());
    m_blanks.resize(txtBoard[0].size()); //?????? ya pas un probleme avec la premiere ligne qui donne la taille du bails ?
    setButtons((int)txtBoard[0].size()); 

	for (size_t i = 0; i < m_board.size(); i++)//set the graphic map according to the text map.
	{
		m_board[i].resize(txtBoard[i].size());
		for (size_t j = 0; j < m_board[i].size(); j++)
		{
			m_board[i][j].setLocation({ (float)55 * j, (float)55 * (i + 1) + 10 });
			switch (txtBoard[i][j])
			{
			case '/':
				m_board[i][j].setObject(m_buttons[0].getImage()->getTexture());
				m_board[i][j].setId(m_buttons[0].getId());
				m_robotExists = true; //????
				break;
			case '!':
				m_board[i][j].setObject(m_buttons[1].getImage()->getTexture());
				m_board[i][j].setId(m_buttons[1].getId());
				break;
			case '@':
				m_board[i][j].setObject(m_buttons[2].getImage()->getTexture());
				m_board[i][j].setId(m_buttons[2].getId());
				break;
			case '#':
				m_board[i][j].setObject(m_buttons[3].getImage()->getTexture());
				m_board[i][j].setId(m_buttons[3].getId());
				break;
			case 'D':
				m_board[i][j].setObject(m_buttons[4].getImage()->getTexture());
				m_board[i][j].setId(m_buttons[4].getId());
				m_doorExists = true; //????????,
				break;
			case '\0':
				m_board[i][j].setObject(m_buttons[5].getAction()->getTexture());
				m_board[i][j].setId(' ');
				break;
			case ' ':
				m_board[i][j].setObject(m_buttons[5].getAction()->getTexture());
				m_board[i][j].setId(' ');
				break;
			}
		}
	}
}

void EditingPad::setButtons(int width)
{
	int scalar = 0;//to scale the toolbar and put it in the middle.
	//?????????????,
	m_buttons.resize(9); 

	for (size_t i = 0; i < m_buttons.size(); i++)
	{
		
		m_buttons[i].setImage(graphics_type.getSprite((int)i));
		if (width > 9)
			scalar = width - 9;
		m_buttons[i].setLocation({ (float)(i * 55 + (scalar * 55) * 0.5), 5.0f }); //taille en pixel des bails

		switch (i)//assigns different actions to the right button.
		{
		case 0:
			m_buttons[i].setAction(graphics_type.getSprite((int)i));
			m_buttons[i].setId('@');
			break;
		case 1:
			m_buttons[i].setAction(graphics_type.getSprite((int)i));
			m_buttons[i].setId('#');
			break;
		case 2:
			m_buttons[i].setAction(graphics_type.getSprite((int)i));
			m_buttons[i].setId('H');
			break;
		case 3:
			m_buttons[i].setAction(graphics_type.getSprite((int)i));
			m_buttons[i].setId('-');
			break;
		case 4:
			m_buttons[i].setAction(graphics_type.getSprite((int)i));
			m_buttons[i].setId('%');
			break;
		case 5:
			m_buttons[i].setAction(&m_background);
			m_buttons[i].setId(' ');
			break;
		case 6:
			m_buttons[i].setAction(&m_background);
			m_buttons[i].setId('C');
			break;
		case 7:
			m_buttons[i].setId('S');
			break;
		}
	}
}

void EditingPad::setPad(int width, int height)
{
	m_board.resize(height);
	m_blanks.resize(width);//for the tiles on the side of the toolbar.

	for (size_t i = 0; i < height; i++)
	{
		m_board[i].resize(width);
		for (size_t j = 0; j < width; j++)
		{
			m_board[i][j].setObject(m_background.getTexture());
			m_board[i][j].setLocation({ (float)55 * j, (float)55 * (i + 1) + 10 });
		}
	}
	setButtons(width);//sets the toolbar.
}

void EditingPad::drawPad() {

	int scalar;//to allign the toolbar correctly.
	sf::RenderWindow window(sf::VideoMode((unsigned int)m_board[0].size() * 55, (unsigned int)m_board.size() * 55 + 10), "Lode Runner Editing Pad Window");

	if (m_board.size() < 8)//sets the scalar.
		scalar = 8 - (int)m_board.size();
	else
		scalar = 0;
	window.setSize({ window.getSize().x + scalar * 55, window.getSize().y + 55 });

	while (window.isOpen())//controlls the flow of the program.
	{
		// handles events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				for (size_t i = 0; i < m_buttons.size(); i++)//finds the button pressed from the toolbar and sets the appropriate action.
					if (m_buttons[i].clicked(window))
					{
						firstClick = true;
						m_action.setObject(m_buttons[i].getAction());
						m_action.setId(m_buttons[i].getId());
						Handler = *graphics_type.getSprite((int)i);
						break;
					}
				if (m_action.getId() == 'S')//if the action is "save".
				{
					saveBoard();
					continue;
				}
				if (m_action.getId() == 'C')//if the action is "clear".
				{
					clearBoard(window);
					break;
				}

				for (size_t i = 0; i < m_map.size(); i++)//makes changes to the graphic map according to the action.
					for (size_t j = 0; j < m_map[i].size(); j++)
					{
						if (clicked(window, *m_map[i][j].getObject()))
						{
							if (checkDoorRobot(m_map[i][j].getId()))
								break;

							m_map[i][j].setObject(m_action.getObject()->getTexture());
							m_map[i][j].setId(m_action.getId());
						}
					}

			}
			if (event.type == sf::Event::Resized)//keeps all the objects in place.
				window.setView(sf::View(sf::FloatRect(0, 0, (float)event.size.width, (float)event.size.height)));

			if (event.type == sf::Event::Closed)//closes window.
				window.close();
		}

		// draw the map
		window.clear();

		//sets the rectangle behind the buttons so it would have a background.(created every time to match the maps size)
		for (size_t i = 0; i < m_map.size(); i++)
		{
			sf::RectangleShape rectangle;
			rectangle.setSize(sf::Vector2f(55, 55));
			rectangle.setPosition(55 * (float)i, 5);
			rectangle.setTexture(m_background.getTexture());
			window.draw(rectangle);
		}

		for (size_t i = 0; i < m_map.size(); i++)//adds shading effect to map.
			for (size_t j = 0; j < m_map[i].size(); j++)
			{
				if (m_map[i][j].getObject()->getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
				{
					m_map[i][j].getObject()->setColor(sf::Color(255, 255, 255, 128));
				}
				else
				{
					m_map[i][j].getObject()->setColor(sf::Color::White);
				}
				window.draw(*m_map[i][j].getObject());
			}

		for (size_t i = 0; i < m_buttons.size(); i++)//adds shading effect to the toolbar.
		{
			if (m_buttons[i].getImage()->getGlobalBounds().contains((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y))
				m_buttons[i].getImage()->setColor(sf::Color(255, 255, 255, 128));
			else
				m_buttons[i].getImage()->setColor(sf::Color::White);
			window.draw(*m_buttons[i].getImage());
		}

		if ((m_action.getId() != 'S') && (m_action.getId() != 'C') && (firstClick))//adds the drag effect when a button is selected.
		{
			window.setMouseCursorVisible(false);
			Handler.setPosition({ (float)sf::Mouse::getPosition(window).x - 27, (float)sf::Mouse::getPosition(window).y - 27 });

			if (sf::Mouse::getPosition(window).y < 65)
			{
				Handler.setColor(sf::Color::Transparent);
				window.setMouseCursorVisible(true);
			}
			else
				Handler.setColor(sf::Color(255, 255, 255, 128));
			window.draw(Handler);
		}
		else
			window.setMouseCursorVisible(true);

		window.display();
	}
}
}