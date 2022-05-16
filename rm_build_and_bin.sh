#!/bin/bash

SCRIPT=$(readlink -f "$0")
BASEDIR=$(dirname "$SCRIPT")


cd $BASEDIR
if [ ! -d ceres  ]
then
    echo "ERROR: can not find $BASEDIR/ceres directory."
    echo "  Please run this script in righr directory."
    exit -1
fi
cd ceres
rm -rf build
rm -rf bin

cd $BASEDIR
if [ ! -d eigen ]
then
    echo "ERROR: can not find $BASEDIR/eigen directory."
    echo "  Please run this script in righr directory."
    exit -1
fi
cd eigen
rm -rf build
rm -rf bin

cd $BASEDIR
if [ ! -d g2o ]
then
    echo "ERROR: can not find $BASEDIR/g2o directory."
    echo "  Please run this script in righr directory."
    exit -1
fi
cd g2o
rm -rf build
rm -rf bin

cd $BASEDIR
if [ ! -d opencv ]
then
    echo "ERROR: can not find $BASEDIR/opencv directory."
    echo "  Please run this script in righr directory."
    exit -1
fi
cd opencv
rm -rf build
rm -rf bin


cd $BASEDIR
if [ ! -d sophus ]
then
    echo "ERROR: can not find $BASEDIR/sophus directory."
    echo "  Please run this script in righr directory."
    exit -1
fi
cd sophus
rm -rf build
rm -rf bin


