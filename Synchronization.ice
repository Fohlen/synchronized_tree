module inexor {
	module tree {
		module item {
			/*
			 * @ErrorType
			 *	NonFound - not found
			 *	Permission - insufficient permission, such as in a protected namespace
			 *	Condition - this only occurs at a race-condition (internally)
			 *	Conversion - type conversion error
			 */
			enum ErrorType { NonFound, Permission, Condition, Conversion };
			enum Type { BoolValue, ShortValue, IntValue, LongValue, FloatValue, DoubleValue, StringValue };
			sequence<byte> ByteSequence;
		
			struct Container {
				string path;
				Type type;
				ByteSequence value;
			};
			
			exception Error {
				// this is not really usefull; Item item;
				ErrorType type;
			};
		};
		
		module path {
			enum Type { Node, Value }; // Is this a node item or a value item?
			
			class Query {
				string path;
				optional(0) int depth = 0; // 0 = everything
			};
			
			class Item {
				string path;
				Type type;
				optional(0) ::inexor::tree::item::Container item; // Optionally deliver the item
			};
			
			sequence<Item> Result;
		};
		
		interface Synchronization {
			idempotent void setItem(::inexor::tree::item::Container item)
				throws ::inexor::tree::item::Error;
        	idempotent ::inexor::tree::item::Container getItem(string path)
        		throws ::inexor::tree::item::Error;
        	::inexor::tree::path::Result QueryPath(::inexor::tree::path::Query query);
    	};
	};
};