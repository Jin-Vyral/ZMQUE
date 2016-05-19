#pragma once

typedef struct ZMQ_msg_t { unsigned char _[32]; } ZMQ_msg_t;

typedef void (ZMQ_free_fn)(void *data, void *hint);

typedef struct
{
  void *socket;
  void *fd;
  int16 events;
  int16 revents;
} ZMQ_pollitem_t;

void *ZMQ_ctx_new(void);
int ZMQ_ctx_term(void *context);
int ZMQ_ctx_shutdown(void *ctx_);
int ZMQ_ctx_set(void *context, int option, int optval);
int ZMQ_ctx_get(void *context, int option);
int ZMQ_msg_init(ZMQ_msg_t *msg);
int ZMQ_msg_init_size(ZMQ_msg_t *msg, int size);
int ZMQ_msg_init_data(ZMQ_msg_t *msg, void *data, int size, void *ffn, void *hint);
int ZMQ_msg_send(ZMQ_msg_t *msg, void *s, int flags);
int ZMQ_msg_recv(ZMQ_msg_t *msg, void *s, int flags);
int ZMQ_msg_close(ZMQ_msg_t *msg);
int ZMQ_msg_move(void *dest, void *src);
int ZMQ_msg_copy(void *dest, void *src);
void *ZMQ_msg_data(ZMQ_msg_t *msg);
int ZMQ_msg_size(ZMQ_msg_t *msg);
int ZMQ_msg_more(ZMQ_msg_t *msg);
int ZMQ_msg_get(ZMQ_msg_t *msg, int option);
int ZMQ_msg_set(ZMQ_msg_t *msg, int option, int optval);
void *ZMQ_socket(void* s, int type);
int ZMQ_close(void *s);
int ZMQ_setsockopt(void *s, int option, const void *optval, int optvallen);
int ZMQ_getsockopt(void *s, int option, void *optval, int *optvallen);
int ZMQ_bind(void *s, const char *addr);
int ZMQ_connect(void *s, const char *addr);
int ZMQ_unbind(void *s, const char *addr);
int ZMQ_disconnect(void *s, const char *addr);
int ZMQ_send(void *s, const void *buf, int len, int flags);
int ZMQ_send_const(void *s, const void *buf, int len, int flags);
int ZMQ_recv(void *s, void *buf, int len, int flags);
int ZMQ_socket_monitor(void *s, const char *addr, int events);
int ZMQ_sendmsg(void *s, ZMQ_msg_t *msg, int flags);
int ZMQ_recvmsg(void *s, ZMQ_msg_t *msg, int flags);
int ZMQ_sendiov(void *s, void *iov, int count, int flags);
int ZMQ_recviov(void *s, void *iov, int *count, int flags);
int ZMQ_poll(ZMQ_pollitem_t *items, int nitems, long timeout);
int ZMQ_proxy(void *frontend, void *backend, void *capture);
char *ZMQ_z85_encode(char *dest, byte *data, int size);
byte *ZMQ_z85_decode(byte *dest, char *string);
void ZMQ_version(int *major, int *minor, int *patch);
int ZMQ_errno(void);
const char *ZMQ_strerror(int errnum);

#define ZMQ_VERSION_MAJOR 4
#define ZMQ_VERSION_MINOR 0
#define ZMQ_VERSION_PATCH 4
#define ZMQ_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define ZMQ_VERSION \
    ZMQ_MAKE_VERSION(ZMQ_VERSION_MAJOR, ZMQ_VERSION_MINOR, ZMQ_VERSION_PATCH)
#define ZMQ_HAUSNUMERO 156384712
#ifndef ENOTSUP
#define ENOTSUP (ZMQ_HAUSNUMERO + 1)
#endif
#ifndef EPROTONOSUPPORT
#define EPROTONOSUPPORT (ZMQ_HAUSNUMERO + 2)
#endif
#ifndef ENOBUFS
#define ENOBUFS (ZMQ_HAUSNUMERO + 3)
#endif
#ifndef ENETDOWN
#define ENETDOWN (ZMQ_HAUSNUMERO + 4)
#endif
#ifndef EADDRINUSE
#define EADDRINUSE (ZMQ_HAUSNUMERO + 5)
#endif
#ifndef EADDRNOTAVAIL
#define EADDRNOTAVAIL (ZMQ_HAUSNUMERO + 6)
#endif
#ifndef ECONNREFUSED
#define ECONNREFUSED (ZMQ_HAUSNUMERO + 7)
#endif
#ifndef EINPROGRESS
#define EINPROGRESS (ZMQ_HAUSNUMERO + 8)
#endif
#ifndef ENOTSOCK
#define ENOTSOCK (ZMQ_HAUSNUMERO + 9)
#endif
#ifndef EMSGSIZE
#define EMSGSIZE (ZMQ_HAUSNUMERO + 10)
#endif
#ifndef EAFNOSUPPORT
#define EAFNOSUPPORT (ZMQ_HAUSNUMERO + 11)
#endif
#ifndef ENETUNREACH
#define ENETUNREACH (ZMQ_HAUSNUMERO + 12)
#endif
#ifndef ECONNABORTED
#define ECONNABORTED (ZMQ_HAUSNUMERO + 13)
#endif
#ifndef ECONNRESET
#define ECONNRESET (ZMQ_HAUSNUMERO + 14)
#endif
#ifndef ENOTCONN
#define ENOTCONN (ZMQ_HAUSNUMERO + 15)
#endif
#ifndef ETIMEDOUT
#define ETIMEDOUT (ZMQ_HAUSNUMERO + 16)
#endif
#ifndef EHOSTUNREACH
#define EHOSTUNREACH (ZMQ_HAUSNUMERO + 17)
#endif
#ifndef ENETRESET
#define ENETRESET (ZMQ_HAUSNUMERO + 18)
#endif
#define EFSM (ZMQ_HAUSNUMERO + 51)
#define ENOCOMPATPROTO (ZMQ_HAUSNUMERO + 52)
#define ETERM (ZMQ_HAUSNUMERO + 53)
#define EMTHREAD (ZMQ_HAUSNUMERO + 54)
#define ZMQ_IO_THREADS  1
#define ZMQ_MAX_SOCKETS 2
#define ZMQ_IO_THREADS_DFLT  1
#define ZMQ_MAX_SOCKETS_DFLT 1023
#define ZMQ_PAIR 0
#define ZMQ_PUB 1
#define ZMQ_SUB 2
#define ZMQ_REQ 3
#define ZMQ_REP 4
#define ZMQ_DEALER 5
#define ZMQ_ROUTER 6
#define ZMQ_PULL 7
#define ZMQ_PUSH 8
#define ZMQ_XPUB 9
#define ZMQ_XSUB 10
#define ZMQ_STREAM 11
#define ZMQ_XREQ ZMQ_DEALER
#define ZMQ_XREP ZMQ_ROUTER
#define ZMQ_AFFINITY 4
#define ZMQ_IDENTITY 5
#define ZMQ_SUBSCRIBE 6
#define ZMQ_UNSUBSCRIBE 7
#define ZMQ_RATE 8
#define ZMQ_RECOVERY_IVL 9
#define ZMQ_SNDBUF 11
#define ZMQ_RCVBUF 12
#define ZMQ_RCVMORE 13
#define ZMQ_FD 14
#define ZMQ_EVENTS 15
#define ZMQ_TYPE 16
#define ZMQ_LINGER 17
#define ZMQ_RECONNECT_IVL 18
#define ZMQ_BACKLOG 19
#define ZMQ_RECONNECT_IVL_MAX 21
#define ZMQ_MAXMSGSIZE 22
#define ZMQ_SNDHWM 23
#define ZMQ_RCVHWM 24
#define ZMQ_MULTICAST_HOPS 25
#define ZMQ_RCVTIMEO 27
#define ZMQ_SNDTIMEO 28
#define ZMQ_LAST_ENDPOINT 32
#define ZMQ_ROUTER_MANDATORY 33
#define ZMQ_TCP_KEEPALIVE 34
#define ZMQ_TCP_KEEPALIVE_CNT 35
#define ZMQ_TCP_KEEPALIVE_IDLE 36
#define ZMQ_TCP_KEEPALIVE_INTVL 37
#define ZMQ_TCP_ACCEPT_FILTER 38
#define ZMQ_IMMEDIATE 39
#define ZMQ_XPUB_VERBOSE 40
#define ZMQ_ROUTER_RAW 41
#define ZMQ_IPV6 42
#define ZMQ_MECHANISM 43
#define ZMQ_PLAIN_SERVER 44
#define ZMQ_PLAIN_USERNAME 45
#define ZMQ_PLAIN_PASSWORD 46
#define ZMQ_CURVE_SERVER 47
#define ZMQ_CURVE_PUBLICKEY 48
#define ZMQ_CURVE_SECRETKEY 49
#define ZMQ_CURVE_SERVERKEY 50
#define ZMQ_PROBE_ROUTER 51
#define ZMQ_REQ_CORRELATE 52
#define ZMQ_REQ_RELAXED 53
#define ZMQ_CONFLATE 54
#define ZMQ_ZAP_DOMAIN 55
#define ZMQ_MORE 1
#define ZMQ_DONTWAIT 1
#define ZMQ_SNDMORE 2
#define ZMQ_NULL 0
#define ZMQ_PLAIN 1
#define ZMQ_CURVE 2
#define ZMQ_IPV4ONLY                31
#define ZMQ_DELAY_ATTACH_ON_CONNECT ZMQ_IMMEDIATE
#define ZMQ_NOBLOCK                 ZMQ_DONTWAIT
#define ZMQ_FAIL_UNROUTABLE         ZMQ_ROUTER_MANDATORY
#define ZMQ_ROUTER_BEHAVIOR         ZMQ_ROUTER_MANDATORY
#define ZMQ_EVENT_CONNECT_DELAYED 2
#define ZMQ_EVENT_CONNECT_RETRIED 4
#define ZMQ_EVENT_LISTENING 8
#define ZMQ_EVENT_BIND_FAILED 16
#define ZMQ_EVENT_ACCEPTED 32
#define ZMQ_EVENT_ACCEPT_FAILED 64
#define ZMQ_EVENT_CLOSED 128
#define ZMQ_EVENT_CLOSE_FAILED 256
#define ZMQ_EVENT_DISCONNECTED 512
#define ZMQ_EVENT_MONITOR_STOPPED 1024
#define ZMQ_EVENT_ALL ( ZMQ_EVENT_CONNECTED | ZMQ_EVENT_CONNECT_DELAYED | \
                        ZMQ_EVENT_CONNECT_RETRIED | ZMQ_EVENT_LISTENING | \
                        ZMQ_EVENT_BIND_FAILED | ZMQ_EVENT_ACCEPTED | \
                        ZMQ_EVENT_ACCEPT_FAILED | ZMQ_EVENT_CLOSED | \
                        ZMQ_EVENT_CLOSE_FAILED | ZMQ_EVENT_DISCONNECTED | \
                        ZMQ_EVENT_MONITOR_STOPPED)
#define ZMQ_POLLIN 1
#define ZMQ_POLLOUT 2
#define ZMQ_POLLERR 4
#define ZMQ_POLLITEMS_DFLT 16
#define ZMQ_STREAMER 1
#define ZMQ_FORWARDER 2
#define ZMQ_QUEUE 3



