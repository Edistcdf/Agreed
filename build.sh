#! /usr/bin/env bash

pushd build
cmake -G Ninja -DCMAKE_PREFIX_PATH=/usr/lib/x86_64-linux-gnu/qt5 ..
ninja
popd
