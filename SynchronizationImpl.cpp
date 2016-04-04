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

	    Primitive p;
	    in->read(p);

	    Tree.put(item.path, p);
	} catch (const boost::property_tree::ptree_bad_data& ex) {
		item::Error* err = new item::Error();
		err->type = Conversion;
		throw err;
	}
}

Container SynchronizationImpl::getItem(const ::std::string& path, const ::Ice::Current& current) {
	Container container;
	Ice::CommunicatorPtr communicator = current.adapter->getCommunicator();
    Ice::OutputStreamPtr out = Ice::createOutputStream(communicator);

    Primitive data = Tree.get<Primitive>(path);
    out->write(data);
    out->finished(container.value);

    try {
    	if (typeid(bool) == data.type()) {
    		container.type = BoolValue;
    	} else if (typeid(short) == data.type()) {
    		container.type = ShortValue;
    	} else if (typeid(int) == data.type()) {
    		container.type = IntValue;
    	} else if (typeid(long) == data.type()) {
    		container.type = LongValue;
    	} else if (typeid(double) == data.type()) {
    		container.type = DoubleValue;
    	} else if (typeid(float) == data.type()) {
    		container.type = FloatValue;
    	} else if (typeid(std::string) == data.type()) {
    		container.type = StringValue;
    	} else {
    		item::Error* err = new item::Error();
    		err->type = Conversion;
    		throw err;
    	}
    } catch ( const boost::property_tree::ptree_bad_path& ex) {
    	item::Error* err = new item::Error();
    	err->type = NonFound;
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
