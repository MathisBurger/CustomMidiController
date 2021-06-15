#include "checker/checker.h"


void checkFader(Protocols prots, uint8_t channel[], int *channelValues[]) {
    for (int i=0; i<(int)sizeof(channel); i++) {
      int value = analogRead(channel[i]);
      if (prots.tolleranceTriggered(*channelValues[i], value)) {
        *channelValues[i] = value;
      }
    }
}