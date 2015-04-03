#include "player.h"
#include "5cellship.h"

//constructers
player::player()
{

}
player::player(int yCord, int xCord, char ship)
{
	x = xCord;
	y = yCord;
	status = ship;
}

//x, y get/seters
int player::get_x()
{
	return x;
}
int player::get_y()
{
	return y;
}

void player::set_x(int xCord)
{
	x = xCord;
}
void player::set_y(int yCord)
{
	y = yCord;
}

//cell status
bool player::get_ship()
{
	return has_ship;
}
void player::set_ship(bool ship)
{
	has_ship = ship;
}


bool player::getStart()
{
	return gameStart;
}
void player::setStart(bool start)
{
	gameStart = start;
}
