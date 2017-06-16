#ifndef QUICKFINDUF_H
#define QUICKFINDUF_H

#include "UF.h"

class QuickFindUF : public UF
{
public:
    QuickFindUF(int N);
    virtual void create_union(int p, int q) override;
    virtual bool connected(int p, int q) override;
};

#endif // QUICKFINDUF_H
