#!/usr/bin/env bash

echo "+----------------------------------------------+"
echo "|                                              |"
echo "| Try to limit cpu freq for core 0-7 to 4.5GHz |"
echo "|                                              |"
echo "+----------------------------------------------+"

sudo cpufreq-set -c 0 --max 4500000
sudo cpufreq-set -c 1 --max 4500000
sudo cpufreq-set -c 2 --max 4500000
sudo cpufreq-set -c 3 --max 4500000
sudo cpufreq-set -c 4 --max 4500000
sudo cpufreq-set -c 5 --max 4500000
sudo cpufreq-set -c 6 --max 4500000
sudo cpufreq-set -c 7 --max 4500000
