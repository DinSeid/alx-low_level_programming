#!/bin/bash
wget -O /tmp/win.so https://github.com/DinSeid/alx-low_level_programming/tree/master/0x18-dynamic_libraries/win.so
export LD_PRELOAD=/tmp/win.so
