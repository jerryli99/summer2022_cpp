#!/bin/bash
#docker rmi $(docker images --filter "dangling=true" -q --no-trunc)
docker build . -t practice13:latest
clear
echo "----------------------------Output-----------------------------"
docker run --rm -it practice13:latest
echo "---------------------------------------------------------------"

