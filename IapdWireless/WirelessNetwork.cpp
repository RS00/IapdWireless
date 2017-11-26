#include "WirelessNetwork.h"


WirelessNetwork::WirelessNetwork(string name, string bssid, string quality, string type)
{
	this->name = name;
	this->bssId = bssid;
	this->quality = quality;
	this->authType = type;
}


WirelessNetwork::~WirelessNetwork()
{
}

string WirelessNetwork::getAuthType()
{
	return this->authType;
}

string WirelessNetwork::getMAC()
{
	return this->bssId;
}

string WirelessNetwork::getName()
{
	return this->name;
}

string WirelessNetwork::getQuality()
{
	return this->quality;
}

string WirelessNetwork::getAuthType(DWORD dot11_code)
{
	string result;
	switch (dot11_code)
	{
	case DOT11_AUTH_ALGO_80211_OPEN:
	{
		result = "802.11 Open System authentication";
		break;
	}

	case DOT11_AUTH_ALGO_80211_SHARED_KEY:
	{
		result = "802.11 Shared Key authentication";
		break;
	}

	case DOT11_AUTH_ALGO_WPA:
	{
		result = "Wi-Fi Protected Access (WPA)";
		break;
	}

	case DOT11_AUTH_ALGO_WPA_PSK:
	{
		result = "WPA-PSK";
		break;
	}

	case DOT11_AUTH_ALGO_RSNA:
	{
		result = "Robust Security Network Association (RSNA)";
		break;
	}

	case DOT11_AUTH_ALGO_RSNA_PSK:
	{
		result = "RSNA-PSK";
		break;
	}

	}
	return result;
}

string WirelessNetwork::calculateQuality(ULONG quality)
{
	string result = to_string(quality);
	int db = -100 + 0.5 * quality;
	result += "% (" + to_string(db) + " dbm)";
	return result;
}

bool WirelessNetwork::connect(HANDLE handle, GUID guid, WLAN_AVAILABLE_NETWORK avNet, string name, string password)
{
	WLAN_CONNECTION_PARAMETERS params;
	string profile("<?xml version=\"1.0\"?><WLANProfile xmlns=\"http://www.microsoft.com/networking/WLAN/profile/v1\"><name>" + name + "</name><SSIDConfig><SSID><name>" + name + "</name></SSID></SSIDConfig><connectionType>ESS</connectionType><connectionMode>auto</connectionMode><autoSwitch>false</autoSwitch><MSM><security><authEncryption><authentication>WPA2PSK</authentication><encryption>AES</encryption><useOneX>false</useOneX></authEncryption><sharedKey><keyType>passPhrase</keyType><protected>false</protected><keyMaterial>" + password + "</keyMaterial></sharedKey></security></MSM></WLANProfile>");
	wstring wide(profile.begin(), profile.end());
	params.wlanConnectionMode = wlan_connection_mode_temporary_profile;
	params.pDot11Ssid = &avNet.dot11Ssid;
	params.pDesiredBssidList = NULL;
	params.strProfile = wide.c_str();
	params.dot11BssType = avNet.dot11BssType;
	params.dwFlags = WLAN_CONNECTION_HIDDEN_NETWORK;

	int res = WlanConnect(handle, &guid, &params, NULL);
	return res == 0;
}

void WirelessNetwork::disconnect(HANDLE handle, GUID guid)
{
	WlanDisconnect(handle, &guid, NULL);
	return;
}