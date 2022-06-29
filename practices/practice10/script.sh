#!/bin/bash
docker rmi $(docker images --filter "dangling=true" -q --no-trunc)
#docker images
docker build . -t practice10:latest
clear
echo "--------------------Output---------------------"
docker run --rm -it practice10:latest
echo "-----------------------------------------------"
docker images
