#!/bin/bash
fname() {
    echo $1;
    echo "$@";
    echo "$*";
    return 0;
}

fname zhang cheng fei
