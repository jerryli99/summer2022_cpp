#!/bin/bash
docker rmi $(docker images --filter "dangling=true" -q --no-trunc)
docker images
docker build . -t practice5:latest
clear
echo "--------------------Output---------------------"
docker run --rm -it practice5:latest
echo "-----------------------------------------------"
#docker images
