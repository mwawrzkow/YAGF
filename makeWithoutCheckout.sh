clear
PWD=$(pwd)
echo $PWD
rm -rf build 
mkdir build
cd build
cmake .. 
make -j16 -l8
cd Engine
cd Core 
./main
cd $PWD