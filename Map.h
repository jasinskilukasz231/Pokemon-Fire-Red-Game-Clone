#pragma once
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <map>
#include <fstream>
#include "DrawMap.h"

using namespace std;
using namespace sf;

class Map
{
	map <string, Texture*> ground_textures; //textures
	map <string, Texture*> buildings_textures; //textures

	//reading file
	fstream map_file; //file variable
	string line; //ridden line variable 
	bool check_location = true; //read file
	char file_location_number;
	int row_index = -1; //-1 because tab is the first sign

	
	//data variables
	string name_of_location = "";
	vector<char> map_hash_table_line;

	//what to read variables
	bool read_location = false;
	bool read_map_table = false;
	bool read_hash_table = false;
	

	//spawning
	vector <DrawMap> map_vect;
	vector <DrawMap> map_vect_spawn_later;
	const float tex_size_x = 40.f;
	const float tex_size_y = 32.f;
	

	void ReadLocation(char number_of_location);
	void initResources();
public:
	Map(char location_number);
	~Map();
	void Render(RenderTarget& target, RenderWindow* window);
	void RenderLater(RenderTarget& target, RenderWindow* window);
	void Update();

	vector<vector<char>> map_hash_table;   //Possible to change, sending by function
};

