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
	virtual void SetItem(const Container& item, const Ice::Current&);
	virtual Container GetItem(const std::string& path, const Ice::Current&);
	virtual Result QueryPath(const Query& query, const Ice::Current&);
};

} /* namespace tree */
} /* namespace inexor */

#endif /* SYNCI_HPP_ */
