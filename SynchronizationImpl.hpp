/*
 * SyncI.h
 *
 * Interface implementation for Inexor/Tree/Synchronization
 */

#ifndef SYNCHRONIZATIONIMPL_HPP_
#define SYNCHRONIZATIONIMPL_HPP_

#include <string>
#include <Ice/Ice.h>
#include "Synchronization.h"

namespace inexor {
namespace tree {

class SynchronizationImpl: public Synchronization {
public:
	virtual void printString(const std::string& s, const Ice::Current&);
};

} /* namespace tree */
} /* namespace inexor */

#endif /* SYNCI_HPP_ */
