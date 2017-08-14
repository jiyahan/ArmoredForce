/*
 * Copyright 2013 Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "TimeoutQueue.h"
#include <algorithm>
#include <vector>

namespace folly {

TimeoutQueue::Id TimeoutQueue::add(
  int64_t now,
  int64_t delay,
  Callback callback) {
  Id id = nextId_++;
  Set::value_type val = {id, now + delay, -1, std::move(callback)};
  timeouts_.insert(std::move(val));
  return id;
}

TimeoutQueue::Id TimeoutQueue::addRepeating(
  int64_t now,
  int64_t interval,
  Callback callback) {
  Id id = nextId_++;
  Set::value_type val = {id, now + interval, interval, std::move(callback)};
  timeouts_.insert(std::move(val));
  return id;
}

int64_t TimeoutQueue::nextExpiration() const {
  return (timeouts_.empty() ? std::numeric_limits<int64_t>::max() :
          timeouts_.get<BY_EXPIRATION>().begin()->expiration);
}

bool TimeoutQueue::erase(Id id) {
  return timeouts_.get<BY_ID>().erase(id);
}

int64_t TimeoutQueue::runInternal(int64_t now, bool onceOnly) {
  auto& byExpiration = timeouts_.get<BY_EXPIRATION>();
  int64_t nextExp;
  do {
    auto end = byExpiration.upper_bound(now);
    std::vector<Event> expired;
    std::move(byExpiration.begin(), end, std::back_inserter(expired));
    byExpiration.erase(byExpiration.begin(), end);
    for (auto& event : expired) {
      // Reinsert if repeating, do this before executing callbacks
      // so the callbacks have a chance to call erase
      if (event.repeatInterval >= 0) {
        Set::value_type val = {event.id, now + event.repeatInterval,
                          event.repeatInterval, event.callback};
        timeouts_.insert(std::move(val));
      }
    }

    // Call callbacks
    for (auto& event : expired) {
      event.callback(event.id, now);
    }
    nextExp = nextExpiration();
  } while (!onceOnly && nextExp <= now);
  return nextExp;
}

}  // namespace folly

