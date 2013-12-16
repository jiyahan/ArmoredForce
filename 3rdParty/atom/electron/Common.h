#ifndef ELECTRON_COMMON_H_
#define ELECTRON_COMMON_H_

#include "../atom/CAtom.h"
#include "../common/Setting.inl"

using namespace atom;

#define MAX_MESSAGE_QUEUE_CONTROLLER_SET 16
#define MAX_MESSAGE_LENGTH               16 * 1024 * 1024

#define HEART_BEAT_INTERVAL              30 * 1000
#define HEART_BEAT_TIMEOUT               15 * 1000

#define MAX_SCHEDULER_WORKER_THREAD      16
#define MIN_COMPRESS_LENGTH              64

#endif