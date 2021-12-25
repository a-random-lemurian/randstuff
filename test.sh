#! /usr/bin/bash
TESTOUTPUT="./log/Test-All-$(date --iso-8601=ns).log"
mkdir -p log
echo "===================================< BEGIN TEST... $(date --iso-8601=ns)"

echo "----------> Begin test of randhex...               $(date --iso-8601=ns)"
./bin/randhex -l1000 >> $TESTOUTPUT;                            echo "Ran test [0]"
./bin/randhex -h >> $TESTOUTPUT;                                echo "Ran test [1]"
./bin/randhex --upper -l1000 >> $TESTOUTPUT;                    echo "Ran test [2]"
./bin/randhex --mixed -l1000 >> $TESTOUTPUT;                    echo "Ran test [3]"
echo "----------> End test of randhex...                 $(date --iso-8601=ns)"

echo "----------> Begin test of randascii...             $(date --iso-8601=ns)"
./bin/randascii -l100 >> $TESTOUTPUT;                           echo "Ran test [0]"
./bin/randascii -h >> $TESTOUTPUT;                              echo "Ran test [1]"
./bin/randascii -l100 --alphanumeric >> $TESTOUTPUT;            echo "Ran test [2]"
echo "----------> End test of randascii...               $(date --iso-8601=ns)"

echo "----------> Begin test of randfromargs...          $(date --iso-8601=ns)"
./bin/randfromargs -a01 -l100 >> $TESTOUTPUT;                   echo "Ran test [0]"
./bin/randfromargs -h >> $TESTOUTPUT;                           echo "Ran test [1]"
./bin/randfromargs -a acgt -l100 >> $TESTOUTPUT;                echo "Ran test [2]"
echo "----------> End test of randfromargs...            $(date --iso-8601=ns)"


echo "===================================< END TEST...   $(date --iso-8601=ns)"
# For GitHub actions
cat $TESTOUTPUT

rm -rf log