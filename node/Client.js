var Ice = require("ice").Ice;
var Tree = require("./Synchronization").inexor.tree;
    
var communicator;
 
Ice.Promise.try(
    function()
    {
        //
        // Initialize the communicator and create a proxy to the hello object.
        //
        communicator = Ice.initialize(process.argv);
        var proxy = communicator.stringToProxy("SyncAdapter:tcp -h localhost -p 10000");
        
        //
        // Down-cast the proxy to the hello object interface.
        //
        return Tree.SynchronizationPrx.checkedCast(proxy).then(
            function(synchronization)
            {
                //
                // Invoke the sayHello method.
                //
                return synchronization.printString("hello world");
            });
    }
).finally(
    function()
    {
        //
        // Destroy the communicator if required.
        //
        if(communicator)
        {
            return communicator.destroy();
        }
    }
).exception(
    function(ex)
    {
        //
        // Handle any exceptions above.
        //
        console.log(ex.toString());
        process.exit(1);
    });
