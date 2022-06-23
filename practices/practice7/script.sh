#!/bin/bash
docker rmi $(docker images --filter "dangling=true" -q --no-trunc)
docker images
docker build . -t practice7:latest
clear
echo "--------------------Output---------------------"
docker run --rm -it practice7:latest
echo "-----------------------------------------------"
#docker images
