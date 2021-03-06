#pragma once

#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include "player.h"
#include "5cellship.h"
#include <fstream>




namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

		array <player^, 2>^ Box1;
	private: System::Windows::Forms::Button^  playgamebutton;
	private: System::Windows::Forms::Label^  EnemyGridLabel_DONOTTOUCH;
	private: System::Windows::Forms::Label^  PlayerLabel_DONOTTOUCH;
			 array <player^, 2>^ Box2;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;

	private:

		////////Player Array////

		/////GRAPHICS//////////////	 

		Drawing::Brush^ redBrush;
		Drawing::Brush^ blackBrush;
		Drawing::Brush^ yellowBrush;
		////////Player Array////
		//array <player^, 2>^ PLAYER_GRID;

		/////GRAPHICS//////////////	 
		Graphics ^gselect, ^g, ^g2, ^g3, ^g4; //[Added 4/6/2015] This is for the Cursor

		///Bitmap^ MapGrid = gcnew Bitmap("Graphics/(50x250)_Colony_CarrierShip_[5Cells].png");
		//Bitmap^ Ship_5 = gcnew Bitmap("Graphics/(250x50)_Colony_CarrierShip_[5Cells].png");

		//Bitmap^ Ship_5 = gcnew Bitmap("Graphics/(250x50)_Colony_CarrierShip_[5Cells].png");
		Bitmap^ MapGrid = gcnew Bitmap("Graphics/(480x480)_Starfield[Grid].png");
		//*******//Bitmap^ Ship_5 = gcnew Bitmap("Graphics/(250x50)_Colony_CarrierShip_[5Cells].png");

		///////////////////// Put Graphics Here /////////////////////////
		Bitmap^ starfieldempty_png = gcnew Bitmap("Graphics/(480x480)_Starfield[Empty].png"); //Empty Grid Picture
		Bitmap^ starfieldgrid_png = gcnew Bitmap("Graphics/(480x480)_Starfield[Grid].png"); //Picture with Grid
		// Logo
		Bitmap^ logo_png = gcnew Bitmap("Graphics/(300x150)BattleStarShips_Logo.png"); //Game Logo
		// Frigate PNG
		Bitmap^ Ship_1_verticalpng = gcnew Bitmap("Graphics/(50x50)_Colony_FrigateShip_[1Cell].png"); //1 Cell Frigate Ship Facing Vertically
		Bitmap^ Ship_1_horizontalpng = gcnew Bitmap("Graphics/(50x50)_Colony_FrigateShip_[1Cell]_RightFace.png"); //1 Cell Frigate Ship Facing Horizontally
		// Stealth PNG
		Bitmap^ Ship_2_verticalpng = gcnew Bitmap("Graphics/(50x100)_Colony_StealthShip_[2Cells].png"); //2 Cell Stealth Ship Facing Vertically
		Bitmap^ Ship_2_horizontalpng = gcnew Bitmap("Graphics/(100x50)_Colony_StealthShip_[2Cells]_RightFace.png"); //2 Cell Stealth Ship Facing Horizontally
		// Cruiser PNG
		Bitmap^ Ship_3_verticalpng = gcnew Bitmap("Graphics/(50x150)_Colony_CruiserShip_[3Cells].png"); //3 Cell Cruiser Ship Facing Vertically
		Bitmap^ Ship_3_horizontalpng = gcnew Bitmap("Graphics/(150x50)_Colony_CruiserShip_[3Cells]_RightFace.png"); //3 Cell Cruiser Ship Facing Horizontally
		// Battleship PNG
		Bitmap^ Ship_4_verticalpng = gcnew Bitmap("Graphics/(50x200)_Colony_BattleShip_[4Cells].png"); //4 Cell Battleship Ship Facing Vertically
		Bitmap^ Ship_4_horizontalpng = gcnew Bitmap("Graphics/(200x50)_Colony_BattleShip_[4Cells]_[RightFace].png"); //4 Cell Battleship Ship Facing Horizontally
		// Carrier PNG
		Bitmap^ Ship_5_verticalpng = gcnew Bitmap("Graphics/(50x250)_Colony_CarrierShip_[5Cells].png"); //5 Cell Carrier Ship Facing Vertically
		Bitmap^ Ship_5_horizontalpng = gcnew Bitmap("Graphics/(250x50)_Colony_CarrierShip_[5Cells]_RightFace.png"); //5 Cell Carrier Ship Facing Horizontally
		// HIT SHIP Graphic PNG [Update added 4/27/2015]
		Bitmap^ hit_png = gcnew Bitmap("Graphics/(50x50)_Hit_Cell.png"); //5 Cell Carrier Ship Facing Vertically
		// MISS Graphic PNG [Update added 4/27/2015]
		Bitmap^ miss_png = gcnew Bitmap("Graphics/(50x50)_Miss_Cell.png"); //5 Cell Carrier Ship Facing Horizontally
		// Cursor Target Select - DrawImage
		Bitmap^ select_png = gcnew Bitmap("Graphics/(50x50)Target_Select_Cell[Cursor_DrawImage].png");
		////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////


		/////////////////////

		/////CONST INTS//////
		static const int NUMROWS = 12;
		static const int NUMCOLS = 12;
		static const int LRGCELLSIZE = 40;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
			 /////////////////////

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newGameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveGameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  difficultyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  easyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  hardToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  hardAsBallsToolStripMenuItem;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newGameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveGameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->difficultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->easyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hardToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hardAsBallsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->playgamebutton = (gcnew System::Windows::Forms::Button());
			this->EnemyGridLabel_DONOTTOUCH = (gcnew System::Windows::Forms::Label());
			this->PlayerLabel_DONOTTOUCH = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->pictureBox1->Location = System::Drawing::Point(12, 60);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(600, 600);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			this->pictureBox1->DoubleClick += gcnew System::EventHandler(this, &MyForm::DC);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MouseD);
			this->pictureBox1->MouseLeave += gcnew System::EventHandler(this, &MyForm::ML);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MM2);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->pictureBox2->Location = System::Drawing::Point(624, 60);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(100, 500);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MD);
			this->pictureBox2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MM);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(655, 24);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(150, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(865, 24);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(150, 20);
			this->textBox3->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(620, 567);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(108, 39);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Place Ships";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->pictureBox3->Location = System::Drawing::Point(758, 60);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(250, 250);
			this->pictureBox3->TabIndex = 6;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->pictureBox4->Location = System::Drawing::Point(734, 351);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(300, 300);
			this->pictureBox4->TabIndex = 7;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MD3);
			this->pictureBox4->MouseLeave += gcnew System::EventHandler(this, &MyForm::ML2);
			this->pictureBox4->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MM3);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::Teal;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->difficultyToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->menuStrip1->Size = System::Drawing::Size(987, 24);
			this->menuStrip1->TabIndex = 6;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MyForm::menuStrip1_ItemClicked);
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->newGameToolStripMenuItem,
					this->saveGameToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// newGameToolStripMenuItem
			// 
			this->newGameToolStripMenuItem->Name = L"newGameToolStripMenuItem";
			this->newGameToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->newGameToolStripMenuItem->Text = L"New Game";
			this->newGameToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::newGameToolStripMenuItem_Click);
			// 
			// saveGameToolStripMenuItem
			// 
			this->saveGameToolStripMenuItem->Name = L"saveGameToolStripMenuItem";
			this->saveGameToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->saveGameToolStripMenuItem->Text = L"Save Game";
			// 
			// difficultyToolStripMenuItem
			// 
			this->difficultyToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->easyToolStripMenuItem,
					this->hardToolStripMenuItem, this->hardAsBallsToolStripMenuItem
			});
			this->difficultyToolStripMenuItem->Name = L"difficultyToolStripMenuItem";
			this->difficultyToolStripMenuItem->Size = System::Drawing::Size(67, 20);
			this->difficultyToolStripMenuItem->Text = L"Difficulty";
			// 
			// easyToolStripMenuItem
			// 
			this->easyToolStripMenuItem->Name = L"easyToolStripMenuItem";
			this->easyToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			// 
			// hardToolStripMenuItem
			// 
			this->hardToolStripMenuItem->Name = L"hardToolStripMenuItem";
			this->hardToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->hardToolStripMenuItem->Text = L"Hard";
			// 
			// hardAsBallsToolStripMenuItem
			// 
			this->hardAsBallsToolStripMenuItem->Name = L"hardAsBallsToolStripMenuItem";
			this->hardAsBallsToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->hardAsBallsToolStripMenuItem->Text = L"Hard as Balls";
			// 
			// playgamebutton
			// 
			this->playgamebutton->Location = System::Drawing::Point(620, 612);
			this->playgamebutton->Name = L"playgamebutton";
			this->playgamebutton->Size = System::Drawing::Size(108, 39);
			this->playgamebutton->TabIndex = 8;
			this->playgamebutton->Text = L"Play Game";
			this->playgamebutton->UseVisualStyleBackColor = true;
			this->playgamebutton->Click += gcnew System::EventHandler(this, &MyForm::playgamebutton_Click);
			// 
			// EnemyGridLabel_DONOTTOUCH
			// 
			this->EnemyGridLabel_DONOTTOUCH->AutoSize = true;
			this->EnemyGridLabel_DONOTTOUCH->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EnemyGridLabel_DONOTTOUCH->ForeColor = System::Drawing::Color::Aqua;
			this->EnemyGridLabel_DONOTTOUCH->Location = System::Drawing::Point(774, 322);
			this->EnemyGridLabel_DONOTTOUCH->Name = L"EnemyGridLabel_DONOTTOUCH";
			this->EnemyGridLabel_DONOTTOUCH->Size = System::Drawing::Size(234, 19);
			this->EnemyGridLabel_DONOTTOUCH->TabIndex = 9;
			this->EnemyGridLabel_DONOTTOUCH->Text = L"Enemy Grid (Attack Here!)";
			// 
			// PlayerLabel_DONOTTOUCH
			// 
			this->PlayerLabel_DONOTTOUCH->AutoSize = true;
			this->PlayerLabel_DONOTTOUCH->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PlayerLabel_DONOTTOUCH->ForeColor = System::Drawing::Color::Aqua;
			this->PlayerLabel_DONOTTOUCH->Location = System::Drawing::Point(97, 25);
			this->PlayerLabel_DONOTTOUCH->Name = L"PlayerLabel_DONOTTOUCH";
			this->PlayerLabel_DONOTTOUCH->Size = System::Drawing::Size(450, 19);
			this->PlayerLabel_DONOTTOUCH->TabIndex = 10;
			this->PlayerLabel_DONOTTOUCH->Text = L"Battle Starships - Player Grid (Place Ships Here)";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1046, 666);
			this->Controls->Add(this->PlayerLabel_DONOTTOUCH);
			this->Controls->Add(this->EnemyGridLabel_DONOTTOUCH);
			this->Controls->Add(this->playgamebutton);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int S = 0;
		int numrow = 12;
		int numcol = 12;
		int getX;
		int getY;
		int t = 0;
		int p;
		////////////for get x and y
		int x1;
		int y1;
		int x2;
		int y2;
		//////////////to get x and y when ship added
		int dx1;
		int dx12;
		int dx2;
		int dx22;
		int dx3;
		int dx32;
		int dx4;
		int dx42;
		int dx5;
		int dx52;




		int dy1;
		int dy12;
		int dy2;
		int dy22;
		int dy3;
		int dy32;
		int dy4;
		int dy42;
		int dy5;
		int dy52;
		///////////for identify is the battleship already puted
		int b1 = 1;
		int b2 = 1;
		int b3 = 1;
		int b4 = 1;
		int b5 = 1;
		//////////
		int getX2;
		int getY2;
		int pw;

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
	{

				 player PlayerClass;




				 g = pictureBox1->CreateGraphics();
				 Box1 = gcnew array<player^, 2>(12, 12);
				 Box2 = gcnew array<player^, 2>(12, 12);
				 g2 = pictureBox2->CreateGraphics();

				 g3 = pictureBox3->CreateGraphics();
				 g4 = pictureBox4->CreateGraphics();
				 blackBrush = gcnew System::Drawing::SolidBrush(Color::Black);


				 gselect = pictureBox1->CreateGraphics(); //[Added 4/6/2015] creates target in pictureBox1

				 redBrush = gcnew System::Drawing::SolidBrush(Color::Red);


				 yellowBrush = gcnew System::Drawing::SolidBrush(Color::White);
				 b1 = 0;
				 b2 = 0;
				 b3 = 0;
				 b4 = 0;
				 b5 = 0;

				 /* PLAYER_GRID = gcnew array<player^, 2>(NUMCOLS, NUMROWS);
				 for (int row = 0; row < NUMROWS; row++)
				 for (int col = 0; col < NUMCOLS; col++)
				 PLAYER_GRID[col, row] = gcnew player(col, row, false);
				 */
				 // player5cell(false);




				 // draw_grid();

	}
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 b1 = 0;
				 b2 = 0;
				 b3 = 0;
				 b4 = 0;
				 b5 = 0;
				 S = 1;
				 pw = 0;
				 //g->DrawImage(backG, 0, 0);
				 for (int row = 0; row < numrow; row++)
				 {
					 for (int col = 0; col < numcol; col++)
					 {
						 Rectangle rect1(row * 50, col * 50, 49, 49);
						 Box1[row, col] = gcnew player(row, col, 'b');
						 g->DrawImage(starfieldempty_png, rect1);



					 }
				 }
				 for (int row = 0; row < numrow; row++)
				 {
					 for (int col = 0; col < numcol; col++)
					 {


						 Box2[row, col] = gcnew player(row, col, 'b');
						 Rectangle rect2(row * 25, col * 25, 24, 24);

						 g4->DrawImage(starfieldempty_png, rect2);


					 }
				 }
				 g2->DrawImage(Ship_1_horizontalpng, 0, 0);
				 g2->DrawImage(Ship_2_verticalpng, 0, 51);
				 g2->DrawImage(Ship_3_verticalpng, 0, 151);
				 g2->DrawImage(Ship_4_verticalpng, 0, 301);
				 g2->DrawImage(Ship_5_verticalpng, 51, 0);
				 g3->DrawImage(starfieldempty_png, 0, 0, 250, 250);
				 g4->DrawImage(starfieldempty_png, 0, 0, 300, 300); //Added 4/27/2015

	}
	private: System::Void MouseD(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 /* Rectangle WhiteRect = Rectangle(e->X - (e->X % LRGCELLSIZE), e->Y - (e->Y % LRGCELLSIZE), LRGCELLSIZE - 1, LRGCELLSIZE - 1);
				 g->DrawImage(MapGrid, 0, 0, 480, 480);
				 g->DrawImage(starfieldempty_png, WhiteRect);*/
				 getX = e->X - (e->X % 50);
				 getY = e->Y - (e->Y % 50);
				 x1 = getX / 50;
				 y1 = getY / 50;
				 y2 = getY / 50 + 1;
				 x2 = getX / 50 + 1;
				 if (b1 == 0)
				 {
					 if (Box1[x1, y1]->status == 'b')
					 {
						 if (p == 1)
						 {
							 Rectangle rect2(getX, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect2);
							 //g->DrawImage(starfieldempty_png, 0, 0, 600, 600); //Added 4/27/2015
							 g->DrawImage(Ship_1_verticalpng, getX, getY);
							 Box1[x1, y1]->status = 'c';
							 Box2[x1, y1]->status = 'c';
							 b1 = 1;
						 }
						 if (p == 12)
						 {
							 Rectangle rect2(getX, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect2);
							 //g->DrawImage(starfieldempty_png, 0, 0, 600, 600); //Added 4/27/2015
							 g->DrawImage(Ship_1_horizontalpng, getX, getY);
							 Box1[x1, y1]->status = 'c';
							 Box2[x1, y1]->status = 'c';
							 b1 = 1;
						 }
						 dx1 = x1;
						 dy1 = y1;
					 }
				 }

				 if (b2 == 0)
				 {
					 if (p == 2)
					 {

						 if (y1 + 1 < 12)
						 {
							 if (Box1[x1, y1]->status == 'b'&&Box1[x1, y1 + 1]->status == 'b')
							 {
								 Rectangle rect2(getX, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 // g->DrawImage(starfieldempty_png, 0, 0, 600, 600); //Added 4/27/2015
								 g->DrawImage(Ship_2_verticalpng, getX, getY);
								 Box1[x1, y1]->status = 'd';

								 Box1[x1, y2]->status = 'd';
								 Box2[x1, y1]->status = 'd';

								 Box2[x1, y2]->status = 'd';
								 b2 = 1;
								 dx2 = x1;
								 dy2 = y1;
							 }
						 }
						 else
						 {
							 if (Box1[x1, y1]->status == 'b'&&Box1[x1, y1 - 1]->status == 'b')
							 {
								 Rectangle rect2(getX, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 //g->DrawImage(starfieldempty_png, 0, 0, 600, 600); //Added 4/27/2015
								 g->DrawImage(Ship_2_verticalpng, getX, getY - 50);
								 Box1[x1, y1]->status = 'd';

								 Box1[x1, y1 - 1]->status = 'd';
								 Box2[x1, y1]->status = 'd';

								 Box2[x1, y1 - 1]->status = 'd';
								 b2 = 1;
								 dx2 = x1;
								 dy2 = y1 - 1;
							 }
						 }

					 }
					 if (p == 22)
					 {
						 if (x1 + 1 < 12)
						 {
							 if (Box1[x1, y1]->status == 'b'&&Box1[x1 + 1, y1]->status == 'b')
							 {
								 Rectangle rect2(getX, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 g->DrawImage(Ship_2_horizontalpng, getX, getY);
								 Box1[x1, y1]->status = 'e';
								 Box1[x2, y1]->status = 'e';
								 Box2[x1, y1]->status = 'e';
								 Box2[x2, y1]->status = 'e';
								 b2 = 1;
								 dx22 = x1;
								 dy22 = y1;
							 }
						 }
						 else
						 {
							 if (Box1[x1, y1]->status == 'b'&&Box1[x1 - 1, y1]->status == 'b')
							 {
								 Rectangle rect2(getX, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 g->DrawImage(Ship_2_horizontalpng, getX - 50, getY);
								 Box1[x1, y1]->status = 'e';
								 Box1[x1 - 1, y1]->status = 'e';
								 Box2[x1, y1]->status = 'e';
								 Box2[x1 - 1, y1]->status = 'e';
								 b2 = 1;
								 dx22 = x1 - 1;
								 dy22 = y1;
							 }
						 }

					 }
				 }
				 if (b3 == 0)
				 {
					 if (p == 3)
					 {
						 if (y1 + 2 < 12)
						 {
							 if (Box1[x1, y1]->status == 'b'&&Box1[x1, y1 + 1]->status == 'b'&&Box1[x1, y1 + 2]->status == 'b')
							 {
								 Rectangle rect2(getX, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 g->DrawImage(Ship_3_verticalpng, getX, getY);
								 Box1[x1, y1]->status = 'f';
								 Box1[x1, y1 + 1]->status = 'f';
								 Box1[x1, y1 + 2]->status = 'f';
								 Box2[x1, y1]->status = 'f';
								 Box2[x1, y1 + 1]->status = 'f';
								 Box2[x1, y1 + 2]->status = 'f';
								 b3 = 1;
								 dx3 = x1;
								 dy3 = y1;
							 }
						 }
						 else
						 {
							 if (Box1[x1, 11]->status == 'b'&&Box1[x1, 11 - 1]->status == 'b'&&Box1[x1, 11 - 2]->status == 'b')
							 {
								 Rectangle rect2(getX, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 g->DrawImage(Ship_3_verticalpng, getX, 450);
								 Box1[x1, 11]->status = 'f';
								 Box1[x1, 9]->status = 'f';
								 Box1[x1, 10]->status = 'f';
								 Box2[x1, 11]->status = 'f';
								 Box2[x1, 9]->status = 'f';
								 Box2[x1, 10]->status = 'f';
								 b3 = 1;
								 dx3 = x1;
								 dy3 = 9;
							 }
						 }

					 }
					 if (p == 32)
					 {
						 if (x1 + 2 < 12)
						 {
							 if (Box1[x1, y1]->status == 'b'&&Box1[x1 + 1, y1]->status == 'b'&&Box1[x1 + 2, y1]->status == 'b')
							 {
								 Rectangle rect2(getX, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 g->DrawImage(Ship_3_horizontalpng, getX, getY);
								 Box1[x1, y1]->status = 'g';
								 Box1[x1 + 1, y1]->status = 'g';
								 Box1[x1 + 2, y1]->status = 'g';
								 Box2[x1, y1]->status = 'g';
								 Box2[x1 + 1, y1]->status = 'g';
								 Box2[x1 + 2, y1]->status = 'g';
								 b3 = 1;
								 dx32 = x1;
								 dy32 = y1;
							 }
						 }
						 else
						 {
							 if (Box1[11, y1]->status == 'b'&&Box1[11 - 1, y1]->status == 'b'&&Box1[11 - 2, y1]->status == 'b')
							 {
								 Rectangle rect2(getX, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 g->DrawImage(Ship_3_horizontalpng, 450, getY);
								 Box1[11, y1]->status = 'g';
								 Box1[11 - 1, y1]->status = 'g';
								 Box1[11 - 2, y1]->status = 'g';
								 Box2[11, y1]->status = 'g';
								 Box2[11 - 1, y1]->status = 'g';
								 Box2[11 - 2, y1]->status = 'g';
								 b3 = 1;
								 dx32 = 9;
								 dy32 = y1;
							 }
						 }

					 }
				 }
				 if (b4 == 0)
				 {
					 if (p == 4)
					 {
						 if (y1 + 3 < 12)
						 {
							 if (Box1[x1, y1]->status == 'b'&&Box1[x1, y1 + 1]->status == 'b'&&Box1[x1, y1 + 2]->status == 'b'&&Box1[x1, y1 + 3]->status == 'b')
							 {
								 Rectangle rect2(getX, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 g->DrawImage(Ship_4_verticalpng, getX, getY);
								 Box1[x1, y1]->status = 'h';
								 Box1[x1, y1 + 1]->status = 'h';
								 Box1[x1, y1 + 2]->status = 'h';
								 Box1[x1, y1 + 3]->status = 'h';
								 Box2[x1, y1]->status = 'h';
								 Box2[x1, y1 + 1]->status = 'h';
								 Box2[x1, y1 + 2]->status = 'h';
								 Box2[x1, y1 + 3]->status = 'h';
								 b4 = 1;
								 dx4 = x1;
								 dy4 = y1;
							 }
						 }
						 else
						 {
							 if (Box1[x1, 11]->status == 'b'&&Box1[x1, 11 - 1]->status == 'b'&&Box1[x1, 11 - 2]->status == 'b'&&Box1[x1, 11 - 3]->status == 'b')
							 {
								 Rectangle rect2(getX, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 g->DrawImage(Ship_4_verticalpng, getX, 400);
								 Box1[x1, 11]->status = 'h';
								 Box1[x1, 11 - 1]->status = 'h';
								 Box1[x1, 11 - 2]->status = 'h';
								 Box1[x1, 11 - 3]->status = 'h';
								 Box2[x1, 11]->status = 'h';
								 Box2[x1, 11 - 1]->status = 'h';
								 Box2[x1, 11 - 2]->status = 'h';
								 Box2[x1, 11 - 3]->status = 'h';
								 b4 = 1;
								 dx4 = x1;
								 dy4 = 8;
							 }
						 }

					 }
					 if (p == 42)
					 {
						 if (x1 + 3 < 12)
						 {
							 if (Box1[x1, y1]->status == 'b'&&Box1[x1 + 1, y1]->status == 'b'&&Box1[x1 + 2, y1]->status == 'b'&&Box1[x1 + 3, y1]->status == 'b')
							 {
								 Rectangle rect2(getX, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 g->DrawImage(Ship_4_horizontalpng, getX, getY);
								 Box1[x1, y1]->status = 'i';
								 Box1[x1 + 1, y1]->status = 'i';
								 Box1[x1 + 2, y1]->status = 'i';
								 Box1[x1 + 3, y1]->status = 'i';
								 b4 = 1;
								 dx42 = x1;
								 dy42 = y1;
								 Box2[x1, y1]->status = 'i';
								 Box2[x1 + 1, y1]->status = 'i';
								 Box2[x1 + 2, y1]->status = 'i';
								 Box2[x1 + 3, y1]->status = 'i';
							 }
						 }
						 else
						 {
							 if (Box1[11, y1]->status == 'b'&&Box1[11 - 1, y1]->status == 'b'&&Box1[11 - 2, y1]->status == 'b'&&Box1[11 - 3, y1]->status == 'b')
							 {
								 Rectangle rect2(getX, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 g->DrawImage(Ship_4_horizontalpng, 400, getY);
								 Box1[11, y1]->status = 'i';
								 Box1[11 - 1, y1]->status = 'i';
								 Box1[11 - 2, y1]->status = 'i';
								 Box1[11 - 3, y1]->status = 'i';
								 Box2[11, y1]->status = 'i';
								 Box2[11 - 1, y1]->status = 'i';
								 Box2[11 - 2, y1]->status = 'i';
								 Box2[11 - 3, y1]->status = 'i';
								 b4 = 1;
								 dx42 = 8;
								 dy42 = y1;
							 }
						 }

					 }
				 }
				 if (b5 == 0)
				 {
					 if (p == 5)
					 {
						 if (y1 + 4 < 12)
						 {
							 if (Box1[x1, y1]->status == 'b'&&Box1[x1, y1 + 1]->status == 'b'&&Box1[x1, y1 + 2]->status == 'b'&&Box1[x1, y1 + 3]->status == 'b'&&Box1[x1, y1 + 4]->status == 'b')
							 {
								 Rectangle rect2(getX, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 g->DrawImage(Ship_5_verticalpng, getX, getY);
								 Box1[x1, y1]->status = 'j';
								 Box1[x1, y1 + 1]->status = 'j';
								 Box1[x1, y1 + 2]->status = 'j';
								 Box1[x1, y1 + 3]->status = 'j';
								 Box1[x1, y1 + 4]->status = 'j';
								 b5 = 1;
								 dx5 = x1;
								 dy5 = y1;
								 Box2[x1, y1]->status = 'j';
								 Box2[x1, y1 + 1]->status = 'j';
								 Box2[x1, y1 + 2]->status = 'j';
								 Box2[x1, y1 + 3]->status = 'j';
								 Box2[x1, y1 + 4]->status = 'j';
							 }
						 }
						 else
						 {
							 if (Box1[x1, 11]->status == 'b'&&Box1[x1, 11 - 1]->status == 'b'&&Box1[x1, 11 - 2]->status == 'b'&&Box1[x1, 11 - 3]->status == 'b'&&Box1[x1, 11 - 4]->status == 'b')
							 {
								 Rectangle rect2(getX, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 g->DrawImage(Ship_5_verticalpng, getX, 350);
								 Box1[x1, 11]->status = 'j';
								 Box1[x1, 11 - 1]->status = 'j';
								 Box1[x1, 11 - 2]->status = 'j';
								 Box1[x1, 11 - 3]->status = 'j';
								 Box1[x1, 11 - 4]->status = 'j';
								 b5 = 1;
								 dx5 = x1;
								 dy5 = 7;
							 }
						 }

					 }
					 if (p == 52)
					 {
						 if (x1 + 4 < 12)
						 {
							 if (Box1[x1, y1]->status == 'b'&&Box1[x1 + 1, y1]->status == 'b'&&Box1[x1 + 2, y1]->status == 'b'&&Box1[x1 + 3, y1]->status == 'b'&&Box1[x1 + 4, y1]->status == 'b')
							 {
								 Rectangle rect2(getX, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 g->DrawImage(Ship_5_horizontalpng, getX, getY);
								 Box1[x1, y1]->status = 'k';
								 Box1[x1 + 1, y1]->status = 'k';
								 Box1[x1 + 2, y1]->status = 'k';
								 Box1[x1 + 3, y1]->status = 'k';
								 Box1[x1 + 4, y1]->status = 'k';
								 Box2[x1, y1]->status = 'k';
								 Box2[x1 + 1, y1]->status = 'k';
								 Box2[x1 + 2, y1]->status = 'k';
								 Box2[x1 + 3, y1]->status = 'k';
								 Box2[x1 + 4, y1]->status = 'k';
								 b5 = 1;
								 dx52 = x1;
								 dy52 = y1;
							 }
						 }
						 else
						 {
							 if (Box1[11, y1]->status == 'b'&&Box1[11 - 1, y1]->status == 'b'&&Box1[11 - 2, y1]->status == 'b'&&Box1[11 - 3, y1]->status == 'b'&&Box1[11 - 4, y1]->status == 'b')
							 {
								 Rectangle rect2(getX, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 g->DrawImage(Ship_5_horizontalpng, 350, getY);
								 Box1[11, y1]->status = 'k';
								 Box1[11 - 1, y1]->status = 'k';
								 Box1[11 - 2, y1]->status = 'k';
								 Box1[11 - 3, y1]->status = 'k';
								 Box1[11 - 4, y1]->status = 'k';
								 b5 = 1;
								 dx52 = 11 - 4;
								 dy52 = y1;
								 Box2[11, y1]->status = 'k';
								 Box2[11 - 1, y1]->status = 'k';
								 Box2[11 - 2, y1]->status = 'k';
								 Box2[11 - 3, y1]->status = 'k';
								 Box2[11 - 4, y1]->status = 'k';
							 }
						 }

					 }
				 }

				 if (b1 == 1 && b2 == 1 && b3 == 1 && b4 == 1 && b5 == 1)
				 {
					 b1 = 2;
					 b2 = 2;
					 b3 = 2;
					 b4 = 2;
					 b5 = 2;
				 }
	}
	private: System::Void easyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MD(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 /////////////
				 /*

				 mouse event for selection grid

				 also rotates selected ship

				 */
				 /////////////

				 getX = e->X - (e->X % 50);
				 getY = e->Y - (e->Y % 50);
				 t++;
				 pictureBox3->Refresh();
				 g3->DrawImage(starfieldempty_png, 0, 0, 250, 250);
				 if (getX == 0 && getY == 0)
				 {
					 if (t % 2 == 1)
					 {

						 g3->DrawImage(Ship_1_verticalpng, 100, 100); //Updated 4/17/2015
						 p = 1;
					 }
					 else
					 {

						 g3->DrawImage(Ship_1_horizontalpng, 100, 100); //Updated 4/17/2015
						 p = 12;
					 }

					 //<<<<<<< HEAD

					 //=======
					 //>>>>>>> origin/master
				 }
				 if (getX == 0 && getY >= 50 && getY <= 100)
				 {
					 if (t % 2 == 1)
					 {

						 g3->DrawImage(Ship_2_verticalpng, 100, 50); //Updated 4/17/2015
						 p = 2;
					 }
					 else
					 {

						 g3->DrawImage(Ship_2_horizontalpng, 100, 100); //Updated 4/17/2015
						 p = 22;
					 }

					 // Ship_1_horizontalpng
				 }
				 if (getX == 0 && getY >= 150 && getY <= 250)
				 {
					 if (t % 2 == 1)
					 {

						 g3->DrawImage(Ship_3_verticalpng, 100, 50); //Updated 4/17/2015
						 p = 3;
					 }
					 else
					 {

						 g3->DrawImage(Ship_3_horizontalpng, 50, 100); //Updated 4/17/2015
						 p = 32;
					 }


				 }
				 if (getX == 0 && getY >= 300)
				 {
					 if (t % 2 == 1)
					 {
						 ;
						 g3->DrawImage(Ship_4_verticalpng, 100, 50); //Updated 4/17/2015
						 p = 4;
					 }
					 else
					 {

						 g3->DrawImage(Ship_4_horizontalpng, 0, 100); //Updated 4/17/2015
						 p = 42;
					 }


				 }
				 if (getX >= 50)
				 {
					 if (t % 2 == 1)
					 {

						 g3->DrawImage(Ship_5_verticalpng, 100, 0); //Updated 4/17/2015
						 p = 5;
					 }
					 else
					 {

						 g3->DrawImage(Ship_5_horizontalpng, 0, 100); //Updated 4/17/2015
						 p = 52;
					 }


				 }
				 //	 g3->DrawImage(Ship_1_verticalpng, 0, 0);
	}
	private: System::Void MM(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 /* getX = e->X - (e->X % 50);
				 getY = e->Y - (e->Y % 50);
				 textBox2->Text = Convert::ToString(getX);*/



	}
	private: System::Void MM2(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 ///////////
				 /*

				 mouse move event
				 uses selected ship as mouse cursor on pb1 grid

				 */
				 ////////////


				 if (S != 0)
				 {
					 x1 = getX / 50;
					 y1 = getY / 50;

					 /* Rectangle rect1(getX, getY, 49, 49);
					 g->DrawImage(starfieldempty_png, rect1);
					 Rectangle rect2(e->X - (e->X %50), e->Y - (e->Y % 50), 49, 49);
					 g->DrawImage(WhiteBrush, rect2);

					 getX = e->X - (e->X % 50);
					 getY = e->Y - (e->Y % 50);*/

					 if (p == 1)
					 {
						 if (Box1[x1, y1]->status == 'b'&& Box1[x1, y1]->status != 'c')
						 {
							 Rectangle rect1(getX, getY, 49, 49);


							 //g->DrawImage(starfieldempty_png, rect1);
							 g->DrawImage(starfieldempty_png, rect1);
							 if (Box1[(e->X - (e->X % 50)) / 50, (e->Y - (e->Y % 50)) / 50]->status == 'b')
							 {
								 g->DrawImage(Ship_1_verticalpng, e->X - (e->X % 50), e->Y - (e->Y % 50));
							 }
						 }


					 }
					 if (p == 12)
					 {
						 if (Box1[x1, y1]->status == 'b'&& Box1[x1, y1]->status != 'c')
						 {
							 Rectangle rect1(getX, getY, 49, 49);


							 //g->DrawImage(starfieldempty_png, rect1);
							 g->DrawImage(starfieldempty_png, rect1);
							 if (Box1[(e->X - (e->X % 50)) / 50, (e->Y - (e->Y % 50)) / 50]->status == 'b')
							 {
								 g->DrawImage(Ship_1_horizontalpng, e->X - (e->X % 50), e->Y - (e->Y % 50));

							 }
						 }
					 }


					 if (p == 2)
					 {
						 if (y1 + 1 < 12)
						 {
							 if (Box1[x1, y1]->status == 'b'&&Box1[x1, y1 + 1]->status == 'b')
							 {
								 Rectangle rect1(getX, getY, 49, 49);
								 Rectangle rect2(getX, getY + 50, 49, 49);
								 g->DrawImage(starfieldempty_png, rect1);
								 g->DrawImage(starfieldempty_png, rect2);
							 }
						 }
						 else
						 {
							 if (Box1[x1, y1]->status == 'b'&&Box1[x1, y1 - 1]->status == 'b')
							 {
								 Rectangle rect1(getX, getY, 49, 49);
								 Rectangle rect2(getX, getY - 50, 49, 49);
								 g->DrawImage(starfieldempty_png, rect1);
								 g->DrawImage(starfieldempty_png, rect2);
							 }
						 }
						 if (e->Y < 550)
						 {

							 if (Box1[(e->X - (e->X % 50)) / 50, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, (e->Y - (e->Y % 50)) / 50 + 1]->status == 'b')
							 {
								 g->DrawImage(Ship_2_verticalpng, e->X - (e->X % 50), e->Y - (e->Y % 50));
							 }
						 }
						 else
						 {
							 if (Box1[(e->X - (e->X % 50)) / 50, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, (e->Y - (e->Y % 50)) / 50 - 1]->status == 'b')
							 {
								 g->DrawImage(Ship_2_verticalpng, e->X - (e->X % 50), 500);
							 }

						 }







					 }

					 if (p == 22)
					 {
						 if (x1 + 1 < 12)
						 {
							 if (Box1[x1 + 1, y1]->status == 'b'&&Box1[x1, y1]->status == 'b')
							 {


								 Rectangle rect2(getX, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 Rectangle rect1(getX + 50, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect1);

							 }

						 }
						 else
						 {
							 if (Box1[x1 - 1, y1]->status == 'b'&&Box1[x1, y1]->status == 'b')
							 {


								 Rectangle rect2(getX, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 Rectangle rect1(getX - 50, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect1);

							 }
						 }
						 if (e->X < 550)
						 {
							 if (Box1[(e->X - (e->X % 50)) / 50 + 1, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, (e->Y - (e->Y % 50)) / 50]->status == 'b')
							 {
								 g->DrawImage(Ship_2_horizontalpng, e->X - (e->X % 50), e->Y - (e->Y % 50));
							 }

						 }
						 else
						 {
							 if (Box1[(e->X - (e->X % 50)) / 50 - 1, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, (e->Y - (e->Y % 50)) / 50]->status == 'b')
							 {
								 g->DrawImage(Ship_2_horizontalpng, 500, e->Y - (e->Y % 50));
							 }

						 }





					 }


					 if (p == 3)
					 {
						 if (y1 + 2 < 12)
						 {

							 if (Box1[x1, y1]->status == 'b'&& Box1[x1, y1 + 1]->status == 'b'&&Box1[x1, y1 + 2]->status == 'b')
							 {
								 Rectangle rect1(getX, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect1);
								 Rectangle rect2(getX, getY + 50, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 Rectangle rect3(getX, getY + 100, 49, 49);
								 g->DrawImage(starfieldempty_png, rect3);
							 }
						 }
						 else
						 {
							 if (Box1[x1, 11]->status == 'b'&& Box1[x1, 10]->status == 'b'&&Box1[x1, 9]->status == 'b')
							 {
								 Rectangle rect1(getX, 450, 49, 49);
								 g->DrawImage(starfieldempty_png, rect1);
								 Rectangle rect2(getX, 500, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 Rectangle rect3(getX, 550, 49, 49);
								 g->DrawImage(starfieldempty_png, rect3);
							 }
						 }
						 if (e->Y < 500)
						 {
							 if (Box1[(e->X - (e->X % 50)) / 50, (e->Y - (e->Y % 50)) / 50 + 1]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, (e->Y - (e->Y % 50)) / 50 + 2]->status == 'b')
							 {
								 g->DrawImage(Ship_3_verticalpng, e->X - (e->X % 50), e->Y - (e->Y % 50));
							 }

						 }
						 else
						 {
							 if (Box1[(e->X - (e->X % 50)) / 50, 11]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, 10]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, 9]->status == 'b')
							 {
								 g->DrawImage(Ship_3_verticalpng, e->X - (e->X % 50), 450);
							 }

						 }



					 }
					 if (p == 32)
					 {
						 if (x1 + 2 < 12)
						 {

							 if (Box1[x1, y1]->status == 'b'&& Box1[x1 + 1, y1]->status == 'b'&&Box1[x1 + 2, y1]->status == 'b')
							 {
								 Rectangle rect1(getX, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect1);
								 Rectangle rect2(getX + 50, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 Rectangle rect3(getX + 100, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect3);
							 }
						 }
						 else
						 {
							 if (Box1[10, y1]->status == 'b'&& Box1[11, y1]->status == 'b'&&Box1[9, y1]->status == 'b')
							 {
								 Rectangle rect1(450, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect1);
								 Rectangle rect2(500, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 Rectangle rect3(550, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect3);
							 }
						 }
						 if (e->X < 500)
						 {
							 if (Box1[(e->X - (e->X % 50)) / 50 + 1, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50 + 2, (e->Y - (e->Y % 50)) / 50]->status == 'b')
							 {
								 g->DrawImage(Ship_3_horizontalpng, e->X - (e->X % 50), e->Y - (e->Y % 50));
							 }

						 }
						 else
						 {
							 if (Box1[11, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[10, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[9, (e->Y - (e->Y % 50)) / 50]->status == 'b')
							 {
								 g->DrawImage(Ship_3_horizontalpng, 450, e->Y - (e->Y % 50));
							 }

						 }



					 }
					 if (p == 4)
					 {
						 if (y1 + 3 < 12)
						 {

							 if (Box1[x1, y1]->status == 'b'&& Box1[x1, y1 + 1]->status == 'b'&&Box1[x1, y1 + 2]->status == 'b'&&Box1[x1, y1 + 3]->status == 'b')
							 {
								 Rectangle rect1(getX, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect1);
								 Rectangle rect2(getX, getY + 50, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 Rectangle rect3(getX, getY + 100, 49, 49);
								 g->DrawImage(starfieldempty_png, rect3);
								 Rectangle rect4(getX, getY + 150, 49, 49);
								 g->DrawImage(starfieldempty_png, rect4);
							 }
						 }
						 else
						 {
							 if (Box1[x1, 11]->status == 'b'&& Box1[x1, 10]->status == 'b'&&Box1[x1, 9]->status == 'b'&&Box1[x1, 8]->status == 'b')
							 {
								 Rectangle rect1(getX, 450, 49, 49);
								 g->DrawImage(starfieldempty_png, rect1);
								 Rectangle rect2(getX, 500, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 Rectangle rect3(getX, 550, 49, 49);
								 g->DrawImage(starfieldempty_png, rect3);
								 Rectangle rect4(getX, 400, 49, 49);
								 g->DrawImage(starfieldempty_png, rect4);
							 }
						 }
						 if (e->Y < 450)
						 {
							 if (Box1[(e->X - (e->X % 50)) / 50, (e->Y - (e->Y % 50)) / 50 + 1]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, (e->Y - (e->Y % 50)) / 50 + 2]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, (e->Y - (e->Y % 50)) / 50 + 3]->status == 'b')
							 {
								 g->DrawImage(Ship_4_verticalpng, e->X - (e->X % 50), e->Y - (e->Y % 50));
							 }

						 }
						 else
						 {
							 if (Box1[(e->X - (e->X % 50)) / 50, 11]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, 10]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, 9]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, 8]->status == 'b')
							 {
								 g->DrawImage(Ship_4_verticalpng, e->X - (e->X % 50), 400);
							 }

						 }



					 }
					 if (p == 42)
					 {
						 if (x1 + 3 < 12)
						 {

							 if (Box1[x1, y1]->status == 'b'&& Box1[x1 + 1, y1]->status == 'b'&&Box1[x1 + 2, y1]->status == 'b'&&Box1[x1 + 3, y1]->status == 'b')
							 {
								 Rectangle rect1(getX, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect1);
								 Rectangle rect2(getX + 50, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 Rectangle rect3(getX + 100, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect3);
								 Rectangle rect4(getX + 150, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect4);
							 }
						 }
						 else
						 {
							 if (Box1[10, y1]->status == 'b'&& Box1[11, y1]->status == 'b'&&Box1[9, y1]->status == 'b'&&Box1[8, y1]->status == 'b')
							 {
								 Rectangle rect1(450, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect1);
								 Rectangle rect2(500, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 Rectangle rect3(550, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect3);
								 Rectangle rect4(400, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect4);
							 }
						 }
						 if (e->X < 450)
						 {
							 if (Box1[(e->X - (e->X % 50)) / 50 + 1, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50 + 2, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50 + 3, (e->Y - (e->Y % 50)) / 50]->status == 'b')
							 {
								 g->DrawImage(Ship_4_horizontalpng, e->X - (e->X % 50), e->Y - (e->Y % 50));
							 }

						 }
						 else
						 {
							 if (Box1[11, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[10, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[9, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[8, (e->Y - (e->Y % 50)) / 50]->status == 'b')
							 {
								 g->DrawImage(Ship_4_horizontalpng, 400, e->Y - (e->Y % 50));
							 }

						 }



					 }
					 if (p == 5)
					 {
						 if (y1 + 4 < 12)
						 {

							 if (Box1[x1, y1]->status == 'b'&& Box1[x1, y1 + 1]->status == 'b'&&Box1[x1, y1 + 2]->status == 'b'&&Box1[x1, y1 + 3]->status == 'b'&&Box1[x1, y1 + 4]->status == 'b')
							 {
								 Rectangle rect1(getX, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect1);
								 Rectangle rect2(getX, getY + 50, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 Rectangle rect3(getX, getY + 100, 49, 49);
								 g->DrawImage(starfieldempty_png, rect3);
								 Rectangle rect4(getX, getY + 150, 49, 49);
								 g->DrawImage(starfieldempty_png, rect4);
								 Rectangle rect5(getX, getY + 200, 49, 49);
								 g->DrawImage(starfieldempty_png, rect5);
							 }
						 }
						 else
						 {
							 if (Box1[x1, 11]->status == 'b'&& Box1[x1, 10]->status == 'b'&&Box1[x1, 9]->status == 'b'&&Box1[x1, 8]->status == 'b'&&Box1[x1, 7]->status == 'b')
							 {
								 Rectangle rect1(getX, 450, 49, 49);
								 g->DrawImage(starfieldempty_png, rect1);
								 Rectangle rect2(getX, 500, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 Rectangle rect3(getX, 550, 49, 49);
								 g->DrawImage(starfieldempty_png, rect3);
								 Rectangle rect4(getX, 400, 49, 49);
								 g->DrawImage(starfieldempty_png, rect4);
								 Rectangle rect5(getX, 350, 49, 49);
								 g->DrawImage(starfieldempty_png, rect5);
							 }
						 }
						 if (e->Y < 400)
						 {
							 if (Box1[(e->X - (e->X % 50)) / 50, (e->Y - (e->Y % 50)) / 50 + 1]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, (e->Y - (e->Y % 50)) / 50 + 2]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, (e->Y - (e->Y % 50)) / 50 + 3]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, (e->Y - (e->Y % 50)) / 50 + 4]->status == 'b')
							 {
								 g->DrawImage(Ship_5_verticalpng, e->X - (e->X % 50), e->Y - (e->Y % 50));
							 }

						 }
						 else
						 {
							 if (Box1[(e->X - (e->X % 50)) / 50, 11]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, 10]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, 9]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, 8]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, 7]->status == 'b')
							 {
								 g->DrawImage(Ship_5_verticalpng, e->X - (e->X % 50), 350);
							 }

						 }



					 }
					 if (p == 52)
					 {
						 if (x1 + 4 < 12)
						 {

							 if (Box1[x1, y1]->status == 'b'&& Box1[x1 + 1, y1]->status == 'b'&&Box1[x1 + 2, y1]->status == 'b'&&Box1[x1 + 3, y1]->status == 'b'&&Box1[x1 + 4, y1]->status == 'b')
							 {
								 Rectangle rect1(getX, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect1);
								 Rectangle rect2(getX + 50, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 Rectangle rect3(getX + 100, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect3);
								 Rectangle rect4(getX + 150, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect4);
								 Rectangle rect5(getX + 200, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect5);
							 }
						 }
						 else
						 {
							 if (Box1[10, y1]->status == 'b'&& Box1[11, y1]->status == 'b'&&Box1[9, y1]->status == 'b'&&Box1[8, y1]->status == 'b'&&Box1[7, y1]->status == 'b')
							 {
								 Rectangle rect1(450, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect1);
								 Rectangle rect2(500, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect2);
								 Rectangle rect3(550, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect3);
								 Rectangle rect4(400, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect4);
								 Rectangle rect5(350, getY, 49, 49);
								 g->DrawImage(starfieldempty_png, rect5);
							 }
						 }
						 if (e->X < 400)
						 {
							 if (Box1[(e->X - (e->X % 50)) / 50 + 1, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50 + 2, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50 + 3, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[(e->X - (e->X % 50)) / 50 + 4, (e->Y - (e->Y % 50)) / 50]->status == 'b')
							 {
								 g->DrawImage(Ship_5_horizontalpng, e->X - (e->X % 50), e->Y - (e->Y % 50));
							 }

						 }
						 else
						 {
							 if (Box1[11, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[10, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[9, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[8, (e->Y - (e->Y % 50)) / 50]->status == 'b'&&Box1[7, (e->Y - (e->Y % 50)) / 50]->status == 'b')
							 {
								 g->DrawImage(Ship_5_horizontalpng, 350, e->Y - (e->Y % 50));
							 }

						 }



					 }
					 getX = e->X - (e->X % 50);
					 getY = e->Y - (e->Y % 50);


					 //textBox1->Text = Convert::ToString(x1);
					 //textBox2->Text = Convert::ToString(y1);
				 }

	}
	private: System::Void ML(System::Object^  sender, System::EventArgs^  e) {
				 if (p == 1 || p == 12)
				 {
					 if (Box1[getX / 50, getY / 50]->status == 'b')
					 {
						 Rectangle rect1(getX, getY, 49, 49);


						 g->DrawImage(starfieldempty_png, rect1);
					 }


				 }
				 if (p == 2)
				 {
					 if (y1 + 1 < 12)
					 {
						 if (Box1[x1, y1]->status == 'b'&&Box1[x1, y1 + 1]->status == 'b')
						 {
							 Rectangle rect1(getX, getY, 49, 49);
							 Rectangle rect2(getX, getY + 50, 49, 49);
							 g->DrawImage(starfieldempty_png, rect1);
							 g->DrawImage(starfieldempty_png, rect2);
						 }
					 }
					 else
					 {
						 if (Box1[x1, y1]->status == 'b'&&Box1[x1, y1 - 1]->status == 'b')
						 {
							 Rectangle rect1(getX, 500, 49, 49);
							 Rectangle rect2(getX, 550, 49, 49);
							 g->DrawImage(starfieldempty_png, rect1);
							 g->DrawImage(starfieldempty_png, rect2);
						 }
					 }
				 }
				 if (p == 22)
				 {
					 if (x1 + 1 < 12)
					 {
						 if (Box1[x1 + 1, y1]->status == 'b'&&Box1[x1, y1]->status == 'b')
						 {


							 Rectangle rect2(getX, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect2);
							 Rectangle rect1(getX + 50, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect1);

						 }

					 }
					 else
					 {
						 if (Box1[x1 - 1, y1]->status == 'b'&&Box1[x1, y1]->status == 'b')
						 {


							 Rectangle rect2(500, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect2);
							 Rectangle rect1(550, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect1);

						 }
					 }
				 }
				 if (p == 3)
				 {
					 if (y1 + 2 < 12)
					 {

						 if (Box1[x1, y1]->status == 'b'&& Box1[x1, y1 + 1]->status == 'b'&&Box1[x1, y1 + 2]->status == 'b')
						 {
							 Rectangle rect1(getX, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect1);
							 Rectangle rect2(getX, getY + 50, 49, 49);
							 g->DrawImage(starfieldempty_png, rect2);
							 Rectangle rect3(getX, getY + 100, 49, 49);
							 g->DrawImage(starfieldempty_png, rect3);
						 }
					 }
					 else
					 {
						 if (Box1[x1, 11]->status == 'b'&& Box1[x1, 10]->status == 'b'&&Box1[x1, 9]->status == 'b')
						 {
							 Rectangle rect1(getX, 450, 49, 49);
							 g->DrawImage(starfieldempty_png, rect1);
							 Rectangle rect2(getX, 500, 49, 49);
							 g->DrawImage(starfieldempty_png, rect2);
							 Rectangle rect3(getX, 550, 49, 49);
							 g->DrawImage(starfieldempty_png, rect3);
						 }
					 }
				 }
				 if (p == 32)
				 {
					 if (x1 + 2 < 12)
					 {

						 if (Box1[x1, y1]->status == 'b'&& Box1[x1 + 1, y1]->status == 'b'&&Box1[x1 + 2, y1]->status == 'b')
						 {
							 Rectangle rect1(getX, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect1);
							 Rectangle rect2(getX + 50, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect2);
							 Rectangle rect3(getX + 100, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect3);
						 }
					 }
					 else
					 {
						 if (Box1[10, y1]->status == 'b'&& Box1[11, y1]->status == 'b'&&Box1[9, y1]->status == 'b')
						 {
							 Rectangle rect1(450, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect1);
							 Rectangle rect2(500, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect2);
							 Rectangle rect3(550, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect3);
						 }
					 }
				 }
				 if (p == 4)
				 {
					 if (y1 + 3 < 12)
					 {

						 if (Box1[x1, y1]->status == 'b'&& Box1[x1, y1 + 1]->status == 'b'&&Box1[x1, y1 + 2]->status == 'b'&&Box1[x1, y1 + 3]->status == 'b')
						 {
							 Rectangle rect1(getX, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect1);
							 Rectangle rect2(getX, getY + 50, 49, 49);
							 g->DrawImage(starfieldempty_png, rect2);
							 Rectangle rect3(getX, getY + 100, 49, 49);
							 g->DrawImage(starfieldempty_png, rect3);
							 Rectangle rect4(getX, getY + 150, 49, 49);
							 g->DrawImage(starfieldempty_png, rect4);
						 }
					 }
					 else
					 {
						 if (Box1[x1, 11]->status == 'b'&& Box1[x1, 10]->status == 'b'&&Box1[x1, 9]->status == 'b'&&Box1[x1, 8]->status == 'b')
						 {
							 Rectangle rect1(getX, 450, 49, 49);
							 g->DrawImage(starfieldempty_png, rect1);
							 Rectangle rect2(getX, 500, 49, 49);
							 g->DrawImage(starfieldempty_png, rect2);
							 Rectangle rect3(getX, 550, 49, 49);
							 g->DrawImage(starfieldempty_png, rect3);
							 Rectangle rect4(getX, 400, 49, 49);
							 g->DrawImage(starfieldempty_png, rect4);
						 }
					 }
				 }
				 if (p == 42)
				 {
					 if (x1 + 3 < 12)
					 {

						 if (Box1[x1, y1]->status == 'b'&& Box1[x1 + 1, y1]->status == 'b'&&Box1[x1 + 2, y1]->status == 'b'&&Box1[x1 + 3, y1]->status == 'b')
						 {
							 Rectangle rect1(getX, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect1);
							 Rectangle rect2(getX + 50, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect2);
							 Rectangle rect3(getX + 100, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect3);
							 Rectangle rect4(getX + 150, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect4);
						 }
					 }
					 else
					 {
						 if (Box1[10, y1]->status == 'b'&& Box1[11, y1]->status == 'b'&&Box1[9, y1]->status == 'b')
						 {
							 Rectangle rect1(450, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect1);
							 Rectangle rect2(500, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect2);
							 Rectangle rect3(550, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect3);
							 Rectangle rect4(400, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect4);
						 }
					 }
				 }
				 if (p == 5)
				 {
					 if (y1 + 4 < 12)
					 {

						 if (Box1[x1, y1]->status == 'b'&& Box1[x1, y1 + 1]->status == 'b'&&Box1[x1, y1 + 2]->status == 'b'&&Box1[x1, y1 + 3]->status == 'b'&&Box1[x1, y1 + 4]->status == 'b')
						 {
							 Rectangle rect1(getX, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect1);
							 Rectangle rect2(getX, getY + 50, 49, 49);
							 g->DrawImage(starfieldempty_png, rect2);
							 Rectangle rect3(getX, getY + 100, 49, 49);
							 g->DrawImage(starfieldempty_png, rect3);
							 Rectangle rect4(getX, getY + 150, 49, 49);
							 g->DrawImage(starfieldempty_png, rect4);
							 Rectangle rect5(getX, getY + 200, 49, 49);
							 g->DrawImage(starfieldempty_png, rect5);
						 }
					 }
					 else
					 {
						 if (Box1[x1, 11]->status == 'b'&& Box1[x1, 10]->status == 'b'&&Box1[x1, 9]->status == 'b'&&Box1[x1, 8]->status == 'b'&&Box1[x1, 7]->status == 'b')
						 {
							 Rectangle rect1(getX, 450, 49, 49);
							 g->DrawImage(starfieldempty_png, rect1);
							 Rectangle rect2(getX, 500, 49, 49);
							 g->DrawImage(starfieldempty_png, rect2);
							 Rectangle rect3(getX, 550, 49, 49);
							 g->DrawImage(starfieldempty_png, rect3);
							 Rectangle rect4(getX, 400, 49, 49);
							 g->DrawImage(starfieldempty_png, rect4);
							 Rectangle rect5(getX, 350, 49, 49);
							 g->DrawImage(starfieldempty_png, rect5);
						 }
					 }
				 }
				 if (p == 52)
				 {
					 if (x1 + 4 < 12)
					 {

						 if (Box1[x1, y1]->status == 'b'&& Box1[x1 + 1, y1]->status == 'b'&&Box1[x1 + 2, y1]->status == 'b'&&Box1[x1 + 3, y1]->status == 'b'&&Box1[x1 + 4, y1]->status == 'b')
						 {
							 Rectangle rect1(getX, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect1);
							 Rectangle rect2(getX + 50, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect2);
							 Rectangle rect3(getX + 100, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect3);
							 Rectangle rect4(getX + 150, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect4);
							 Rectangle rect5(getX + 200, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect5);
						 }
					 }
					 else
					 {
						 if (Box1[10, y1]->status == 'b'&& Box1[11, y1]->status == 'b'&&Box1[9, y1]->status == 'b')
						 {
							 Rectangle rect1(450, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect1);
							 Rectangle rect2(500, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect2);
							 Rectangle rect3(550, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect3);
							 Rectangle rect4(400, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect4);
							 Rectangle rect5(350, getY, 49, 49);
							 g->DrawImage(starfieldempty_png, rect5);
						 }
					 }
				 }

	}
	private: System::Void newGameToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 //////////////////
				 /*

				 starts new game from menu

				 */
				 /////////////////////



				 S = 1;
				 Box1 = gcnew array<player^, 2>(12, 12);
				 for (int row = 0; row < numrow; row++)
				 {
					 for (int col = 0; col < numcol; col++)
					 {
						 Rectangle rect1(row * 50, col * 50, 49, 49);
						 Box1[row, col] = gcnew player(row, col, 'b');
						 g->DrawImage(starfieldempty_png, rect1);



					 }
				 }


				 g2->DrawImage(Ship_1_verticalpng, 0, 0);
				 g2->DrawImage(Ship_2_verticalpng, 0, 51);
				 g2->DrawImage(Ship_3_verticalpng, 0, 151);
				 g2->DrawImage(Ship_4_verticalpng, 0, 301);
				 g2->DrawImage(Ship_5_verticalpng, 51, 0);
				 g3->DrawImage(starfieldempty_png, 0, 0, 250, 250);
	}
	private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
	}
	private: System::Void DC(System::Object^  sender, System::EventArgs^  e) {

				 if (Box1[x1, y1]->status == 'c')
				 {
					 p = 11;
					 Rectangle rect6(getX, getY, 49, 49);
					 g->DrawImage(starfieldempty_png, rect6);
					 Box1[x1, y1]->status = 'b';
					 b1 = 0;
				 }
				 if (Box1[x1, y1]->status == 'd')
				 {
					 p = 11;
					 Rectangle rect6(dx2 * 50, dy2 * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect6);
					 Rectangle rect1(dx2 * 50, (dy2 + 1) * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect1);
					 Box1[dx2, dy2]->status = 'b';
					 Box1[dx2, dy2 + 1]->status = 'b';
					 b2 = 0;
				 }
				 if (Box1[x1, y1]->status == 'e')
				 {
					 p = 11;
					 Rectangle rect6(dx22 * 50, dy22 * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect6);
					 Rectangle rect1((dx22 + 1) * 50, dy22 * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect1);
					 Box1[dx22, dy22]->status = 'b';
					 Box1[dx22 + 1, dy22]->status = 'b';
					 b2 = 0;
				 }

				 if (Box1[x1, y1]->status == 'f')
				 {
					 p = 11;
					 Rectangle rect6(dx3 * 50, dy3 * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect6);
					 Rectangle rect1(dx3 * 50, (dy3 + 1) * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect1);
					 Box1[dx3, dy3]->status = 'b';
					 Box1[dx3, dy3 + 1]->status = 'b';
					 Rectangle rect2(dx3 * 50, (dy3 + 2) * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect2);
					 Box1[dx3, dy3 + 2]->status = 'b';
					 b3 = 0;
				 }
				 if (Box1[x1, y1]->status == 'g')
				 {
					 p = 11;
					 Rectangle rect6(dx32 * 50, dy32 * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect6);
					 Rectangle rect2((dx32 + 2) * 50, dy32 * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect2);
					 Rectangle rect1((dx32 + 1) * 50, dy32 * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect1);
					 Box1[dx32, dy32]->status = 'b';
					 Box1[dx32 + 1, dy32]->status = 'b';
					 Box1[dx32 + 2, dy32]->status = 'b';
					 b3 = 0;
				 }
				 if (Box1[x1, y1]->status == 'h')
				 {
					 p = 11;
					 Rectangle rect6(dx4 * 50, dy4 * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect6);
					 Rectangle rect1(dx4 * 50, (dy4 + 1) * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect1);
					 Rectangle rect2(dx4 * 50, (dy4 + 2) * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect2);
					 Rectangle rect3(dx4 * 50, (dy4 + 3) * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect3);
					 Box1[dx4, dy4]->status = 'b';
					 Box1[dx4, dy4 + 1]->status = 'b';
					 Box1[dx4, dy4 + 2]->status = 'b';
					 Box1[dx4, dy4 + 3]->status = 'b';
					 b4 = 0;
				 }
				 if (Box1[x1, y1]->status == 'i')
				 {
					 p = 11;
					 Rectangle rect6(dx42 * 50, dy42 * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect6);
					 Rectangle rect1((dx42 + 1) * 50, dy42 * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect1);
					 Rectangle rect2((dx42 + 2) * 50, dy42 * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect2);
					 Rectangle rect3((dx42 + 3) * 50, dy42 * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect3);
					 Box1[dx42, dy42]->status = 'b';
					 Box1[dx42 + 1, dy42]->status = 'b';

					 Box1[dx42 + 2, dy42]->status = 'b';

					 Box1[dx42 + 3, dy42]->status = 'b';
					 b4 = 0;
				 }

				 if (Box1[x1, y1]->status == 'j')
				 {
					 p = 11;
					 Rectangle rect6(dx5 * 50, dy5 * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect6);
					 Rectangle rect1(dx5 * 50, (dy5 + 1) * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect1);
					 Rectangle rect2(dx5 * 50, (dy5 + 2) * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect2);
					 Rectangle rect3(dx5 * 50, (dy5 + 3) * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect3);
					 Rectangle rect4(dx5 * 50, (dy5 + 4) * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect4);
					 Box1[dx5, dy5]->status = 'b';
					 Box1[dx5, dy5 + 1]->status = 'b';
					 Box1[dx5, dy5 + 2]->status = 'b';
					 Box1[dx5, dy5 + 3]->status = 'b';
					 Box1[dx5, dy5 + 4]->status = 'b';
					 b5 = 0;
				 }
				 if (Box1[x1, y1]->status == 'k')
				 {
					 p = 11;
					 Rectangle rect6(dx52 * 50, dy52 * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect6);
					 Rectangle rect1((dx52 + 1) * 50, dy52 * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect1);
					 Rectangle rect2((dx52 + 2) * 50, dy52 * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect2);
					 Rectangle rect3((dx52 + 3) * 50, dy52 * 50, 49, 49);
					 Rectangle rect4((dx52 + 4) * 50, dy52 * 50, 49, 49);
					 g->DrawImage(starfieldempty_png, rect3);
					 g->DrawImage(starfieldempty_png, rect4);
					 Box1[dx52, dy52]->status = 'b';
					 Box1[dx52 + 1, dy52]->status = 'b';

					 Box1[dx52 + 2, dy52]->status = 'b';

					 Box1[dx52 + 3, dy52]->status = 'b';
					 Box1[dx52 + 4, dy52]->status = 'b';
					 b5 = 0;
				 }
	}
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MM3(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 if (S != 0)
				 {
					 if (Box2[getX2 / 25, getY2 / 25]->status != 'y'&&Box2[getX2 / 25, getY2 / 25]->status != 'z')
					 {
						 Rectangle rect1(getX2, getY2, 24, 24);
						 //g4->DrawImage(yellowBrush, rect1);
						 g4->DrawImage(starfieldempty_png, rect1);
					 }
					 if (Box2[(e->X - (e->X % 25)) / 25, (e->Y - (e->Y % 25)) / 25]->status != 'y'&&Box2[(e->X - (e->X % 25)) / 25, (e->Y - (e->Y % 25)) / 25]->status != 'z')
					 {
						 Rectangle rect2(e->X - (e->X % 25), e->Y - (e->Y % 25), 24, 24);
						 //g4->DrawImage(blackBrush, rect2);
						 g4->DrawImage(starfieldempty_png, rect2);
					 }


					 getX2 = e->X - (e->X % 25);
					 getY2 = e->Y - (e->Y % 25);
				 }


	}
	private: System::Void ML2(System::Object^  sender, System::EventArgs^  e) {
				 if (S != 0)
				 {
					 if (Box2[getX2 / 25, getY2 / 25]->status != 'y')
					 {
						 Rectangle rect1(getX2, getY2, 24, 24);
						 //g4->DrawImage(yellowBrush, rect1);
						 g4->DrawImage(starfieldempty_png, rect1); //Added 4/27/2015

					 }

				 }
	}
	private: System::Void MD3(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 int aix;
				 int aiy;
				 srand(time(NULL));
				 aix = rand() % 11 + 0;
				 aiy = rand() % 11 + 0;
				 /* do
				 {
				 ai1x =rand() % 12 + 0;
				 ai1y = rand() % 12 + 0;

				 } while (Box2[ai1x, ai1y]->status != 'b');*/

				 //g->DrawImage(backG, 0, 0);
				 if (b1 == 2 && b2 == 2 && b3 == 2 && b4 == 2 && b5 == 2)
				 {
					 if (Box2[getX2 / 25, getY2 / 25]->status != 'b'&&Box2[getX2 / 25, getY2 / 25]->status != 'y')
					 {
						 Box2[getX2 / 25, getY2 / 25]->status = 'y';
						 Rectangle rect1(getX2, getY2, 24, 24);
						 //g4->DrawImage(blackBrush, rect1);
						 g4->DrawImage(hit_png, rect1);
						 pw++;

					 }
					 else
					 {
						 if (Box2[getX2 / 25, getY2 / 25]->status == 'b')
						 {
							 Box2[getX2 / 25, getY2 / 25]->status = 'y';
							 Rectangle rect1(getX2, getY2, 24, 24);
							 //g4->DrawImage(redBrush, rect1);
							 g4->DrawImage(miss_png, rect1);
						 }

					 }

					 if (Box1[aix, aiy]->status != 'b')
					 {
						 Box2[aix / 25, aiy / 25]->status = 'y';
						 Rectangle rect1(aix * 50, aiy * 50, 49, 49);
						 //g->DrawImage(blackBrush, rect1);
						 g->DrawImage(hit_png, rect1);

					 }
					 else
					 {
						 Box2[aix / 25, aiy / 25]->status = 'y';
						 Rectangle rect1(aix * 50, aiy * 50, 49, 49);

						 //g->DrawImage(redBrush, rect1);
						 g->DrawImage(miss_png, rect1);
					 }
					 if (pw == 15)
					 {
						 MessageBox::Show("you win");
					 }
				 }
	}
	private: System::Void playgamebutton_Click(System::Object^  sender, System::EventArgs^  e)
	{
				 //Get Ship Placement
				 //draw image
				 //g4->DrawImage(starfieldgrid_png, 0, 0, 300, 300);
				 pictureBox2->Refresh(); //Added 4/27/2015
				 // g->DrawImage(starfieldgrid_png, 0, 0, 600, 600);
	}
	};
}

/*
System::Void Computer_move()
{

srand(time(NULL));
int x = rand() % 40 + 0;
int y = rand() % 40 + 0;
//Box1[x, y]->status = 'r';

/*
Void draw_grid(){

for (int row = 0; row < NUMROWS; row++){
for (int col = 0; col < NUMCOLS; col++){
int x = col * LRGCELLSIZE;
int y = row * LRGCELLSIZE;

Rectangle grids = Rectangle(x, y, LRGCELLSIZE - 1, LRGCELLSIZE - 1);
g->DrawRectangle(blackBrush, grids);
}
}
}





*/

//notes
/*
large cell size == 40
small cell size == 20
*/
