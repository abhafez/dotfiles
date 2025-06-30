#!/bin/bash

setopt +o nomatch
doas rm -rf /var/lib/bluetooth/*
setopt -o nomatch  # optional: re-enable
doas ls -la /var/lib/bluetooth/
doas systemctl restart bluetooth

