#include <iostream>
#include "IManager.h"
#include "OBJBASE.h"

int main() {
    IClassFactory* pF = NULL;
    HRESULT_ result = GetClassObject(CLSID_SERVER, IID_ICLASSFACTORY, (void**)&pF);
    pF->Release();
	
    if (result == S_OK) {
        IAccordion* pX = NULL;
        result = pF->CreateInstance(IID_IACCORDION, (void**)&pX);
        pF->Release();
		
        if (result == S_OK) {
            std::cout << "Func result: " << pX->GetSound() << std::endl;
            pX->Release();
        }
        else std::cout << "Warning" << std::endl;
        
		IPlayer* pY = NULL;
		result = pX->QueryInterface(IID_IPLAYER, (void**)&pY);
		
        if (result == S_OK) {
            std::cout << "Func result: " << pY->PlayAccord() << std::endl;
            pX->Release();
        }
        else std::cout << "Warning" << std::endl;
        pX->Release();
    }
    else std::cout << "Warning" << std::endl;
	
    return 0;
}