#pragma once

ref class player{
private:
	int x;
	int y;
	bool has_ship;

public:
	player();
	player(int, int, bool);

	int get_x();
	int get_y();

	void set_x(int);
	void set_y(int);

	bool get_ship();
	void set_ship(bool);



};
