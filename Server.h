#ifndef SERVER_H
#define SERVER_H
#include "IMusician.h"
#include "OBJBASE.h"
class Server : public IAccordion, public IPlayer {
private:
    long m_cRef;
public:
    Server();
    ~Server();
    virtual int GetSound();
    virtual int GetAccord();
	virtual int NextAccord();
	virtual int PlaySound();
    virtual int PlayAccord();
    HRESULT_ QueryInterface(IID_, void**);
    ULONG_ AddRef();
    ULONG_ Release();
};
#endif

class ServerFactory : public IClassFactory {
private:
    long m_cRef;
public:
    ServerFactory();
    ~ServerFactory();
    HRESULT_ CreateInstance(IID_, void**);
    HRESULT_ QueryInterface(IID_, void**);
    ULONG_ AddRef();
    ULONG_ Release();
};