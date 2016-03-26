/*
 * SyncI.h
 *
 * Interface implementation for Inexor/Tree/Synchronization
 */

#ifndef SYNCHRONIZATIONIMPL_HPP_
#define SYNCHRONIZATIONIMPL_HPP_

#include <string>
#include <vector>

#include <Ice/Ice.h>
#include "Synchronization.h"

namespace inexor {
namespace tree {

using namespace item;
using namespace path;

class SynchronizationImpl: public Synchronization {
public:
    virtual void setItem(const Container&, const Ice::Current&);
    virtual Container getItem(const std::string&, const Ice::Current&);
    virtual Result QueryPath(const QueryPtr& query, const Ice::Current&);
};

} /* namespace tree */
} /* namespace inexor */

#endif /* SYNCI_HPP_ */
