#include "WirelessNetworkInterface.h"

WirelessNetworkInterface::WirelessNetworkInterface()
{
}


WirelessNetworkInterface::~WirelessNetworkInterface()
{
}


vector<WLAN_INTERFACE_INFO> WirelessNetworkInterface::getWlanInterfaces()
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

vector<WLAN_AVAILABLE_NETWORK> WirelessNetworkInterface::getAvailableNetworks(GUID interfaceGuid)
{
	PWLAN_AVAILABLE_NETWORK_LIST pAvList = NULL;
	vector<WLAN_AVAILABLE_NETWORK> result;
	WlanGetAvailableNetworkList(hClient,
		&interfaceGuid,
		0,
		NULL,
		&pAvList);
	if (!pAvList)
		return result;
	for (int i = 0; i < pAvList->dwNumberOfItems; i++)
	{
		result.push_back(pAvList->Network[i]);
	}
	return result;
}

string WirelessNetworkInterface::getBssId(GUID interfaceGuid, PDOT11_SSID ssid)
{
	WLAN_BSS_ENTRY info = getBssInfo(interfaceGuid, ssid);
	char macStr[18];
	snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
		info.dot11Bssid[0], info.dot11Bssid[1], info.dot11Bssid[2], info.dot11Bssid[3], info.dot11Bssid[4], info.dot11Bssid[5]);
	return string(macStr);
}

WLAN_BSS_ENTRY WirelessNetworkInterface::getBssInfo(GUID interfaceGuid, PDOT11_SSID ssid)
{
	PWLAN_BSS_LIST list;
	WlanGetNetworkBssList(hClient, &interfaceGuid, ssid, dot11_BSS_type_infrastructure, true, NULL, &list);
	return list->wlanBssEntries[0];
}

vector<WirelessNetwork> WirelessNetworkInterface::getAvailableNetworksVector()
{
	WlanOpenHandle(WLAN_CLIENT_VERSION, NULL, &currentVersion, &hClient);
	vector<WirelessNetwork> result;
	vector<WLAN_INTERFACE_INFO> interfaces = getWlanInterfaces();
	if (interfaces.size() == 0)
		return result;
	vector<WLAN_AVAILABLE_NETWORK> availableNet = getAvailableNetworks(interfaces[0].InterfaceGuid);
	for (int i = 0; i < availableNet.size(); i++)
	{
		string name((char *) availableNet[i].dot11Ssid.ucSSID);
		string bssid = getBssId(interfaces[0].InterfaceGuid, &availableNet[i].dot11Ssid);
		ULONG quality = availableNet[i].wlanSignalQuality;
		string qualityStr = WirelessNetwork::calculateQuality(quality);
		string authType = WirelessNetwork::getAuthType(availableNet[i].dot11DefaultAuthAlgorithm);
		WirelessNetwork net(name, bssid, qualityStr, authType, availableNet[i]);
		result.push_back(net);
	}
	WlanCloseHandle(hClient, NULL);
	return result;
}

bool WirelessNetworkInterface::isConnected()
{
	WlanOpenHandle(WLAN_CLIENT_VERSION, NULL, &currentVersion, &hClient);
	vector<WLAN_INTERFACE_INFO> interfaces = getWlanInterfaces();
	if (interfaces.size() == 0 || interfaces[0].isState == wlan_interface_state_disconnected)
		return false;
	WlanCloseHandle(hClient, NULL);
	return true;
}

GUID WirelessNetworkInterface::getInterfaceGUID()
{
	WlanOpenHandle(WLAN_CLIENT_VERSION, NULL, &currentVersion, &hClient);
	GUID res;
	vector<WLAN_INTERFACE_INFO> interfaces = getWlanInterfaces();
	if (interfaces.size() > 0)
	{
		res = interfaces[0].InterfaceGuid;
	}
	WlanCloseHandle(hClient, NULL);
	return res;
}