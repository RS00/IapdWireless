#pragma once
#define WINDOW_TITLE "Wireless Info"
#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 300

namespace IapdWireless {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		System::ComponentModel::Container ^components;
	
		void InitializeComponent();
	
	protected:
		~MainForm();
	
	public:
		MainForm();
	};
}