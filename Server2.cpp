#include <iostream>
#include "Server2.h"
#include "OBJBASE.h"

Server2::Server2() {
    m_cRef = 0;
};
Server2::~Server2() {
    std::cout << "Server2.Destructor: Liquidated." << std::endl;
};

int Server2::PlaySound() {
    return 21;
}

int Server2::PlayAccord() {
    return 22;
}

int Server2::NextAccord() {
    return 13;
}

HRESULT_ Server2::QueryInterface(IID_ IID, void** ppv) {
    switch (IID) {
    case IID_IMUSICIAN:
        *ppv = (IMusician*)(IPlayer*)ppv;
        std::cout << "Server2.QueryInterface: IUnknown connected." << std::endl;
        break;
    case IID_IPLAYER:
        *ppv = (IPlayer*)this;
        std::cout << "Server2.QueryInterface: IY connected." << std::endl;
        break;
    default:
        *ppv = NULL;
        std::cout << "Server2.QueryInterface: Invalid interface" << std::endl;
        return S_FAIL;
    }
    return S_OK;
}

ULONG_ Server2::AddRef() {
    std::cout << "Server2.AddRef = " << m_cRef + 1 << std::endl;
    return ++m_cRef; 
} 
 
ULONG_ Server2::Release() { 
    std::cout << "Server2.Release = " << m_cRef - 1 << std::endl;
    if(--m_cRef == 0)
    {
        delete this;
        return 0;
    }
    return m_cRef;
}


Server2Factory::Server2Factory() {
    m_cRef = 0;
};
Server2Factory::~Server2Factory() {
    std::cout << "Server2Factory.Destructor: Liquidated." << std::endl;
};

HRESULT_ Server2Factory::CreateInstance(IID_ IID, void** ppv) {
    Server2* server2 = new Server2;
    std::cout << "Server2.CreateInstance: Server2 connected." << std::endl;
    return server2->QueryInterface(IID, ppv);
};

HRESULT_ Server2Factory::QueryInterface(IID_ IID, void** ppv) {
    switch (IID) {
		case IID_ICLASSFACTORY:
			std::cout << "Server2Factory.QueryInterface: IClassFactory connected." << std::endl;
			*ppv = (IClassFactory*)this;
			break;
		default:
			std::cout << "Server2Factory.QueryInterface: Invalid interface" << std::endl;
			*ppv = NULL;
			return S_FAIL;
    }
    return S_OK;
}

ULONG_ Server2Factory::AddRef() { 
    std::cout << "Server2Factory.AddRef = " << m_cRef + 1 << std::endl;
    return ++m_cRef; 
} 
 
ULONG_ Server2Factory::Release() { 
    std::cout << "Server2Factory.Release = " << m_cRef - 1 << std::endl;
    if(--m_cRef == 0) {
        delete this;
        return 0;
    }
    return m_cRef;
}
