#!/bin/sh

qemu-system-arm \
    -M versatilepb \
    -cpu arm1176 \
    -m 128 \
    -kernel kernel.img \
    -nographic \
    -s