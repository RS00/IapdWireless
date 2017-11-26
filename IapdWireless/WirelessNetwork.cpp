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