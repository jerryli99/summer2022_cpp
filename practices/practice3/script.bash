#!/bin/bash
docker images
docker build . -t practice3:latest
clear
echo "----------------Output---------------"
docker run --rm -it practice3:latest
echo "-------------------------------------"
docker rmi $(docker images --filter "dangling=true" -q --no-trunc)
docker images
