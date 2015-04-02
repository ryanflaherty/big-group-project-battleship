#pragma once

#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include "player.h"
#include "5cellship.h"

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
		//Graphics^ g;
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
		//array <player^, 2>^ PLAYER_GRID;

	/////GRAPHICS//////////////	 
		Graphics^ g;
		Pen^ blackBrush;
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
		////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////


	/////CONST INTS//////
		static const int NUMROWS = 12;
		static const int NUMCOLS = 12;
		static const int LRGCELLSIZE = 40;
	private: System::Windows::Forms::Button^  button1;
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
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Location = System::Drawing::Point(75, 75);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(480, 480);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MouseD);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(589, 215);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(240, 340);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(589, 75);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(150, 20);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(589, 151);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(150, 20);
			this->textBox3->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(241, 561);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(108, 39);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Start Game";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
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
			this->ClientSize = System::Drawing::Size(884, 612);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		int numrow = 40;
		int numcol = 40;

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

				 /*
				 g = pictureBox1->CreateGraphics();
				 Box1 = gcnew array<player^, 2>(40, 40);
				 for (int row = 0; row < numrow; row++)
				 {
					 for (int col = 0; col < numcol; col++)
					 {
						 
							 Box1[row, col] = gcnew player(row, col, 'b');
							 


						 

					 }
				 }
	
				 */

				 g = pictureBox1->CreateGraphics();
				 blackBrush = gcnew System::Drawing::Pen(Color::Black);

				 WhiteBrush = gcnew System::Drawing::SolidBrush(Color::White);

				 button1->Hide();
				 textBox2->Hide();
				 textBox3->Hide();
					

				 
	}
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) 
	{
	}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void MouseD(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 Rectangle WhiteRect = Rectangle(e->X - (e->X % LRGCELLSIZE), e->Y - (e->Y % LRGCELLSIZE), LRGCELLSIZE - 1, LRGCELLSIZE - 1);
			 g->DrawImage(starfieldgrid_png, 0, 0, 480, 480);
			 g->FillRectangle(WhiteBrush, WhiteRect);
}
private: System::Void easyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}



private: System::Void newGameToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 g->DrawImage(starfieldgrid_png, 0, 0, 480, 480);

			 button1->Show();

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
