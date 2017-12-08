#pragma once
#include <Windows.h>
#include <string>
#include <wchar.h>
#include <Wlanapi.h>
#define WLAN_CLIENT_VERSION 2
#define TYPE_OPEN "802.11 Open System authentication"
#pragma comment(lib, "Wlanapi.lib")

using namespace std;

class WirelessNetwork
{
private:
	WLAN_AVAILABLE_NETWORK net;
	string name;
	string bssId;
	string quality;
	string authType;
public:
	static string calculateQuality(ULONG quality);
	static string getAuthType(DWORD dot11_code);
	bool connect(GUID guid, string password);
	static void disconnect(GUID guid);
	string getName();
	string getMAC();
	string getQuality();
	string getAuthType();
	WLAN_AVAILABLE_NETWORK getAvNetStr();
	WirelessNetwork(string name, string bssid, string quality, string type, WLAN_AVAILABLE_NETWORK net);
	~WirelessNetwork();
};

