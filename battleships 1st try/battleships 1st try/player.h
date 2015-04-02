
#pragma once;
using namespace System::Drawing;
ref class player
{
private:
	
public:
	player();
	player(int , int , char);
	char status;

<<<<<<< HEAD
//};
//#pragma once
=======
};

#pragma once
>>>>>>> 8126dd4e36c7a72cc83c803e162f6cd4a0c72a1b

//ref class player{
private:
	int x;
	int y;
	bool has_ship;
	
public:
//	player();
	//player(int, int, bool);

	int get_x();
	int get_y();

	void set_x(int);
	void set_y(int);

	bool get_ship();
	void set_ship(bool);

};
