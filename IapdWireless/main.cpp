#include "mainForm.h"
#include "WirelessNetworkList.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew IapdWireless::MainForm());
	WirelessNetworkList list;
	vector<WLAN_INTERFACE_INFO> info = list.getWlanInterfaces();
	vector<WLAN_AVAILABLE_NETWORK> network = list.getAvailableNetworks(info[0].InterfaceGuid);
	return 0;
}