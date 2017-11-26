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

string WirelessNetworkList::getBssId(GUID interfaceGuid, PDOT11_SSID ssid)
{
	PWLAN_BSS_LIST list;
	WlanGetNetworkBssList(hClient, &interfaceGuid, ssid, dot11_BSS_type_infrastructure, true, NULL, &list);
	char macStr[18];
	snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
		list->wlanBssEntries[0].dot11Bssid[0], list->wlanBssEntries[0].dot11Bssid[1], list->wlanBssEntries[0].dot11Bssid[2], list->wlanBssEntries[0].dot11Bssid[3], list->wlanBssEntries[0].dot11Bssid[4], list->wlanBssEntries[0].dot11Bssid[5]);
	return string(macStr);

}