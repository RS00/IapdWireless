#include "mainForm.h"
#include "WirelessNetworkList.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew IapdWireless::MainForm());
	return 0;
}