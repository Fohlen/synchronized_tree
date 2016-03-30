/*
 * SyncI.h
 *
 * Interface implementation for Inexor/Tree/Synchronization
 */

#ifndef SYNCHRONIZATIONIMPL_HPP_
#define SYNCHRONIZATIONIMPL_HPP_

#include <string>
#include <vector>
#include <typeinfo>
#include <Ice/Ice.h>
#include "Tree.hpp"
#include "Synchronization.h"

namespace inexor {
namespace tree {

using namespace item;
using namespace path;

class SynchronizationImpl: public Synchronization {
public:
    virtual void setItem(const Container& item, const Ice::Current& current);
    virtual Container getItem(const std::string& path, const Ice::Current& current);
    virtual Result QueryPath(const QueryPtr& query, const Ice::Current& current);
};

} /* namespace tree */
} /* namespace inexor */

#endif /* SYNCI_HPP_ */
