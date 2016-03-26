/*
 * SyncI.cpp
 *
 */

#include "SynchronizationImpl.hpp"

namespace inexor {
namespace tree {

void SynchronizationImpl::setItem(const Container&, const ::Ice::Current&) {

}

Container SynchronizationImpl::getItem(const ::std::string&, const ::Ice::Current&) {
	Container c;
	return c;
}

Result SynchronizationImpl::QueryPath(const QueryPtr& query, const Ice::Current&) {
	Result r;
	return r;
}

} /* namespace tree */
} /* namespace inexor */
