/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/

#include "QmlZpoller.h"


///
//  Add a reader to be polled. Returns 0 if OK, -1 on failure. The reader may
//  be a libzmq void * socket, a zsock_t instance, or a zactor_t instance.   
int QmlZpoller::add (void *reader) {
    return zpoller_add (self, reader);
};

///
//  Remove a reader from the poller; returns 0 if OK, -1 on failure. The reader
//  must have been passed during construction, or in an zpoller_add () call.   
int QmlZpoller::remove (void *reader) {
    return zpoller_remove (self, reader);
};

///
//  By default the poller stops if the process receives a SIGINT or SIGTERM  
//  signal. This makes it impossible to shut-down message based architectures
//  like zactors. This method lets you switch off break handling. The default
//  nonstop setting is off (false).                                          
void QmlZpoller::setNonstop (bool nonstop) {
    zpoller_set_nonstop (self, nonstop);
};

///
//  Poll the registered readers for I/O, return first reader that has input.  
//  The reader will be a libzmq void * socket, or a zsock_t or zactor_t       
//  instance as specified in zpoller_new/zpoller_add. The timeout should be   
//  zero or greater, or -1 to wait indefinitely. Socket priority is defined   
//  by their order in the poll list. If you need a balanced poll, use the low 
//  level zmq_poll method directly. If the poll call was interrupted (SIGINT),
//  or the ZMQ context was destroyed, or the timeout expired, returns NULL.   
//  You can test the actual exit condition by calling zpoller_expired () and  
//  zpoller_terminated (). The timeout is in msec.                            
void *QmlZpoller::wait (int timeout) {
    return zpoller_wait (self, timeout);
};

///
//  Return true if the last zpoller_wait () call ended because the timeout
//  expired, without any error.                                           
bool QmlZpoller::expired () {
    return zpoller_expired (self);
};

///
//  Return true if the last zpoller_wait () call ended because the process
//  was interrupted, or the parent context was destroyed.                 
bool QmlZpoller::terminated () {
    return zpoller_terminated (self);
};


QObject* QmlZpoller::qmlAttachedProperties(QObject* object) {
    return new QmlZpollerAttached(object);
}


///
//  Self test of this class.
void QmlZpollerAttached::test (bool verbose) {
    zpoller_test (verbose);
};

///
//  Create new poller, specifying zero or more readers. The list of 
//  readers ends in a NULL. Each reader can be a zsock_t instance, a
//  zactor_t instance, a libzmq socket (void *), or a file handle.  
QmlZpoller *QmlZpollerAttached::construct (void *reader) {
    QmlZpoller *qmlSelf = new QmlZpoller ();
    qmlSelf->self = zpoller_new (reader);
    return qmlSelf;
};

///
//  Destroy a poller
void QmlZpollerAttached::destruct (QmlZpoller *qmlSelf) {
    zpoller_destroy (&qmlSelf->self);
};

/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
