#include "System.h"

System::System()
{
	this->initResources();
	this->initVariables();
	
	this->window = new RenderWindow(VideoMode(this->win_x, this->win_y), "Pokemons", Style::Default);

	this->window->setFramerateLimit(16);

	this->initTextures();

	//if statements
	this->map_obj.push_back(new Map(this->locations["Location_1"])); //rendering first location
}

System::~System()
{
	delete this->window;

	delete this->mainView;
	delete this->pok_menu_view;

	delete this->menu;

	for (auto& i : this->textures)
	{
		delete i.second;
	}

	delete this->player;
	
}

void System::Run()
{
	while (this->window->isOpen())
	{
		this->PollEv();
		
		this->Update();

		this->window->clear(Color::Green);

		this->RenderObjects();


		this->window->display();
	}

}
void System::PollEv()
{
	while (this->window->pollEvent(this->ev))
	{
		if (ev.type == Event::Closed)
			this->window->close();

		if (ev.type == Event::KeyPressed && ev.key.code == Keyboard::Escape)
			this->window->close();

		//player controling
		if (ev.type == Event::KeyReleased && ev.key.code == Keyboard::Enter)
		{
			if (this->show_menu == true)
			{
				this->show_menu = false;
				
			}
			else
			{
				this->set_menu_pos = true;
				this->show_menu = true;
			}
		}

		
		if (ev.type == Event::KeyReleased && ev.key.code == Keyboard::Up)
		{
			if (this->show_menu == true)
			{
				if (this->menu_index == 0)
				{
					this->menu_index = 6;
					this->menu->setPointerPos(Vector2f(0.f, 35.f * this->menu_index));
				}
				else
				{
					this->menu_index--;
					this->menu->setPointerPos(Vector2f(0.f, -35.f));
				}
			}
			if (this->show_pok_menu == true)
			{

			}

		}
		else if (ev.type == Event::KeyReleased && ev.key.code == Keyboard::Down)
		{
			if (this->show_menu == true)
			{
				if (this->menu_index == 6)
				{
					this->menu->setPointerPos(Vector2f(0.f, -35.f*this->menu_index));
					this->menu_index = 0;
				}
				else
				{
					this->menu_index++;
					this->menu->setPointerPos(Vector2f(0.f, 35.f));
				}
				
			}
		}
		else if (ev.type == Event::KeyReleased && ev.key.code == Keyboard::Z)
		{
			if (this->show_menu == true)
			{
				switch (this->menu_index)
				{
				case 0:

					break;
				case 1:
					this->show_pok_menu = true;
					this->show_menu = false;
					break;
				case 2:

					break;
				case 3:

					break;
				case 4:

					break;
				case 5:

					break;
				case 6:

					break;
				}
			}
		}
		else if (ev.type == Event::KeyReleased && ev.key.code == Keyboard::X)
		{
			if (this->show_menu == true)
			{
				this->show_menu = false;
			}

			if (this->show_pok_menu == true)
			{
				this->show_pok_menu = false;
			}
		}

	}
}

void System::changePlayerPos()
{
	//if this function returns true it means it is ready for action if false it means that the action is being done
	//cout << this->frames << endl;
	if (this->go_down_player == true)
	{
		this->frames++;
		if (this->frames <= 8)
		{
			this->player_movement_being_done = true;

			this->player->setPosition(this->player->getSprite().getPosition().x,
				this->player->getSprite().getPosition().y + (this->tex_size.y - (4 * 7)));
		}
		else if (this->frames > 8)
		{
			this->frames = 0;
			this->player_movement_being_done = false;

		}
	}
	else if (this->go_up_player == true)
	{
		this->frames++;
		if (this->frames <= 8)
		{
			this->player_movement_being_done = true;

			this->player->setPosition(this->player->getSprite().getPosition().x,
				this->player->getSprite().getPosition().y - (this->tex_size.y - (4 * 7)));
		}
		else if (this->frames > 8)
		{
			this->frames = 0;
			this->player_movement_being_done = false;

		}
	}
	else if (this->go_left_player == true)
	{
		this->frames++;
		if (this->frames <= 8)
		{
			this->player_movement_being_done = true;

			this->player->setPosition(this->player->getSprite().getPosition().x - (this->tex_size.x - (5 * 7)),
				this->player->getSprite().getPosition().y);
		}
		else if (this->frames > 8)
		{
			this->frames = 0;
			this->player_movement_being_done = false;

		}
	}
	else if (this->go_right_player == true)
	{
		this->frames++;
		if (this->frames <= 8)
		{
			this->player_movement_being_done = true;

			this->player->setPosition(this->player->getSprite().getPosition().x + (this->tex_size.x - (5 * 7)),
				this->player->getSprite().getPosition().y);
		}
		else if (this->frames > 8)
		{
			this->frames = 0;
			this->player_movement_being_done = false;

		}
	}


}

void System::changeNpcPos(Npc* obj)
{
	
	if (obj->go_down_npc == true)
	{
		obj->frames_npc++;
		if (obj->frames_npc <= 8)
		{
			obj->npc_movement_being_done = true;

			obj->setPos(obj->getSprite().getPosition().x,
				obj->getSprite().getPosition().y + (this->tex_size.y - (4 * 7)));
		}
		else if (obj->frames_npc > 8)
		{
			obj->frames_npc = 0;
			obj->npc_movement_being_done = false;

		}
	}
	else if (obj->go_up_npc == true)
	{
		obj->frames_npc++;
		if (obj->frames_npc <= 8)
		{
			obj->npc_movement_being_done = true;

			obj->setPos(obj->getSprite().getPosition().x,
				obj->getSprite().getPosition().y - (this->tex_size.y - (4 * 7)));
		}
		else if (obj->frames_npc > 8)
		{
			obj->frames_npc = 0;
			obj->npc_movement_being_done = false;

		}
	}
	else if (obj->go_left_npc == true)
	{
		obj->frames_npc++;
		if (obj->frames_npc <= 8)
		{
			obj->npc_movement_being_done = true;

			obj->setPos(obj->getSprite().getPosition().x - (this->tex_size.x - (5 * 7)),
				obj->getSprite().getPosition().y);
		}
		else if (obj->frames_npc > 8)
		{
			obj->frames_npc = 0;
			obj->npc_movement_being_done = false;

		}
	}
	else if (obj->go_right_npc == true)
	{
		obj->frames_npc++;
		if (obj->frames_npc <= 8)
		{
			obj->npc_movement_being_done = true;

			obj->setPos(obj->getSprite().getPosition().x + (this->tex_size.x - (5 * 7)),
				obj->getSprite().getPosition().y);
		}
		else if (obj->frames_npc > 8)
		{
			obj->frames_npc = 0;
			obj->npc_movement_being_done = false;

		}
	}
}

void System::playerControl()
{
	this->index_x = int(this->player->getPlayerPosIndex().x);
	this->index_y = int(this->player->getPlayerPosIndex().y);

	if (this->player_movement_being_done == false) //player staying in place
	{
		this->go_down_player = false;
		this->go_right_player = false;
		this->go_left_player = false;
		this->go_up_player = false;

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			if (this->map_obj[0]->map_hash_table.at(this->index_x + 1).at(this->player->getPlayerPosIndex().y) != '0')
			{
				this->go_right_player = true;
				this->player->PlayerMovementAnimation(true, '1');
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			if (this->map_obj[0]->map_hash_table.at(this->index_x - 1).at(this->player->getPlayerPosIndex().y) != '0')
			{
				this->go_left_player = true;
				this->player->PlayerMovementAnimation(true, '2');
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			if (this->map_obj[0]->map_hash_table.at(this->player->getPlayerPosIndex().x).at(this->index_y - 1) != '0')
			{
				this->go_up_player = true;
				this->player->PlayerMovementAnimation(true, '3');
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			if (this->map_obj[0]->map_hash_table.at(this->player->getPlayerPosIndex().x).at(this->index_y + 1) != '0')
			{
				this->go_down_player = true;
				this->player->PlayerMovementAnimation(true, '4');

			}
		}
	}
}

void System::NpcRandomMovement(Npc* obj)
{	
	obj->choose_dir_number = rand() % 150;

	if (obj->going_the_same_dir_counter >= obj->change_dir_after)
	{
		obj->npc_staying = true;
		obj->npc_move_down = false;
		obj->npc_move_up = false;
		obj->npc_move_left = false;
		obj->npc_move_right = false;
		obj->going_the_same_dir_counter = 0;
	}
	
	//randomly going throuht the map

	if (obj->npc_movement_being_done == false) //player staying in place
	{
		obj->go_down_npc = false;
		obj->go_right_npc = false;
		obj->go_left_npc = false;
		obj->go_up_npc = false;

		if (obj->npc_move_right == true)
		{
			if (this->map_obj[0]->map_hash_table.at(int(obj->getCharPosIndex().x) + 1).at(obj->getCharPosIndex().y) != '0')
			{
				obj->going_the_same_dir_counter++;
				obj->go_right_npc = true;
				obj->Update(true, '1');
			}
			else
			{
				obj->go_right_npc = false;
				obj->going_the_same_dir_counter = 0;
				obj->npc_move_right = false;
				if (obj->choose_dir_number < 33)
					obj->npc_move_down = true;
				else if (obj->choose_dir_number < 66 && obj->choose_dir_number > 33)
					obj->npc_move_up = true;
				else if (obj->choose_dir_number > 66 && obj->choose_dir_number < 100)
					obj->npc_move_left = true;
				else
				{
					obj->npc_staying = true;
					obj->staying_time = rand() % 70;
				}
			}
		}
		else if (obj->npc_move_left == true)
		{
			if (this->map_obj[0]->map_hash_table.at(int(obj->getCharPosIndex().x) - 1).at(obj->getCharPosIndex().y) != '0')
			{
				obj->going_the_same_dir_counter++;
				obj->go_left_npc = true;
				obj->Update(true, '2');
			}
			else
			{
				obj->go_left_npc = false;
				obj->going_the_same_dir_counter = 0;
				obj->npc_move_left = false;
				if (obj->choose_dir_number < 33)
					obj->npc_move_down = true;
				else if (obj->choose_dir_number < 66 && obj->choose_dir_number > 33)
					obj->npc_move_up = true;
				else if (obj->choose_dir_number > 66 && obj->choose_dir_number < 100)
					obj->npc_move_right = true;
				else
				{
					obj->npc_staying = true;
					obj->staying_time = rand() % 70;
				}
			}
		}
		else if (obj->npc_move_up == true)
		{
			if (this->map_obj[0]->map_hash_table.at(obj->getCharPosIndex().x).at(int(obj->getCharPosIndex().y) - 1) != '0')
			{
				obj->going_the_same_dir_counter++;
				obj->go_up_npc = true;
				obj->Update(true, '3');
			}
			else
			{
				obj->go_up_npc = false;
				obj->going_the_same_dir_counter = 0;
				obj->npc_move_up = false;
				if (obj->choose_dir_number < 33)
					obj->npc_move_down = true;
				else if (obj->choose_dir_number < 66 && obj->choose_dir_number > 33)
					obj->npc_move_right = true;
				else if (obj->choose_dir_number > 66 && obj->choose_dir_number < 100)
					obj->npc_move_left = true;
				else
				{
					obj->npc_staying = true;
					obj->staying_time = rand() % 70;
				}
			}
		}
		else if (obj->npc_move_down == true)
		{
			if (this->map_obj[0]->map_hash_table.at(obj->getCharPosIndex().x).at(int(obj->getCharPosIndex().y) + 1) != '0')
			{
				obj->going_the_same_dir_counter++;
				obj->go_down_npc = true;
				obj->Update(true, '4');

			}
			else
			{
				obj->go_down_npc = false;
				obj->going_the_same_dir_counter = 0;
				obj->npc_move_down = false;
				if (obj->choose_dir_number < 33)
					obj->npc_move_right = true;
				else if (obj->choose_dir_number < 66 && obj->choose_dir_number > 33)
					obj->npc_move_up = true;
				else if (obj->choose_dir_number > 66 && obj->choose_dir_number < 100)
					obj->npc_move_left = true;
				else
				{
					obj->npc_staying = true;
					obj->staying_time = rand() % 70;
				}
			}
		}
		else if (obj->npc_staying == true)
		{
			obj->staying_timer++;
			if (obj->staying_timer >= obj->staying_time)
			{

				obj->staying_timer = 0;
				obj->npc_staying = false;
				if (obj->choose_dir_number < 33)
					obj->npc_move_right = true;
				else if (obj->choose_dir_number < 66 && obj->choose_dir_number > 33)
					obj->npc_move_up = true;
				else if (obj->choose_dir_number > 66 && obj->choose_dir_number < 100)
					obj->npc_move_left = true;
				else
				{
					obj->npc_move_down = true;
				}

			}

		}
	}

	
}

void System::Update()
{
	if (this->show_menu == false)
	{
		this->timer = game_clock.getElapsedTime();

		this->updateViews();

		this->playerControl();

		//TODO
		this->NpcRandomMovement(this->npcs[0]);
		this->changeNpcPos(this->npcs[0]);

		this->NpcRandomMovement(this->npcs[1]);
		this->changeNpcPos(this->npcs[1]);

		this->NpcRandomMovement(this->npcs[2]);
		this->changeNpcPos(this->npcs[2]);
			


		this->changePlayerPos();

		this->EnterHouse();
	}
	else
	{
		if (this->set_menu_pos == true)
		{
			this->menu->SetMenuPos(this->mainView->getCenter());
			this->set_menu_pos = false;
			this->menu_index = 0;
		}
	}
}

void System::EnterHouse()
{
	//TODO

	//10 na y 7 na x  -> wejscie do domu 1
	if (this->player->getSprite().getPosition().x >= 318 &&
		this->player->getSprite().getPosition().x <= 322 &&
		this->player->getSprite().getPosition().y >= 286 &&
		this->player->getSprite().getPosition().y <= 290)
	{
		this->entrance_house_1 = true; 
	}


	if (this->player->getSprite().getPosition().x >= 318 &&
		this->player->getSprite().getPosition().x <= 322 &&
		this->player->getSprite().getPosition().y >= 254 &&
		this->player->getSprite().getPosition().y <= 258)
	{
		this->goto_house_1 = true; 
		this->entrance_house_1 = false;
	}

}

void System::updateViews()
{
	if (this->show_pok_menu == true)
	{
		//HERE TELLING HOW MUCH POKEMONS ARE IN POCKET
		this->pokmenu->getData(3);//////////

		this->window->setView(*this->pok_menu_view);
	}
	else
	{
		if (this->goto_house_1 == true)
		{
			this->mainView->setCenter(-1000, 0);
		}
		else
		{
			if (this->player->getSprite().getPosition().x > 800.f)
				this->mainView->setCenter(800, this->player->getSprite().getPosition().y);
			else if (this->player->getSprite().getPosition().x < 280.f)
				this->mainView->setCenter(280, this->player->getSprite().getPosition().y);
			else
				this->mainView->setCenter(this->player->getSprite().getPosition().x, this->player->getSprite().getPosition().y);
		}

		this->window->setView(*this->mainView);
	}
}

void System::RenderObjects()
{
	if (this->show_pok_menu == true)
	{
		if (this->set_menu_pos == true)
		{
			this->set_menu_pos = false;
		}

		
		this->pokmenu->Render(*this->window);
	}
	else
	{
		this->RenderMap();

		//rendering characters
		this->player->Render(*this->window);
		this->npcs[0]->Render(*this->window);
		this->npcs[1]->Render(*this->window);
		this->npcs[2]->Render(*this->window);

		for (auto* i : this->map_obj)
		{
			i->RenderLater(*this->window, this->window);
		}

		if (this->show_menu == true)
			this->menu->Render(*this->window);
	

	}
	
}

void System::RenderMap()
{
	for (auto *i : this->map_obj)
	{
		i->Render(*this->window, this->window);
	}
}

void System::initResources()
{
	this->initTextures();
}

void System::initTextures()
{
	//other
	this->textures["MENU"] = new Texture();
	this->textures["MENU"]->loadFromFile("C:/Users/jasin/Desktop/programy/C++/Pokemone_clone/data/textures/other/menu.png");
	this->textures["POINTER_MENU"] = new Texture();
	this->textures["POINTER_MENU"]->loadFromFile("C:/Users/jasin/Desktop/programy/C++/Pokemone_clone/data/textures/other/pointer_menu.png");
	this->textures["BOARD"] = new Texture();
	this->textures["BOARD"]->loadFromFile("C:/Users/jasin/Desktop/programy/C++/Pokemone_clone/data/textures/other/board.png");
	this->textures["BACKGROUND_POK_MENU"] = new Texture();
	this->textures["BACKGROUND_POK_MENU"]->loadFromFile("C:/Users/jasin/Desktop/programy/C++/Pokemone_clone/data/textures/other/background_pok_menu.png");
	this->textures["EMPTY_SLOT"] = new Texture();
	this->textures["EMPTY_SLOT"]->loadFromFile("C:/Users/jasin/Desktop/programy/C++/Pokemone_clone/data/textures/other/empty_slot.png");
	this->textures["CANCEL_BUTTON"] = new Texture();
	this->textures["CANCEL_BUTTON"]->loadFromFile("C:/Users/jasin/Desktop/programy/C++/Pokemone_clone/data/textures/other/cancel_button.png");

	

	//characters
	this->textures["PLAYER"] = new Texture();
	this->textures["PLAYER"]->loadFromFile("data/textures/characters/player.png");
	this->textures["GIRL1"] = new Texture();
	this->textures["GIRL1"]->loadFromFile("data/textures/characters/girl.png");
}

void System::initVariables()
{
	this->tex_size.x = 40;
	this->tex_size.y = 32;

	this->mainView = new View();
	this->mainView->setSize(float(this->win_x), float(this->win_y));
	this->mainView->zoom(0.60f);

	this->pok_menu_view = new View();
	this->pok_menu_view->setSize(float(this->win_x), float(this->win_y));
	this->pok_menu_view->setCenter(Vector2f(0.f, 0.f));

	this->player = new Player(this->textures["PLAYER"], this->tex_size, Vector2f(120.f, 128.f));
	this->npcs.push_back(new Npc(1, this->textures["GIRL1"], this->tex_size, Vector2f(520.f, 128.f)));
	this->npcs.push_back(new Npc(1, this->textures["GIRL1"], this->tex_size, Vector2f(520.f, 128.f)));
	this->npcs.push_back(new Npc(1, this->textures["GIRL1"], this->tex_size, Vector2f(520.f, 128.f)));

	this->menu = new Menu(this->textures["MENU"], this->textures["POINTER_MENU"], this->textures["BOARD"]);

	this->pokmenu = new PokemonMenu(this->textures["BACKGROUND_POK_MENU"],
		this->textures["EMPTY_SLOT"], this->textures["CANCEL_BUTTON"]);

	this->locations["Location_1"] = '1';
}
