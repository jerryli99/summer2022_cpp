#!/bin/bash
#docker rmi $(docker images --filter "dangling=true" -q --no-trunc)
docker build . -t practice14:latest
clear
echo "----------------------------Output-----------------------------"
docker run --rm -it practice14:latest
echo "---------------------------------------------------------------"

