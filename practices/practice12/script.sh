#!/bin/bash
#docker rmi $(docker images --filter "dangling=true" -q --no-trunc)
docker build . -t practice12:latest
clear
echo "----------------------------Output-----------------------------"
docker run --rm -it practice12:latest
echo "---------------------------------------------------------------"

