#include "WirelessNetworkList.h"


WirelessNetworkList::WirelessNetworkList()
{
	WlanOpenHandle(WLAN_CLIENT_VERSION, NULL, &currentVersion, &hClient);
}


WirelessNetworkList::~WirelessNetworkList()
{
}


vector<WLAN_INTERFACE_INFO> WirelessNetworkList::getWlanInterfaces()
{
	PWLAN_INTERFACE_INFO_LIST pIfList = NULL;

	WlanEnumInterfaces(hClient, NULL, &pIfList);
	vector<WLAN_INTERFACE_INFO> result;
	for (int i = 0; i < pIfList->dwNumberOfItems; i++)
	{
		result.push_back(pIfList->InterfaceInfo[i]);
	}
	return result;
}

vector<WLAN_AVAILABLE_NETWORK> WirelessNetworkList::getAvailableNetworks(GUID interfaceGuid)
{
	PWLAN_AVAILABLE_NETWORK_LIST pAvList = NULL;
	vector<WLAN_AVAILABLE_NETWORK> result;
	WlanGetAvailableNetworkList(hClient,
		&interfaceGuid,
		0,
		NULL,
		&pAvList);
	for (int i = 0; i < pAvList->dwNumberOfItems; i++)
	{
		result.push_back(pAvList->Network[i]);
	}
	return result;
}

WLAN_BSS_ENTRY getBssInfo(GUID interfaceGuid, PDOT11_SSID ssid);