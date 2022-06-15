#!/bin/bash
docker images
docker build . -t practice2:latest
clear
echo "----------------Output---------------"
docker run --rm -it practice2:latest
echo "-------------------------------------"
docker rmi $(docker images --filter "dangling=true" -q --no-trunc)
docker images
