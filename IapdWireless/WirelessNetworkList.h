#pragma once
#include <Windows.h>
#include <Wlanapi.h>
#include <vector>
#define WLAN_CLIENT_VERSION 2
#pragma comment(lib, "Wlanapi.lib")
using namespace std;

class WirelessNetworkList
{
private:
	HANDLE hClient;
	DWORD currentVersion;
public:
	WirelessNetworkList();
	vector<WLAN_INTERFACE_INFO> getWlanInterfaces();
	vector<WLAN_AVAILABLE_NETWORK> getAvailableNetworks(GUID interfaceGuid);
	~WirelessNetworkList();
};

