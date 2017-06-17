#ifndef QUOUFCANONICAL_H
#define QUOUFCANONICAL_H

#include "QuickUnionOptimizedUF.h"
#include <vector>

/*
 * Introduces timestamp tracking so that we can recognize the time
 * at which all items are connected
 */
class QUOUFCanonical : public QuickUnionOptimizedUF
{
 public:
    QUOUFCanonical(int N);
    virtual ~QUOUFCanonical();
    virtual void create_union(int p, int q) override;
    virtual int find(int p) override;
};

#endif // QUOUFCANONICAL_H
