#include "Map.h"

void Map::ReadLocation(char number_of_location)
{
	this->map_file.open("data/map.txt", ios::in);
	if (!this->map_file.is_open())
	{
		cout << "ERROR::COULD NOT READ A MAP FILE!" << endl;
		exit(0);
	}
	else
	{
		while (this->check_location == true)
		{
			getline(this->map_file, this->line); //reading line
			if (this->read_map_table == true) this->row_index++;
			if (this->read_hash_table == true)
			{
				this->map_hash_table.push_back(this->map_hash_table_line);
				this->map_hash_table_line.clear();
			}
			
			for (size_t i = 0; i < this->line.length(); i++) //checking certain line 
			{
				if (this->file_location_number == number_of_location)
				{
					if (this->read_location == true) this->name_of_location += this->line[i];
					
					if (this->read_map_table == true)
					{
						switch (this->line[i])
						{
						case '1':
							this->map_vect.push_back(DrawMap(i * this->tex_size_x,
								float(this->row_index) * this->tex_size_y,
								this->ground_textures["GRASS"], 0, NULL, NULL, 0, NULL, NULL));
							break;
						case '5':
							this->map_vect.push_back(DrawMap(i * this->tex_size_x,
								float(this->row_index) * this->tex_size_y,
								this->ground_textures["DIRT"], 0, NULL, NULL, 1, 0, 0));
							break;
						case '2':
							this->map_vect.push_back(DrawMap(i * this->tex_size_x,
								float(this->row_index) * this->tex_size_y,
								this->ground_textures["DIRT"], 0, NULL, NULL, 1, 1, 0));
							break;
						case '6':
							this->map_vect.push_back(DrawMap(i * this->tex_size_x,
								float(this->row_index) * this->tex_size_y,
								this->ground_textures["DIRT"], 0, NULL, NULL, 1, 2, 0));
							break;
						case '3':
							this->map_vect.push_back(DrawMap(i * this->tex_size_x,
								float(this->row_index) * this->tex_size_y,
								this->ground_textures["WATER"], 0, NULL, NULL, 0, NULL, NULL));
							break;
						case '4':
							this->map_vect_spawn_later.push_back(DrawMap(i * this->tex_size_x,
								float(this->row_index) * this->tex_size_y,
								this->ground_textures["TREE"], 1, 0.f, 128.f, 0, NULL, NULL));
							break;
						case 'a':///////////////////////BUILDINGS ABOVE
							this->map_vect.push_back(DrawMap(i * this->tex_size_x,
								float(this->row_index) * this->tex_size_y,
								this->buildings_textures["HOUSE1"], 1, 40.f, 32.f, 0, NULL, NULL)); //changing origin 1 down 1 right
							break;
						case 'f':
							this->map_vect.push_back(DrawMap(i * this->tex_size_x,
								float(this->row_index) * this->tex_size_y,
								this->buildings_textures["FENCE"], 0, NULL, NULL, 1, 0, 0));  //basic fence
							break;
						case 'l':
							this->map_vect.push_back(DrawMap(i * this->tex_size_x,
								float(this->row_index) * this->tex_size_y,
								this->buildings_textures["FENCE"], 0, NULL, NULL, 1, 1, 0));  //fence 1
							break;
						case 'k':
							this->map_vect.push_back(DrawMap(i * this->tex_size_x,
								float(this->row_index) * this->tex_size_y,
								this->buildings_textures["FENCE"], 0, NULL, NULL, 1, 2, 0));  //fence 2
							break;
						case 'o':
							this->map_vect.push_back(DrawMap(i * this->tex_size_x,
								float(this->row_index) * this->tex_size_y,
								this->buildings_textures["FENCE"], 0, NULL, NULL, 1, 3, 0));  //fence 3
							break;
						case 'i':
							this->map_vect.push_back(DrawMap(i * this->tex_size_x,
								float(this->row_index) * this->tex_size_y,
								this->buildings_textures["FENCE"], 0, NULL, NULL, 1, 4, 0));  //fence 4
							break;
						case 'u':
							this->map_vect.push_back(DrawMap(i * this->tex_size_x,
								float(this->row_index) * this->tex_size_y,
								this->buildings_textures["FENCE"], 0, NULL, NULL, 1, 5, 0));  //fence 5
							break;
						case 'j':
							this->map_vect.push_back(DrawMap(i * this->tex_size_x,
								float(this->row_index) * this->tex_size_y,
								this->buildings_textures["FENCE"], 0, NULL, NULL, 1, 6, 0));  //fence 6
							break;
						}


					}

					if (this->read_hash_table == true)
					{
						if (this->line[i] == '0') this->map_hash_table_line.push_back('0');
						else this->map_hash_table_line.push_back('1');
						
					}
				}

				switch (this->line[i])
				{
					case '/': if (this->line[i + 1] == '/')this->check_location = false; break;//ending file reading 
					case '<': 
						if (this->read_location == true)
						{
							this->read_location = false; 
							this->read_map_table = true;
							
						}
						else this->file_location_number = this->line[i + 1]; this->read_hash_table = false;
						break;
						
					case '>': this->read_location = true; break;
					case '&': this->read_map_table = false; this->read_hash_table = true; break;
					
				}
			}
			
		}
		
		this->map_file.close();
		this->name_of_location.pop_back(); //deleting last sign of string

		/*for (int i = 0; i < map_hash_table.size(); i++)
		{
			for (int j = 0; j < map_hash_table.at(i).size(); j++)
				cout << this->map_hash_table.at(i).at(j);
			std::cout << std::endl;
		}*/
		
	}
}

void Map::initResources()
{
	this->ground_textures["GRASS"] = new Texture;
	if (!this->ground_textures["GRASS"]->loadFromFile("data/textures/map/ground/grass.png"))
		cout << "COULD NOT LOAD A GRASS TEXTURE!" << endl;
	this->ground_textures["DIRT"] = new Texture;
	if (!this->ground_textures["DIRT"]->loadFromFile("data/textures/map/ground/dirt.png"))
		cout << "COULD NOT LOAD A DIRT TEXTURE!" << endl;
	this->ground_textures["WATER"] = new Texture;
	if (!this->ground_textures["WATER"]->loadFromFile("data/textures/map/ground/water.png"))
		cout << "COULD NOT LOAD A WATER TEXTURE!" << endl;
	this->ground_textures["TREE"] = new Texture;
	if (!this->ground_textures["TREE"]->loadFromFile("data/textures/map/ground/tree.png"))
		cout << "COULD NOT LOAD A TREE TEXTURE!" << endl;

	this->buildings_textures["HOUSE1"] = new Texture;
	if (!this->buildings_textures["HOUSE1"]->loadFromFile("data/textures/map/buildings/house1.png"))
		cout << "COULD NOT LOAD A HOUSE1 TEXTURE!" << endl;
	this->buildings_textures["FENCE"] = new Texture;
	if (!this->buildings_textures["FENCE"]->loadFromFile("data/textures/map/buildings/fence.png"))
		cout << "COULD NOT LOAD A FENCE TEXTURE!" << endl;
	

}

Map::Map(char location_number)
{
	this->initResources();

	//reading proper map resources from file 
	this->ReadLocation(location_number);
}

Map::~Map()
{

}

void Map::Render(RenderTarget& target, RenderWindow* window)
{
	for (auto i : this->map_vect)
	{
		i.Render(*window);
	}

}
void Map::RenderLater(RenderTarget& target, RenderWindow* window)
{
	for (auto i : this->map_vect_spawn_later)
	{
		i.Render(*window);
	}

}

void Map::Update()
{

}



