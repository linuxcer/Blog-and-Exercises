#!/bin/bash
for i in {1..6};
do
    set -x
    echo $i
    set +x
done
echo "done"
