#pragma once
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
		array <player^, 2>^ PLAYER_GRID;

	/////GRAPHICS//////////////	 
		Graphics^ g;
		Pen^ blackBrush;
		Bitmap^ Ship_5 = gcnew Bitmap("Graphics/(250x50)_Colony_CarrierShip_[5Cells].png");

	/////////////////////

	/////CONST INTS//////
		static const int NUMROWS = 12;
		static const int NUMCOLS = 12;
		static const int LRGCELLSIZE = 40;
	private: System::Windows::Forms::Button^  button1;
			 /////////////////////

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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
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
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

				 g = pictureBox1->CreateGraphics();
				 blackBrush = gcnew System::Drawing::Pen(Color::Black);

				 

				 PLAYER_GRID = gcnew array<player^, 2>(NUMCOLS, NUMROWS);
				 for (int row = 0; row < NUMROWS; row++)
				 for (int col = 0; col < NUMCOLS; col++)
					 PLAYER_GRID[col, row] = gcnew player(col, row, false);

				 player5cell(false);

					


				// draw_grid();
				 
	}
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}


private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

			 for (int row = 0; row < NUMROWS; row++){
				 for (int col = 0; col < NUMCOLS; col++){
					 int x = col * LRGCELLSIZE;
					 int y = row * LRGCELLSIZE;



					 

					 Rectangle lrggridsrect = Rectangle(x, y, LRGCELLSIZE - 1, LRGCELLSIZE - 1);
					 g->DrawRectangle(blackBrush, lrggridsrect);
				 }
			 }
}
};
}



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
