#pragma once
#include <Windows.h>
#include <string>
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
	string getName();
	string getMAC();
	string getQuality();
	string getAuthType();
	WirelessNetwork(string name, string bssid, string quality, string type);
	~WirelessNetwork();
};

