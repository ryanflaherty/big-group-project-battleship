#pragma once

#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include "player.h"

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
		//array <player^, 2>^ Box1;
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
		array <player^, 2>^ Box1;

	/////GRAPHICS//////////////	 
		Graphics^ g,^g2,^g3;
		Pen^ blackBrush;
		Brush^ yellowBrush;
		////////Player Array////
		//array <player^, 2>^ PLAYER_GRID;

		/////GRAPHICS//////////////	 
		//Graphics^ g;
		//Graphics^ g2; //[Added 4/2/2015] Picture Box 2
		Graphics^ gselect; //[Added 4/6/2015] This is for the Cursor
		//Pen^ blackBrush;
		Brush^ WhiteBrush;
		///Bitmap^ MapGrid = gcnew Bitmap("Graphics/(50x250)_Colony_CarrierShip_[5Cells].png");
		//Bitmap^ Ship_5 = gcnew Bitmap("Graphics/(250x50)_Colony_CarrierShip_[5Cells].png");

		///////////////////// Put Graphics Here /////////////////////////
		Bitmap^ starfieldempty_png = gcnew Bitmap("Graphics/(480x480)_Starfield[Empty].png"); //Empty Grid Picture
		Bitmap^ starfieldgrid_png = gcnew Bitmap("Graphics/(480x480)_Starfield[Grid].png"); //Picture with Grid [[[Commented out because MAPGrid is already used for this picture]]]
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
		// HIT SHIP Graphic PNG [Update added 4/2/2015]
		Bitmap^ hit_png = gcnew Bitmap("Graphics/(50x50)_Hit_Cell.png"); //5 Cell Carrier Ship Facing Vertically
		// MISS Graphic PNG [Update added 4/2/2015]
		Bitmap^ miss_png = gcnew Bitmap("Graphics/(50x50)_Miss_Cell.png"); //5 Cell Carrier Ship Facing Horizontally
		// Cursor Target Select - FillRectangle
		Bitmap^ select_png = gcnew Bitmap("Graphics/(50x50)Target_Select_Cell[Cursor_FillRectangle].png");
		////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////



		/////CONST INTS//////
		static const int LrgGridSize = 480;
		static const int SmallGridSize = 240;
		static const int NUMROWS = 12;
		static const int NUMCOLS = 12;
		static const int LRGCELLSIZE = 40;
		static const int smallCELLSIZE = 20;

		const char isEmpty = '0'; // [Update added 4/2/2015]
		const char isHit = 'X'; // [Update added 4/2/2015]
		const char isShip = 'S'; // [Update added 4/2/2015]

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newGameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveGameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->difficultyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->easyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hardToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hardAsBallsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::PowderBlue;
			this->pictureBox1->Location = System::Drawing::Point(12, 60);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(600, 600);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MouseD);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MM2);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(628, 75);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(100, 500);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MD);
			this->pictureBox2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MM);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(368, 12);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(150, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(368, 38);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(150, 20);
			this->textBox3->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(681, 621);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(108, 39);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Start Game";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(734, 75);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(250, 250);
			this->pictureBox3->TabIndex = 6;
			this->pictureBox3->TabStop = false;
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->difficultyToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
			this->menuStrip1->Size = System::Drawing::Size(884, 24);
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
			this->easyToolStripMenuItem->Text = L"Easy";
			this->easyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::easyToolStripMenuItem_Click);
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(987, 666);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Battle Starships!";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
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
		int t=0;
		int p;
		int x1;
		int y1;
		int x2;
		int y2;
	
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

		player PlayerClass;


		int numrow = 40;
		int numcol = 40;

				 /*
				 g = pictureBox1->CreateGraphics();
				 Box1 = gcnew array<player^, 2>(12, 12);
				 for (int row = 0; row < numrow; row++)
				 {
				 for (int col = 0; col < numcol; col++)
				 {

				 Box1[row, col] = gcnew player(row, col, 'b');




					 }
				 }/*
	
				 */

				 g = pictureBox1->CreateGraphics();
				 g2 = pictureBox2->CreateGraphics();
				 g3 = pictureBox3->CreateGraphics();
				 

				 

				 g = pictureBox1->CreateGraphics(); //Large Picture Box for the Starfield Grid

				 g2 = pictureBox2->CreateGraphics();  //Smaller Picture Box on the Right for the Empty Starfield Grid [Added 4/2/2015]
				
				 gselect = pictureBox1->CreateGraphics(); //[Added 4/6/2015] creates target in pictureBox1

				 blackBrush = gcnew System::Drawing::Pen(Color::Black);

				 yellowBrush = gcnew System::Drawing::SolidBrush(Color::White);

				 button1->Hide();
				 textBox2->Hide();
				 textBox3->Hide();

				 PlayerClass.setStart(false);

	}
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
	}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 /*
			 S = 1; 
			 Box1 = gcnew array<player^, 2>(12, 12);
			 for (int row = 0; row < numrow; row++)
			 {
				 for (int col = 0; col < numcol; col++)
				 {
					 Rectangle rect1(row * 50, col * 50, 49, 49);
					 Box1[row, col] = gcnew player(row, col, 'b');
					 g->FillRectangle(yellowBrush, rect1);



				 }
			 }
			
			
			 g2->DrawImage(Ship_1_verticalpng, 0, 0);
			 g2->DrawImage(Ship_2_verticalpng, 0, 51);
			 g2->DrawImage(Ship_3_verticalpng, 0, 151);
			 g2->DrawImage(Ship_4_verticalpng, 0, 301);
			 g2->DrawImage(Ship_5_verticalpng, 51, 0);*/
			 /*
			 g2->DrawImage(B12, 102, 0);
			 g2->DrawImage(B32, 102, 51);
			 g2->DrawImage(B42, 102, 101);
			 g2->DrawImage(B52, 102, 151);*/
}
	private: System::Void MouseD(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 /* Rectangle WhiteRect = Rectangle(e->X - (e->X % LRGCELLSIZE), e->Y - (e->Y % LRGCELLSIZE), LRGCELLSIZE - 1, LRGCELLSIZE - 1);
				  g->DrawImage(MapGrid, 0, 0, 480, 480);
				  g->FillRectangle(yellowBrush, WhiteRect);*/
				 getX = e->X - (e->X % 50);
				 getY = e->Y - (e->Y % 50);
				 x1 = getX / 50;
				 y1 = getY / 50;
				 y2 = getY / 50 + 1;
				 x2 = getX / 50 + 1;
				 //	 S =0;
				 if (Box1[x1, y1]->status == 'b')
				 {
					 if (p == 1)
					 {
						 Rectangle rect2(getX, getY, 49, 49);
						 g->FillRectangle(yellowBrush, rect2);
						 g->DrawImage(Ship_1_verticalpng, getX, getY);
						 Box1[x1, y1]->status = 'c';
					 }
					 if (p == 12)
					 {
						 Rectangle rect2(getX, getY, 49, 49);
						 g->FillRectangle(yellowBrush, rect2);
						 g->DrawImage(Ship_1_horizontalpng, getX, getY);
						 Box1[x1, y1]->status = 'c';
					 }
				 }

				 if (p == 2)
				 {
					 if (y1 + 1 < 12)
					 {
						 if (Box1[x1, y1]->status == 'b'&&Box1[x1, y1 + 1]->status == 'b')
						 {
							 Rectangle rect2(getX, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 g->DrawImage(Ship_2_verticalpng, getX, getY);
							 Box1[x1, y1]->status = 'c';

							 Box1[x1, y2]->status = 'c';
						 }
					 }
					 else
					 {
						 if (Box1[x1, y1]->status == 'b'&&Box1[x1, y1 - 1]->status == 'b')
						 {
							 Rectangle rect2(getX, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 g->DrawImage(Ship_2_verticalpng, getX, getY - 50);
							 Box1[x1, y1]->status = 'c';

							 Box1[x1, y1 - 1]->status = 'c';
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
							 g->FillRectangle(yellowBrush, rect2);
							 g->DrawImage(Ship_2_horizontalpng, getX, getY);
							 Box1[x1, y1]->status = 'c';
							 Box1[x2, y1]->status = 'c';
						 }
					 }
					 else
					 {
						 if (Box1[x1, y1]->status == 'b'&&Box1[x1 - 1, y1]->status == 'b')
						 {
							 Rectangle rect2(getX, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 g->DrawImage(Ship_2_horizontalpng, getX - 50, getY);
							 Box1[x1, y1]->status = 'c';
							 Box1[x1 - 1, y1]->status = 'c';
						 }
					 }

				 }
				 if (p == 3)
				 {
					 if (y1 + 2 < 12)
					 {
						 if (Box1[x1, y1]->status == 'b'&&Box1[x1, y1 + 1]->status == 'b'&&Box1[x1, y1 + 2]->status == 'b')
						 {
							 Rectangle rect2(getX, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 g->DrawImage(Ship_3_verticalpng, getX, getY);
							 Box1[x1, y1]->status = 'c';
							 Box1[x1, y1 + 1]->status = 'c';
							 Box1[x1, y1 + 2]->status = 'c';
						 }
					 }
					 else
					 {
						 if (Box1[x1, 11]->status == 'b'&&Box1[x1, 11 - 1]->status == 'b'&&Box1[x1, 11 - 2]->status == 'b')
						 {
							 Rectangle rect2(getX, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 g->DrawImage(Ship_3_verticalpng, getX, 450);
							 Box1[x1, 11]->status = 'c';
							 Box1[x1, 9]->status = 'c';
							 Box1[x1, 10]->status = 'c';
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
							 g->FillRectangle(yellowBrush, rect2);
							 g->DrawImage(Ship_3_horizontalpng, getX, getY);
							 Box1[x1, y1]->status = 'c';
							 Box1[x1 + 1, y1]->status = 'c';
							 Box1[x1 + 2, y1]->status = 'c';
						 }
					 }
					 else
					 {
						 if (Box1[11, y1]->status == 'b'&&Box1[11 - 1, y1]->status == 'b'&&Box1[11 - 2, y1]->status == 'b')
						 {
							 Rectangle rect2(getX, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 g->DrawImage(Ship_3_horizontalpng, 450, getY);
							 Box1[11, y1]->status = 'c';
							 Box1[11 - 1, y1]->status = 'c';
							 Box1[11 - 2, y1]->status = 'c';
						 }
					 }

				 }
				 if (p == 4)
				 {
					 if (y1 + 3 < 12)
					 {
						 if (Box1[x1, y1]->status == 'b'&&Box1[x1, y1 + 1]->status == 'b'&&Box1[x1, y1 + 2]->status == 'b'&&Box1[x1, y1 + 3]->status == 'b')
						 {
							 Rectangle rect2(getX, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 g->DrawImage(Ship_4_verticalpng, getX, getY);
							 Box1[x1, y1]->status = 'c';
							 Box1[x1, y1 + 1]->status = 'c';
							 Box1[x1, y1 + 2]->status = 'c';
							 Box1[x1, y1 + 3]->status = 'c';
						 }
					 }
					 else
					 {
						 if (Box1[x1, 11]->status == 'b'&&Box1[x1, 11 - 1]->status == 'b'&&Box1[x1, 11 - 2]->status == 'b'&&Box1[x1, 11 - 3]->status == 'b')
						 {
							 Rectangle rect2(getX, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 g->DrawImage(Ship_4_verticalpng, getX, 400);
							 Box1[x1, 11]->status = 'c';
							 Box1[x1, 11 - 1]->status = 'c';
							 Box1[x1, 11 - 2]->status = 'c';
							 Box1[x1, 11 - 3]->status = 'c';
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
							 g->FillRectangle(yellowBrush, rect2);
							 g->DrawImage(Ship_4_horizontalpng, getX, getY);
							 Box1[x1, y1]->status = 'c';
							 Box1[x1 + 1, y1]->status = 'c';
							 Box1[x1 + 2, y1]->status = 'c';
							 Box1[x1 + 3, y1]->status = 'c';
						 }
					 }
					 else
					 {
						 if (Box1[11, y1]->status == 'b'&&Box1[11 - 1, y1]->status == 'b'&&Box1[11 - 2, y1]->status == 'b'&&Box1[11 - 3, y1]->status == 'b')
						 {
							 Rectangle rect2(getX, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 g->DrawImage(Ship_4_horizontalpng, 400, getY);
							 Box1[11, y1]->status = 'c';
							 Box1[11 - 1, y1]->status = 'c';
							 Box1[11 - 2, y1]->status = 'c';
							 Box1[11 - 3, y1]->status = 'c';
						 }
					 }

				 }
				 if (p == 5)
				 {
					 if (y1 + 4 < 12)
					 {
						 if (Box1[x1, y1]->status == 'b'&&Box1[x1, y1 + 1]->status == 'b'&&Box1[x1, y1 + 2]->status == 'b'&&Box1[x1, y1 + 3]->status == 'b'&&Box1[x1, y1 + 4]->status == 'b')
						 {
							 Rectangle rect2(getX, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 g->DrawImage(Ship_5_verticalpng, getX, getY);
							 Box1[x1, y1]->status = 'c';
							 Box1[x1, y1 + 1]->status = 'c';
							 Box1[x1, y1 + 2]->status = 'c';
							 Box1[x1, y1 + 3]->status = 'c';
							 Box1[x1, y1 + 4]->status = 'c';
						 }
					 }
					 else
					 {
						 if (Box1[x1, 11]->status == 'b'&&Box1[x1, 11 - 1]->status == 'b'&&Box1[x1, 11 - 2]->status == 'b'&&Box1[x1, 11 - 3]->status == 'b'&&Box1[x1, 11 - 4]->status == 'b')
						 {
							 Rectangle rect2(getX, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 g->DrawImage(Ship_5_verticalpng, getX, 350);
							 Box1[x1, 11]->status = 'c';
							 Box1[x1, 11 - 1]->status = 'c';
							 Box1[x1, 11 - 2]->status = 'c';
							 Box1[x1, 11 - 3]->status = 'c';
							 Box1[x1, 11 - 4]->status = 'c';
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
							 g->FillRectangle(yellowBrush, rect2);
							 g->DrawImage(Ship_5_horizontalpng, getX, getY);
							 Box1[x1, y1]->status = 'c';
							 Box1[x1 + 1, y1]->status = 'c';
							 Box1[x1 + 2, y1]->status = 'c';
							 Box1[x1 + 3, y1]->status = 'c';
							 Box1[x1 + 4, y1]->status = 'c';
						 }
					 }
					 else
					 {
						 if (Box1[11, y1]->status == 'b'&&Box1[11 - 1, y1]->status == 'b'&&Box1[11 - 2, y1]->status == 'b'&&Box1[11 - 3, y1]->status == 'b'&&Box1[11 - 4, y1]->status == 'b')
						 {
							 Rectangle rect2(getX, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 g->DrawImage(Ship_5_horizontalpng, 350, getY);
							 Box1[11, y1]->status = 'c';
							 Box1[11 - 1, y1]->status = 'c';
							 Box1[11 - 2, y1]->status = 'c';
							 Box1[11 - 3, y1]->status = 'c';
							 Box1[11 - 4, y1]->status = 'c';
						 }
					 }
				 }
	}
			 
	//private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) //START GAME
	//{
	//			 g2->DrawImage(starfieldempty_png, 0, 0, SmallGridSize, SmallGridSize); //[Added 4/2/2015]

	//}

	/*
	private: System::Void MouseD(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{
				 if (PlayerClass.getStart())
				 {

					 int new_x = e->X - (e->X % LRGCELLSIZE);
					 int new_y = e->Y - (e->Y % LRGCELLSIZE);
					 
					 if (new_x >= LRGCELLSIZE && new_y >= LRGCELLSIZE)
					 {
						 Rectangle WhiteRect = Rectangle(new_x + 1, new_y + 1, LRGCELLSIZE - 1, LRGCELLSIZE - 1);
						 g->DrawImage(starfieldgrid_png, 0, 0, LrgGridSize, LrgGridSize);
						 gselect->DrawImage(select_png, new_x + 1, new_y + 1, LRGCELLSIZE, LRGCELLSIZE); //[Added 4/6/2015] creates target on the cell clicked
						 //g->FillRectangle(WhiteBrush, WhiteRect); //Commented out to replace whitebrush with target
					 }
				 }

	}*/


	private: System::Void easyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	}

			 

private: System::Void MD(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 getX = e->X - (e->X % 50);
			 getY = e->Y - (e->Y % 50);
			 t++;
			 pictureBox3->Refresh();
			 if (getX == 0 && getY == 0)
			 {
				 if (t % 2 == 1)
				 {
					 g3->DrawImage(Ship_1_verticalpng, getX, getY);
					 p = 1;
				 }
				 else
				 {
					 g3->DrawImage(Ship_1_horizontalpng, 0, 0);
					 p = 12;
				 }

			 }
			 if (getX == 0 && getY >= 50 && getY <= 100)
			 {
				 if (t % 2 == 1)
				 {
					 g3->DrawImage(Ship_2_verticalpng, getX, getY);
					 p = 2;
				 }
				 else
				 {
					 g3->DrawImage(Ship_2_horizontalpng, 0, 0);
					 p = 22;
				 }

				 // Ship_1_horizontalpng
			 }
			 if (getX == 0 && getY >= 150 && getY <= 250)
			 {
				 if (t % 2 == 1)
				 {
					 g3->DrawImage(Ship_3_verticalpng, getX, 0);
					 p = 3;
				 }
				 else
				 {
					 g3->DrawImage(Ship_3_horizontalpng, 0, 0);
					 p = 32;
				 }


			 }
			 if (getX == 0 && getY >= 300)
			 {
				 if (t % 2 == 1)
				 {
					 g3->DrawImage(Ship_4_verticalpng, getX, 0);
					 p = 4;
				 }
				 else
				 {
					 g3->DrawImage(Ship_4_horizontalpng, 0, 0);
					 p = 42;
				 }


			 }
			 if (getX >= 50)
			 {
				 if (t % 2 == 1)
				 {
					 g3->DrawImage(Ship_5_verticalpng, 0, 0);
					 p = 5;
				 }
				 else
				 {
					 g3->DrawImage(Ship_5_horizontalpng, 0, 0);
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
			 if (S != 0)
			 {
				 x1 = getX / 50;
				 y1 = getY / 50;

				 /* Rectangle rect1(getX, getY, 49, 49);
				 g->FillRectangle(yellowBrush, rect1);
				 Rectangle rect2(e->X - (e->X %50), e->Y - (e->Y % 50), 49, 49);
				 g->FillRectangle(WhiteBrush, rect2);

				 getX = e->X - (e->X % 50);
				 getY = e->Y - (e->Y % 50);*/

				 if (p == 1)
				 {
					 if (Box1[x1, y1]->status == 'b'&& Box1[x1, y1]->status != 'c')
					 {
						 Rectangle rect1(getX, getY, 49, 49);


						 g->FillRectangle(yellowBrush, rect1);
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


						 g->FillRectangle(yellowBrush, rect1);
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
							 g->FillRectangle(yellowBrush, rect1);
							 g->FillRectangle(yellowBrush, rect2);
						 }
					 }
					 else
					 {
						 if (Box1[x1, y1]->status == 'b'&&Box1[x1, y1 - 1]->status == 'b')
						 {
							 Rectangle rect1(getX, getY, 49, 49);
							 Rectangle rect2(getX, getY - 50, 49, 49);
							 g->FillRectangle(yellowBrush, rect1);
							 g->FillRectangle(yellowBrush, rect2);
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
							 g->FillRectangle(yellowBrush, rect2);
							 Rectangle rect1(getX + 50, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect1);

						 }

					 }
					 else
					 {
						 if (Box1[x1 - 1, y1]->status == 'b'&&Box1[x1, y1]->status == 'b')
						 {


							 Rectangle rect2(getX, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 Rectangle rect1(getX - 50, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect1);

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
							 g->FillRectangle(yellowBrush, rect1);
							 Rectangle rect2(getX, getY + 50, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 Rectangle rect3(getX, getY + 100, 49, 49);
							 g->FillRectangle(yellowBrush, rect3);
						 }
					 }
					 else
					 {
						 if (Box1[x1, 11]->status == 'b'&& Box1[x1, 10]->status == 'b'&&Box1[x1, 9]->status == 'b')
						 {
							 Rectangle rect1(getX, 450, 49, 49);
							 g->FillRectangle(yellowBrush, rect1);
							 Rectangle rect2(getX, 500, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 Rectangle rect3(getX, 550, 49, 49);
							 g->FillRectangle(yellowBrush, rect3);
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
							 g->FillRectangle(yellowBrush, rect1);
							 Rectangle rect2(getX + 50, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 Rectangle rect3(getX + 100, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect3);
						 }
					 }
					 else
					 {
						 if (Box1[10, y1]->status == 'b'&& Box1[11, y1]->status == 'b'&&Box1[9, y1]->status == 'b')
						 {
							 Rectangle rect1(450, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect1);
							 Rectangle rect2(500, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 Rectangle rect3(550, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect3);
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
							 g->FillRectangle(yellowBrush, rect1);
							 Rectangle rect2(getX, getY + 50, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 Rectangle rect3(getX, getY + 100, 49, 49);
							 g->FillRectangle(yellowBrush, rect3);
							 Rectangle rect4(getX, getY + 150, 49, 49);
							 g->FillRectangle(yellowBrush, rect4);
						 }
					 }
					 else
					 {
						 if (Box1[x1, 11]->status == 'b'&& Box1[x1, 10]->status == 'b'&&Box1[x1, 9]->status == 'b'&&Box1[x1, 8]->status == 'b')
						 {
							 Rectangle rect1(getX, 450, 49, 49);
							 g->FillRectangle(yellowBrush, rect1);
							 Rectangle rect2(getX, 500, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 Rectangle rect3(getX, 550, 49, 49);
							 g->FillRectangle(yellowBrush, rect3);
							 Rectangle rect4(getX, 400, 49, 49);
							 g->FillRectangle(yellowBrush, rect4);
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
							 g->FillRectangle(yellowBrush, rect1);
							 Rectangle rect2(getX + 50, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 Rectangle rect3(getX + 100, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect3);
							 Rectangle rect4(getX + 150, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect4);
						 }
					 }
					 else
					 {
						 if (Box1[10, y1]->status == 'b'&& Box1[11, y1]->status == 'b'&&Box1[9, y1]->status == 'b'&&Box1[8, y1]->status == 'b')
						 {
							 Rectangle rect1(450, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect1);
							 Rectangle rect2(500, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 Rectangle rect3(550, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect3);
							 Rectangle rect4(400, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect4);
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
							 g->FillRectangle(yellowBrush, rect1);
							 Rectangle rect2(getX, getY + 50, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 Rectangle rect3(getX, getY + 100, 49, 49);
							 g->FillRectangle(yellowBrush, rect3);
							 Rectangle rect4(getX, getY + 150, 49, 49);
							 g->FillRectangle(yellowBrush, rect4);
							 Rectangle rect5(getX, getY + 200, 49, 49);
							 g->FillRectangle(yellowBrush, rect5);
						 }
					 }
					 else
					 {
						 if (Box1[x1, 11]->status == 'b'&& Box1[x1, 10]->status == 'b'&&Box1[x1, 9]->status == 'b'&&Box1[x1, 8]->status == 'b'&&Box1[x1, 7]->status == 'b')
						 {
							 Rectangle rect1(getX, 450, 49, 49);
							 g->FillRectangle(yellowBrush, rect1);
							 Rectangle rect2(getX, 500, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 Rectangle rect3(getX, 550, 49, 49);
							 g->FillRectangle(yellowBrush, rect3);
							 Rectangle rect4(getX, 400, 49, 49);
							 g->FillRectangle(yellowBrush, rect4);
							 Rectangle rect5(getX, 350, 49, 49);
							 g->FillRectangle(yellowBrush, rect5);
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
							 g->FillRectangle(yellowBrush, rect1);
							 Rectangle rect2(getX + 50, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 Rectangle rect3(getX + 100, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect3);
							 Rectangle rect4(getX + 150, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect4);
							 Rectangle rect5(getX + 200, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect5);
						 }
					 }
					 else
					 {
						 if (Box1[10, y1]->status == 'b'&& Box1[11, y1]->status == 'b'&&Box1[9, y1]->status == 'b'&&Box1[8, y1]->status == 'b'&&Box1[7, y1]->status == 'b')
						 {
							 Rectangle rect1(450, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect1);
							 Rectangle rect2(500, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect2);
							 Rectangle rect3(550, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect3);
							 Rectangle rect4(400, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect4);
							 Rectangle rect5(350, getY, 49, 49);
							 g->FillRectangle(yellowBrush, rect5);
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
	private: System::Void newGameToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 /*
				 g->DrawImage(starfieldgrid_png, 0, 0, LrgGridSize, LrgGridSize);
				 g2->DrawImage(starfieldempty_png, 0, 0, 240, 240); //[Added 4/6/2015] Creates Empty starfield in PictureBox 2
				 g2->DrawImage(Ship_1_horizontalpng, 160, 285, 25, 25); //[Added 4/6/2015] Creates Frigate underneath starfield in PictureBox 2
				 g2->DrawImage(Ship_2_horizontalpng, 150, 250, 50, 25); //[Added 4/6/2015] Creates Stealth Ship underneath starfield in PictureBox 2
				 g2->DrawImage(Ship_3_horizontalpng, 25, 250, 75, 25); //[Added 4/6/2015] Creates Cruiser underneath starfield in PictureBox 2
				 g2->DrawImage(Ship_4_horizontalpng, 25, 283, 100, 25); //[Added 4/6/2015] Creates BattleShip underneath starfield in PictureBox 2
				 g2->DrawImage(Ship_5_horizontalpng, 25, 315, 125, 25); //[Added 4/6/2015] Creates Carrier underneath starfield in PictureBox 2

				 button1->Show();
				 //PlayerClass.setStart(true);
				 */

				 S = 1;
				 Box1 = gcnew array<player^, 2>(12, 12);
				 for (int row = 0; row < numrow; row++)
				 {
					 for (int col = 0; col < numcol; col++)
					 {
						 Rectangle rect1(row * 50, col * 50, 49, 49);
						 Box1[row, col] = gcnew player(row, col, 'b');
						 g->FillRectangle(yellowBrush, rect1);



					 }
				 }


				 g2->DrawImage(Ship_1_verticalpng, 0, 0);
				 g2->DrawImage(Ship_2_verticalpng, 0, 51);
				 g2->DrawImage(Ship_3_verticalpng, 0, 151);
				 g2->DrawImage(Ship_4_verticalpng, 0, 301);
				 g2->DrawImage(Ship_5_verticalpng, 51, 0);
	}

	
	private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
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


//notes
/*
large cell size == 40
small cell size == 20
*/