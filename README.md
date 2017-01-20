# ZMQUE
ZMQ for Unreal Engine 4 -- Quick &amp; Dirty


This project was built during a rapid prototyping push, so it exists as
a quick-and-dirty interface. There was no thought to efficiency or
elegance. There are just pass-through functions and the minimum that
is required to call every zmq function in the library.

This is not completely tested. Only the basic calls are in use.

This project and its contents are provided without warranty and support
will not be provided. This project and its contents exist within the
public domain. Any derivations or use cases can attribute the author
and this Git repository at the discretion of their owners, but any
acknowledgement is appreciated.

This Git will be maintained, albeit minimally, and others are welcome
to help improve this code base.


NOTES:

The source and a pre-built version are provided. Games using the ZMQUE
module will only be able to compile for Windows (or anything that can
handle "Win64").

The project is for Visual Studio 2015.

I used ZMQ version 4.0.4 but it is very easy to replace what is there
now. Also, I am using the DLL version of ZMQ. That adds extra work
placing the DLL where it needs to be so the game/editor can find it.

The biggest hurdle was the fact that UE4 and ZMQ treat "short" in two
different ways. As with the poll item struct, it is important that any
other instances of data passing also take this difference into
consideration. Make sure you are explicit about the "sizeof" the data
your game passes to or gets from ZMQ.
