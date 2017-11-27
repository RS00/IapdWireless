#pragma once
#include <Windows.h>
#include <Wlanapi.h>
#include <Windot11.h>
#include <vector>
#include "WirelessNetwork.h"
#define WLAN_CLIENT_VERSION 2
#pragma comment(lib, "Wlanapi.lib")
using namespace std;

class WirelessNetworkList
{
private:
	HANDLE hClient;
	DWORD currentVersion;
	WLAN_BSS_ENTRY getBssInfo(GUID interfaceGuid, PDOT11_SSID ssid);
	vector<WLAN_AVAILABLE_NETWORK> getAvailableNetworks(GUID interfaceGuid);
	vector<WLAN_INTERFACE_INFO> getWlanInterfaces();
	string getBssId(GUID interfaceGuid, PDOT11_SSID ssid);
	
public:
	WirelessNetworkList();
	bool isConnected();
	GUID getInterfaceGUID();
	vector<WirelessNetwork> getAvailableNetworksVector();
	~WirelessNetworkList();
};

