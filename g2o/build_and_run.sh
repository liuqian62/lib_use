rm -rf build
rm -rf bin
mkdir build
mkdir bin
cd build
cmake ..
make
cd ..
./bin/useG2o