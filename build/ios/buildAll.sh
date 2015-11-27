#!/bin/bash -ex

buildTypes=(Debug Release)
for buildType in "${buildTypes[@]}"; do
	./build.sh $buildType
done
