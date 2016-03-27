/*
 * SyncI.cpp
 *
 */

#include "SynchronizationImpl.hpp"

namespace inexor {
namespace tree {

void SynchronizationImpl::setItem(const Container& item, const ::Ice::Current& c) {
	try {
	    Ice::CommunicatorPtr communicator = c.adapter->getCommunicator();
	    Ice::InputStreamPtr in = Ice::createInputStream(communicator, item.value);

	    switch(item.type) {
	    	case BoolValue:
	    		double boolval;
	    		in->read(boolval);
	    		//inexor::tree::Tree.put<bool>(item.path, boolval);
	    		break;
	    	case ShortValue:
	    		short shortval;
	    		in->read(shortval);
	    		break;
	    	case IntValue:
	    		int intval;
	    		in->read(intval);
	    		break;
	    	case LongValue:
	    		long longval;
	    		in->read(longval);
	    		break;
	    	case FloatValue:
	    		float floatval;
	    		in->read(floatval);
	    		break;
	    	case DoubleValue:
	    		double doubleval;
	    		in->read(doubleval);
	    		break;
	    	case StringValue:
	    		std::string stringval;
	    		in->read(stringval);
	    		break;
	    	/*default:
	    		throw Ice::UserException;
	    		break;*/
	    }

	} catch (const Ice::UserException& ex) {
		Error* err = new Error;
		err->type = item.type;
		throw err;
	}
}

Container SynchronizationImpl::getItem(const ::std::string& path, const ::Ice::Current& c) {
	Container container;
	return container;
}

Result SynchronizationImpl::QueryPath(const QueryPtr& query, const Ice::Current& c) {
	Result r;
	return r;
}

} /* namespace tree */
} /* namespace inexor */
