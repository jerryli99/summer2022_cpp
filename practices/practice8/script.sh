#!/bin/bash
docker rmi $(docker images --filter "dangling=true" -q --no-trunc)
docker images
docker build . -t practic8:latest
clear
echo "--------------------Output---------------------"
docker run --rm -it practic8:latest
echo "-----------------------------------------------"
#docker images
