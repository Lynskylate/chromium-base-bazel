package(default_visibility = ["//visibility:public"])

load("//build:compiler.bzl", "COPTS")

cc_library(
    name = "libevent",
    srcs = [
        "buffer.c",
        "evbuffer.c",
        "evdns.c",
        "event.c",
        "event_tagging.c",
        "evrpc.c",
        "evutil.c",
        "http.c",
        "log.c",
        "poll.c",
        "select.c",
        "signal.c",
        "strlcpy.c",
    ] + [
        # Linux
        "compat/sys/_libevent_time.h",
        "compat/sys/queue.h",
        "epoll.c",
    ],
    hdrs = [
        "evdns.h",
        "event.h",
        "event-internal.h",
        "evhttp.h",
        "evrpc.h",
        "evrpc-internal.h",
        "evsignal.h",
        "evutil.h",
        "http-internal.h",
        "linux/config.h",
        "linux/event-config.h",
        "log.h",
        "min_heap.h",
        "strlcpy-internal.h",
    ],
    copts = COPTS,
    defines = ["HAVE_CONFIG_H"],
    includes = [
        ".",
        "compat",
        "linux",
    ],
    licenses = ["permissive"],
    linkstatic = True,
)
