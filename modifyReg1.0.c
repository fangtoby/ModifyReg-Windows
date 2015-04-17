/*
	Modify Windows Reg

	version: 1.0
	author: fangtoby@live.cn
	date: 2015-4-17
*/

#include <windows.h>
#include <stdio.h>

int main()
{
	char szModule[200];
	
	char keyName[100];

readUserInput:
	
	printf("input new reg item name \n");

	gets(keyName);

	printf("input new reg item software path <C:\\Program Files (x86)\\Koala\\koala.exe> \n");

	gets(szModule);

	printf("szModule %d , keyName %d \n", strlen(szModule),strlen(keyName) );

	if (strlen(szModule) == 0 || strlen(keyName) == 0){
		goto readUserInput;
	}

	HKEY hRoot = HKEY_CURRENT_USER;

	char *szSubKey = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";

	HKEY hKey;

	DWORD dwDisposition = REG_OPENED_EXISTING_KEY;

	LONG lRet = RegCreateKeyEx(hRoot, szSubKey, 0, NULL, REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS, NULL, &hKey, &dwDisposition);

	if(lRet != ERROR_SUCCESS)
	{
		printf("failed to find !\n");
		return -1;
	}

	lRet = RegSetValueEx(hKey, keyName , 0, REG_SZ, (BYTE *)szModule, strlen(szModule));

	RegCloseKey(hKey);

	if(lRet != ERROR_SUCCESS)
	{
		printf("failed to reg !\n");
		return -1;
	}else{
		printf("set success.\n");
	}

	return 0;
}
