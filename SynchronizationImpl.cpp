/*
 * SyncI.cpp
 *
 */

#include "SynchronizationImpl.hpp"

namespace inexor {
namespace tree {

void SynchronizationImpl::SetItem(const ::inexor::tree::item::Container& item, const Ice::Current&) {

}

Container SynchronizationImpl::GetItem(const std::string& path, const Ice::Current&) {
	Container c;
	return c;
}

Result SynchronizationImpl::QueryPath(const Query& query, const Ice::Current&) {
	Result r;
	return r;
}

} /* namespace tree */
} /* namespace inexor */
