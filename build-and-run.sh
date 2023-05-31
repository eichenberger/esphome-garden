#!/bin/sh

docker run --net=host --rm -v "${PWD}":/config -it esphome/esphome:dev run garden.yaml
