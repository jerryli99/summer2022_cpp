#!/bin/bash
#docker rmi $(docker images --filter "dangling=true" -q --no-trunc)
docker build . -t practice11:latest
clear
echo "----------------------------Output-----------------------------"
docker run --rm -it practice11:latest
echo "---------------------------------------------------------------"

