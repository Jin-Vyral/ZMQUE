#include "stdafx.h"
#include "ZMQUE.h"

void* ZMQ_ctx_new()
{
  return zmq_ctx_new();
}

int ZMQ_ctx_term(void *context)
{
  return zmq_ctx_term(context);
}

int ZMQ_ctx_shutdown(void *ctx_)
{
  return zmq_ctx_shutdown(ctx_);
}

int ZMQ_ctx_set(void *context, int option, int optval)
{
  return zmq_ctx_set(context, option, optval);
}

int ZMQ_ctx_get(void *context, int option)
{
  return zmq_ctx_get(context, option);
}

int ZMQ_msg_init(ZMQ_msg_t *msg)
{
  return zmq_msg_init((zmq_msg_t*) msg);
}

int ZMQ_msg_init_size(ZMQ_msg_t *msg, int size)
{
  return zmq_msg_init_size((zmq_msg_t*) msg, (size_t) size);
}

int ZMQ_msg_init_data(ZMQ_msg_t *msg, void *data, int size, void *ffn, void *hint)
{
  return zmq_msg_init_data((zmq_msg_t*) msg, data, (size_t) size, (zmq_free_fn*) ffn, hint);
}

int ZMQ_msg_send(ZMQ_msg_t *msg, void *s, int flags)
{
  return zmq_msg_send((zmq_msg_t*) msg, s, flags);
}

int ZMQ_msg_recv(ZMQ_msg_t *msg, void *s, int flags)
{
  return zmq_msg_recv((zmq_msg_t*) msg, s, flags);
}

int ZMQ_msg_close(ZMQ_msg_t *msg)
{
  return zmq_msg_close((zmq_msg_t*) msg);
}

int ZMQ_msg_move(ZMQ_msg_t *dest, ZMQ_msg_t *src)
{
  return zmq_msg_move((zmq_msg_t*) dest, (zmq_msg_t*) src);
}

int ZMQ_msg_copy(ZMQ_msg_t *dest, ZMQ_msg_t *src)
{
  return zmq_msg_copy((zmq_msg_t*) dest, (zmq_msg_t*) src);
}

void *ZMQ_msg_data(ZMQ_msg_t *msg)
{
  return zmq_msg_data((zmq_msg_t*) msg);
}

int ZMQ_msg_size(ZMQ_msg_t *msg)
{
  return (int) zmq_msg_size((zmq_msg_t*) msg);
}

int ZMQ_msg_more(ZMQ_msg_t *msg)
{
  return zmq_msg_more((zmq_msg_t*) msg);
}

int ZMQ_msg_get(ZMQ_msg_t *msg, int option)
{
  return zmq_msg_get((zmq_msg_t*) msg, option);
}

int ZMQ_msg_set(ZMQ_msg_t *msg, int option, int optval)
{
  return zmq_msg_set((zmq_msg_t*) msg, option, optval);
}

void *ZMQ_socket(void* s, int type)
{
  return zmq_socket(s, type);
}

int ZMQ_close(void *s)
{
  return zmq_close(s);
}

int ZMQ_setsockopt(void *s, int option, const void *optval, int optvallen)
{
  return zmq_setsockopt(s, option, optval, (size_t) optvallen);
}

int ZMQ_getsockopt(void *s, int option, void *optval, int *optvallen)
{
  return zmq_getsockopt(s, option, optval, (size_t*) optvallen);
}

int ZMQ_bind(void *s, const char *addr)
{
  return zmq_bind(s, addr);
}

int ZMQ_connect(void *s, const char *addr)
{
  return zmq_connect(s, addr);
}

int ZMQ_unbind(void *s, const char *addr)
{
  return zmq_unbind(s, addr);
}

int ZMQ_disconnect(void *s, const char *addr)
{
  return zmq_disconnect(s, addr);
}

int ZMQ_send(void *s, const void *buf, int len, int flags)
{
  return zmq_send(s, buf, (size_t) len, flags);
}

int ZMQ_send_const(void *s, const void *buf, int len, int flags)
{
  return zmq_send_const(s, buf, (size_t) len, flags);
}

int ZMQ_recv(void *s, void *buf, int len, int flags)
{
  return zmq_recv(s, buf, (size_t) len, flags);
}

int ZMQ_socket_monitor(void *s, const char *addr, int events)
{
  return zmq_socket_monitor(s, addr, events);
}

int ZMQ_sendmsg(void *s, ZMQ_msg_t *msg, int flags)
{
  return zmq_sendmsg(s, (zmq_msg_t*) msg, flags);
}

int ZMQ_recvmsg(void *s, ZMQ_msg_t *msg, int flags)
{
  return zmq_recvmsg(s, (zmq_msg_t*) msg, flags);
}

int ZMQ_sendiov(void *s, void *iov, int count, int flags)
{
  return zmq_sendiov(s, (struct iovec*) iov, (size_t) count, flags);
}

int ZMQ_recviov(void *s, void *iov, int *count, int flags)
{
  return zmq_recviov(s, (struct iovec*) iov, (size_t*) count, flags);
}

int ZMQ_poll(ZMQ_pollitem_t *items, int nitems, long timeout)
{
  return zmq_poll((zmq_pollitem_t*) items, nitems, timeout);
}

int ZMQ_proxy(void *frontend, void *backend, void *capture)
{
  return zmq_proxy(frontend, backend, capture);
}

char *ZMQ_z85_encode(char *dest, byte *data, int size)
{
  return zmq_z85_encode(dest, data, (size_t) size);
}

byte *ZMQ_z85_decode(byte *dest, char *string)
{
  return zmq_z85_decode(dest, string);
}

void ZMQ_version(int *major, int *minor, int *patch)
{
  zmq_version(major, minor, patch);
}

int ZMQ_errno(void)
{
  return zmq_errno();
}

const char *ZMQ_strerror(int errnum)
{
  return zmq_strerror(errnum);
}

