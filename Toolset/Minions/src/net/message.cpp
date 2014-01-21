#include "message.h"

Message::Message()
{
    buffer_.emplace_back('o');
}

Message::~Message()
{
}