#ifndef QUICKUNIONUF_H
#define QUICKUNIONUF_H

#include "UF.h"

class QuickUnionUF : public UF
{
 public:
    QuickUnionUF(int N);
    virtual bool connected(int p, int q) override;
    virtual void create_union(int p, int q) override;
 protected:
    int findRoot(int id);
};

#endif // QUICKUNIONUF_H
