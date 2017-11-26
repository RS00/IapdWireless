#pragma once
#include <Windows.h>
#include <string>
#include <wchar.h>
#include <Wlanapi.h>
#pragma comment(lib, "Wlanapi.lib")

using namespace std;

class WirelessNetwork
{
private:
	string name;
	string bssId;
	string quality;
	string authType;
public:
	static string calculateQuality(ULONG quality);
	static string getAuthType(DWORD dot11_code);
	static bool connect(HANDLE handle, GUID guid, WLAN_AVAILABLE_NETWORK avNet, string name, string password);
	static void disconnect(HANDLE handle, GUID guid);
	string getName();
	string getMAC();
	string getQuality();
	string getAuthType();
	WirelessNetwork(string name, string bssid, string quality, string type);
	~WirelessNetwork();
};

