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
	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
	list = gcnew ListView();
	list->Width = LISTVIEW_WIDTH;
	list->Height = LISTVIEW_HEIGHT;
	list->Location = Point(LISTVIEW_X, LISTVIEW_Y);
	list->View = View::Details;
	list->Columns->Add(LISTVIEW_COL1, LISTVIEW_COL1_WIDTH, HorizontalAlignment::Center);
	list->Columns->Add(LISTVIEW_COL2, LISTVIEW_COL2_WIDTH, HorizontalAlignment::Center);
	list->Columns->Add(LISTVIEW_COL3, LISTVIEW_COL3_WIDTH, HorizontalAlignment::Center);
	list->Columns->Add(LISTVIEW_COL4, LISTVIEW_COL4_WIDTH, HorizontalAlignment::Center);
	Controls->Add(list);
}