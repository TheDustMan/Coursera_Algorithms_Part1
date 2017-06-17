#ifndef QUOUFTIMESTAMP_H
#define QUOUFTIMESTAMP_H

#include "QuickUnionOptimizedUF.h"
#include <functional>
#include <vector>

/*
 * Introduces timestamp tracking so that we can recognize the time
 * at which all items are connected
 */
class QUOUFTimestamp : public QuickUnionOptimizedUF
{
 public:
    QUOUFTimestamp(int N);
    virtual ~QUOUFTimestamp();
    virtual void create_union(int p, int q, int timestamp);
    virtual void onFullConnection(std::function<void(int)> f);
 private:
    int _uniqueRoots;
    std::vector<int> _timestamps;
    std::function<void(int timestamp)> _onFullConnection;
};

#endif // QUOUFTIMESTAMP_H
