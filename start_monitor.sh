#!/bin/bash

echo "Starting Smart Network Monitor..."

# Move to project root first
cd "$(cd "$(dirname "$0")" && pwd)/.."

# Create logs folder if it doesn't exist
mkdir -p logs

# Run the monitor continuously
while true
do
    ./build/monitor
    sleep 10
done
