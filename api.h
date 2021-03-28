#ifndef API_H
#define API_H

#define API_REQ_PADSTART (192)

struct apiEntry {
    uint32_t addr;
    int32_t lat;
    int32_t lon;
    int jsonLen;
    char json[1024];
};

struct apiThread {
    pthread_t thread;
    pthread_mutex_t mutex;
    int index;
    int epfd;
    int eventfd;
};

struct twofds {
    int32_t read;
    int32_t accept;
} __attribute__ ((__packed__));

struct apiBuffer {
    int len;
    int alloc;
    struct apiEntry *list;
    uint64_t timestamp;
};

struct range {
    int from; // inclusive
    int to; // exclusive
};

void apiInit();
void apiCleanup();

int apiUpdate(struct craftArray *ca);
struct char_buffer apiReq(struct apiBuffer *buffer, double latMin, double latMax, double lonMin, double lonMax);

#endif