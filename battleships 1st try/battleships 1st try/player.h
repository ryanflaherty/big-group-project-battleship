
#pragma once;
using namespace System::Drawing;
ref class player
{
private:
	bool gameStart;


	int x;
	int y;
	bool has_ship;

public:
	player();
	player(int , int , char);
	char status;

	bool getStart();
	void setStart(bool);


	int get_x();
	int get_y();

	void set_x(int);
	void set_y(int);

	bool get_ship();
	void set_ship(bool);
};

