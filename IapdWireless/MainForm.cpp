#include "MainForm.h"
using namespace IapdWireless;

MainForm::MainForm()
{
	InitializeComponent();
}

MainForm::~MainForm()
{
	if (components)
	{
		delete components;
	}
}

void MainForm::InitializeComponent()
{
	this->components = gcnew System::ComponentModel::Container();
	this->Size = System::Drawing::Size(WINDOW_WIDTH, WINDOW_HEIGHT);
	this->Text = WINDOW_TITLE;
	this->Padding = System::Windows::Forms::Padding(0);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
}