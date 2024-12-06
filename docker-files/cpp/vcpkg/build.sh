#!/bin/bash
echo "* build image: wedpr_component_vcpkg_cache, branch: ${1}"
docker build --build-arg SOURCE_BRANCH=${1} -t wedpr_component_vcpkg_cache .
echo "* build image: wedpr_component_vcpkg_cache success, branch: ${1}"