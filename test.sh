#! /usr/bin/bash
echo "BEGIN TEST... $(date --iso-8601=ns)"
./bin/randhex -l1000 > /dev/null
./bin/randhex -h > /dev/null
./bin/randhex --upper -l1000 > /dev/null
./bin/randhex --mixed -l1000 > /dev/null
echo "END TEST...   $(date --iso-8601=ns)"