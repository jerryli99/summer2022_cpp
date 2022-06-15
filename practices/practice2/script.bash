#!/bin/bash
docker images
docker build . -t cpp_docker:latest
clear
echo "----------------Output---------------"
docker run --rm -it cpp_docker:latest
echo "-------------------------------------"
docker rmi $(docker images --filter "dangling=true" -q --no-trunc)
docker images
