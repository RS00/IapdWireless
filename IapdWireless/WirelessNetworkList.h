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
	static WirelessNetworkList inst;
	HANDLE hClient;
	DWORD currentVersion;
	WLAN_BSS_ENTRY getBssInfo(GUID interfaceGuid, PDOT11_SSID ssid);
	vector<WLAN_AVAILABLE_NETWORK> getAvailableNetworks(GUID interfaceGuid);
	WirelessNetworkList();
public:
	static WirelessNetworkList getInstance();
	vector<WLAN_INTERFACE_INFO> getWlanInterfaces();
	string getBssId(GUID interfaceGuid, PDOT11_SSID ssid);
	vector<WirelessNetwork> getAvailableNetworksVector();
	~WirelessNetworkList();
};

