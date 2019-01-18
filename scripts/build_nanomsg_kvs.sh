#!/bin/bash

set -e 

topdir=`pwd`
installdir=`pwd`/third_party/local

if [ -z "${CMAKE_BIN+x}" ]; then
  CMAKE_BIN=cmake
fi

if [ -z "${CC+x}" ]; then
  c_compiler=mpicc
  CC=mpicc
else
  c_compiler=${CC}
fi

if [ -z "${CXX+x}" ]; then
  cxx_compiler=mpicxx
  CXX=mpicxx
else
  cxx_compiler=${CXX}
fi

c_flags="-fPIC"
cxx_flags="-fPIC"

echo "C compiler  : " ${CC}
echo "CXX compiler: " ${CXX}

function clean_install_dir {
	rm -rf ${installdir}
}

function build_nanomsg {

	cd third_party/ 
	cd nanomsg/
	#if [ -f "Makefile" ]; then
	#	make distclean
	#fi

	autoreconf -ivf
	CXX=${cxx_compiler} CC=${c_compiler} ./configure --prefix=${installdir}/nanomsg && make -j 12 && make install
	if [[ $? != 0 ]]; then exit $?; fi
	cd ${topdir}
}

function build_kvs {

	cd third_party

	rm -rf KVS_build
	mkdir -p KVS_build
	cd KVS_build

	CXX=${cxx_compiler} CC=${c_compiler} CFLAGS=${c_flags} CXXFLAGS=${cxx_flags} ${CMAKE_BIN} -DCMAKE_INSTALL_PREFIX=${installdir}/kvs -DKVS_TOOL=OFF -DKVS_SUPPORT_GLUT=ON -DKVS_SUPPORT_QT=OFF -DKVS_SUPPORT_OPENCV=OFF -DKVS_SUPPORT_CUDA=OFF ../KVS && make -j 12 && make install

	if [[ $? != 0 ]]; then exit $?; fi
	cd ${topdir}
}

clean_install_dir
build_nanomsg
build_kvs
