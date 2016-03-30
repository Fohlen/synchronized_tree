/*
 * SyncI.cpp
 *
 */

#include "SynchronizationImpl.hpp"

namespace inexor {
namespace tree {

void SynchronizationImpl::setItem(const Container& item, const ::Ice::Current& current) {
	try {
	    Ice::CommunicatorPtr communicator = current.adapter->getCommunicator();
	    Ice::InputStreamPtr in = Ice::createInputStream(communicator, item.value);

	    switch(item.type) {
	    	case BoolValue:
	    		double boolval;
	    		in->read(boolval);
	    		Tree.put(item.path, boolval);
	    		break;
	    	case ShortValue:
	    		short shortval;
	    		in->read(shortval);
	    		Tree.put(item.path, shortval);
	    		break;
	    	case IntValue:
	    		int intval;
	    		in->read(intval);
	    		Tree.put(item.path, intval);
	    		break;
	    	case LongValue:
	    		long longval;
	    		in->read(longval);
	    		Tree.put(item.path, longval);
	    		break;
	    	case FloatValue:
	    		float floatval;
	    		in->read(floatval);
	    		Tree.put(item.path, floatval);
	    		break;
	    	case DoubleValue:
	    		double doubleval;
	    		in->read(doubleval);
	    		Tree.put(item.path, doubleval);
	    		break;
	    	case StringValue:
	    		std::string stringval;
	    		in->read(stringval);
	    		Tree.put(item.path, stringval);
	    		break;
	    }
	} catch (const boost::property_tree::ptree_bad_data& ex) {
		item::Error* err = new item::Error();
		err->type = Failed;
		throw err;
	}
}

Container SynchronizationImpl::getItem(const ::std::string& path, const ::Ice::Current& current) {
    Ice::CommunicatorPtr communicator = current.adapter->getCommunicator();
    Ice::OutputStreamPtr out = Ice::createOutputStream(communicator);
	Container container;

    boost::property_tree::ptree::assoc_iterator item = Tree.find(path);
    auto data = item->second;
    out->write(data);
    out->finished(container.value);
    // TODO: Unfortanly this is not possible due to compile-time issues?

    if (item != Tree.end()) {
    	if (typeid(bool) == typeid(data)) {
    		container.type = BoolValue;
    	} else if (typeid(short) == typeid(data)) {
    		container.type = ShortValue;
    	} else if (typeid(int) == typeid(data)) {
    		container.type = IntValue;
    	} else if (typeid(long) == typeid(data)) {
    		container.type = LongValue;
    	} else if (typeid(float) == typeid(data)) {
    		container.type = FloatValue;
    	} else if (typeid(double) == typeid(data)) {
    		container.type = DoubleValue;
    	} else if (typeid(std::string) == typeid(data)) {
    		container.type = StringValue;
    	} else {
    		item::Error* err = new item::Error();
    		err->type = Failed;
    		throw err;
    	}
    } else {
		item::Error* err = new item::Error();
		err->type = Invalid;
		throw err;
    }

	return container;
}

Result SynchronizationImpl::QueryPath(const QueryPtr& query, const Ice::Current& current) {
	Result r;
	return r;
}

} /* namespace tree */
} /* namespace inexor */
