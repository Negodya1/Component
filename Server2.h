#ifndef SERVER2_H
#define SERVER2_H
#include "IMusician.h"
#include "OBJBASE.h"
class Server2 : public IPlayer {
private:
    long m_cRef;
public:
    Server2();
    ~Server2();
    virtual int PlaySound();
	virtual int PlayAccord();
	virtual int NextAccord();
    HRESULT_ QueryInterface(IID_, void**);
    ULONG_ AddRef();
    ULONG_ Release();
};
#endif

class Server2Factory : public IClassFactory {
private:
    long m_cRef;
public:
    Server2Factory();
    ~Server2Factory();
    HRESULT_ CreateInstance(IID_, void**);
    HRESULT_ QueryInterface(IID_, void**);
    ULONG_ AddRef();
    ULONG_ Release();
};