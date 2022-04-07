#include <iostream>
#include "IManager.h"
#include "OBJBASE.h"

HRESULT_ CreateInstance(CLSID_ CLSID, IID_ IID, void** ppv) {
    IMusician* pIUnknown = NULL;
    switch (CLSID) {
		case CLSID_SERVER:
			pIUnknown = (IAccordion*) new Server;
			std::cout << "Global.CreateInstance: Server connected." << std::endl;
			break;
		case CLSID_SERVER2:
			pIUnknown = (IPlayer*) new Server2;
			std::cout << "Global.CreateInstance: Server2 connected." << std::endl;
			break;
		default:
			std::cout << "Global.CreateInstance: connection error." << std::endl;
			return S_FAIL;
			break;
    }
    pIUnknown->AddRef();
    return pIUnknown->QueryInterface(IID, ppv);
}

HRESULT_ GetClassObject(CLSID_ CLSID, IID_ IID, void** ppv) {
    IMusician* pIUnknown = NULL;
    switch (CLSID) {
		case CLSID_SERVER:
			pIUnknown = (IClassFactory*) new ServerFactory;
			std::cout << "GetClassObject: ServerFactory connected." << std::endl;
			break;
		case CLSID_SERVER2:
			pIUnknown = (IClassFactory*) new Server2Factory;
			std::cout << "GetClassObject: Server2Factory connected." << std::endl;
			break;
		default:
			std::cout << "GetClassObject: connection error." << std::endl;
			return S_FAIL;
			break;
    }
    pIUnknown->AddRef();
    return pIUnknown->QueryInterface(IID, ppv);
}