#include <iostream>
#include "Server.h"
#include "OBJBASE.h"

Server::Server() {
    m_cRef = 0;
};
Server::~Server() {
    std::cout << "Server.Destructor: Liquidated." << std::endl;
};

int Server::GetSound() {
    return 11;
}

int Server::GetAccord() {
    return 12;
}

int Server::NextAccord() {
    return 13;
}

int Server::PlaySound() {
    return 21;
}

int Server::PlayAccord() {
    return 22;
}

HRESULT_ Server::QueryInterface(IID_ IID, void** ppv) {
    switch (IID) {
    case IID_IMUSICIAN:
        *ppv = (IMusician*)(IAccordion*)ppv;
        std::cout << "Server.QueryInterface: IUnknown connected." << std::endl;
        break;
    case IID_IACCORDION:
        *ppv = (IAccordion*)this;
        std::cout << "Server.QueryInterface: IX connected." << std::endl;
        break;
    case IID_IPLAYER:
        *ppv = (IPlayer*)this;
        std::cout << "Server.QueryInterface: IY connected." << std::endl;
        break;
    default:
        *ppv = NULL;
        std::cout << "Server.QueryInterface: Invalid interface" << std::endl;
        return S_FAIL;
    }
    reinterpret_cast<IMusician*>(*ppv)->AddRef();
    return S_OK;
}

ULONG_ Server::AddRef() { 
    std::cout << "Server.AddRef = " << m_cRef + 1 << std::endl;
    return ++m_cRef; 
} 
 
ULONG_ Server::Release() { 
    std::cout << "Server.Release = " << m_cRef - 1 << std::endl;
    if(--m_cRef == 0) {
        delete this;
        return 0;
    }
    return m_cRef;
}

ServerFactory::ServerFactory() {
    m_cRef = 0;
};
ServerFactory::~ServerFactory() {
    std::cout << "ServerFactory.Destructor: Liquidated." << std::endl;
};

HRESULT_ ServerFactory::CreateInstance(IID_ IID, void** ppv) {
    Server* server = new Server;
    std::cout << "Server.CreateInstance: Server connected." << std::endl;
    server->AddRef();
    return server->QueryInterface(IID, ppv);
};

HRESULT_ ServerFactory::QueryInterface(IID_ IID, void** ppv) {
    switch (IID) {
    case IID_ICLASSFACTORY:
        std::cout << "ServerFactory.QueryInterface: IClassFactory connected." << std::endl;
        *ppv = (IClassFactory*)this;
        break;
    default:
        std::cout << "ServerFactory.QueryInterface: Invalid interface" << std::endl;
        *ppv = NULL;
        return S_FAIL;
    }
    reinterpret_cast<IMusician*>(*ppv)->AddRef();
    return S_OK;
};

ULONG_ ServerFactory::AddRef() { 
    std::cout << "ServerFactory.AddRef = " << m_cRef + 1 << std::endl;
    return ++m_cRef; 
} 
 
ULONG_ ServerFactory::Release() { 
    std::cout << "ServerFactory.Release = " << m_cRef - 1 << std::endl;
    if(--m_cRef == 0) {
        delete this;
        return 0;
    }
    return m_cRef;
}