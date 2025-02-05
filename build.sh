#! /usr/bin/env bash

pushd build
cmake -G Ninja ..
ninja
popd
