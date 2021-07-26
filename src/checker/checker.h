#ifndef CHECKER_H
#define CHECKER_H

#include "protocols/protocols.h"
#include <Arduino.h>

void checkFader(Protocols *prots, uint8_t *channel[], int *channelValues[], int *channelNumbers[]);

#endif